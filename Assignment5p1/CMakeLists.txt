cmake_minimum_required(VERSION 3.12)
project(Assignment5_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
#include_directories(Assign05P1SuppliedFiles)

add_executable(Assignment5_2
        Assign05P1.cpp
        llcpImp.cpp
        llcpInt.h)

#add_executable(Assignment5_2
#        Assign05P1SuppliedFiles/Assign05P1.cpp
#        Assign05P1SuppliedFiles/llcpImp.cpp
#        Assign05P1SuppliedFiles/llcpInt.h
#        Assign05P1.cpp
#        llcpImp.cpp
#        llcpInt.h)
