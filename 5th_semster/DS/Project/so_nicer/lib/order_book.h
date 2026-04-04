#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include "red_black_tree.h"
#include "fibonacci_heap.h"
#include "order.h"
#include <stdio.h>

typedef struct {
    RBTree *buy_tree;
    RBTree *sell_tree;
    FibonacciHeap *expiry_heap;
} OptimizedOrderBook;

typedef struct {
    Order *buy_orders;
    int buy_count;
    int buy_capacity;
    Order *sell_orders;
    int sell_count;
    int sell_capacity;
} BaselineOrderBook;

OptimizedOrderBook* optimized_order_book_create(void);
void optimized_process_order(OptimizedOrderBook *book, Order new_order, int debug);
void optimized_process_events(OptimizedOrderBook *book, int current_time, int debug);
void optimized_order_book_print(OptimizedOrderBook *book);
void optimized_order_book_destroy(OptimizedOrderBook *book);

BaselineOrderBook* baseline_order_book_create(void);
void baseline_process_order(BaselineOrderBook *book, Order new_order, int debug);
void baseline_order_book_print(BaselineOrderBook *book);
void baseline_order_book_destroy(BaselineOrderBook *book);

#endif // ORDER_BOOK_H