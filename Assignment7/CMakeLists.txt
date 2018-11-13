cmake_minimum_required(VERSION 3.12)
project(Assignment7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment7
        Assign07Test.cpp
        DPQueue.cpp
        DPQueue.h
        Makefile
        MakefileAutoDOS
        SuccessfulAutoTest.txt)
