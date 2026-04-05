/*
 * order.h — Core Order definition
 *
 * An Order is the fundamental unit of the matching engine.
 * Every buy or sell request in the system is represented as an Order.
 */
#ifndef ORDER_H
#define ORDER_H

#include <stdio.h>

/* Order direction */
typedef enum {
    BUY  = 0,
    SELL = 1
} OrderType;

/* Order struct — immutable identity fields + mutable quantity */
typedef struct {
    int       id;         /* unique identifier                   */
    OrderType type;       /* BUY or SELL                         */
    double    price;      /* limit price                         */
    int       quantity;   /* remaining (unfilled) quantity       */
    long      timestamp;  /* creation time, used for tie-breaking*/
} Order;

Order       order_create(int id, OrderType type,
                         double price, int quantity, long timestamp);
void        order_print(const Order *o);
const char *order_type_str(OrderType t);

#endif /* ORDER_H */
