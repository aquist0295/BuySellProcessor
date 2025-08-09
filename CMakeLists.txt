cmake_minimum_required(VERSION 3.4...3.18)
project(processor)

add_subdirectory(Pybind11Submodule)
pybind11_add_module(processor cppFiles/main.cpp)

