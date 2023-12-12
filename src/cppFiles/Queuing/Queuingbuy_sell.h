#ifndef QUEUINGBUY_SELL_H
#define QUEUINGBUY_SELL_H
#include <map>
#include <utility>
#include "../base_class/StockInformation.h"

using namespace std;

class Queues{
    public:
    StockInformation *st;
    Queues(StockInformation *st);
    void AddBuySideQueue(float);
    void AddSellSideQueue(float);
    void CheckBuyPriceMatch(float, float);
    void CheckSellPriceMatch(float, float);

    
};

#endif