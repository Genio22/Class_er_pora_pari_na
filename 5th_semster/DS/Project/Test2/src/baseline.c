/*
 * baseline.c — Linked-list order book implementation
 *
 * Matching rules (same for both systems):
 *   BUY  at price P → match lowest  SELL whose price <= P
 *   SELL at price P → match highest BUY  whose price >= P
 *   Ties on price   → earlier timestamp gets priority
 *   Partial fills   → reduce quantity, keep remainder in book
 */
#include "baseline.h"
#include <stdlib.h>
#include <stdio.h>

/* ------------------------------------------------------------------ */
/*  Allocation helpers                                                 */
/* ------------------------------------------------------------------ */

BaselineBook *baseline_create(void) {
    BaselineBook *bk = (BaselineBook *)malloc(sizeof(BaselineBook));
    bk->buy_head          = NULL;
    bk->sell_head         = NULL;
    bk->inserted          = 0;
    bk->matched_trades    = 0;
    bk->total_matched_qty = 0;
    return bk;
}

static void free_list(BLNode *head) {
    while (head) {
        BLNode *tmp = head->next;
        free(head);
        head = tmp;
    }
}

void baseline_destroy(BaselineBook *bk) {
    if (!bk) return;
    free_list(bk->buy_head);
    free_list(bk->sell_head);
    free(bk);
}

static BLNode *make_node(Order o) {
    BLNode *n  = (BLNode *)malloc(sizeof(BLNode));
    n->order   = o;
    n->next    = NULL;
    return n;
}

/* ------------------------------------------------------------------ */
/*  Sorted insertion                                                   */
/* ------------------------------------------------------------------ */

/*
 * buy_insert: keeps list sorted descending by price.
 * For equal prices the earlier (smaller) timestamp comes first.
 */
static void buy_insert(BaselineBook *bk, Order o) {
    BLNode  *node = make_node(o);
    BLNode **pp   = &bk->buy_head;
    while (*pp) {
        double p = (*pp)->order.price;
        /* o should go before *pp if: o.price > p
           OR (prices equal AND o is earlier)            */
        if (o.price > p) break;
        if (o.price == p && o.timestamp < (*pp)->order.timestamp) break;
        pp = &(*pp)->next;
    }
    node->next = *pp;
    *pp        = node;
}

/*
 * sell_insert: keeps list sorted ascending by price.
 * For equal prices the earlier timestamp comes first.
 */
static void sell_insert(BaselineBook *bk, Order o) {
    BLNode  *node = make_node(o);
    BLNode **pp   = &bk->sell_head;
    while (*pp) {
        double p = (*pp)->order.price;
        if (o.price < p) break;
        if (o.price == p && o.timestamp < (*pp)->order.timestamp) break;
        pp = &(*pp)->next;
    }
    node->next = *pp;
    *pp        = node;
}

/* Remove the node currently pointed-to by *pp and advance *pp. */
static void remove_node(BLNode **pp) {
    BLNode *del = *pp;
    *pp         = del->next;
    free(del);
}

/* ------------------------------------------------------------------ */
/*  Matching logic                                                     */
/* ------------------------------------------------------------------ */

/*
 * match_buy: walk sell list (ascending price) from the front.
 *   front = lowest ask — compare against buy limit price.
 *   Stop as soon as ask > buy price (no more matchable sells).
 */
static int match_buy(BaselineBook *bk,
                     Order        *buy,
                     Trade        *trades,
                     int           verbose) {
    int      count = 0;
    BLNode **pp    = &bk->sell_head;

    while (*pp && buy->quantity > 0) {
        Order *sell = &(*pp)->order;

        /* sell list is ascending: once sell price > buy price, done */
        if (sell->price > buy->price) break;

        /* ---- match! ---- */
        int qty = (buy->quantity < sell->quantity)
                    ? buy->quantity : sell->quantity;

        Trade t;
        t.buy_id   = buy->id;
        t.sell_id  = sell->id;
        t.price    = sell->price;   /* passive side sets price */
        t.quantity = qty;
        trades[count++] = t;

        bk->matched_trades++;
        bk->total_matched_qty += qty;
        if (verbose) trade_print(&t);

        buy->quantity  -= qty;
        sell->quantity -= qty;

        if (sell->quantity == 0) {
            remove_node(pp);    /* *pp now points to next sell */
        } else {
            /* sell partially filled; buy must be exhausted */
            pp = &(*pp)->next;  /* advance (won't iterate again) */
        }
    }
    return count;
}

/*
 * match_sell: walk buy list (descending price) from the front.
 *   front = highest bid — compare against sell limit price.
 *   Stop as soon as bid < sell price.
 */
static int match_sell(BaselineBook *bk,
                      Order        *sell,
                      Trade        *trades,
                      int           verbose) {
    int      count = 0;
    BLNode **pp    = &bk->buy_head;

    while (*pp && sell->quantity > 0) {
        Order *buy = &(*pp)->order;

        /* buy list is descending: once buy price < sell price, done */
        if (buy->price < sell->price) break;

        int qty = (sell->quantity < buy->quantity)
                    ? sell->quantity : buy->quantity;

        Trade t;
        t.buy_id   = buy->id;
        t.sell_id  = sell->id;
        t.price    = buy->price;    /* passive side (resting buy) sets price */
        t.quantity = qty;
        trades[count++] = t;

        bk->matched_trades++;
        bk->total_matched_qty += qty;
        if (verbose) trade_print(&t);

        sell->quantity -= qty;
        buy->quantity  -= qty;

        if (buy->quantity == 0) {
            remove_node(pp);
        } else {
            pp = &(*pp)->next;
        }
    }
    return count;
}

/* ------------------------------------------------------------------ */
/*  Public API                                                         */
/* ------------------------------------------------------------------ */

int baseline_process(BaselineBook *bk, Order order,
                     Trade *out_trades, int verbose) {
    bk->inserted++;
    int n = 0;

    if (order.type == BUY) {
        n = match_buy(bk, &order, out_trades, verbose);
        if (order.quantity > 0) buy_insert(bk, order);
    } else {
        n = match_sell(bk, &order, out_trades, verbose);
        if (order.quantity > 0) sell_insert(bk, order);
    }
    return n;
}

void baseline_print_top5(const BaselineBook *bk) {
    printf("  +-BUY  book (highest bid first)-+\n");
    BLNode *n   = bk->buy_head;
    int     cnt = 0;
    while (n && cnt < 5) {
        printf("    [%4d] price=%6.2f  qty=%-4d\n",
               n->order.id, n->order.price, n->order.quantity);
        n = n->next;
        cnt++;
    }
    if (!bk->buy_head) printf("    (empty)\n");

    printf("  +-SELL book (lowest  ask first)-+\n");
    n   = bk->sell_head;
    cnt = 0;
    while (n && cnt < 5) {
        printf("    [%4d] price=%6.2f  qty=%-4d\n",
               n->order.id, n->order.price, n->order.quantity);
        n = n->next;
        cnt++;
    }
    if (!bk->sell_head) printf("    (empty)\n");
}

int baseline_pending(const BaselineBook *bk) {
    int cnt = 0;
    BLNode *n = bk->buy_head;
    while (n) { cnt++; n = n->next; }
    n = bk->sell_head;
    while (n) { cnt++; n = n->next; }
    return cnt;
}
