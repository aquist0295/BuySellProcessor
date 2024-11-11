 /*
###########################################################################################################################################
stockProcessor.h contains definitions for functions and variables that will define how orders are processed.
See stockProcessor.cpp for more information.
###########################################################################################################################################
*/


#ifndef STOCKPROCESSOR_H
#define STOCKPROCESSOR_H
#include <string>
#include <map>
#include <utility>

class StockProcessor {
    public:
    std:: string live_stock_ticker;
    float live_stock_price;
    float stock_buy_price;
    float stock_buy_quatity;
    float stock_sell_price;
    float stock_sell_quatity;
    // This data structure will hold all buy and sell orders that have successfully been executed.
    std::map<std::string, std::pair<std:: string, std::pair<float,float>>> buy_sell_Activity;

    StockProcessor(std::string, float);
    template <typename T, typename S> bool executeBuy(T , S);
    template <typename T, typename S> bool executeSell(T, S);
    void buyConfirmation();
    void sellConfirmation();
};

#endif //STOCKPROCESSOR_H




