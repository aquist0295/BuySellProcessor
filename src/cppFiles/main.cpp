#include <iostream>
#include <thread>
#include <utility>
#include <pybind11/pybind11.h>
#include "base_class/StockInformation.cpp"
#include "buysellExecution/stockProcessor.cpp"
#include "Queuing/Queuingbuy_sell.cpp"

using namespace std;

namespace py = pybind11;

//This function wiil be called as a pybind11 module which will retrieve prices from the market python script and commence processing
void GetStockinfo(string ticker, float price){
float buyPrice     = 0.0;
float buyQuantity  = 0.0;
float sellPrice    = 0.0;
float sellQuantity = 0.0;
string transactionType = "";

StockInformation st(ticker, price);

cout<<"Would you like to buy or sell this security?"<<endl;
cin>>transactionType;

if(transactionType == "buy"){
    cout<<"Enter Buy Price:"<<endl;
    cin>>buyPrice;
    cout<<"Enter Buy Quantity:"<<endl;
    cin>>buyQuantity;
}
else{
    cout<<"Enter Sell Price:"<<endl;
    cin>>sellPrice;
    cout<<"Enter Sell Quantity:"<<endl;
    cin>>sellQuantity;
}

StockProcessor P(&st);
bool check = P.setBuyPrice(buyPrice, buyQuantity);

if(!check){
    Queues q(&st);

    if(transactionType = "buy"){
        q.AddBuySideQueue(buyPrice);
        thread t1(q.CheckBuyPriceMatch, buyPrice, buyQuantity);
        t1.detach();//this is tentative, currently figuring out how and when to join the thread to the main thread
    }

    else{
        q.AddSellSideQueue(sellPrice);
        thread t1(q.CheckSellPriceMatch, sellPrice, sellQuantity);
        t1.detach();//tentative
    }
}

}


//pybind11 module for market script(Processor)
PYBIND11_MODULE(Processor, m) {
    m.doc() = "testin pybind with testpybind code";

    m.def("GetStockinfo", &GetStockinfo, "A function to retrieve stock information");
}

