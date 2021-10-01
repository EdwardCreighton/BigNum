cmake_minimum_required(VERSION 3.19)
project(BigNum)

set(CMAKE_CXX_STANDARD 14)

add_executable(BigNum
        ./Headers/BigNum_Int.h
        ./Headers/Byte.h
        ./Source/BigNum_Int.cpp
        ./Source/Byte.cpp
        main.cpp)