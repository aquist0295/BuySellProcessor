#include <iostream>
#include <string>
#include <map>
#include <utility>
#include "stockProcessor.h"

using namespace std;

StockProcessor :: StockProcessor(string stock_ticker, double stock_current_price){
    this->stock_ticker  = stock_ticker;
    this->stock_current_price = stock_current_price;
    stock_buy_price     = 0.0;
    stock_sell_price    = 0.0;
    stock_buy_quatity   = 0.0;
    stock_sell_quatity  = 0.0;


   //search Buy cache for orders that may have not been executed for the current ticker 
    for(auto m : Buy_Order_queue){
        string ticker_in_cache = m.first;
        if(ticker_in_cache == stock_ticker){
            if(m.second.first == stock_current_price){
                setBuyPrice(m.second.first, m.second.second);
                Buy_Order_queue.erase(ticker_in_cache);
            }
        }
    }

   //search Sell cache for orders that may have not been executed for the current ticker
    for(auto m : Sell_Order_queue){
        string ticker_in_cache = m.first;
        if(ticker_in_cache == stock_ticker){
            if(m.second.first == stock_current_price){
                setSellPrice(m.second.first, m.second.second);
                Sell_Order_queue.erase(ticker_in_cache);
            }
        }
    }
}

//#################################################################################################################################################################

void StockProcessor :: setBuyPrice(double BuyOrderPrice, double BuyOrderQty){
   /*
     This function will process buy orders. If the BuyOrderPrice and BuyOrderQty match the current stock price, the order will be processed and added to
     the Stock_Buy_Activity table. Otherwise, the buy order will be added to the Buy_Order_queue for processing later.   
   */
    stock_buy_price   = BuyOrderPrice;
    stock_buy_quatity = BuyOrderQty;
    
    if(BuyOrderPrice >= stock_current_price){
        Stock_Buy_Activity[stock_ticker] = make_pair(BuyOrderPrice, BuyOrderQty);
        getBuyPrice("PASS");
    }
   
    else{
        Buy_Order_queue[stock_ticker] = make_pair(BuyOrderPrice, BuyOrderQty);
        getBuyPrice("NO PASS");
    }
}

//#################################################################################################################################################################

void StockProcessor :: setSellPrice(double SellOrderPrice, double SellOrderQty){
    /*
     This function will process Sell orders. If the SellOrderPrice and SellOrderQty match the current stock price, the order will be processed and added to
     the Stock_Sell_Activity table. Otherwise, the Sell order will be added to the Sell_Order_queue for processing later.
    */

    if(Stock_Buy_Activity.count(stock_ticker) == 0){
       cout<<"Unable to sell, Please verify stock is purchased first"<<endl;
       return;
    }

    if(SellOrderQty > Stock_Buy_Activity[stock_ticker].second){
        cout<<"Sell Quantity exceeds Owned Quantity, Please verify Quantity and try again"<<endl;
        return;
    }

    else{
        stock_sell_price    = SellOrderPrice;
        stock_sell_quatity  = SellOrderQty;

        if(SellOrderPrice <= stock_current_price){
            Stock_Sell_Activity[stock_ticker]= make_pair(SellOrderPrice, SellOrderQty);
            getSellPrice("PASS");
        }
        else{
            Sell_Order_queue[stock_ticker] = make_pair(SellOrderPrice, SellOrderQty);
            getSellPrice("NO PASS");
        }
    }
}

//#################################################################################################################################################################

void StockProcessor :: getBuyPrice(string BuyStatus){
    //This function will print Buy order status, depending on whether the order was processed immediately or added to the buy queue.

    if(BuyStatus == "PASS"){
        cout<<"Buy Order Quantity of: "<< stock_buy_quatity << " for ticker: " << stock_ticker <<  " at: $"<< stock_buy_price << " was successfully processed."
        <<endl;
    }
    else{
       cout<<"Buy Price Or Buy Quantity does not match market"<<endl; 
       cout<<"Buy Order Quantity of: "<< stock_buy_quatity << " for ticker: " << stock_ticker << " at: $"<< stock_buy_price << " has been added to the buy queue."
       <<endl;
    }

}

//#################################################################################################################################################################

void StockProcessor :: getSellPrice(string SellStatus){
    //This function will print Sell order status, depending on whether the order was processed immediately or added to the Sell queue.

    if(SellStatus == "PASS"){
        cout<<"Sell Order Quantity of: "<< stock_sell_price << " for ticker: " << stock_ticker <<  " at: $"<< stock_sell_price << " was successfully processed."
        <<endl;
    }
    else{
        cout<<"Sell Price Or Sell Quantity does not match market"<<endl; 
        cout<<"Sell Order Quantity of: "<< stock_sell_quatity << " for ticker: " << stock_ticker << " at: $"<< stock_sell_price << " has been added to the sell queue."
        <<endl;
    }

}

//#################################################################################################################################################################


