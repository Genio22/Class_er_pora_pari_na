#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "order_book.h"

typedef struct {
    Order *orders;
    int count;
} OrderDataset;

OrderDataset generate_orders(int num_orders) {
    OrderDataset dataset;
    dataset.count = num_orders;
    dataset.orders = (Order *)malloc(sizeof(Order) * num_orders);
    
    srand(1337);
    
    for (int i = 0; i < num_orders; i++) {
        dataset.orders[i].id = i + 1;
        dataset.orders[i].type = (rand() % 2 == 0) ? BUY : SELL;
        dataset.orders[i].price = 80 + (rand() % 41);
        dataset.orders[i].quantity = 10 + (rand() % 91);
        dataset.orders[i].timestamp = i;
        dataset.orders[i].expiry_time = i + 5000;
    }
    
    return dataset;
}

void free_dataset(OrderDataset *dataset) {
    if (dataset->orders)
        free(dataset->orders);
    dataset->count = 0;
}

void run_demo() {
    printf("========================================================\n");
    printf("                   DEMO MODE (DEBUG ON)                 \n");
    printf("========================================================\n\n");
    
    Order demo_dataset[] = {
        {1, SELL, 100, 50, 1, 1000},
        {2, SELL, 110, 40, 2, 1000},
        {3, SELL, 90, 30, 3, 1000},
        {4, BUY, 105, 60, 4, 1000},
        {5, BUY, 85, 20, 5, 1000}
    };
    
    int demo_count = sizeof(demo_dataset) / sizeof(demo_dataset[0]);
    
    printf("--- GENERATED DATASET ---\n");
    for (int i = 0; i < demo_count; i++) {
        printf("Order ID: %d | Type: %s | Qty: %d | Price: %d\n",
               demo_dataset[i].id,
               demo_dataset[i].type == BUY ? "BUY" : "SELL",
               demo_dataset[i].quantity,
               demo_dataset[i].price);
    }
    
    printf("\n\n================ BASELINE EXECUTION ================\n");
    BaselineOrderBook *baseline = baseline_order_book_create();
    for (int i = 0; i < demo_count; i++) {
        baseline_process_order(baseline, demo_dataset[i], 1);
    }
    baseline_order_book_print(baseline);
    baseline_order_book_destroy(baseline);
    
    printf("\n\n================ OPTIMIZED EXECUTION ===============\n");
    OptimizedOrderBook *optimized = optimized_order_book_create();
    for (int i = 0; i < demo_count; i++) {
        optimized_process_order(optimized, demo_dataset[i], 1);
    }
    optimized_order_book_print(optimized);
    optimized_order_book_destroy(optimized);
    
    printf("\n\n================ COMPARISON SUMMARY ================\n");
    printf("* BASELINE required O(N) linear scans to find the global optimum price among unsorted arrays.\n");
    printf("* OPTIMIZED used an RBTree to make an O(log N) jump directly to the mathematical minimum/maximum price.\n\n\n");
}

void run_benchmark() {
    printf("========================================================\n");
    printf("      PERFORMANCE MODE (DEBUG OFF - BENCHMARKING)       \n");
    printf("========================================================\n\n");
    
    printf("%-10s %-20s %-20s %s\n", "Orders", "Baseline Time (s)", "Optimized Time (s)", "Improvement");
    printf("%s\n", "---------------------------------------------------------------------");
    
    int test_sizes[] = {500, 1000, 2000, 50000, 100000, 200000};
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);
    
    for (int t = 0; t < num_tests; t++) {
        int size = test_sizes[t];
        OrderDataset dataset = generate_orders(size);
        
        BaselineOrderBook *baseline = baseline_order_book_create();
        OptimizedOrderBook *optimized = optimized_order_book_create();
        
        clock_t start_base = clock();
        for (int i = 0; i < dataset.count; i++) {
            baseline_process_order(baseline, dataset.orders[i], 0);
        }
        clock_t end_base = clock();
        double time_base = (double)(end_base - start_base) / CLOCKS_PER_SEC;
        
        clock_t start_opt = clock();
        for (int i = 0; i < dataset.count; i++) {
            optimized_process_order(optimized, dataset.orders[i], 0);
        }
        clock_t end_opt = clock();
        double time_opt = (double)(end_opt - start_opt) / CLOCKS_PER_SEC;
        
        double improvement = time_opt > 0 ? time_base / time_opt : 0.0;
        
        printf("%-10d %-20.6f %-20.6f %.2fx\n", size, time_base, time_opt, improvement);
        
        baseline_order_book_destroy(baseline);
        optimized_order_book_destroy(optimized);
        free_dataset(&dataset);
    }
}

int main() {
    run_demo();
    run_benchmark();
    return 0;
}