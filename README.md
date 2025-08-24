# E*trade REST API(live trading) using a C++ moudule built with pybind11

## A functional Trade execution sample project, integrating the E*trade REST API to track live security prices using Python and binding with pybind11 to expose C++ code to Python scripts.

## This sample project was built as a simple execution engine to showcase the following:
* How to effectively use REST APIs to GET information from endpoints using Python.
* How to pass that information to C++ code, by exposing C++ code to Python using pybind11.
* How to use OOP concepts effectively: inheritance, encapsulation, classes, objects, templates, etc, to execute buy and sell orders for securities.
* How to create and run threads in C++. (commented out because it is not completely executed yet)
* How to use Docker containers.

## BUILT WITH
* Python
* C++
* Pybind11
* CMAKE
* REST API
* Docker
* Selenium and Google Chrome for web automation

## GETTING STARTED
* This section will describe how to build a Docker image of the project and run the project within a container.
  

### Prerequisites
* Docker
   * For Mac: https://docs.docker.com/desktop/setup/install/mac-install/
   * For Windows: https://docs.docker.com/desktop/setup/install/windows-install/

     
### INSTALLATION & USAGE
* Clone the repo
  ```
  $ git clone https://github.com/aquist0295/BuySellProcessor
  ```
* Run from top directory, i.e,/BuySellProcessor. This will create a pybind11 binary module(processor.cpython-310-aarch64-linux-gnu.so) in the Docker image.
* which will be called in /pythonFiles/market/market.py script to expose C++ code(GetStockinfo).
  ```
  $ docker build -t processor:latest .
  $ docker run -it processor 
  ```
* For M1 Mac, please follow these directions to build a Docker image and run a container
  ```
  $ docker build --platform linux/amd64 -t processor:latest .
  $ docker run -it processor 
  ```

  NB: Automation will sign the user into the extrade application, but will not copy the code to authenticate the user. Implementation for the complete automation will added shortly.
   
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
  
