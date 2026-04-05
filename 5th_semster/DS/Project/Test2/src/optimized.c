/*
 * optimized.c — RBTree + Fibonacci Heap order book
 *
 * Matching logic is identical to the baseline; only the underlying
 * data structure operations differ:
 *   - "find best price" is O(log n) via rbtree_min/max
 *   - "remove exhausted order" is O(log n) via rbtree_pop_front
 *   - "schedule expiry" is O(1) amortised via fh_insert
 *   - "process next expiry" is O(log n) amortised via fh_extract_min
 */
#include "optimized.h"
#include <stdlib.h>
#include <stdio.h>

OptimizedBook *opt_create(void) {
    OptimizedBook *bk    = (OptimizedBook *)malloc(sizeof(OptimizedBook));
    bk->buy_tree          = rbtree_create();
    bk->sell_tree         = rbtree_create();
    bk->event_heap        = fh_create();
    bk->inserted          = 0;
    bk->matched_trades    = 0;
    bk->total_matched_qty = 0;
    return bk;
}

void opt_destroy(OptimizedBook *bk) {
    if (!bk) return;
    rbtree_destroy(bk->buy_tree);
    rbtree_destroy(bk->sell_tree);
    fh_destroy(bk->event_heap);
    free(bk);
}

/* ------------------------------------------------------------------ */
/*  Matching — BUY incoming                                            */
/*                                                                     */
/*  Strategy: repeatedly grab the cheapest resting sell.              */
/*    rbtree_min(sell_tree)  → O(log n) — the lowest ask              */
/*    If lowest ask <= buy limit price → match                        */
/*    After full fill of sell level front, pop it → O(log n)         */
/* ------------------------------------------------------------------ */
static int match_buy_opt(OptimizedBook *bk,
                         Order         *buy,
                         Trade         *trades,
                         int            verbose) {
    int count = 0;

    while (buy->quantity > 0) {
        /* O(log n): find the resting sell with the lowest price */
        RBNode *best_sell = rbtree_min(bk->sell_tree);
        if (!best_sell) break;                    /* no resting sells */
        if (best_sell->key > buy->price) break;   /* price does not cross */

        /* Front of the price level = earliest (time-priority) order */
        PriceNode *pn        = best_sell->orders;
        int        qty       = (buy->quantity < pn->order.quantity)
                                 ? buy->quantity : pn->order.quantity;

        /* Record trade */
        Trade t;
        t.buy_id   = buy->id;
        t.sell_id  = pn->order.id;
        t.price    = pn->order.price;  /* passive sell sets price */
        t.quantity = qty;
        trades[count++] = t;
        bk->matched_trades++;
        bk->total_matched_qty += qty;
        if (verbose) trade_print(&t);

        buy->quantity      -= qty;
        pn->order.quantity -= qty;

        if (pn->order.quantity == 0) {
            /*
             * Sell order fully consumed — pop it.
             * best_sell may be freed inside rbtree_pop_front
             * if the price level becomes empty; do NOT use it after.
             */
            rbtree_pop_front(bk->sell_tree, best_sell);
        }
        /*
         * If pn->order.quantity > 0 the sell is partially filled,
         * which means buy->quantity hit 0 (qty == buy->quantity),
         * so the while condition will fail on next iteration.
         */
    }
    return count;
}

/* ------------------------------------------------------------------ */
/*  Matching — SELL incoming                                           */
/*                                                                     */
/*  Strategy: repeatedly grab the highest resting buy.               */
/*    rbtree_max(buy_tree)  → O(log n) — the highest bid             */
/*    If highest bid >= sell limit price → match                      */
/* ------------------------------------------------------------------ */
static int match_sell_opt(OptimizedBook *bk,
                          Order         *sell,
                          Trade         *trades,
                          int            verbose) {
    int count = 0;

    while (sell->quantity > 0) {
        /* O(log n): find the resting buy with the highest price */
        RBNode *best_buy = rbtree_max(bk->buy_tree);
        if (!best_buy) break;
        if (best_buy->key < sell->price) break;

        PriceNode *pn  = best_buy->orders;
        int        qty = (sell->quantity < pn->order.quantity)
                           ? sell->quantity : pn->order.quantity;

        Trade t;
        t.buy_id   = pn->order.id;
        t.sell_id  = sell->id;
        t.price    = pn->order.price;   /* passive buy sets price */
        t.quantity = qty;
        trades[count++] = t;
        bk->matched_trades++;
        bk->total_matched_qty += qty;
        if (verbose) trade_print(&t);

        sell->quantity     -= qty;
        pn->order.quantity -= qty;

        if (pn->order.quantity == 0) {
            rbtree_pop_front(bk->buy_tree, best_buy);
        }
    }
    return count;
}

/* ------------------------------------------------------------------ */
/*  Public process                                                     */
/* ------------------------------------------------------------------ */

int opt_process(OptimizedBook *bk, Order order,
                Trade *out_trades, int verbose) {
    bk->inserted++;
    int n = 0;

    if (order.type == BUY) {
        n = match_buy_opt(bk, &order, out_trades, verbose);
        if (order.quantity > 0) {
            /* Insert remainder into buy tree — O(log n) */
            rbtree_insert(bk->buy_tree, order);
            /* Schedule expiry event — O(1) amortised */
            fh_insert(bk->event_heap,
                      order.timestamp + ORDER_EXPIRY_OFFSET,
                      order.id, order.price, 0 /* BUY */);
        }
    } else {
        n = match_sell_opt(bk, &order, out_trades, verbose);
        if (order.quantity > 0) {
            rbtree_insert(bk->sell_tree, order);
            fh_insert(bk->event_heap,
                      order.timestamp + ORDER_EXPIRY_OFFSET,
                      order.id, order.price, 1 /* SELL */);
        }
    }
    return n;
}

/* ------------------------------------------------------------------ */
/*  Expiry processing (Fibonacci Heap demo)                            */
/*                                                                     */
/*  Process all events whose scheduled time <= current_time.          */
/*  Each fh_extract_min is O(log n) amortised.                        */
/* ------------------------------------------------------------------ */
void opt_process_expired(OptimizedBook *bk, long current_time) {
    while (!fh_empty(bk->event_heap)) {
        FHNode *top = bk->event_heap->min;
        if (top->key > current_time) break;

        FHNode *expired = fh_extract_min(bk->event_heap); /* O(log n) */

        /* Remove the order from the appropriate RBTree */
        if (expired->order_type == 0) {   /* BUY */
            rbtree_remove_order(bk->buy_tree,
                                expired->order_id,
                                expired->order_price);
        } else {                           /* SELL */
            rbtree_remove_order(bk->sell_tree,
                                expired->order_id,
                                expired->order_price);
        }
        free(expired);
    }
}

/* ------------------------------------------------------------------ */
/*  Diagnostics                                                        */
/* ------------------------------------------------------------------ */

void opt_print_top5(OptimizedBook *bk) {
    printf("  +-BUY  book (highest bid first)-+\n");
    rbtree_print_top(bk->buy_tree,  5, 0);   /* 0 = descending */
    printf("  +-SELL book (lowest  ask first)-+\n");
    rbtree_print_top(bk->sell_tree, 5, 1);   /* 1 = ascending  */
}

int opt_pending(OptimizedBook *bk) {
    /* Each price level in the tree may have multiple orders;
       we report the number of distinct price levels for simplicity. */
    return bk->buy_tree->size + bk->sell_tree->size;
}
