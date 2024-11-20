# E*trade REST API(live trading) with Pybind11 for binding with C++ execution engine.

## A functional Trade execution sample project, integrating the E*trade REST API to track live security prices using Python and a binding agent(pybind11) to expose C++ code to Python scripts for execution.

## This sample project was built as a simple execution engine to showcase the following:
* How to effectively use REST APIs to GET information from endpoints using Python.
* How to pass that information to C++ by exposing C++ code to Python using pybind11.
* How to use OOP concepts effectively: inheritance, encapsulation, classes and objects, etc
* How to run threads in C++.
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
    * For Mac: Download and install Python from https://www.python.org/downloads/mac verify install by running:
      ```
      $ python --version
      ```              
    * For Windows: Download and install Python from https://www.python.org/downloads/mac verify install by running:
       ```
      $ python --version
      ```
       
* g++ for compiling C++ code:
    * Ensure that g++ is installed.
    * For Mac install Xcode(all tools needed to compile c++). For 
    * For Windows visit:https://code.visualstudio.com/docs/cpp/config-mingw

* CMAKE:
    * For Mac & Windows visit for more instructions:https://cmake.org/download/
    * Verify that CMAKE is installed:
      ```
      $ cmake --version
      ```      

### INSTALLATION
* Create Python virtual environment
  ```
  $ pip3 install virtualenv
  $ mkdir <name of direcctor> NB: This is optional
  $ python3 -m venv <name of environment> NB: I recommend naming should be same as project name but not necessary 
  $ source <name of environment>/bin/activate
  ```
* Clone the repo
  ```
  $ cd <name of environment>
  $ git clone https://github.com/aquist0295/BuySellProcessor
  ```
* Run from top-most directory, This will create a pybind11 binary module which will be used in Python scripts to expose C++ code and start 
  the program 
  ```
  $  cmake .
  $  make
  $  mv Processor.cpython-39-darwin.so src/pythonFiles
  $  cd src/pythonFiles
  ```
### USAGE
  * Run python script
    ```
    $ python3 python_client.py
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
  
