# Trade execution and automation using python & c++, Docker for deployment.

## A functional Trade execution sample project, integrating API endpoints to get live ticker prices, selenium automation for signing in, Python, and C++ for execution.

## This sample project was built as a simple execution engine to showcase the following:
* How to effectively use REST APIs to GET information from endpoints using Python.
* How to automate web functionality for faster and easier access using Selenium.
* How to pass information from a REST API in Python to C++, by exposing C++ code to Python using pybind11 bindings.
* How to use OOP and C++ concepts effectively: inheritance, encapsulation, classes, objects, templates, etc, effectively.
* How to create and run threads in C++.
* How to use Docker containers. NB: the Dockerfile is effective and works, unfortunately, due to OATH authentication, headless browser mode will not be possible. A work-around would be to add a display to ensure sign-in(I will add that functionality soon using either VNC or X11). 

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
* Execution within a Docker container will be added soon. Ochestration with Kubernetes - using minikube.
  

### Prerequisites
* Local Machine using a terminal running Linux 
     ```
     $ mkdir -p <name of directory>
     ```
* Docker (a linked display to the container is required if using a Docker container and Selenium Chrome)
   * For Mac: https://docs.docker.com/desktop/setup/install/mac-install/
   * For Windows: https://docs.docker.com/desktop/setup/install/windows-install/

     
### INSTALLATION & USAGE
* Clone the repo
  ```
  $ git clone https://github.com/aquist0295/BuySellProcessor
  ```
* Update config.ini with CONSUMER_KEY & CONSUMER_SECRET NB: an Etrade account is required for this. Using an editor of your choice(i.e nano, vim, visual-studio) - in this example,I will use vim, since it's available in most Linux distributions. 
  ```
  $ vim /BuySellProcessor/pythonFiles/config.ini

  
  ```
* Update sign_in_automation.py with both username and password within the script, this will automate sign-in. NB: MFA authentications will send a token to your phone associated with your account at some point in the sign-in process.
  ```
  $ vim /BuySellProcessor/pythonFiles/sign_in_automation.py

  user_input.send_keys("") # Enter with your username
  password_input.send_keys("") # Enter with your password
  ```  
* On local machine run(this assumes you have installed python3) alternatively you can run a Python venv follow steps here(https://medium.com/@lucasthedev/a-comprehensive-guide-to-      python-virtual-environments-with-venv-cb76fea6a550):
  ```
  $ python3 python3 pythonFiles/python_client.py
  ```  
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
  
