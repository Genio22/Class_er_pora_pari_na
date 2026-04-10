/* trade.c */
#include "../lib/trade.h"
#include <stdio.h>

void trade_print(const Trade *t) {
    printf("    >> TRADE  BUY[%d] x SELL[%d]  @ %.2f  qty=%d\n",
           t->buy_id, t->sell_id, t->price, t->quantity);
}
