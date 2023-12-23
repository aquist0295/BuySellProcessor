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
   a. CPP files
      i. main.cpp
      ii. base_class: This directory contains the StockInformation header and cpp files, which will initially be called to get the ticker(from the user) & the ticker's price from the
          API.
      iii. buysellExecution: This directory contains the StockProcessor header and cpp files, which will execute buys and sells.
      iv. Queueing: This directory contains the Queuingbuy_sell header and cpp files, which will queue trades that cannot be executed at the current time.
   
   b. python files
      i. Python_client.py: python script for authentication. This script authenticates User Credentials and calls the Market class.
      ii. market/market.py: python script to get the price information of the current ticker and then using Pybind11, passes that information to the StockInformation class in the                 cppfiles directory.
   
 4. CMakeFile.txt: This file helps to compile the cpp code as well as configure the pybind11 submodule.
 5. setup.py

NB: The API only works with an etrade account(check authentication info and API info in the Python_client.py script), you will need your security token to access the API.
    It's possible to use your other APIs here. NB: I will be using a different API soon.

HOW TO START THIS PROGRAM
DEPENDENCIES:
1. I would recommend using a virtual environment in Python, The link below should help you set up a virtual environment(Ensure Python has been installed and is working properly)
   LINK: https://medium.com/geekculture/installing-python-3-x-development-environment-on-macos-a64c0141b20c (Scroll down to Install and Create Virtual Environment section)

2. Ensure CMAKE is installed and all its dependencies are installed as well.
   CMAKE install cmd:
   MAC: run <brew install cmake> OR download CMAKE directly from the CMAKE website

3. Ensure the PYBIND11 submodule is downloaded. (Refer to my installation for more info and clone if possible OR the official cmake_example project on GitHub)

EXECUTION:
1. run <pip install ./<project name> in the topmost directory => This will build a library that you can now use in your Python scripts to expose cpp functionality in Python.

TESTING CPP CODE W/O Python scripts(This is only for testing purposes)
1. cd <src/cppFiles/main> in terminal
2. run <g++ -std=c++11 -o main.exe main.cpp> (This will compile, link, and create an executable file called main.exe in the current directory)
3. Execute the main.exe file by running ./main.exe


    

