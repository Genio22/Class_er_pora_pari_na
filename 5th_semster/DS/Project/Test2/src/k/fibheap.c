/*
 * fibheap.c — Fibonacci Heap (CLRS §19)
 *
 * Structure:
 *   The heap is a forest of min-heap-ordered trees.
 *   All roots are linked in a circular doubly-linked list.
 *   h->min points to the root with the smallest key.
 *
 * The "lazy" design defers work to extract_min (consolidation),
 * giving insert and decrease_key their O(1) amortised bounds.
 *
 * Potential function Φ = (# trees in root list) + 2*(# marked nodes)
 * drives the amortised analysis.
 */
#include "../lib/fibheap.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* A key smaller than any real timestamp, used by fh_delete */
#define FH_NEG_INF  LONG_MIN

/* Safe upper bound on maximum degree for n <= 2^62 nodes.
   Actual max degree <= 1.44 * log2(n), so 90 is very conservative. */
#define FH_MAX_DEGREE  90

/* ================================================================== */
/*  Internal helpers                                                   */
/* ================================================================== */

/*
 * Add node x to root list beside h->min.
 * Updates h->min if x has a smaller key.
 */
static void fh_root_add(FibHeap *h, FHNode *x) {
    if (!h->min) {
        /* First node in the heap */
        x->left  = x;
        x->right = x;
        h->min   = x;
    } else {
        /* Splice x into root list to the immediate left of h->min */
        x->right            = h->min;
        x->left             = h->min->left;
        h->min->left->right = x;
        h->min->left        = x;
        if (x->key < h->min->key) h->min = x;
    }
}

/*
 * fh_link: make y a child of x.
 *   Precondition: x.key <= y.key.
 *   y must already be disconnected from the root list.
 */
static void fh_link(FHNode *y, FHNode *x) {
    y->parent = x;
    if (!x->child) {
        x->child = y;
        y->left  = y;
        y->right = y;
    } else {
        /* Insert y into x's child list */
        y->right            = x->child;
        y->left             = x->child->left;
        x->child->left->right = y;
        x->child->left      = y;
    }
    x->degree++;
    y->marked = 0;
}

/* ================================================================== */
/*  Public API                                                         */
/* ================================================================== */

FibHeap *fh_create(void) {
    FibHeap *h = (FibHeap *)malloc(sizeof(FibHeap));
    h->min     = NULL;
    h->n       = 0;
    return h;
}

/* Recursively free a circular child list */
static void fh_free_circular(FHNode *node) {
    if (!node) return;
    FHNode *start = node;
    FHNode *curr  = node;
    do {
        FHNode *nxt = curr->right;
        if (curr->child) fh_free_circular(curr->child);
        free(curr);
        curr = nxt;
    } while (curr != start);
}

void fh_destroy(FibHeap *h) {
    if (!h) return;
    fh_free_circular(h->min);
    free(h);
}

int fh_empty(FibHeap *h) { return h->min == NULL; }

/* ------------------------------------------------------------------ */
/*  Insert  O(1)                                                       */
/* ------------------------------------------------------------------ */
FHNode *fh_insert(FibHeap *h, long key,
                  int order_id, double order_price, int order_type) {
    FHNode *x        = (FHNode *)malloc(sizeof(FHNode));
    x->key           = key;
    x->order_id      = order_id;
    x->order_price   = order_price;
    x->order_type    = order_type;
    x->degree        = 0;
    x->marked        = 0;
    x->parent        = NULL;
    x->child         = NULL;
    x->left          = x;
    x->right         = x;
    fh_root_add(h, x);
    h->n++;
    return x;
}

/* ------------------------------------------------------------------ */
/*  Extract-min  O(log n) amortised                                    */
/* ------------------------------------------------------------------ */

/*
 * consolidate: merge trees of equal degree until all roots have
 * distinct degrees.  This is the expensive step deferred from insert.
 */
static void fh_consolidate(FibHeap *h) {
    FHNode *A[FH_MAX_DEGREE + 1];
    for (int i = 0; i <= FH_MAX_DEGREE; i++) A[i] = NULL;

    /*
     * Snapshot the current root list before we start modifying it.
     * We'll use the snapshot array to iterate safely.
     */
    int     root_count = 0;
    FHNode *start      = h->min;
    FHNode *curr       = start;
    do { root_count++; curr = curr->right; } while (curr != start);

    FHNode **roots = (FHNode **)malloc(root_count * sizeof(FHNode *));
    curr = start;
    for (int i = 0; i < root_count; i++) {
        roots[i] = curr;
        curr     = curr->right;
    }

    /* Process each root from the snapshot */
    for (int i = 0; i < root_count; i++) {
        FHNode *x = roots[i];
        /* Disconnect x from the root list so link() doesn't corrupt it */
        x->left  = x;
        x->right = x;
        x->parent = NULL;

        int d = x->degree;
        while (d <= FH_MAX_DEGREE && A[d] != NULL) {
            FHNode *y = A[d];
            /* Ensure x is the one with the smaller key */
            if (x->key > y->key) { FHNode *tmp = x; x = y; y = tmp; }
            fh_link(y, x);   /* y becomes child of x */
            A[d] = NULL;
            d++;
        }
        if (d <= FH_MAX_DEGREE) A[d] = x;
    }
    free(roots);

    /* Rebuild root list from A[] */
    h->min = NULL;
    for (int i = 0; i <= FH_MAX_DEGREE; i++) {
        if (!A[i]) continue;
        FHNode *node  = A[i];
        node->parent  = NULL;
        node->left    = node;
        node->right   = node;
        fh_root_add(h, node);   /* also updates h->min */
    }
}

FHNode *fh_extract_min(FibHeap *h) {
    FHNode *z = h->min;
    if (!z) return NULL;

    /* Move all of z's children to the root list */
    if (z->child) {
        FHNode *child = z->child;
        FHNode *cstart = child;
        do {
            FHNode *cnext   = child->right;
            child->parent   = NULL;
            /* Splice child into root list left of z */
            child->right            = h->min;
            child->left             = h->min->left;
            h->min->left->right     = child;
            h->min->left            = child;
            child = cnext;
        } while (child != cstart);
        z->child = NULL;
    }

    /* Remove z from root list */
    if (z == z->right) {
        /* z was the only root */
        h->min = NULL;
    } else {
        z->left->right = z->right;
        z->right->left = z->left;
        h->min = z->right;          /* temporary min; consolidated below */
        fh_consolidate(h);
    }
    h->n--;
    return z;   /* caller is responsible for free() */
}

/* ------------------------------------------------------------------ */
/*  Decrease-key  O(1) amortised                                       */
/* ------------------------------------------------------------------ */

/*
 * fh_cut: remove x from its parent y's child list,
 *         add x to the root list, clear x's mark.
 */
static void fh_cut(FibHeap *h, FHNode *x, FHNode *y) {
    /* Remove x from y's child list */
    if (x->right == x) {
        y->child = NULL;
    } else {
        x->left->right = x->right;
        x->right->left = x->left;
        if (y->child == x) y->child = x->right;
    }
    y->degree--;

    /* Add x to root list */
    x->parent = NULL;
    x->marked  = 0;
    x->left    = x;
    x->right   = x;
    fh_root_add(h, x);
}

/*
 * fh_cascading_cut: if y is marked (has already lost one child),
 *   cut y from its parent too, and cascade upward.
 */
static void fh_cascading_cut(FibHeap *h, FHNode *y) {
    FHNode *z = y->parent;
    if (z) {
        if (!y->marked) {
            y->marked = 1;
        } else {
            fh_cut(h, y, z);
            fh_cascading_cut(h, z);
        }
    }
}

void fh_decrease_key(FibHeap *h, FHNode *x, long new_key) {
    if (new_key > x->key) return;   /* not a decrease — ignore */
    x->key      = new_key;
    FHNode *y   = x->parent;
    if (y && x->key < y->key) {
        fh_cut(h, x, y);
        fh_cascading_cut(h, y);
    }
    if (x->key < h->min->key) h->min = x;
}

/* ------------------------------------------------------------------ */
/*  Delete  O(log n) amortised                                         */
/* ------------------------------------------------------------------ */

void fh_delete(FibHeap *h, FHNode *x) {
    fh_decrease_key(h, x, FH_NEG_INF);
    FHNode *extracted = fh_extract_min(h);
    free(extracted);
}
