#ifndef STOCKPROCESSOR_H
#define STOCKPROCESSOR_H
#include <string>
#include <map>
#include <utility>

using namespace std;

class StockProcessor{

    private:
    string stock_ticker;
    float stock_current_price;
    float stock_buy_price;
    float stock_sell_price;
    float stock_buy_quatity;
    float stock_sell_quatity;
    map<string,pair <float,float> >Stock_Buy_Activity;
    map<string,pair <float,float> >Stock_Sell_Activity;
    map<string,pair <float,float> >Buy_Order_queue;
    map<string,pair <float,float> >Sell_Order_queue;

    public:
    //constructor
    StockProcessor(string, float);

    //setters 
   void setBuyPrice(float, float);
   void setSellPrice(float, float);

    //getters
   void getBuyPrice(string);
   void getSellPrice(string);

};

#endif 




