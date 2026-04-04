#ifndef FIBONACCI_HEAP_H
#define FIBONACCI_HEAP_H

#include "order.h"

typedef struct FibNode {
    int key;
    Order *order;
    int degree;
    struct FibNode *parent;
    struct FibNode *child;
    struct FibNode *left;
    struct FibNode *right;
    int mark;
} FibNode;

typedef struct {
    FibNode *min_node;
    int num_nodes;
} FibonacciHeap;

FibonacciHeap* fib_heap_create(void);
void fib_heap_insert(FibonacciHeap *heap, int key, Order *order);
FibNode* fib_heap_extract_min(FibonacciHeap *heap);
int fib_heap_is_empty(FibonacciHeap *heap);
void fib_heap_destroy(FibonacciHeap *heap);

#endif // FIBONACCI_HEAP_H