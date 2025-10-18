# Trade execution and automation using python & c++, Docker for deployment.

## A functional Trade execution sample project, integrating API endpoints to get live ticker prices, selenium automation for signing in, Python, and C++ for execution.

## This sample project was built as a simple execution engine to showcase the following:
* How to effectively use REST APIs to GET information from endpoints using Python.
* How to automate web functionality for faster and easier access using Selenium.
* How to pass information from a REST API in Python to C++, by exposing C++ code to Python using pybind11 bindings.
* How to use OOP and C++ concepts effectively: inheritance, encapsulation, classes, objects, templates, etc.
* How to create and run threads in C++.
* How to use Docker containers. NB: the Dockerfile is effective and works, unfortunately, due to OATH authentication, headless browser mode is not possible. A workaround is to add a display to ensure sign-in(that functionality will be added shortly using either VNC or X11). 

## BUILT WITH
* Python
* C++
* Pybind11
* CMAKE
* REST API
* Docker
* Selenium and Google Chrome for web automation

## GETTING STARTED
* This section will describe how to get the project running on your local machine.
* Execution within a Docker container will be added shortly. Ochestration with Kubernetes will be added shortly as well - using minikube.
  
### Prerequisites
* Local Machine using a terminal running Linux (This assumes you have python3 installed)
* Alternatively, you can run a Python venv. follow the steps here: (https://medium.com/@lucasthedev/a-comprehensive-guide-to-python-virtual-environments-with-venv-cb76fea6a550)
   ```
   $ mkdir -p <name of directory>
   $ git clone https://github.com/aquist0295/BuySellProcessor
   ```
* Docker (a linked display to the container is required if using a Docker container and Selenium Chrome)
* Below are resources to help you get started with docker and docker-desktop.
   * For Mac: https://docs.docker.com/desktop/setup/install/mac-install/
   * For Windows: https://docs.docker.com/desktop/setup/install/windows-install/

     
### INSTALLATION & USAGE
* Update config.ini with CONSUMER_KEY & CONSUMER_SECRET NB: an Etrade account is required. Using an editor of your choice(i.e nano, vim, visual-studio) - For this tutorial, i will use vim, since it's available in most Linux distributions. 
  ```
  $ vim /BuySellProcessor/pythonFiles/config.ini
  
  >> CONSUMER_KEY = < Enter CONSUMER_KEY here >
  >> CONSUMER_SECRET = < Enter CONSUMER_SECRET here >
  ```
* Update sign_in_automation.py with Etrade username and password. This will automate sign-in. NB: Etrade's MFA authentications will send a token to the phone number associated with your account during the sign-in process.
  ```
  $ vim /BuySellProcessor/pythonFiles/sign_in_automation.py

  >> user_input.send_keys("") # Enter with your username
  >> password_input.send_keys("") # Enter with your password
  ```  
* Run the application
  ```
  $ cd < top directory from the prerequisites section >
  $ python3 pythonFiles/python_client.py
  ```
* MFA authentication
  ```
  $ Please enter mfa verification code from your device: < Enter code sent to your phone number here >
  ```
## DO NOT INTERUPT THE BROWSER !!! ALL OTHER STEPS ARE AUTOMATED.  

## Please skip section for now : Docker implementation coming shortly
* Build a Docker image and create a container
  ```
  $ docker build -t processor:latest .
  $ docker run -it processor 
  ```
* For M1 Mac, please follow these directions to build a Docker image and run a container
  ```
  $ docker build --platform linux/amd64 -t processor:latest .
  $ docker run -it processor 
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
  
