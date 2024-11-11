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

    //call CheckBuyPriceMatch to create a thread for this order.
    CheckBuyPriceMatch();
}


void QueueOrders :: AddToSellQueue () {
     //Add the order to the sell queue.
     SellQueue[live_stock_ticker] = std::make_pair(stock_sell_price, live_stock_price);
     std::cout<<"Sell Order for ticker: " << live_stock_ticker << " at: $"<< stock_sell_price << " has been added to the sell queue."<<std::endl;

    //call CheckSellPriceMatch to create a thread for this order.
    CheckSellPriceMatch();  
}


//
void QueueOrders:: CheckBuyPriceMatch () {
    float previousPrice  = st->stock_current_price;
    float buy_price      = stock_buy_price;
    float buy_qty        = stock_buy_qty;

    while (true){ //could change this condition to time
        if (st->stock_current_price != previousPrice) {
            if (st->stock_current_price == buy_price) {
                //execute Trade if currentPrice from the api is equal to User's Buy price
                st->Update_Stock_Buy_Activity(buy_price, buy_qty);

                //remove the entry from the buyside hashtable
                st->Delete_BuySideQueue();
                
                break; //exit the while loop
            }
            previousPrice = st->stock_current_price;
        }
    }
}


void QueueOrders :: CheckSellPriceMatch () {
    float previousPrice  = st->stock_current_price;
    float sell_price      = stock_sell_price;
    float sell_qty        = stock_sell_qty;

    while (true) { //could change this condition to time
        if (st->stock_current_price != previousPrice) {
            if (st->stock_current_price == sell_price) {
                //execute Trade if currentPrice from the api is equal to User's Buy price
                st->Update_Stock_Sell_Activity(sell_price, sell_qty);

                //remove the entry from the buyside hashtable
                st->Delete_BuySideQueue();
                
                break; //exit the while loop
            }
            previousPrice = st->stock_current_price;
        }
    }
}

