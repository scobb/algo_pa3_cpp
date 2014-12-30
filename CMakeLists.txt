cmake_minimum_required(VERSION 2.8.4)
project(Algo_PA3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp parser.cpp)
add_executable(Algo_PA3 ${SOURCE_FILES})