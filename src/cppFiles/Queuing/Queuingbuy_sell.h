/*
###########################################################################################################################################
QueueOrders.h contains definitions for functions and variables that will define how orders are processed if they are unable to meet buy and
sell conditions. See QueueOrders.cpp for more information.
QueueOrders inherits StockProcessor. This allows QueueOrders to access variables and functions in StockProcessor. 
###########################################################################################################################################
*/


#ifndef QUEUEORDERS_H
#define QUEUEORDERS_H
#include <map>
#include <utility>
#include <string>
#include "../buysellExecution/stockProcessor.h"

//QueueOrders class is a child of StockProcessor, this is achieved through inheritance.
class QueueOrders : public StockProcessor {
    public:
    std::map<std::string, std::pair<float,float> > BuyQueue;
    std::map<std::string, std::pair<float,float> > SellQueue;

    QueueOrders(std::string, float);
    void AddToBuyQueue();
    void AddToSellQueue();
    void CheckBuyPriceMatch(float, float, float);
    void CheckSellPriceMatch(float, float, float);
};

#endif //QUEUEORDERS_H