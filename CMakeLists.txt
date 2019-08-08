cmake_minimum_required(VERSION 3.13)
project(filter)

set(CMAKE_CXX_STANDARD 14)

add_executable(filter main.cpp IIR_Filter.cpp IIR_Filter.h)