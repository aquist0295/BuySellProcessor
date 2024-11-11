/*
###########################################################################################################################################
The stockProcessor class is responsible for processing buy and sell orders.
The constructor is responsible for initializing live_stock_price and live_stock_ticker variables which were passed from GetStockinfo.
All other functions are responsible for executing either buys or sells based on user inputs from: /src/cppFiles/main.cpp.
###########################################################################################################################################
*/

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include "stockProcessor.h"

// A constructor to initialize the current stock price and ticker symbol.
StockProcessor :: StockProcessor(std:: string live_stock_ticker, float live_stock_price) {
    this->live_stock_ticker = live_stock_ticker;
    this->live_stock_price  = live_stock_price;
}

/*
 An executeBuy template function which is responsible for executing buy orders by verifying the users desired price(stock_buy_price) is
 greater than or equal to the live price of the security.
 If this condition is true, the order will be executed by adding it to the buy_sell_Activity table for our records, otherwise return false.
*/
template <typename T, typename S> bool StockProcessor :: executeBuy (T stock_buy_price, S stock_buy_quatity) {
    this->stock_buy_price   = stock_buy_price;
    this->stock_buy_quatity = stock_buy_quatity;

    // Execute buy by recording the order transaction in the buy_sell_Activity table.
    if (stock_buy_price >= live_stock_price) {
        buy_sell_Activity[live_stock_ticker] = std::make_pair("BUY", std::make_pair(stock_buy_price, stock_buy_quatity));
        buyConfirmation();
        return true;
    }

    // return false if order is unsuccessful
    return false;
}

/*
 An executeSell template function which is responsible for executing sell orders by verifying the users desired price(stock_sell_price) is
 less than or equal to the live price of the security.
 If this condition is true, the order will be executed by adding it to the buy_sell_Activity table for our records, otherwise return false;
*/
template <typename T, typename S> bool StockProcessor :: executeSell (T stock_sell_price, S stock_sell_quatity) { 
    //validate that the ticker has been purchased and the stock_sell_quantity does not exceed the buy quantity.
    if (buy_sell_Activity.count(live_stock_price) == 0) {
        return false;
    }

    //Ensure that the desired sell quantity does not exceed owned quatity of the ticker.

    this->stock_sell_price    = stock_sell_price;
    this->stock_sell_quatity  = stock_sell_quatity;
    
    if (stock_sell_price <= live_stock_price) {
        buy_sell_Activity[live_stock_ticker] = std::make_pair("SELL", std::make_pair(stock_sell_price, stock_sell_quatity));
        return getSellPrice();
        return true;
    }
        
    // return false if order is unsuccessful
    return false;
}

//This function will print Buy order status, depending on whether the order was processed immediately or added to the buy queue.
void StockProcessor :: buyConfirmation () {
    std::cout<<"Buy Order Quantity of: "<< stock_buy_quatity << " for ticker: " << live_stock_ticker <<  " at: $"<< stock_buy_price << " was successfully processed."
    <<std::endl;
}


//This function will print Sell order status, depending on whether the order was processed immediately or added to the Sell queue.
void StockProcessor :: sellConfirmation() {
    std::cout<<"Sell Order Quantity of: "<< stock_sell_quatity << " for ticker: " << live_stock_ticker <<  " at: $"<< stock_sell_price << " was successfully processed."
    <<std::endl;
}

