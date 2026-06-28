#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "order_book.h"

Order* generate_orders(int count) {
    Order *orders = (Order *)malloc(sizeof(Order) * count);
    srand(time(NULL));
    
    for (int i = 0; i < count; i++) {
        orders[i].id = i + 1;
        orders[i].type = (rand() % 2 == 0) ? BUY : SELL;
        orders[i].quantity = 10 + (rand() % 90);
        orders[i].price = 50 + (rand() % 100);
        orders[i].timestamp = time(NULL) + i;
    }
    
    return orders;
}

void validate_books(BookEntry *baseline_entries, int baseline_count,
                   BookEntry *optimized_entries, int optimized_count) {
    printf("\n   ================ COMPARISON SUMMARY ================\n\n");
    printf("   * BASELINE required O(N) linear scans to find the global optimum price among unsorted arrays.\n\n");
    printf("   * OPTIMIZED used an RBTree to make an O(log N) jump directly to the mathematical minimum/maximum price.\n\n");
}

void demo_mode() {
    printf("\n========================================================\n\n");
    printf("                  DEMO MODE (DEBUG ON)                 \n\n");
    printf("========================================================\n");
    
    // Generate small dataset
    Order demo_orders[] = {
        {1, SELL, 50, 100, 0},
        {2, SELL, 40, 110, 1},
        {3, SELL, 30, 90, 2},
        {4, BUY, 60, 105, 3},
        {5, BUY, 20, 85, 4}
    };
    int demo_count = 5;
    
    printf("\n   --- GENERATED DATASET ---\n");
    for (int i = 0; i < demo_count; i++) {
        printf("\n   Order ID: %d | Type: %s | Qty: %d | Price: %.0f\n",
               demo_orders[i].id,
               demo_orders[i].type == BUY ? "BUY" : "SELL",
               demo_orders[i].quantity,
               demo_orders[i].price);
    }
    
    // BASELINE EXECUTION
    printf("\n\n   ================ BASELINE EXECUTION ================\n");
    baseline_init();
    for (int i = 0; i < demo_count; i++) {
        baseline_process_order(&demo_orders[i], 1);
    }
    baseline_print_book();
    
    int baseline_buy_count, baseline_sell_count;
    BookEntry *baseline_entries = baseline_get_entries(&baseline_buy_count, &baseline_sell_count);
    baseline_cleanup();
    
    // OPTIMIZED EXECUTION
    printf("\n   ================ OPTIMIZED EXECUTION ===============\n");
    optimized_init();
    for (int i = 0; i < demo_count; i++) {
        optimized_process_order(&demo_orders[i], 1);
    }
    optimized_print_book();
    
    int optimized_buy_count, optimized_sell_count;
    BookEntry *optimized_entries = optimized_get_entries(&optimized_buy_count, &optimized_sell_count);
    optimized_cleanup();
    
    validate_books(baseline_entries, baseline_buy_count + baseline_sell_count,
                   optimized_entries, optimized_buy_count + optimized_sell_count);
    
    printf("   ========================================================\n\n");
    
    free(baseline_entries);
    free(optimized_entries);
}

void benchmark_mode() {
    printf("\n========================================================\n\n");
    printf("         PERFORMANCE MODE (DEBUG OFF - BENCHMARKING)       \n\n");
    printf("========================================================\n\n");
    
    int sizes[] = {500, 1000, 2000, 50000, 100000, 200000, 500000};
    int num_sizes = 7;
    
    printf("   Orders     Baseline Time (s)    Optimized Time (s)   Improvement\n");
    printf("\n   ");
    for (int i = 0; i < 65; i++) printf("-");
    printf("\n");
    
    for (int s = 0; s < num_sizes; s++) {
        int order_count = sizes[s];
        Order *orders = generate_orders(order_count);
        
        // Baseline benchmark
        baseline_init();
        clock_t baseline_start = clock();
        for (int i = 0; i < order_count; i++) {
            baseline_process_order(&orders[i], 0);
        }
        clock_t baseline_end = clock();
        double baseline_time = (double)(baseline_end - baseline_start) / CLOCKS_PER_SEC;
        baseline_cleanup();
        
        // Optimized benchmark
        optimized_init();
        clock_t optimized_start = clock();
        for (int i = 0; i < order_count; i++) {
            optimized_process_order(&orders[i], 0);
        }
        clock_t optimized_end = clock();
        double optimized_time = (double)(optimized_end - optimized_start) / CLOCKS_PER_SEC;
        optimized_cleanup();
        
        double improvement = (baseline_time > 0) ? (baseline_time / optimized_time) : 0;
        
        printf("\n   %-10d %-20.6f %-20.6f %.2fx",
               order_count, baseline_time, optimized_time, improvement);
        
        free(orders);
    }
    
    printf("\n\n   ========================================================\n\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "bench") == 0) {
        benchmark_mode();
    } else {
        demo_mode();
    }
    
    return 0;
}