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
StockInformation st(ticker, price);

/*
string transactionType = "";
cout<<"Would you like to buy or sell said ticker? Please enter b for BUY and s for SELL: "<<endl;
cin>>transactionType;

if(transactionType = "b"){

}

else{

}
*/

float buyPrice = 200, buyQuantity = 100;

StockProcessor P(&st);

bool check = P.setBuyPrice(buyPrice, buyQuantity);

if(!check){
    Queues q(&st);
    
    q.AddBuySideQueue(buyPrice);

    //q.CheckBuyPriceMatch(buyprice, buyQuantity); //this is where you start a new thread for each value added to the queue
}

}


//pybind11 module for market script(Processor)
PYBIND11_MODULE(Processor, m) {
    m.doc() = "testin pybind with testpybind code";

    m.def("GetStockinfo", &GetStockinfo, "A function to retrieve stock information");
}

