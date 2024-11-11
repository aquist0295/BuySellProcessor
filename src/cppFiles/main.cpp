/* ###########################################################################################################################################

This block of code contains a function(GetStockinfo(string ticker, float price)) and a module(PYBIND11_MODULE(Processor, m)):

1. GetStockinfo(string ticker, float price) : A void function which accepts two(2) arguments (string ticker i.e the ticker 
    symbol of the security being traded and float price i.e the current price of the ticker symbol). 
    The arguments are passed to this function from the python script which is located here: /src/pythonFiles/market/market.py.

2. PYBIND11_MODULE(Processor, m) : This pybind11 module will create a binary module file that will be called in the: /src/pythonFiles/market/market.py
    as an import. This allows market.py to pass the ticker and price information to GetStockinfo for further processing in C++.
    NB: Processor is the binary module file name.                   
                                                                                                                                    
############################################################################################################################################## */

#include <pybind11/pybind11.h>
#include <iostream>
#include <thread>
#include <utility>
#include "buysellExecution/stockProcessor.cpp"
#include "Queuing/Queuingbuy_sell.cpp"

namespace py = pybind11;

/* 
 The GetStockinfo function is the start function of the CPP program.
 GetStockinfo is binded to python as a module using CMAKE and then called from: /src/pythonFiles/market/market.py to pass relevant information i.e
 ticker and price of a security.
 Refer to the pybind11 module: PYBIND11_MODULE(Processor, m) at the bottom to see where it is defined for python binding.
*/
void GetStockinfo (string ticker, float price) {
// Initialize variables to capture user inputs   
    std::float  buyPrice     = 0.0;
    std::float  buyQuantity  = 0.0;
    std::float  sellPrice    = 0.0;
    std::float  sellQuantity = 0.0;
    std::string transactionType = "";

// Capture user input for either buy or sell of security
    cout<<"Would you like to buy or sell this security?"<<endl;
    cin>>transactionType;

// Based on user input(transactionType) execute buy or sell of said security
    if (transactionType == "buy") {
        cout<<"Enter Buy Price:"<<endl;
        cin>>buyPrice;
        cout<<"Enter Buy Quantity:"<<endl;
        cin>>buyQuantity;
    }
    else {
        cout<<"Enter Sell Price:"<<endl;
        cin>>sellPrice;
        cout<<"Enter Sell Quantity:"<<endl;
        cin>>sellQuantity;
    }

/*
 Once all information has been gathered from the user inputs, the program will proceed to execute either a buy or sell.
 If a buy or sell is executed successfully, that transaction will be added to a buy/sell side table(map).
 If the order is not executed successfully, that transaction will be added to a queue for processing later.
 NB: multi-threading will be used here to concurrently monitor transactions in the queue(desired order) against their live traded values(price). 
     If there is a match between the live price of a security and the desired price(price in queue), then the order will
     be executed.
*/

// instantiate the StockProcessor and create an object. for more information refer to: src/cppFiles/buysellExecution.
    StockProcessor P(ticker, price);

// orderStatus will be true if executeBuy function is able to successful execute a buy and false otherwise.   
    bool orderStatus = true;

// Verify if transactionType is either a buy or sell from the user input
    if (transactionType == buy) {
        bool orderStatus = P.executeBuy(buyPrice, buyQuantity);

        // instantiate the QueueOrders class if orderStatus is false, refer to: /src/cppFiles/Queuing for more information
        if (orderStatus == false) {
            QueueOrders Q;
            Q.AddToBuyQueue;
        }
    }
    else {
       bool orderStatus = P.executeSell(sellPrice, sellQuantity);

        // instantiate the Queue class if orderStatus is false, refer to: /src/cppFiles/Queuing for more information
        if (orderStatus == false) {
            QueueOrders Q;
            Q.AddToSellQueue;
        }
    }    
}


// Pybind11 module definition for our bindings
PYBIND11_MODULE(Processor, m) {
/*
 This line is for testing purposes. This will output the string ("testing pybind11 with testpybind code") 
 to the console to ensure pybind11 is functioning properly.
*/
    m.doc() = "testing pybind11 with testpybind code";
 
// m.def will generate binding code that will expose the GetStockinfo function to python.
    m.def("GetStockinfo", &GetStockinfo, "A function to retrieve stock information");
}

