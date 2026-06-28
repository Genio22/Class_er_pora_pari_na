#include "order_book.h"

typedef struct {
    BookEntry *entries;
    int count;
    int capacity;
} SimpleBook;

static SimpleBook buy_book;
static SimpleBook sell_book;

void baseline_init() {
    buy_book.capacity = 10000;
    buy_book.count = 0;
    buy_book.entries = (BookEntry *)malloc(sizeof(BookEntry) * buy_book.capacity);
    
    sell_book.capacity = 10000;
    sell_book.count = 0;
    sell_book.entries = (BookEntry *)malloc(sizeof(BookEntry) * sell_book.capacity);
}

void baseline_cleanup() {
    free(buy_book.entries);
    free(sell_book.entries);
}

void baseline_add_to_buy_book(Order *order, int remaining_qty) {
    if (buy_book.count >= buy_book.capacity) {
        buy_book.capacity *= 2;
        buy_book.entries = (BookEntry *)realloc(buy_book.entries, 
                                                sizeof(BookEntry) * buy_book.capacity);
    }
    buy_book.entries[buy_book.count].id = order->id;
    buy_book.entries[buy_book.count].quantity = remaining_qty;
    buy_book.entries[buy_book.count].price = order->price;
    buy_book.count++;
}

void baseline_add_to_sell_book(Order *order, int remaining_qty) {
    if (sell_book.count >= sell_book.capacity) {
        sell_book.capacity *= 2;
        sell_book.entries = (BookEntry *)realloc(sell_book.entries, 
                                                 sizeof(BookEntry) * sell_book.capacity);
    }
    sell_book.entries[sell_book.count].id = order->id;
    sell_book.entries[sell_book.count].quantity = remaining_qty;
    sell_book.entries[sell_book.count].price = order->price;
    sell_book.count++;
}

void baseline_remove_order(SimpleBook *book, int index) {
    for (int i = index; i < book->count - 1; i++) {
        book->entries[i] = book->entries[i + 1];
    }
    book->count--;
}

void baseline_process_order(Order *order, int debug) {
    int remaining_qty = order->quantity;
    
    if (debug) {
        printf("\n   [BASELINE] Processing %s Order #%d (Qty: %d, Price: %.0f)\n",
               order->type == BUY ? "BUY" : "SELL",
               order->id, order->quantity, order->price);
    }
    
    if (order->type == BUY) {
        // BUY order: match with SELL orders
        if (debug) {
            printf("\n     Scanning unordered SELL list linearly...\n");
        }
        
        int best_idx = -1;
        double best_price = INFINITY;
        
        while (remaining_qty > 0) {
            best_idx = -1;
            best_price = INFINITY;
            
            // Find the best (lowest) SELL price
            for (int i = 0; i < sell_book.count; i++) {
                if (debug) {
                    printf("\n       -> Checking SELL Order #%d @ Price %.0f ",
                           sell_book.entries[i].id, sell_book.entries[i].price);
                }
                
                if (sell_book.entries[i].price <= order->price) {
                    if (debug) {
                        printf("[Valid candidate]");
                    }
                    if (sell_book.entries[i].price < best_price) {
                        best_price = sell_book.entries[i].price;
                        best_idx = i;
                    }
                } else {
                    if (debug) {
                        printf("[No match - Price too high]");
                    }
                }
            }
            
            if (best_idx == -1) {
                if (debug) {
                    printf("\n\n     No further matches found.\n");
                }
                break;
            }
            
            int matched_qty = (remaining_qty < sell_book.entries[best_idx].quantity) 
                            ? remaining_qty 
                            : sell_book.entries[best_idx].quantity;
            
            if (debug) {
                printf("\n\n     Best match chosen: Order #%d @ Price %.0f\n",
                       sell_book.entries[best_idx].id, best_price);
                printf("\n       Matched %d units.\n", matched_qty);
            }
            
            remaining_qty -= matched_qty;
            sell_book.entries[best_idx].quantity -= matched_qty;
            
            if (sell_book.entries[best_idx].quantity == 0) {
                if (debug) {
                    printf("\n       Order #%d fully filled and removed.\n",
                           sell_book.entries[best_idx].id);
                }
                baseline_remove_order(&sell_book, best_idx);
            }
        }
    } else {
        // SELL order: match with BUY orders
        if (debug) {
            printf("\n     Scanning unordered BUY list linearly...\n");
        }
        
        int best_idx = -1;
        double best_price = -INFINITY;
        
        while (remaining_qty > 0) {
            best_idx = -1;
            best_price = -INFINITY;
            
            // Find the best (highest) BUY price
            for (int i = 0; i < buy_book.count; i++) {
                if (debug) {
                    printf("\n       -> Checking BUY Order #%d @ Price %.0f ",
                           buy_book.entries[i].id, buy_book.entries[i].price);
                }
                
                if (buy_book.entries[i].price >= order->price) {
                    if (debug) {
                        printf("[Valid candidate]");
                    }
                    if (buy_book.entries[i].price > best_price) {
                        best_price = buy_book.entries[i].price;
                        best_idx = i;
                    }
                } else {
                    if (debug) {
                        printf("[No match - Price too low]");
                    }
                }
            }
            
            if (best_idx == -1) {
                if (debug) {
                    printf("\n\n     No further matches found.\n");
                }
                break;
            }
            
            int matched_qty = (remaining_qty < buy_book.entries[best_idx].quantity) 
                            ? remaining_qty 
                            : buy_book.entries[best_idx].quantity;
            
            if (debug) {
                printf("\n\n     Best match chosen: Order #%d @ Price %.0f\n",
                       buy_book.entries[best_idx].id, best_price);
                printf("\n       Matched %d units.\n", matched_qty);
            }
            
            remaining_qty -= matched_qty;
            buy_book.entries[best_idx].quantity -= matched_qty;
            
            if (buy_book.entries[best_idx].quantity == 0) {
                if (debug) {
                    printf("\n       Order #%d fully filled and removed.\n",
                           buy_book.entries[best_idx].id);
                }
                baseline_remove_order(&buy_book, best_idx);
            }
        }
    }
    
    // Add remaining quantity to book
    if (remaining_qty > 0) {
        if (order->type == BUY) {
            baseline_add_to_buy_book(order, remaining_qty);
        } else {
            baseline_add_to_sell_book(order, remaining_qty);
        }
    }
}

void baseline_print_book() {
    printf("\n   === BASELINE FINAL ORDER BOOK ===\n\n");
    
    printf("   BUY Book:\n");
    if (buy_book.count == 0) {
        printf("\n     (empty)\n");
    } else {
        for (int i = 0; i < buy_book.count; i++) {
            printf("\n     ID:%d Qty:%d @ Prc:%.0f\n",
                   buy_book.entries[i].id,
                   buy_book.entries[i].quantity,
                   buy_book.entries[i].price);
        }
    }
    
    printf("\n   SELL Book:\n");
    if (sell_book.count == 0) {
        printf("\n     (empty)\n");
    } else {
        for (int i = 0; i < sell_book.count; i++) {
            printf("\n     ID:%d Qty:%d @ Prc:%.0f\n",
                   sell_book.entries[i].id,
                   sell_book.entries[i].quantity,
                   sell_book.entries[i].price);
        }
    }
    printf("\n");
}

BookEntry* baseline_get_entries(int *buy_count, int *sell_count) {
    BookEntry *result = (BookEntry *)malloc(sizeof(BookEntry) * (buy_book.count + sell_book.count));
    *buy_count = buy_book.count;
    *sell_count = sell_book.count;
    
    memcpy(result, buy_book.entries, sizeof(BookEntry) * buy_book.count);
    memcpy(result + buy_book.count, sell_book.entries, sizeof(BookEntry) * sell_book.count);
    
    return result;
}