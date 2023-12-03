#ifndef QUEUINGBUY_SELL_H
#define QUEUINGBUY_SELL_H
#include <map>
#include <utility>

using namespace std;

class QueueMech{
    private:
    map<string, float >buyQueue;
    map<string, float >sellQueue;

    public:
    QueueMech();
    pair<string, float> UpdateBuyQueue();
    pair<string, float> UpdateSellQueue();

};

class Buys : public QueueMech{
    public:
    Buys();
    string ParseBuys();
    void PrintBuys();

};

class Sells : public QueueMech{
    public:
    Sells();
    string ParseSells();
    void PrintSells();    
};

#endif