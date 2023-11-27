# BuySellProcessor
This program in C++ and Python uses the pybind11 library to send information(ticker and price info) to the cpp constructor.

#About
This program uses the etrade API to authenticate user credentials and request ticker information(ticker symbol and price) in real-time. The program uses this information
to either trigger a buy or sell depending on the price of the security and the quantity requested.

#Files and directories
1. pybind11(submodule)
2. src
   a. cppFiles
      i. main.cpp
      ii. stockProcessor.cpp
      iii. stockProcessor.h
   b. pythonFiles
      i. Python_client.py
      ii. market/market.py
 3. CMakeFile.txt
 4. setup.py

NB: The API only works with an etrade account(check authentication info and API info in the Python_client.py script), you will need your security token to access the API.
    It's possible to use your own API here.

    

