cmake_minimum_required(VERSION 3.17)
project(Aufgabe2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Aufgabe2
        ComplexNumber.cpp
        ComplexNumber.h
        main.cpp PolarData.cpp PolarData.h CartasianData.cpp CartasianData.h includes.h)
