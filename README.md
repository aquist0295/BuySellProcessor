# E*trade REST API(live trading) with Pybind11 for binding with C++ execution.

## A functional Trade execution sample project, integrating the E*trade REST API to track live security prices using Python and binding with pybind11 to expose C++ code to Python scripts.

## This sample project was built as a simple execution engine to showcase the following:
* How to effectively use REST APIs to GET information from endpoints using Python.
* How to pass that information to C++ by exposing C++ code to Python using pybind11.
* How to use OOP concepts effectively: inheritance, encapsulation, classes, objects, templates etc to execute buy and sell orders for securities.
* How to create and run threads in C++.
* How to create a Python environment for testing/building purposes.

## BUILT WITH
* Python
* C++
* Pybind11
* CMAKE
* REST API

## GETTING STARTED
* This section will describe how to locally build this program. To get a local copy up and running follow these simple steps.

### Prerequisites
* Python & PIP:
    * For Mac: Download and install Python from https://www.python.org/downloads/mac and verify install by running:
      ```
      $ python --version
      ```              
    * For Windows: Download and install Python from https://www.python.org/downloads/windows and verify install by running:
       ```
      $ python --version
       ```      

* install and Create Python virtual environment
  ```
  $ pip3 install virtualenv
  $ mkdir <name of direcctor> NB: This is optional
  $ python3 -m venv <name of environment> NB: I recommend naming should be same as project name but not necessary 
  $ source <name of environment>/bin/activate
  ```
       
* g++ for compiling C++ code:
    * Ensure that g++ is installed.
    * For Mac install:
      ```
      brew install clang
      ```
    * For Windows visit: https://code.visualstudio.com/docs/cpp/config-mingw
    * Verify that g++ is installed:
      ```
      g++ --version
      ```

* CMAKE:
    * For Mac & Windows follow instructions here: https://cmake.org/download/
    * Verify that CMAKE is installed:
      ```
      $ cmake --version
      ```      

### INSTALLATION
* Clone the repo
  ```
  $ cd <name of environment>
  $ git clone https://github.com/aquist0295/BuySellProcessor
  ```
* Run from top directory i.e /BuySellProcessor, This will create a pybind11 binary module(Processor.cpython-39-darwin.so)
* which is called in the market.py script to expose C++ code(GetStockinfo).
  ```
  $  cmake .
  $  make
  $  mv Processor.cpython-39-darwin.so src/pythonFiles
  $  cd src/pythonFiles
  ```
### USAGE
  * Run python script
    ```
    $ python python_client.py
    ```
  * Sample output
 ```
 /Users/anthonyquist/Documents/python-vms/testing_final_env/lib/python3.9/site-packages/urllib3/__init__.py:35: NotOpenSSLWarning: urllib3 v2 only supports OpenSSL 1.1.1+, currently the 'ssl' module is compiled with 'LibreSSL 2.8.3'. See: https://github.com/urllib3/urllib3/issues/3020warnings.warn(
Please accept agreement and enter verification code from browser: <Enter verification code here>

Please enter Stock Symbol: aapl
ticker: AAPL
Current Price: 228.02
Would you like to buy or sell this security?
buy
Enter Buy Price:
230
Enter Buy Quantity:
50
Buy Order Quantity of: 50 for ticker: AAPL at: $230 was successfully processed.
ticker: AAPL
Current Price: 228.02

```   
  
