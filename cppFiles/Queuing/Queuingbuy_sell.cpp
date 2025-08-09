/*
###########################################################################################################################################
The QueueOrders class is responsible for queuing transactions that have not been processed.
This class contains four(4) functions as follows:
The AddToBuyQueue() and AddToSellQueue() functions are responsible for adding buy and sell transactions to the BuyQueue or the sellQueue.
CheckBuyPriceMatch() and CheckSellPriceMatch() will be called for all orders added to the queue.
These functions will are called as part of multi-threading(concurrency) to allow the program to monitor any prices changes continously. refer:/src/cppFiles/main.cpp
###########################################################################################################################################
*/

#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <thread>
#include "Queuingbuy_sell.h"

/*
Invoking the base class constructor by passing arguments to the base class constructor.
Refernce the object of this class here: /src/cppFiles/main.cpp
*/
QueueOrders :: QueueOrders (std::string ticker, float price) : StockProcessor (ticker, price) {}

//function to add unsuccessful buy transactions to the BuyQueue.
void QueueOrders :: AddToBuyQueue () {
    //Add the order to the buy queue.
    BuyQueue[live_stock_ticker] = std::make_pair(stock_buy_price, stock_buy_quatity);
    std::cout<<"Buy Order for ticker: " << live_stock_ticker << " at: $"<< stock_buy_price << " has been added to the buy queue."<<std::endl;
}

//function to add unsuccessful sell transactions to the SellQueue.
void QueueOrders :: AddToSellQueue () {
     //Add the order to the sell queue.
     SellQueue[live_stock_ticker] = std::make_pair(stock_sell_price, stock_sell_quatity);
     std::cout<<"Sell Order for ticker: " << live_stock_ticker << " at: $"<< stock_sell_price << " has been added to the sell queue."<<std::endl;
}


// This function will check to see if the desired buy price matches the live price of the security.
void QueueOrders:: CheckBuyPriceMatch (float currentPrice, float buyPrice, float buyQuantity) {
    //execute a buy if the currentPrice/live price matches the desired buy price of the security.
    while (true) {
        if (currentPrice == buyPrice) {
            executeBuy(buyPrice, buyQuantity);
            break;
        }
    }
}

// This function will check to see if the desired buy price matches the live price of the security.
void QueueOrders :: CheckSellPriceMatch (float currentPrice, float sellPrice, float sellQuantity) {
     //execute a sell if the currentPrice/live price matches the desired sell price of the security.
    while (true) {
        if (currentPrice == sellPrice) {
            executeBuy(sellPrice, sellQuantity);
            break;
        }
    }
}
