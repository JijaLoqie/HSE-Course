cmake_minimum_required(VERSION 3.13.4)

project("list")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(list tests.cpp list.h list.cpp)