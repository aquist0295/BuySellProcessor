#include <iostream>
//#include <pybind11/pybind11.h>
#include "stockProcessor.cpp"

using namespace std;

//namespace py = pybind11;

int main(){
    //string ticker1 = ticker;
    //float price1 = price;

    StockProcessor processor("aapl", 100.00);
    processor.setBuyPrice(200.98, 200);
    processor.setSellPrice(150.56, 100);

return 0;}


/*
PYBIND11_MODULE(Processor, m) {
    m.doc() = "testin pybind with testpybind code";

    m.def("print", &print, "A function that prints");
}
*/
