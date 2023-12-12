#include <iostream>
#include <thread>
//#include <pybind11/pybind11.h>
#include "base_class/StockInformation.cpp"
#include "buysellExecution/stockProcessor.cpp"
#include "Queuing/Queuingbuy_sell.cpp"

using namespace std;

//namespace py = pybind11;

//Will be using pybind to get the actual price of a stock in function here
/*
template <typename F> float GetStockinfo(F price){
    if(price){
        return price;
    }
    
    GetStockinfo(price);
}
*/

int main(){    
//cout<<"Welcome to this program"<<endl;

string ticker = "aapl";

//cout<<"Please enter ticker symbol: ";
//cin >> ticker;

//call pybind11 function here(GetStockiinfo) to get the current price
//float curr_price = 0.0;
//float curr_price = GetStockinfo(curr_price)
float curr_price = 100;

//instantiate stockinformation class here
//StockInformation(ticker, curr_price);

float buyPrice = 90, buyQuantity = 100;
/*
cout<<"Please enter buy price: ";
cin>>buyPrice;
cout<<"Please enter buy Quantity: ";
cin>>buyQuantity;
*/

StockInformation st(ticker, curr_price);

//instantiate stockProcessor class here
StockProcessor P(&st);

bool check = P.setBuyPrice(buyPrice, buyQuantity);

if(!check){
    Queues q(&st);
    
    q.AddBuySideQueue(buyPrice);

    //q.CheckBuyPriceMatch(buyprice, buyQuantity); //this is where you start a new thread for each value added to the queue
}


return 0;}


/*
PYBIND11_MODULE(Processor, m) {
    m.doc() = "testin pybind with testpybind code";

    m.def("print", &print, "A function that prints");
}
*/
