cmake_minimum_required(VERSION 3.12)
project(AssignmentOptional)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AssignmentOptional
        ao1.out
        AssignOpt01.cpp
        btNode.cpp
        btNode.h
        Makefile)
