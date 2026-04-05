/*
 * scenario.h — Deterministic random order generator
 *
 * Both the baseline and optimised systems receive the EXACT same
 * sequence of orders so that performance comparisons are fair.
 *
 * Parameters:
 *   n    — number of orders
 *   seed — srand() seed for reproducibility
 *
 * Generated order properties:
 *   type      — random BUY or SELL (50 / 50)
 *   price     — integer in [10, 100]   (91 possible values)
 *   quantity  — integer in [1, 500]
 *   timestamp — sequential (1, 2, …, n)
 *
 * The narrow price range [10–100] is deliberate: it increases
 * price overlap between buys and sells, generating more trades
 * and exercising the matching logic more thoroughly.
 */
#ifndef SCENARIO_H
#define SCENARIO_H

#include "order.h"

/*
 * generate_orders():
 *   Allocate and return an array of n Orders.
 *   Caller must free() the returned pointer.
 */
Order *generate_orders(int n, unsigned int seed);

/* Print a summary of the order mix */
void   scenario_print_summary(const Order *orders, int n);

#endif /* SCENARIO_H */
