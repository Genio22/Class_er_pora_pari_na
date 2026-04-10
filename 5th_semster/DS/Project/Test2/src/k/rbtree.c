/*
 * rbtree.c — Red-Black Tree implementation (CLRS §13)
 *
 * Invariants maintained after every operation:
 *   1. Every node is RED or BLACK.
 *   2. The root is BLACK.
 *   3. Every leaf (nil sentinel) is BLACK.
 *   4. If a node is RED, both children are BLACK.
 *   5. All paths from any node to descendant leaves have
 *      the same number of BLACK nodes (black-height).
 *
 * These invariants ensure height <= 2·log2(n+1), giving
 * O(log n) insert / delete / search.
 */
#include "../lib/rbtree.h"
#include <stdlib.h>
#include <stdio.h>

/* ================================================================== */
/*  Price-level list helpers                                          */
/* ================================================================== */

static PriceNode *pnode_create(Order o) {
    PriceNode *p = (PriceNode *)malloc(sizeof(PriceNode));
    p->order     = o;
    p->next      = NULL;
    return p;
}

/*
 * plist_insert: insert in ascending-timestamp order so that
 * the front of the list is always the oldest (earliest) order.
 * Time-priority is FIFO within a price level.
 */
static void plist_insert(PriceNode **head, Order o) {
    PriceNode  *node = pnode_create(o);
    PriceNode **pp   = head;
    while (*pp && (*pp)->order.timestamp <= o.timestamp)
        pp = &(*pp)->next;
    node->next = *pp;
    *pp        = node;
}

/* Remove order by id. Returns 1 if found, 0 otherwise. */
static int plist_remove(PriceNode **head, int order_id) {
    PriceNode **pp = head;
    while (*pp) {
        if ((*pp)->order.id == order_id) {
            PriceNode *del = *pp;
            *pp = del->next;
            free(del);
            return 1;
        }
        pp = &(*pp)->next;
    }
    return 0;
}

static void plist_free(PriceNode *head) {
    while (head) {
        PriceNode *tmp = head->next;
        free(head);
        head = tmp;
    }
}

/* ================================================================== */
/*  RB-Tree internal helpers                                          */
/* ================================================================== */

/* Create a new RED tree node containing one order. */
static RBNode *rb_node_create(RBTree *t, double key, Order o) {
    RBNode *n  = (RBNode *)malloc(sizeof(RBNode));
    n->key     = key;
    n->orders  = NULL;
    n->color   = RB_RED;
    n->left    = t->nil;
    n->right   = t->nil;
    n->parent  = t->nil;
    plist_insert(&n->orders, o);
    return n;
}

RBTree *rbtree_create(void) {
    RBTree *t     = (RBTree *)malloc(sizeof(RBTree));
    /* Sentinel nil node — shared by all leaves */
    t->nil        = (RBNode *)calloc(1, sizeof(RBNode));
    t->nil->color  = RB_BLACK;
    t->nil->left   = t->nil;
    t->nil->right  = t->nil;
    t->nil->parent = t->nil;
    t->nil->orders = NULL;
    t->root        = t->nil;
    t->size        = 0;
    return t;
}

static void rbtree_free_node(RBNode *node, RBNode *nil) {
    if (node == nil) return;
    rbtree_free_node(node->left,  nil);
    rbtree_free_node(node->right, nil);
    plist_free(node->orders);
    free(node);
}

void rbtree_destroy(RBTree *t) {
    if (!t) return;
    rbtree_free_node(t->root, t->nil);
    free(t->nil);
    free(t);
}

/* ------------------------------------------------------------------ */
/*  Rotations (preserve BST order, used during fixup)                 */
/* ------------------------------------------------------------------ */

/*
 *     x                  y
 *    / \                / \
 *   a   y     -->      x   c
 *      / \            / \
 *     b   c          a   b
 */
static void left_rotate(RBTree *t, RBNode *x) {
    RBNode *y = x->right;
    x->right  = y->left;
    if (y->left != t->nil) y->left->parent = x;
    y->parent = x->parent;
    if      (x->parent == t->nil)        t->root          = y;
    else if (x == x->parent->left)       x->parent->left  = y;
    else                                  x->parent->right = y;
    y->left   = x;
    x->parent = y;
}

/*
 *       y              x
 *      / \            / \
 *     x   c  -->     a   y
 *    / \                / \
 *   a   b              b   c
 */
static void right_rotate(RBTree *t, RBNode *y) {
    RBNode *x = y->left;
    y->left   = x->right;
    if (x->right != t->nil) x->right->parent = y;
    x->parent = y->parent;
    if      (y->parent == t->nil)        t->root          = x;
    else if (y == y->parent->left)       y->parent->left  = x;
    else                                  y->parent->right = x;
    x->right  = y;
    y->parent = x;
}

/* ------------------------------------------------------------------ */
/*  Insert                                                            */
/* ------------------------------------------------------------------ */

static void rb_insert_fixup(RBTree *t, RBNode *z) {
    /*
     * z is RED; if z's parent is also RED, RB invariant 4 is violated.
     * Three cases per side (mirrored for right/left):
     *   Case 1: uncle is RED   → recolour, move z up
     *   Case 2: uncle is BLACK, z is "inner" child → rotate z up
     *   Case 3: uncle is BLACK, z is "outer" child → rotate parent, recolour
     */
    while (z->parent->color == RB_RED) {
        if (z->parent == z->parent->parent->left) {
            RBNode *y = z->parent->parent->right;   /* uncle */
            if (y->color == RB_RED) {
                /* Case 1 */
                z->parent->color         = RB_BLACK;
                y->color                 = RB_BLACK;
                z->parent->parent->color = RB_RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    /* Case 2 → convert to Case 3 */
                    z = z->parent;
                    left_rotate(t, z);
                }
                /* Case 3 */
                z->parent->color         = RB_BLACK;
                z->parent->parent->color = RB_RED;
                right_rotate(t, z->parent->parent);
            }
        } else {
            /* Mirror image */
            RBNode *y = z->parent->parent->left;
            if (y->color == RB_RED) {
                z->parent->color         = RB_BLACK;
                y->color                 = RB_BLACK;
                z->parent->parent->color = RB_RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    right_rotate(t, z);
                }
                z->parent->color         = RB_BLACK;
                z->parent->parent->color = RB_RED;
                left_rotate(t, z->parent->parent);
            }
        }
    }
    t->root->color = RB_BLACK;  /* invariant 2 */
}

void rbtree_insert(RBTree *t, Order o) {
    double  key  = o.price;
    /* Search for an existing node at this price level */
    RBNode *curr = t->root;
    while (curr != t->nil) {
        if (key == curr->key) {
            /* Price level already exists — just add order to its list */
            plist_insert(&curr->orders, o);
            return;
        }
        curr = (key < curr->key) ? curr->left : curr->right;
    }

    /* New price level: standard BST insert then fixup */
    RBNode *z = rb_node_create(t, key, o);
    RBNode *y = t->nil;
    curr      = t->root;
    while (curr != t->nil) {
        y    = curr;
        curr = (z->key < curr->key) ? curr->left : curr->right;
    }
    z->parent = y;
    if      (y == t->nil)       t->root    = z;
    else if (z->key < y->key)  y->left    = z;
    else                        y->right   = z;

    t->size++;
    rb_insert_fixup(t, z);
}

/* ------------------------------------------------------------------ */
/*  Delete                                                            */
/* ------------------------------------------------------------------ */

/* Replace subtree rooted at u with subtree rooted at v */
static void rb_transplant(RBTree *t, RBNode *u, RBNode *v) {
    if      (u->parent == t->nil)        t->root          = v;
    else if (u == u->parent->left)       u->parent->left  = v;
    else                                  u->parent->right = v;
    v->parent = u->parent;
}

/* Leftmost node in subtree x */
static RBNode *tree_min_node(RBTree *t, RBNode *x) {
    while (x->left != t->nil) x = x->left;
    return x;
}

static void rb_delete_fixup(RBTree *t, RBNode *x) {
    /*
     * x has a "missing" black on its path; we push this
     * deficiency upward until we can absorb it.
     */
    while (x != t->root && x->color == RB_BLACK) {
        if (x == x->parent->left) {
            RBNode *w = x->parent->right;  /* sibling */
            if (w->color == RB_RED) {
                /* Case 1: sibling is RED → convert to cases 2-4 */
                w->color         = RB_BLACK;
                x->parent->color = RB_RED;
                left_rotate(t, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == RB_BLACK && w->right->color == RB_BLACK) {
                /* Case 2: sibling's children both BLACK */
                w->color = RB_RED;
                x        = x->parent;
            } else {
                if (w->right->color == RB_BLACK) {
                    /* Case 3: sibling's right child BLACK → rotate */
                    w->left->color = RB_BLACK;
                    w->color       = RB_RED;
                    right_rotate(t, w);
                    w = x->parent->right;
                }
                /* Case 4: absorb deficiency */
                w->color         = x->parent->color;
                x->parent->color = RB_BLACK;
                w->right->color  = RB_BLACK;
                left_rotate(t, x->parent);
                x = t->root;
            }
        } else {
            /* Mirror image */
            RBNode *w = x->parent->left;
            if (w->color == RB_RED) {
                w->color         = RB_BLACK;
                x->parent->color = RB_RED;
                right_rotate(t, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == RB_BLACK && w->left->color == RB_BLACK) {
                w->color = RB_RED;
                x        = x->parent;
            } else {
                if (w->left->color == RB_BLACK) {
                    w->right->color = RB_BLACK;
                    w->color        = RB_RED;
                    left_rotate(t, w);
                    w = x->parent->left;
                }
                w->color         = x->parent->color;
                x->parent->color = RB_BLACK;
                w->left->color   = RB_BLACK;
                right_rotate(t, x->parent);
                x = t->root;
            }
        }
    }
    x->color = RB_BLACK;
}

/* Delete the RBNode z from the tree (its order list must already be
   empty or freed by the caller). */
static void rb_delete_node(RBTree *t, RBNode *z) {
    RBNode *y             = z;
    RBColor y_orig_color  = y->color;
    RBNode *x;

    if (z->left == t->nil) {
        x = z->right;
        rb_transplant(t, z, z->right);
    } else if (z->right == t->nil) {
        x = z->left;
        rb_transplant(t, z, z->left);
    } else {
        /* y = successor (leftmost of right subtree) */
        y            = tree_min_node(t, z->right);
        y_orig_color = y->color;
        x            = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rb_transplant(t, y, y->right);
            y->right         = z->right;
            y->right->parent = y;
        }
        rb_transplant(t, z, y);
        y->left         = z->left;
        y->left->parent = y;
        y->color        = z->color;
    }
    if (y_orig_color == RB_BLACK)
        rb_delete_fixup(t, x);

    /* Free the old node (order list freed by caller or already empty) */
    plist_free(z->orders);
    free(z);
    t->size--;
}

void rbtree_remove_order(RBTree *t, int order_id, double price) {
    RBNode *node = t->root;
    while (node != t->nil) {
        if      (price == node->key) break;
        else if (price <  node->key) node = node->left;
        else                          node = node->right;
    }
    if (node == t->nil) return;  /* price level not found */

    plist_remove(&node->orders, order_id);

    /* If price level is now empty, remove the tree node */
    if (node->orders == NULL) {
        node->orders = NULL;     /* already NULL, just guard */
        rb_delete_node(t, node); /* frees node */
    }
}

/* ================================================================== */
/*  Query operations                                                  */
/* ================================================================== */

RBNode *rbtree_min(RBTree *t) {
    if (t->root == t->nil) return NULL;
    return tree_min_node(t, t->root);
}

RBNode *rbtree_max(RBTree *t) {
    if (t->root == t->nil) return NULL;
    RBNode *x = t->root;
    while (x->right != t->nil) x = x->right;
    return x;
}

/* Largest key <= price (floor) */
RBNode *rbtree_find_le(RBTree *t, double price) {
    RBNode *curr = t->root;
    RBNode *best = NULL;
    while (curr != t->nil) {
        if (curr->key <= price) {
            best = curr;
            curr = curr->right;  /* try to find a larger valid key */
        } else {
            curr = curr->left;
        }
    }
    return best;
}

/* Smallest key >= price (ceiling) */
RBNode *rbtree_find_ge(RBTree *t, double price) {
    RBNode *curr = t->root;
    RBNode *best = NULL;
    while (curr != t->nil) {
        if (curr->key >= price) {
            best = curr;
            curr = curr->left;   /* try to find a smaller valid key */
        } else {
            curr = curr->right;
        }
    }
    return best;
}

/*
 * rbtree_pop_front:
 *   Remove and return the earliest (smallest timestamp) order at node.
 *   If the price level's order list becomes empty, the node is
 *   deleted from the tree (freeing memory).
 *   WARNING: do not access node after this call if it could be freed.
 */
Order rbtree_pop_front(RBTree *t, RBNode *node) {
    PriceNode *front = node->orders;
    Order      o     = front->order;      /* copy by value */
    node->orders     = front->next;
    free(front);

    if (node->orders == NULL) {
        rb_delete_node(t, node);          /* removes & frees node */
    }
    return o;
}

/* ================================================================== */
/*  Diagnostics                                                       */
/* ================================================================== */

/*
 * Iterative in-order traversal.
 * ascending=1 → smallest first (for sell book)
 * ascending=0 → largest  first (for buy  book)
 */
void rbtree_print_top(RBTree *t, int n, int ascending) {
    if (t->root == t->nil) { printf("    (empty)\n"); return; }

    RBNode *stack[128];
    int     sp    = 0;
    RBNode *curr  = t->root;
    int     count = 0;

    if (ascending) {
        /* normal in-order: left → root → right */
        while ((curr != t->nil || sp > 0) && count < n) {
            while (curr != t->nil) { stack[sp++] = curr; curr = curr->left; }
            curr = stack[--sp];
            /* visit */
            int total_qty = 0;
            for (PriceNode *p = curr->orders; p; p = p->next)
                total_qty += p->order.quantity;
            printf("    price=%6.2f  total_qty=%-5d\n", curr->key, total_qty);
            count++;
            curr = curr->right;
        }
    } else {
        /* reverse in-order: right → root → left */
        while ((curr != t->nil || sp > 0) && count < n) {
            while (curr != t->nil) { stack[sp++] = curr; curr = curr->right; }
            curr = stack[--sp];
            int total_qty = 0;
            for (PriceNode *p = curr->orders; p; p = p->next)
                total_qty += p->order.quantity;
            printf("    price=%6.2f  total_qty=%-5d\n", curr->key, total_qty);
            count++;
            curr = curr->left;
        }
    }
}
