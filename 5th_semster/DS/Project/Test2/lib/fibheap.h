/*
 * fibheap.h — Fibonacci Heap (CLRS §19)
 *
 * Used by the optimised order book to schedule and process
 * order-expiry events in minimum-time-first order.
 *
 * Amortised complexities:
 *   fh_insert        — O(1)
 *   fh_extract_min   — O(log n)
 *   fh_decrease_key  — O(1)
 *   fh_delete        — O(log n)
 *
 * Why Fibonacci Heap over a binary heap?
 *   fh_decrease_key is O(1) amortised (vs O(log n) for binary heap).
 *   When an order's expiry is updated (e.g. a cancel-replace),
 *   the heap can be updated cheaply without full re-heapification.
 *
 * Heap property: min-heap on `key` (execution/expiry time).
 */
#ifndef FIBHEAP_H
#define FIBHEAP_H

#include "order.h"

/* ---- heap node -------------------------------------------------- */
typedef struct FHNode {
    long          key;          /* expiry timestamp                */
    int           order_id;     /* associated order id             */
    double        order_price;  /* needed to locate in RBTree      */
    int           order_type;   /* 0=BUY, 1=SELL                   */

    int           degree;       /* number of children              */
    int           marked;       /* lost a child since last cut?    */

    struct FHNode *parent;
    struct FHNode *child;       /* one child (circular list entry) */
    struct FHNode *left;        /* circular doubly-linked siblings */
    struct FHNode *right;
} FHNode;

/* ---- heap handle ----------------------------------------------- */
typedef struct {
    FHNode *min;  /* pointer to minimum-key root node */
    int     n;    /* total number of nodes            */
} FibHeap;

/* lifecycle */
FibHeap *fh_create(void);
void     fh_destroy(FibHeap *h);

/* operations */
FHNode  *fh_insert(FibHeap *h, long key,
                   int order_id, double order_price, int order_type);
FHNode  *fh_extract_min(FibHeap *h);
void     fh_decrease_key(FibHeap *h, FHNode *x, long new_key);
void     fh_delete(FibHeap *h, FHNode *x);

int      fh_empty(FibHeap *h);

#endif /* FIBHEAP_H */
