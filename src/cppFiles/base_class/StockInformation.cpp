#include <iostream>
#include <map>
#include <utility>
#include <string>
#include "StockInformation.h"

using namespace std;

StockInformation :: StockInformation(string stock_ticker, float stock_current_price){
    this->stock_ticker = stock_ticker;
    this->stock_current_price = stock_current_price;
}

//#################################################################################################################################################################
StockInformation :: StockInformation(){
    cout<< "starting Processor..." <<endl; 
}

//#################################################################################################################################################################
void StockInformation :: Update_Stock_Buy_Activity(float BuyOrderPrice, float BuyOrderQty){
    Stock_Buy_Activity[stock_ticker] = make_pair(BuyOrderPrice, BuyOrderQty);
}

//#################################################################################################################################################################
void StockInformation :: Update_Stock_Sell_Activity(float SellOrderPrice, float SellOrderQty){
    Stock_Sell_Activity[stock_ticker] = make_pair(SellOrderPrice, SellOrderQty);
}

//#################################################################################################################################################################
void StockInformation :: Update_BuySideQueue(float BuyOrderPrice){
    BuySideQueue[stock_ticker] = make_pair(BuyOrderPrice, stock_current_price);
}

//#################################################################################################################################################################
void StockInformation :: Delete_BuySideQueue(){
    BuySideQueue.erase(stock_ticker);
}

//#################################################################################################################################################################
void StockInformation :: Update_SellSideQueue(float SellOrderPrice){
    SellSideQueue[stock_ticker] = make_pair(SellOrderPrice, stock_current_price);
}

//#################################################################################################################################################################
void StockInformation :: Delete_SellSideQueue(){
    SellSideQueue.erase(stock_ticker);
}

//#################################################################################################################################################################
bool StockInformation :: ValidateSellInfo(string stock_ticker, float SellOrderQty){
    if(Stock_Sell_Activity.count(stock_ticker) == 0){
       cout<<"Unable to sell, Please verify stock has been purchased"<<endl;
       return false;
    }

    if(SellOrderQty > Stock_Buy_Activity[stock_ticker].second){
        cout<<"Sell Quantity exceeds Owned Quantity, Please verify Quantity and try again"<<endl;
        return false;
    }

return true;}