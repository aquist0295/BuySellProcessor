/*
###########################################################################################################################################

###########################################################################################################################################
*/

#include <iostream>
#include <map>
#include <utility>
#include <string>
#include "Queuingbuy_sell.h"

void QueueOrders :: AddToBuyQueue() {
    //Add the order to the buy queue.
    BuyQueue[live_stock_ticker] = std::make_pair(stock_buy_price, live_stock_price);
    std::cout<<"Buy Order for ticker: " << live_stock_ticker << " at: $"<< stock_buy_price << " has been added to the buy queue."<<std::endl;

    //call CheckBuyPriceMatch to create a thread for this order(this will be called as a thread)
    CheckBuyPriceMatch(BuyQueue[live_stock_ticker].first, stock_buy_quatity, BuyQueue[live_stock_ticker].second);
}


void QueueOrders :: AddToSellQueue () {
     //Add the order to the sell queue.
     SellQueue[live_stock_ticker] = std::make_pair(stock_sell_price, live_stock_price);
     std::cout<<"Sell Order for ticker: " << live_stock_ticker << " at: $"<< stock_sell_price << " has been added to the sell queue."<<std::endl;

    //call CheckSellPriceMatch to create a thread for this order.(this will be called as a thread)
    CheckSellPriceMatch(SellQueue[live_stock_ticker].first, stock_sell_quatity, SellQueue[live_stock_ticker].second);  
}


// This function will check to see if the desired buy price matches the live price of the security(to do: expose this function to python for live price updates).
void QueueOrders:: CheckBuyPriceMatch (float buyPrice, float buyQuantity, float currentPrice) {
    //execute a buy if the currentPrice passed from: (insert python script here) is equal to the buyPrice(desired price from the user)
    if (currentPrice == buyPrice) {
        executeBuy(buyPrice, buyQuantity);
    }

}

// This function will check to see if the desired buy price matches the live price of the security(to do: expose this function to python for live price updates).
void QueueOrders :: CheckSellPriceMatch (float sellPrice, float sellQuantity, float currentPrice) {
    //execute a sell if the currentPrice passed from: (insert python script here) is equal to the sellPrice(desired price from the user)
    if (currentPrice == sellPrice) {
        executeBuy(sellPrice, sellQuantity);
    }
}

