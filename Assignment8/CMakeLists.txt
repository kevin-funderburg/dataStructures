cmake_minimum_required(VERSION 3.12)
project(Assignment8)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment8
        a8test.txt
        Assign08.cpp
        dict0.txt
        dict1.txt
        HashTable.cpp
        HashTable.h
        Makefile)
