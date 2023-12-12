# BuySellProcessor
This program in C++ and Python uses the pybind11 library to send information(ticker and price info) to the cpp constructor.

#About
This program uses the etrade API to authenticate user credentials and request ticker information(ticker symbol and price) in real-time. The program uses this information
to either trigger a buy or sell depending on the price of the security and the quantity requested.

#Requirements
1. Python3
2. Pip
3. Pybind11
4. Cmake

#Files and directories
1. pybind11(submodule)
2. src
   a. cppFiles
      i. main.cpp
      ii. base_class: This directory contains the StockInformation header and cpp files, which will initially be called to get the ticker(from the user) & the ticker's price from the
          API.
      iii. buysellExecution: This directory contains the StockProcessor header and cpp files, which will execute buys and sells.
      iv. Queueing: This directory contains the Queuingbuy_sell header and cpp files, which will queue trades that cannot be executed at the current time.
   
   b. pythonFiles
      i. Python_client.py: python script for authentication. This script authenticates User Credentials and calls the Market class.
      ii. market/market.py: python script to get the price information of the current ticker and then using Pybind11, passes that information to the StockInformation class in the                 cppfiles directory.
   
 4. CMakeFile.txt: This file helps to compile the cpp code as well as configure the pybind11 submodule.
 5. setup.py: Run this script to begin i.e. python3 setup.py

NB: The API only works with an etrade account(check authentication info and API info in the Python_client.py script), you will need your security token to access the API.
    It's possible to use your other APIs here. NB: I will be using a different API soon.

    

