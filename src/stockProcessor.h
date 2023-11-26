#ifndef STOCKPROCESSOR_H
#define STOCKPROCESSOR_H
#include <string>
#include <map>
#include <utility>

using namespace std;

class StockProcessor{

    private:
    string stock_ticker;
    double stock_current_price;
    double stock_buy_price;
    double stock_sell_price;
    double stock_buy_quatity;
    double stock_sell_quatity;
    map<string,pair <double,double> >Stock_Buy_Activity;
    map<string,pair <double,double> >Stock_Sell_Activity;
    map<string,pair <double,double> >Buy_Order_queue;
    map<string,pair <double,double> >Sell_Order_queue;

    public:
    //constructor
    StockProcessor(string, double);

    //setters 
   void setBuyPrice(double, double);
   void setSellPrice(double, double);

    //getters
   void getBuyPrice(string);
   void getSellPrice(string);

};

#endif 




