#include "fibonacci_heap.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

static void link(FibNode *y, FibNode *x);
static void consolidate(FibonacciHeap *heap);
static void fib_node_destroy(FibNode *node);

FibonacciHeap* fib_heap_create(void) {
    FibonacciHeap *heap = (FibonacciHeap *)malloc(sizeof(FibonacciHeap));
    heap->min_node = NULL;
    heap->num_nodes = 0;
    return heap;
}

static FibNode* fib_node_create(int key, Order *order) {
    FibNode *node = (FibNode *)malloc(sizeof(FibNode));
    node->key = key;
    node->order = order;
    node->degree = 0;
    node->parent = NULL;
    node->child = NULL;
    node->mark = 0;
    node->left = node;
    node->right = node;
    return node;
}

void fib_heap_insert(FibonacciHeap *heap, int key, Order *order) {
    FibNode *node = fib_node_create(key, order);
    
    if (heap->min_node == NULL) {
        heap->min_node = node;
    } else {
        node->left = heap->min_node;
        node->right = heap->min_node->right;
        heap->min_node->right->left = node;
        heap->min_node->right = node;
        
        if (node->key < heap->min_node->key)
            heap->min_node = node;
    }
    
    heap->num_nodes++;
}

static void link(FibNode *y, FibNode *x) {
    y->left->right = y->right;
    y->right->left = y->left;
    y->parent = x;
    
    if (x->child == NULL) {
        x->child = y;
        y->right = y;
        y->left = y;
    } else {
        y->left = x->child;
        y->right = x->child->right;
        x->child->right->left = y;
        x->child->right = y;
    }
    
    x->degree++;
    y->mark = 0;
}

static void consolidate(FibonacciHeap *heap) {
    if (!heap->min_node)
        return;
    
    int max_degree = (int)log2(heap->num_nodes) + 2;
    FibNode **A = (FibNode **)calloc(max_degree, sizeof(FibNode *));
    
    /* Count root nodes first to allocate correct size */
    int root_count = 0;
    FibNode *x = heap->min_node;
    if (x) {
        do {
            root_count++;
            x = x->right;
        } while (x != heap->min_node);
    }
    
    FibNode **root_nodes = (FibNode **)malloc(sizeof(FibNode *) * root_count);
    int idx = 0;
    x = heap->min_node;
    
    if (x) {
        do {
            root_nodes[idx++] = x;
            x = x->right;
        } while (x != heap->min_node);
    }
    
    for (int i = 0; i < root_count; i++) {
        FibNode *curr = root_nodes[i];
        int d = curr->degree;
        
        while (d < max_degree && A[d] != NULL) {
            FibNode *y = A[d];
            
            if (curr->key > y->key) {
                FibNode *tmp = curr;
                curr = y;
                y = tmp;
            }
            
            link(y, curr);
            A[d] = NULL;
            d++;
        }
        
        if (d < max_degree)
            A[d] = curr;
    }
    
    heap->min_node = NULL;
    
    for (int i = 0; i < max_degree; i++) {
        if (A[i] != NULL) {
            if (heap->min_node == NULL) {
                heap->min_node = A[i];
                heap->min_node->left = heap->min_node;
                heap->min_node->right = heap->min_node;
            } else {
                A[i]->left = heap->min_node;
                A[i]->right = heap->min_node->right;
                heap->min_node->right->left = A[i];
                heap->min_node->right = A[i];
                
                if (A[i]->key < heap->min_node->key)
                    heap->min_node = A[i];
            }
        }
    }
    
    free(root_nodes);
    free(A);
}

FibNode* fib_heap_extract_min(FibonacciHeap *heap) {
    FibNode *z = heap->min_node;
    
    if (z != NULL) {
        if (z->child != NULL) {
            FibNode *child = z->child;
            do {
                FibNode *next = child->right;
                child->left = heap->min_node;
                child->right = heap->min_node->right;
                heap->min_node->right->left = child;
                heap->min_node->right = child;
                child->parent = NULL;
                child = next;
            } while (child != z->child);
        }
        
        z->left->right = z->right;
        z->right->left = z->left;
        
        if (z == z->right)
            heap->min_node = NULL;
        else {
            heap->min_node = z->right;
            consolidate(heap);
        }
        
        heap->num_nodes--;
    }
    
    return z;
}

int fib_heap_is_empty(FibonacciHeap *heap) {
    return heap->min_node == NULL;
}

static void fib_node_destroy(FibNode *node) {
    if (node == NULL)
        return;
    
    if (node->child) {
        FibNode *curr = node->child;
        FibNode *next;
        do {
            next = curr->right;
            fib_node_destroy(curr);
            curr = next;
        } while (curr != node->child);
    }
    
    free(node);
}

void fib_heap_destroy(FibonacciHeap *heap) {
    if (heap == NULL)
        return;
    
    if (heap->min_node) {
        FibNode *curr = heap->min_node;
        FibNode *next;
        do {
            next = curr->right;
            fib_node_destroy(curr);
            curr = next;
        } while (curr != heap->min_node);
    }
    
    free(heap);
}