//
// Created by Fabian Bucher on 23.02.21.
//

#ifndef AUFGABE4_RECTANGLE_H
#define AUFGABE4_RECTANGLE_H

#include "Graph.h"
#include <cmath>

class Rectangle : public Graph {
public:
    Coordinate spanningCorner;
    explicit Rectangle(Coordinate spanningCorner, Coordinate origin = Coordinate()) : spanningCorner(spanningCorner), Graph(origin) {}
    std::string toString() override {
        return "I am a rectangle. My origin is at " + origin.toString() + ". And my spanning corner is at " + spanningCorner.toString() + ".";
    }
    float calcCircumference() override {
        return (std::abs(origin.x - spanningCorner.x) + std::abs(origin.y - spanningCorner.y)) * 2;
    }
};

#endif //AUFGABE4_RECTANGLE_H
