#include <iostream>
#include <map>
#include <utility>
#include "Queuingbuy_sell.h"

using namespace std;

Queues :: Queues(StockInformation *st){
    this->st = st;
}

//#################################################################################################################################################################
void Queues :: AddBuySideQueue(float stock_buy_price){
    st->Update_BuySideQueue(stock_buy_price);
    cout<<"Buy Order for ticker: " << st->stock_ticker << " at: $"<< stock_buy_price << " has been added to the buy queue."<<endl;
}

//#################################################################################################################################################################
void Queues :: AddSellSideQueue(float stock_sell_price){
     st->Update_SellSideQueue(stock_sell_price);
     cout<<"Sell Order for ticker: " << st->stock_ticker << " at: $"<< stock_sell_price << " has been added to the sell queue."<<endl;
}

//#################################################################################################################################################################
//The next 2 function should be executed as threads with parrallelism in the main program(NB: I will add that feature soon)
void Queues :: CheckBuyPriceMatch(float stock_buy_price, float stock_buy_qty){
    float previousPrice  = st->stock_current_price;
    float buy_price      = stock_buy_price;
    float buy_qty        = stock_buy_qty;
     while(true){ //could change this condition to time
        if(st->stock_current_price != previousPrice){
            if(st->stock_current_price == buy_price){
                //execute Trade if currentPrice from the api is equal to User's Buy price
                st->Update_Stock_Buy_Activity(buy_price, buy_qty);

                //remove the entry from the buyside hashtable
                st->Delete_BuySideQueue();
       
                //end thread and break
                
                break; //exit the while loop
            }
            previousPrice = st->stock_current_price;
        }
    }
}

//#################################################################################################################################################################
void Queues :: CheckSellPriceMatch(float stock_sell_price, float stock_sell_qty){
    float previousPrice  = st->stock_current_price;
    float sell_price      = stock_sell_price;
    float sell_qty        = stock_sell_qty;
     while(true){ //could change this condition to time
        if(st->stock_current_price != previousPrice){
            if(st->stock_current_price == sell_price){
                //execute Trade if currentPrice from the api is equal to User's Buy price
                st->Update_Stock_Sell_Activity(sell_price, sell_qty);

                //remove the entry from the buyside hashtable
                st->Delete_BuySideQueue();
       
                //end thread and break
                
                break; //exit the while loop
            }
            previousPrice = st->stock_current_price;
        }
    }
}

