#ifndef STOCKPROCESSOR_H
#define STOCKPROCESSOR_H
#include <string>
#include <map>
#include <utility>
#include "../base_class/StockInformation.h"

using namespace std;

class StockProcessor{
    public:
    float stock_buy_price;
    float stock_buy_quatity;
    float stock_sell_price;
    float stock_sell_quatity;
    StockInformation *st;

    StockProcessor(StockInformation *st);
    template <typename T, typename S> bool setBuyPrice(T , S);
    template <typename T, typename S> bool setSellPrice(T, S);
    bool getBuyPrice(string);
    bool getSellPrice(string);
};

#endif 




