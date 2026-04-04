#include "red_black_tree.h"
#include <stdlib.h>
#include <string.h>

static void left_rotate(RBTree *tree, RBNode *x);
static void right_rotate(RBTree *tree, RBNode *x);
static void insert_fix(RBTree *tree, RBNode *k);

RBTree* rb_tree_create(void) {
    RBTree *tree = (RBTree *)malloc(sizeof(RBTree));
    tree->tnull = (RBNode *)malloc(sizeof(RBNode));
    tree->tnull->color = BLACK;
    tree->tnull->left = tree->tnull;
    tree->tnull->right = tree->tnull;
    tree->tnull->parent = NULL;
    tree->tnull->price = 0;
    tree->tnull->orders = NULL;
    tree->tnull->orders_count = 0;
    tree->tnull->orders_capacity = 0;
    tree->root = tree->tnull;
    return tree;
}

static RBNode* rb_node_create(int price, const Order *order, RBNode *tnull) {
    RBNode *node = (RBNode *)malloc(sizeof(RBNode));
    node->price = price;
    node->color = RED;
    node->left = tnull;
    node->right = tnull;
    node->parent = NULL;
    
    node->orders_capacity = 10;
    node->orders = (Order *)malloc(sizeof(Order) * node->orders_capacity);
    node->orders_count = 1;
    memcpy(&node->orders[0], order, sizeof(Order));
    
    return node;
}

static void left_rotate(RBTree *tree, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    
    if (y->left != tree->tnull)
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (x->parent == NULL)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}

static void right_rotate(RBTree *tree, RBNode *x) {
    RBNode *y = x->left;
    x->left = y->right;
    
    if (y->right != tree->tnull)
        y->right->parent = x;
    
    y->parent = x->parent;
    
    if (x->parent == NULL)
        tree->root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    
    y->right = x;
    x->parent = y;
}

static void insert_fix(RBTree *tree, RBNode *k) {
    RBNode *u;
    
    while (k->parent != NULL && k->parent->color == RED) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            
            if (u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    right_rotate(tree, k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                left_rotate(tree, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            
            if (u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    left_rotate(tree, k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                right_rotate(tree, k->parent->parent);
            }
        }
        
        if (k == tree->root)
            break;
    }
    
    tree->root->color = BLACK;
}

RBNode* rb_tree_insert_and_get_node(RBTree *tree, int price, const Order *order) {
    RBNode *node = rb_node_create(price, order, tree->tnull);
    RBNode *y = NULL;
    RBNode *x = tree->root;
    
    while (x != tree->tnull) {
        y = x;
        
        if (node->price == x->price) {
            if (x->orders_count >= x->orders_capacity) {
                x->orders_capacity *= 2;
                x->orders = (Order *)realloc(x->orders, sizeof(Order) * x->orders_capacity);
            }
            memcpy(&x->orders[x->orders_count++], order, sizeof(Order));
            free(node->orders);
            free(node);
            return x;
        }
        
        if (node->price < x->price)
            x = x->left;
        else
            x = x->right;
    }
    
    node->parent = y;
    
    if (y == NULL)
        tree->root = node;
    else if (node->price < y->price)
        y->left = node;
    else
        y->right = node;
    
    if (node->parent == NULL) {
        node->color = BLACK;
        return node;
    }
    
    if (node->parent->parent == NULL)
        return node;
    
    insert_fix(tree, node);
    return node;
}

RBNode* rb_tree_minimum(RBTree *tree, RBNode *node) {
    if (node == tree->tnull || node == NULL)
        return tree->tnull;
    
    while (node->left != tree->tnull)
        node = node->left;
    
    return node;
}

RBNode* rb_tree_maximum(RBTree *tree, RBNode *node) {
    if (node == tree->tnull || node == NULL)
        return tree->tnull;
    
    while (node->right != tree->tnull)
        node = node->right;
    
    return node;
}

RBNode* rb_tree_successor(RBTree *tree, RBNode *x) {
    if (x == NULL || x == tree->tnull)
        return tree->tnull;
    
    if (x->right != tree->tnull)
        return rb_tree_minimum(tree, x->right);
    
    RBNode *y = x->parent;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    
    return y ? y : tree->tnull;
}

RBNode* rb_tree_predecessor(RBTree *tree, RBNode *x) {
    if (x == NULL || x == tree->tnull)
        return tree->tnull;
    
    if (x->left != tree->tnull)
        return rb_tree_maximum(tree, x->left);
    
    RBNode *y = x->parent;
    while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
    }
    
    return y ? y : tree->tnull;
}

RBNode* rb_tree_get_root(RBTree *tree) {
    return tree->root;
}

RBNode* rb_tree_get_tnull(RBTree *tree) {
    return tree->tnull;
}

static void rb_node_destroy(RBTree *tree, RBNode *node) {
    if (node == NULL || node == tree->tnull)
        return;
    
    rb_node_destroy(tree, node->left);
    rb_node_destroy(tree, node->right);
    
    if (node->orders)
        free(node->orders);
    
    free(node);
}

void rb_tree_destroy(RBTree *tree) {
    if (tree == NULL)
        return;
    
    rb_node_destroy(tree, tree->root);
    free(tree->tnull);
    free(tree);
}