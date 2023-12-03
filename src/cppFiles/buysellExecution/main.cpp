#include <iostream>
#include <pybind11/pybind11.h>
#include "stockProcessor.cpp"

using namespace std;

namespace py = pybind11;

void print(string ticker, float price){
    string ticker1 = ticker;
    float price1 = price;

    StockProcessor processor(ticker1, price1);
    processor.setBuyPrice(200.0, 200.0);
}


PYBIND11_MODULE(Processor, m) {
    m.doc() = "testin pybind with testpybind code";

    m.def("print", &print, "A function that prints");
}

