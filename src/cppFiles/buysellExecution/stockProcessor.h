#ifndef STOCKPROCESSOR_H
#define STOCKPROCESSOR_H
#include <string>
#include <map>
#include <utility>
#include <thread>

using namespace std;

class StockProcessor{
    private:
    map<string,pair <float,float> >Stock_Buy_Activity;
    map<string,pair <float,float> >Stock_Sell_Activity;

    public:
    string stock_ticker;
    float stock_current_price;
    float stock_buy_price;
    float stock_sell_price;
    float stock_buy_quatity;
    float stock_sell_quatity;

    //constructor
   StockProcessor(string, float);

   template <typename T, typename S> void setBuyPrice(T , S, string);
   template <typename T, typename S> void setSellPrice(T, S, string);
   void getBuyPrice(string);
   void getSellPrice(string);
};

#endif 




