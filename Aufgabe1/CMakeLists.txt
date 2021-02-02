cmake_minimum_required(VERSION 3.17)
project(Aufgabe1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Aufgabe1
        main.cpp
        Taxi.cpp
        Taxi.h)
