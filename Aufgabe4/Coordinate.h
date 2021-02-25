//
// Created by Fabian Bucher on 23.02.21.
//

#ifndef AUFGABE4_COORDINATE_H
#define AUFGABE4_COORDINATE_H

#include <string>
#include <sstream>

class Coordinate {
public:
    float x = 0, y = 0;
    Coordinate(float x, float y) : x(x), y(y) {}
    Coordinate() = default;
    std::string toString() const;
};

#endif //AUFGABE4_COORDINATE_H
