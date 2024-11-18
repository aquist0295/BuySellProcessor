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

## THE DIAGRAM BELOW WILL GIVE YOU A BETTER UNDERSTANDING OF HOW THIS PROGRAM WORKS.


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
  $ mkdir <name of directory>
  $ python3 -m venv <name of project>
  $ source project_env/bin/activate
  ```
* Clone the repo
  ```
  $ git clone https://github.com/aquist0295/BuySellProcessor
  ```
* Run from topmost directory, This will create a pybind11 binary module which will be used in Python scripts to expose C++ code and start 
  the program 
  ```
  $ pip install ./Processor  
  ```
### USAGE

  
