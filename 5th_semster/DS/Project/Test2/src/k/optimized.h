/*
 * optimized.h — Optimised Order Book (RBTree + Fibonacci Heap)
 *
 * Data structures:
 *   buy_tree   — RBTree keyed by price for pending BUY  orders
 *   sell_tree  — RBTree keyed by price for pending SELL orders
 *   event_heap — FibHeap ordered by expiry timestamp
 *
 * Complexities (vs O(n) for Baseline):
 *   Insert     — O(log n)  tree insert
 *   Match      — O(k log n) where k = number of trades
 *   Expiry     — O(log n)  heap extract-min per expired event
 *
 * Within a price level, orders are served FIFO (time-priority).
 */
#ifndef OPTIMIZED_H
#define OPTIMIZED_H

#include "order.h"
#include "trade.h"
#include "rbtree.h"
#include "fibheap.h"

/* Orders expire after this many time units */
#define ORDER_EXPIRY_OFFSET  1000L

typedef struct {
    RBTree  *buy_tree;          /* resting BUY  orders by price   */
    RBTree  *sell_tree;         /* resting SELL orders by price   */
    FibHeap *event_heap;        /* min-heap of expiry events      */
    int      inserted;
    int      matched_trades;
    long     total_matched_qty;
} OptimizedBook;

/* lifecycle */
OptimizedBook *opt_create(void);
void           opt_destroy(OptimizedBook *bk);

/*
 * opt_process():
 *   Attempt to match `order` against the resting side, then insert
 *   any remainder into the appropriate RBTree and schedule expiry.
 *   Returns number of trades generated.
 */
int  opt_process(OptimizedBook *bk, Order order,
                 Trade *out_trades, int verbose);

/*
 * opt_process_expired():
 *   Extract all events from the heap whose key <= current_time
 *   and cancel (remove) those orders from the book.
 */
void opt_process_expired(OptimizedBook *bk, long current_time);

/* diagnostics */
void opt_print_top5(OptimizedBook *bk);
int  opt_pending(OptimizedBook *bk);

#endif /* OPTIMIZED_H */
