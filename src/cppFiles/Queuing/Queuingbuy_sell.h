#ifndef QUEUINGBUY_SELL_H
#define QUEUINGBUY_SELL_H
#include <map>
#include <utility>
#include "../buysellExecution/stockProcessor.h"


using namespace std;

class Queues : public StockProcessor{
    private:
    map<string, pair<float, float>> BuySideQueue;
    map<string, pair<float, float>> SellSideQueue;

    public:
    void AddBuySideQueue(float);
    void AddSellSideQueue(float);
    void CheckBuyPriceMatch(float);
    void CheckSellPriceMatch(float);

    
};

#endif