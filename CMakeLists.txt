cmake_minimum_required(VERSION 3.4...3.18)
project(Processor)

add_subdirectory(Pybind11Submodule)
pybind11_add_module(Processor src/cppFiles/main.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(Processor
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
