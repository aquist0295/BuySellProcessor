#ifndef STOCKINFORMATION_H
#define STOCKINFORMATION_H
#include <map>
#include <utility>
#include <string>

using namespace std;

class StockInformation{
    private:
    map<string,pair <float,float> > Stock_Buy_Activity;
    map<string,pair <float,float> > Stock_Sell_Activity;
    map<string, pair<float,float> > BuySideQueue;
    map<string, pair<float,float> > SellSideQueue;

    public:
    string stock_ticker;
    float stock_current_price;
    StockInformation(string, float);
    StockInformation();
    void Update_Stock_Buy_Activity(float, float);
    void Update_Stock_Sell_Activity(float, float);
    void Update_BuySideQueue(float);
    void Delete_BuySideQueue();
    void Update_SellSideQueue(float); 
    void Delete_SellSideQueue();
    bool ValidateSellInfo(string, float);

};

#endif //STOCKINFORMATION_H