/*
 * baseline.h — Baseline Order Book (Linked List)
 *
 * Two sorted singly-linked lists hold live orders:
 *   buy_head  : descending price, ascending timestamp for equal prices
 *   sell_head : ascending  price, ascending timestamp for equal prices
 *
 * Insert   : O(n)   — walk to correct sorted position
 * Match    : O(n)   — linear scan from head (best price)
 * Remove   : O(n)   — scan for node, unlink
 *
 * This is the "naive" baseline whose performance we compare against
 * the RBTree + FibHeap optimised system.
 */
#ifndef BASELINE_H
#define BASELINE_H

#include "order.h"
#include "trade.h"

/* --- linked list node -------------------------------------------- */
typedef struct BLNode {
    Order          order;
    struct BLNode *next;
} BLNode;

/* --- order book --------------------------------------------------- */
typedef struct {
    BLNode *buy_head;           /* best (highest)   buy  at front  */
    BLNode *sell_head;          /* best (lowest)    sell at front  */
    int     inserted;           /* cumulative orders inserted      */
    int     matched_trades;     /* cumulative trades executed      */
    long    total_matched_qty;  /* cumulative quantity matched     */
} BaselineBook;

/* lifecycle */
BaselineBook *baseline_create(void);
void          baseline_destroy(BaselineBook *bk);

/*
 * baseline_process():
 *   1. Try to match `order` against the opposite side.
 *   2. If unfilled quantity remains, insert it into the book.
 *   out_trades[] must have room for at least MAX_TRADES_BUF entries.
 *   Returns number of trades generated.
 *   If verbose != 0, each trade is printed.
 */
int  baseline_process(BaselineBook *bk, Order order,
                      Trade *out_trades, int verbose);

/* diagnostics */
void baseline_print_top5(const BaselineBook *bk);
int  baseline_pending(const BaselineBook *bk);  /* # live orders */

#endif /* BASELINE_H */
