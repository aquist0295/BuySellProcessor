#include <iostream>
#include <string>
#include <map>
#include <utility>
#include "stockProcessor.h"
#include "../base_class/StockInformation.h"

using namespace std;

StockProcessor :: StockProcessor(StockInformation* st){
    this->st = st;
}

//#################################################################################################################################################################
template <typename T, typename S> bool StockProcessor :: setBuyPrice(T stock_buy_price, S stock_buy_quatity){
   /*
     This function will process buy orders. If the BuyOrderPrice and BuyOrderQty match the current stock price, the order will be processed and added to
     the Stock_Buy_Activity table. Otherwise, the buy order will be added to the Buy_Order_queue for processing later.   
   */
    this->stock_buy_price   = stock_buy_price;
    this->stock_buy_quatity = stock_buy_quatity;

    if(stock_buy_price >= st->stock_current_price){
        st->Update_Stock_Buy_Activity(stock_buy_price, stock_buy_quatity);
        return getBuyPrice("PASS");
    }
   
    else{ 
        return getBuyPrice("NO PASS");
    }
}

//#################################################################################################################################################################
template <typename T, typename S> bool StockProcessor :: setSellPrice(T stock_sell_price, S stock_sell_quatity){
    /*
     This function will process Sell orders. If the SellOrderPrice and SellOrderQty match the current stock price, the order will be processed and added to
     the Stock_Sell_Activity table. Otherwise, the Sell order will be added to the Sell_Order_queue for processing later.
    */   
        //validate that the ticker has been purchased and the stock_sell_quantity does not exceed the buy quantity
        bool ValidateOrder = st->ValidateSellInfo(st->stock_ticker, stock_sell_quatity);

        if(!ValidateOrder){
            return false;
        }
        
        this->stock_sell_price    = stock_sell_price;
        this->stock_sell_quatity  = stock_sell_quatity;
    
        if(stock_sell_price <= st->stock_current_price){
            st->Update_Stock_Sell_Activity(stock_sell_price, stock_sell_quatity);
            return getSellPrice("PASS");
        }
        else{
            return getSellPrice("NO PASS");
        }
}

//#################################################################################################################################################################
bool StockProcessor :: getBuyPrice(string BuyStatus){
    //This function will print Buy order status, depending on whether the order was processed immediately or added to the buy queue.
    if(BuyStatus == "PASS"){
        cout<<"Buy Order Quantity of: "<< stock_buy_quatity << " for ticker: " << st->stock_ticker <<  " at: $"<< stock_buy_price << " was successfully processed."
        <<endl;
        return true;
    }

    return false;
}

//#################################################################################################################################################################
bool StockProcessor :: getSellPrice(string SellStatus){
    //This function will print Sell order status, depending on whether the order was processed immediately or added to the Sell queue.

    if(SellStatus == "PASS"){
        cout<<"Sell Order Quantity of: "<< stock_sell_quatity << " for ticker: " << st->stock_ticker <<  " at: $"<< stock_sell_price << " was successfully processed."
        <<endl;
        return true;
    }
    
    return false;
}

