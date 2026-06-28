#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stddef.h>
#include "order.h"

typedef enum {
    RED,
    BLACK
} Color;

typedef struct RBNode {
    int price;
    Order *orders;
    int orders_count;
    int orders_capacity;
    Color color;
    struct RBNode *left;
    struct RBNode *right;
    struct RBNode *parent;
} RBNode;

typedef struct {
    RBNode *root;
    RBNode *tnull;
} RBTree;

RBTree* rb_tree_create(void);
RBNode* rb_tree_insert_and_get_node(RBTree *tree, int price, const Order *order);
RBNode* rb_tree_minimum(RBTree *tree, RBNode *node);
RBNode* rb_tree_maximum(RBTree *tree, RBNode *node);
RBNode* rb_tree_successor(RBTree *tree, RBNode *x);
RBNode* rb_tree_predecessor(RBTree *tree, RBNode *x);
RBNode* rb_tree_get_root(RBTree *tree);
RBNode* rb_tree_get_tnull(RBTree *tree);
void rb_tree_destroy(RBTree *tree);

#endif // RED_BLACK_TREE_H