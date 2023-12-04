#include <iostream>
#include <map>
#include <utility>
#include "../buysellExecution/stockProcessor.h"
#include "Queuingbuy_sell.h"

using namespace std;

void Queues :: AddBuySideQueue(float CurrentPrice){
    BuySideQueue[stock_ticker] = {stock_buy_price, CurrentPrice};
    CheckBuyPriceMatch(CurrentPrice);
}

//#################################################################################################################################################################
void Queues :: AddSellSideQueue(float CurrentPrice){
     SellSideQueue[stock_ticker] = {stock_sell_price, CurrentPrice};
     CheckSellPriceMatch(CurrentPrice);
}

//#################################################################################################################################################################
//The next 2 function should be executed as threads with parrallelism in the main program(NB: I will add that feature soon)
void Queues :: CheckBuyPriceMatch(float CurrentPrice){
    float previousPrice  = CurrentPrice;
    float buy_price      = stock_buy_price;
    float buy_quantity   = stock_buy_quatity;
    string currentTicker = stock_ticker;
     while(true){ //could change this condition to date and time
        if(CurrentPrice != previousPrice){
            if(CurrentPrice == buy_price){
                //execute Trade if currentPrice from the api is equal to User's Buy price
                setBuyPrice(buy_price, buy_quantity, currentTicker);
                //remove the entry from the buyside hashtable
                BuySideQueue.erase(currentTicker);
                break; //exit the while loop
            }
            previousPrice = CurrentPrice;
        }
    }
}

//#################################################################################################################################################################

void Queues :: CheckSellPriceMatch(float CurrentPrice){
    float previousPrice = CurrentPrice;
    float sell_price    = stock_sell_price;
    float sell_quantity = stock_sell_quatity;
    string currentTicker = stock_ticker;
     while(true){ //could change this condition to date and time
        if(CurrentPrice != previousPrice){
            if(CurrentPrice == sell_price){
                //execute Trade if currentPrice from the api is equal to User's Sell price
                setSellPrice(sell_price, sell_quantity, currentTicker);
                //remove the entry from the sellside hashtable
                SellSideQueue.erase(currentTicker);
                break;
            }
            previousPrice = CurrentPrice;
        }
    }
}


//create pybind11 module to update currentprice for both functions when the price changes
