#include "order_book.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// ==================== OPTIMIZED IMPLEMENTATION ====================

OptimizedOrderBook* optimized_order_book_create(void) {
    OptimizedOrderBook *book = (OptimizedOrderBook *)malloc(sizeof(OptimizedOrderBook));
    book->buy_tree = rb_tree_create();
    book->sell_tree = rb_tree_create();
    book->expiry_heap = fib_heap_create();
    return book;
}

void optimized_process_events(OptimizedOrderBook *book, int current_time, int debug) {
    while (!fib_heap_is_empty(book->expiry_heap)) {
        FibNode *min_event = fib_heap_extract_min(book->expiry_heap);
        
        if (!min_event)
            break;
        
        if (min_event->key <= current_time) {
            if (min_event->order && min_event->order->quantity > 0) {
                if (debug)
                    printf("  [EVENT] Order #%d expired via Heap extraction.\n", min_event->order->id);
                min_event->order->quantity = 0;
            }
            free(min_event);
        } else {
            fib_heap_insert(book->expiry_heap, min_event->key, min_event->order);
            free(min_event);
            break;
        }
    }
}

void optimized_process_order(OptimizedOrderBook *book, Order new_order, int debug) {
    if (debug) {
        printf("\n[OPTIMIZED] Processing %s Order #%d (Qty: %d, Price: %d)\n",
               new_order.type == BUY ? "BUY" : "SELL",
               new_order.id, new_order.quantity, new_order.price);
    }
    
    Order *order_copy = (Order *)malloc(sizeof(Order));
    memcpy(order_copy, &new_order, sizeof(Order));
    
    fib_heap_insert(book->expiry_heap, new_order.expiry_time, order_copy);
    optimized_process_events(book, new_order.timestamp, debug);
    
    if (new_order.type == BUY) {
        if (debug)
            printf("  O(log N) jump directly to minimum SELL price node...\n");
        
        RBNode *node = rb_tree_minimum(book->sell_tree, rb_tree_get_root(book->sell_tree));
        
        while (new_order.quantity > 0 && node != NULL && 
               node != rb_tree_get_tnull(book->sell_tree) && node->price <= new_order.price) {
            
            if (debug)
                printf("    -> Checking tree node @ Price %d\n", node->price);
            
            for (int i = 0; i < node->orders_count && new_order.quantity > 0; i++) {
                if (node->orders[i].quantity == 0)
                    continue;
                
                int match_qty = node->orders[i].quantity < new_order.quantity ? 
                               node->orders[i].quantity : new_order.quantity;
                
                new_order.quantity -= match_qty;
                node->orders[i].quantity -= match_qty;
                
                if (debug)
                    printf("      Matched %d units with Order #%d\n", match_qty, node->orders[i].id);
            }
            
            node = rb_tree_successor(book->sell_tree, node);
        }
        
        if (new_order.quantity > 0) {
            Order *buy_order = (Order *)malloc(sizeof(Order));
            memcpy(buy_order, &new_order, sizeof(Order));
            rb_tree_insert_and_get_node(book->buy_tree, new_order.price, buy_order);
            
            if (debug)
                printf("  Remaining qty (%d) inserted into BUY RBTree.\n", new_order.quantity);
        }
    } else {
        if (debug)
            printf("  O(log N) jump directly to maximum BUY price node...\n");
        
        RBNode *node = rb_tree_maximum(book->buy_tree, rb_tree_get_root(book->buy_tree));
        
        while (new_order.quantity > 0 && node != NULL && 
               node != rb_tree_get_tnull(book->buy_tree) && node->price >= new_order.price) {
            
            if (debug)
                printf("    -> Checking tree node @ Price %d\n", node->price);
            
            for (int i = 0; i < node->orders_count && new_order.quantity > 0; i++) {
                if (node->orders[i].quantity == 0)
                    continue;
                
                int match_qty = node->orders[i].quantity < new_order.quantity ? 
                               node->orders[i].quantity : new_order.quantity;
                
                new_order.quantity -= match_qty;
                node->orders[i].quantity -= match_qty;
                
                if (debug)
                    printf("      Matched %d units with Order #%d\n", match_qty, node->orders[i].id);
            }
            
            node = rb_tree_predecessor(book->buy_tree, node);
        }
        
        if (new_order.quantity > 0) {
            Order *sell_order = (Order *)malloc(sizeof(Order));
            memcpy(sell_order, &new_order, sizeof(Order));
            rb_tree_insert_and_get_node(book->sell_tree, new_order.price, sell_order);
            
            if (debug)
                printf("  Remaining qty (%d) inserted into SELL RBTree.\n", new_order.quantity);
        }
    }
}

void optimized_order_book_print(OptimizedOrderBook *book) {
    printf("\n=== OPTIMIZED FINAL ORDER BOOK ===\n");
    printf("BUY Book (Descending Print):\n");
    
    RBNode *node = rb_tree_maximum(book->buy_tree, rb_tree_get_root(book->buy_tree));
    while (node != NULL && node != rb_tree_get_tnull(book->buy_tree)) {
        for (int i = 0; i < node->orders_count; i++) {
            if (node->orders[i].quantity > 0)
                printf("  ID:%d Qty:%d @ Prc:%d\n", 
                       node->orders[i].id, node->orders[i].quantity, node->price);
        }
        node = rb_tree_predecessor(book->buy_tree, node);
    }
    
    printf("SELL Book (Ascending Print):\n");
    node = rb_tree_minimum(book->sell_tree, rb_tree_get_root(book->sell_tree));
    while (node != NULL && node != rb_tree_get_tnull(book->sell_tree)) {
        for (int i = 0; i < node->orders_count; i++) {
            if (node->orders[i].quantity > 0)
                printf("  ID:%d Qty:%d @ Prc:%d\n", 
                       node->orders[i].id, node->orders[i].quantity, node->price);
        }
        node = rb_tree_successor(book->sell_tree, node);
    }
}

void optimized_order_book_destroy(OptimizedOrderBook *book) {
    if (book == NULL)
        return;
    
    rb_tree_destroy(book->buy_tree);
    rb_tree_destroy(book->sell_tree);
    fib_heap_destroy(book->expiry_heap);
    free(book);
}

// ==================== BASELINE IMPLEMENTATION ====================

BaselineOrderBook* baseline_order_book_create(void) {
    BaselineOrderBook *book = (BaselineOrderBook *)malloc(sizeof(BaselineOrderBook));
    
    book->buy_capacity = 100;
    book->buy_count = 0;
    book->buy_orders = (Order *)malloc(sizeof(Order) * book->buy_capacity);
    
    book->sell_capacity = 100;
    book->sell_count = 0;
    book->sell_orders = (Order *)malloc(sizeof(Order) * book->sell_capacity);
    
    return book;
}

static int min_int(int a, int b) {
    return a < b ? a : b;
}

void baseline_process_order(BaselineOrderBook *book, Order new_order, int debug) {
    if (debug) {
        printf("\n[BASELINE] Processing %s Order #%d (Qty: %d, Price: %d)\n",
               new_order.type == BUY ? "BUY" : "SELL",
               new_order.id, new_order.quantity, new_order.price);
    }
    
    if (new_order.type == BUY) {
        if (debug)
            printf("  Scanning unordered SELL list linearly...\n");
        
        while (new_order.quantity > 0) {
            int best_idx = -1;
            
            for (int i = 0; i < book->sell_count; i++) {
                if (debug)
                    printf("    -> Checking SELL Order #%d @ Price %d", 
                           book->sell_orders[i].id, book->sell_orders[i].price);
                
                if (book->sell_orders[i].price <= new_order.price) {
                    if (debug)
                        printf(" [Valid candidate]\n");
                    
                    if (best_idx == -1 || book->sell_orders[i].price < book->sell_orders[best_idx].price ||
                        (book->sell_orders[i].price == book->sell_orders[best_idx].price && 
                         book->sell_orders[i].timestamp < book->sell_orders[best_idx].timestamp)) {
                        best_idx = i;
                    }
                } else {
                    if (debug)
                        printf(" [No match - Price too high]\n");
                }
            }
            
            if (best_idx != -1) {
                if (debug)
                    printf("  Best match chosen: Order #%d @ Price %d\n",
                           book->sell_orders[best_idx].id, book->sell_orders[best_idx].price);
                
                int match_qty = min_int(new_order.quantity, book->sell_orders[best_idx].quantity);
                new_order.quantity -= match_qty;
                book->sell_orders[best_idx].quantity -= match_qty;
                
                if (debug)
                    printf("    Matched %d units.\n", match_qty);
                
                if (book->sell_orders[best_idx].quantity == 0) {
                    for (int i = best_idx; i < book->sell_count - 1; i++) {
                        book->sell_orders[i] = book->sell_orders[i + 1];
                    }
                    book->sell_count--;
                    
                    if (debug)
                        printf("    Order #%d fully filled and removed.\n", book->sell_orders[best_idx].id);
                }
            } else {
                if (debug)
                    printf("  No further matches found.\n");
                break;
            }
        }
        
        if (new_order.quantity > 0) {
            if (book->buy_count >= book->buy_capacity) {
                book->buy_capacity *= 2;
                book->buy_orders = (Order *)realloc(book->buy_orders, 
                                                   sizeof(Order) * book->buy_capacity);
            }
            book->buy_orders[book->buy_count++] = new_order;
            
            if (debug)
                printf("  Remaining qty (%d) added to BUY book.\n", new_order.quantity);
        }
    } else {
        if (debug)
            printf("  Scanning unordered BUY list linearly...\n");
        
        while (new_order.quantity > 0) {
            int best_idx = -1;
            
            for (int i = 0; i < book->buy_count; i++) {
                if (debug)
                    printf("    -> Checking BUY Order #%d @ Price %d",
                           book->buy_orders[i].id, book->buy_orders[i].price);
                
                if (book->buy_orders[i].price >= new_order.price) {
                    if (debug)
                        printf(" [Valid candidate]\n");
                    
                    if (best_idx == -1 || book->buy_orders[i].price > book->buy_orders[best_idx].price ||
                        (book->buy_orders[i].price == book->buy_orders[best_idx].price && 
                         book->buy_orders[i].timestamp < book->buy_orders[best_idx].timestamp)) {
                        best_idx = i;
                    }
                } else {
                    if (debug)
                        printf(" [No match - Price too low]\n");
                }
            }
            
            if (best_idx != -1) {
                if (debug)
                    printf("  Best match chosen: Order #%d @ Price %d\n",
                           book->buy_orders[best_idx].id, book->buy_orders[best_idx].price);
                
                int match_qty = min_int(new_order.quantity, book->buy_orders[best_idx].quantity);
                new_order.quantity -= match_qty;
                book->buy_orders[best_idx].quantity -= match_qty;
                
                if (debug)
                    printf("    Matched %d units.\n", match_qty);
                
                if (book->buy_orders[best_idx].quantity == 0) {
                    for (int i = best_idx; i < book->buy_count - 1; i++) {
                        book->buy_orders[i] = book->buy_orders[i + 1];
                    }
                    book->buy_count--;
                    
                    if (debug)
                        printf("    Order #%d fully filled and removed.\n", book->buy_orders[best_idx].id);
                }
            } else {
                if (debug)
                    printf("  No further matches found.\n");
                break;
            }
        }
        
        if (new_order.quantity > 0) {
            if (book->sell_count >= book->sell_capacity) {
                book->sell_capacity *= 2;
                book->sell_orders = (Order *)realloc(book->sell_orders, 
                                                    sizeof(Order) * book->sell_capacity);
            }
            book->sell_orders[book->sell_count++] = new_order;
            
            if (debug)
                printf("  Remaining qty (%d) added to SELL book.\n", new_order.quantity);
        }
    }
}

void baseline_order_book_print(BaselineOrderBook *book) {
    printf("\n=== BASELINE FINAL ORDER BOOK ===\n");
    printf("BUY Book:\n");
    for (int i = 0; i < book->buy_count; i++)
        printf("  ID:%d Qty:%d @ Prc:%d\n", 
               book->buy_orders[i].id, book->buy_orders[i].quantity, book->buy_orders[i].price);
    
    printf("SELL Book:\n");
    for (int i = 0; i < book->sell_count; i++)
        printf("  ID:%d Qty:%d @ Prc:%d\n", 
               book->sell_orders[i].id, book->sell_orders[i].quantity, book->sell_orders[i].price);
}

void baseline_order_book_destroy(BaselineOrderBook *book) {
    if (book == NULL)
        return;
    
    free(book->buy_orders);
    free(book->sell_orders);
    free(book);
}