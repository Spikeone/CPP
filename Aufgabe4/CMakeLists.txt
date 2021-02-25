cmake_minimum_required(VERSION 3.17)
project(Aufgabe4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Aufgabe4
        main.cpp Coordinate.cpp Coordinate.h Graph.cpp Graph.h Circle.cpp Circle.h Rectangle.cpp Rectangle.h CustomException.cpp CustomException.h CircleException.cpp CircleException.h RectangleException.cpp RectangleException.h InputException.cpp InputException.h)
