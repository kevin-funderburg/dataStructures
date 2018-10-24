cmake_minimum_required(VERSION 3.12)
project(Assignment6pt1B)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment6pt1B
        a6p1Btest.out
        Assign06P1B.cpp
        llcpImp.cpp
        llcpInt.h
        Makefile)
