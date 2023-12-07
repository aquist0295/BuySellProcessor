#include <iostream>
#include <map>
#include <utility>
#include "../buysellExecution/stockProcessor.h"
#include "Queuingbuy_sell.h"

using namespace std;

Queues :: Queues(string stock_ticker, float stock_current_price) : StockProcessor(stock_ticker, stock_current_price){
   cout << "Calling constructor from queue class"<<endl; 
   this->CurrentPrice = stock_current_price;
}


//#################################################################################################################################################################

void Queues :: AddBuySideQueue(float buyOrderPrice){
    BuySideQueue[stock_ticker] = make_pair(stock_buy_price, CurrentPrice);
    cout<<"Added " << stock_ticker << " for : $" << buyOrderPrice << " to the buy queue."<<endl;
    //CheckBuyPriceMatch();
}

//#################################################################################################################################################################
void Queues :: AddSellSideQueue(){
     SellSideQueue[stock_ticker] = make_pair(stock_sell_price, CurrentPrice);
     CheckSellPriceMatch();
}

//#################################################################################################################################################################
//The next 2 function should be executed as threads with parrallelism in the main program(NB: I will add that feature soon)
void Queues :: CheckBuyPriceMatch(){
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

void Queues :: CheckSellPriceMatch(){
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