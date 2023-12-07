#include <iostream>
//#include <pybind11/pybind11.h>
#include "buysellExecution/stockProcessor.cpp"
#include "Queuing/Queuingbuy_sell.cpp"

using namespace std;

//namespace py = pybind11;

int main(){
    //string ticker1 = ticker;
    //float price1 = price;

    StockProcessor processor("aapl", 100.00);
    bool passOrNopass = processor.setBuyPrice(96.78, 200, "");

    if(passOrNopass == 0){
         Queues q("aapl", 100.00);
         q.AddBuySideQueue(100.00, 96.78);
    }

    

    


return 0;}


/*
PYBIND11_MODULE(Processor, m) {
    m.doc() = "testin pybind with testpybind code";

    m.def("print", &print, "A function that prints");
}
*/
