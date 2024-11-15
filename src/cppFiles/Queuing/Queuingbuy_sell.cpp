/*
###########################################################################################################################################
The QueueOrders class is responsible for queuing transactions that have not been processed.
This class contains four(4) functions as follows:
The AddToBuyQueue() and AddToSellQueue() functions are responsible for adding buy and sell transactions to the BuyQueue or the sellQueue.
CheckBuyPriceMatch() and CheckSellPriceMatch() will be called from the previous functions for all orders added to the queue. These
functions will are called as part of multi-threading(concurrency) to allow the program to monitor any prices changes continously.
###########################################################################################################################################
*/

#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <thread>
#include "Queuingbuy_sell.h"

//function to add unsuccessful buy transactions to the BuyQueue and create a thread.
void QueueOrders :: AddToBuyQueue () {
    //Add the order to the buy queue.
    BuyQueue[live_stock_ticker] = std::make_pair(stock_buy_price, stock_buy_quatity);
    std::cout<<"Buy Order for ticker: " << live_stock_ticker << " at: $"<< stock_buy_price << " has been added to the buy queue."<<std::endl;

    //create a sub-process(thread) with CheckBuyPriceMatch, this will allow previous orders to complete without the main process(thread).
    std::thread t1(CheckBuyPriceMatch, live_stock_price, BuyQueue[live_stock_ticker].first, BuyQueue[live_stock_ticker].second);

    //detach thread to allow it to execute on itself. NB: join() might be a better option depending on use case.
    t1.detach();
}

//function to add unsuccessful sell transactions to the SellQueue and create a thread.
void QueueOrders :: AddToSellQueue () {
     //Add the order to the sell queue.
     SellQueue[live_stock_ticker] = std::make_pair(stock_sell_price, stock_sell_quatity);
     std::cout<<"Sell Order for ticker: " << live_stock_ticker << " at: $"<< stock_sell_price << " has been added to the sell queue."<<std::endl;

    //call CheckBuyPriceMatch to create a thread for this order(this will be called as a thread)
    std::thread t1(CheckSellPriceMatch, live_stock_price, SellQueue[live_stock_ticker].first, SellQueue[live_stock_ticker].second);

     //detach thread to allow it to execute on itself. NB: join() might be a better option depending on use case.
    t1.detach();
}


// This function will check to sege if the desired buy price matches the live price of the security(to do: expose this function to python for live price updates).
void QueueOrders:: CheckBuyPriceMatch (float currentPrice, float buyPrice, float buyQuantity) {
    //execute a buy if the currentPrice passed from: (insert python script here) is equal to the buyPrice(desired price from the user)
    while (true) {
        if (currentPrice == buyPrice) {
            executeBuy(buyPrice, buyQuantity);
            break;
        }
    }
}

// This function will check to see if the desired buy price matches the live price of the security(to do: expose this function to python for live price updates).
void QueueOrders :: CheckSellPriceMatch (float currentPrice, float sellPrice, float sellQuantity) {
    //execute a sell if the currentPrice passed from: (insert python script here) is equal to the sellPrice(desired price from the user)
    while (true) {
        if (currentPrice == sellPrice) {
            executeBuy(sellPrice, sellQuantity);
            break;
        }
    }
}
