cmake_minimum_required(VERSION 3.12)
project(Assignment5p2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment5p2
        a5p2_test.in
        Assign05P2.cpp
        cnPtrQueue.cpp
        cnPtrQueue.h
        nodes_LLoLL.cpp
        nodes_LLoLL.h)
