#ifndef ORDER_H
#define ORDER_H

typedef enum {
    BUY,
    SELL
} OrderType;

typedef struct {
    int id;
    OrderType type;
    int price;
    int quantity;
    int timestamp;
    int expiry_time;
} Order;

#endif // ORDER_H