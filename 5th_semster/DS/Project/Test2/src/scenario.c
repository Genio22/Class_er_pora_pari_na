/* scenario.c */
#include "scenario.h"
#include <stdlib.h>
#include <stdio.h>

Order *generate_orders(int n, unsigned int seed) {
    srand(seed);
    Order *orders = (Order *)malloc((size_t)n * sizeof(Order));
    for (int i = 0; i < n; i++) {
        orders[i].id        = i + 1;
        orders[i].type      = (rand() % 2 == 0) ? BUY : SELL;
        orders[i].price     = (double)(rand() % 91 + 10); /* 10 – 100  */
        orders[i].quantity  = rand() % 500 + 1;            /* 1 – 500   */
        orders[i].timestamp = (long)(i + 1);
    }
    return orders;
}

void scenario_print_summary(const Order *orders, int n) {
    int buys = 0, sells = 0;
    double min_p = orders[0].price, max_p = orders[0].price;
    int    min_q = orders[0].quantity, max_q = orders[0].quantity;
    for (int i = 0; i < n; i++) {
        if (orders[i].type == BUY) buys++; else sells++;
        if (orders[i].price    < min_p) min_p = orders[i].price;
        if (orders[i].price    > max_p) max_p = orders[i].price;
        if (orders[i].quantity < min_q) min_q = orders[i].quantity;
        if (orders[i].quantity > max_q) max_q = orders[i].quantity;
    }
    printf("  Orders: %d  |  BUY: %d  SELL: %d\n", n, buys, sells);
    printf("  Price range:  [%.0f, %.0f]   "
           "Qty range: [%d, %d]\n", min_p, max_p, min_q, max_q);
}
