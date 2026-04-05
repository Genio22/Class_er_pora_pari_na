/* order.c */
#include "../lib/order.h"
#include <stdio.h>

const char *order_type_str(OrderType t) {
    return (t == BUY) ? "BUY" : "SELL";
}

Order order_create(int id, OrderType type,
                   double price, int quantity, long timestamp) {
    Order o;
    o.id        = id;
    o.type      = type;
    o.price     = price;
    o.quantity  = quantity;
    o.timestamp = timestamp;
    return o;
}

void order_print(const Order *o) {
    printf("  Order[id=%-4d  %-4s  price=%6.2f  qty=%-4d  ts=%ld]\n",
           o->id, order_type_str(o->type),
           o->price, o->quantity, o->timestamp);
}
