/*
 * trade.h — Trade record
 *
 * A Trade is created when a BUY and SELL order price-cross.
 * The engine records the two order IDs, the execution price,
 * and the filled quantity.
 */
#ifndef TRADE_H
#define TRADE_H

#include <stdio.h>

typedef struct {
    int    buy_id;    /* id of the buy  order                  */
    int    sell_id;   /* id of the sell order                  */
    double price;     /* execution price (aggressor determines)*/
    int    quantity;  /* number of shares/units traded         */
} Trade;

void trade_print(const Trade *t);

#endif /* TRADE_H */
