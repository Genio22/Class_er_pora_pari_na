#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ORDERS 1000000
#define MAX_PRICE_LEVELS 100000
#define DEBUG 1

typedef enum {
    BUY,
    SELL
} OrderType;

typedef struct {
    int id;
    OrderType type;
    int quantity;
    double price;
    long timestamp;
} Order;

typedef struct OrderNode {
    Order order;
    struct OrderNode *next;
    struct OrderNode *prev;
} OrderNode;

typedef struct RBNode {
    double price;
    OrderNode *head;
    OrderNode *tail;
    int order_count;
    struct RBNode *parent;
    struct RBNode *left;
    struct RBNode *right;
    int color; // 0 = BLACK, 1 = RED
} RBNode;

typedef struct {
    int id;
    int quantity;
    double price;
} BookEntry;

// Baseline Functions
void baseline_init();
void baseline_cleanup();
void baseline_add_order(Order *order);
void baseline_print_book();
void baseline_process_order(Order *order, int debug);
BookEntry* baseline_get_entries(int *buy_count, int *sell_count);

// Optimized Functions
void optimized_init();
void optimized_cleanup();
void optimized_add_order(Order *order);
void optimized_print_book();
void optimized_process_order(Order *order, int debug);
BookEntry* optimized_get_entries(int *buy_count, int *sell_count);

// Utility
Order* generate_orders(int count);
void validate_books(BookEntry *baseline_entries, int baseline_count,
                   BookEntry *optimized_entries, int optimized_count);

#endif