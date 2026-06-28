/*
 * rbtree.h — Red-Black Tree (CLRS §13)
 *
 * Stores order book price levels.
 *   key   = price (double)
 *   value = singly-linked list of orders at that price,
 *           sorted by timestamp ascending (earliest first).
 *
 * Operations:
 *   rbtree_insert        — O(log n)  add an order
 *   rbtree_remove_order  — O(log n)  remove a specific order by id + price
 *   rbtree_pop_front     — O(1)/O(log n) take oldest order at a price level
 *   rbtree_min / max     — O(log n)  find best price node
 *   rbtree_find_le / ge  — O(log n)  floor / ceiling search
 *
 * Why RB Tree over a plain BST?
 *   Guarantees O(log n) worst-case height via colour-based rotations,
 *   unlike an unbalanced BST that degrades to O(n) on sorted input.
 *   Price data tends to cluster, so balance matters.
 */
#ifndef RBTREE_H
#define RBTREE_H

#include "order.h"

/* ---- price-level list node -------------------------------------- */
typedef struct PriceNode {
    Order             order;
    struct PriceNode *next;
} PriceNode;

/* ---- RB-tree node colour --------------------------------------- */
typedef enum { RB_RED = 0, RB_BLACK = 1 } RBColor;

/* ---- RB-tree node ---------------------------------------------- */
typedef struct RBNode {
    double         key;     /* price level                    */
    PriceNode     *orders;  /* list of orders at this price   */
    RBColor        color;
    struct RBNode *left;
    struct RBNode *right;
    struct RBNode *parent;
} RBNode;

/* ---- tree handle ----------------------------------------------- */
typedef struct {
    RBNode *root;
    RBNode *nil;   /* sentinel leaf — always BLACK, child of leaves */
    int     size;  /* number of distinct price levels               */
} RBTree;

/* lifecycle */
RBTree *rbtree_create(void);
void    rbtree_destroy(RBTree *t);

/* mutation */
void    rbtree_insert(RBTree *t, Order o);
void    rbtree_remove_order(RBTree *t, int order_id, double price);

/*
 * rbtree_pop_front:
 *   Remove & return the earliest-timestamp order at *node*.
 *   If the price level becomes empty, the node is deleted from the tree.
 *   Caller must NOT access *node after this call (may be freed).
 */
Order   rbtree_pop_front(RBTree *t, RBNode *node);

/* queries */
RBNode *rbtree_min(RBTree *t);              /* smallest key */
RBNode *rbtree_max(RBTree *t);              /* largest  key */
RBNode *rbtree_find_le(RBTree *t, double price); /* floor  */
RBNode *rbtree_find_ge(RBTree *t, double price); /* ceiling*/

/* diagnostics — print top n price levels */
void    rbtree_print_top(RBTree *t, int n, int ascending);

#endif /* RBTREE_H */
