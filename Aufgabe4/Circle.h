//
// Created by Fabian Bucher on 23.02.21.
//

#ifndef AUFGABE4_CIRCLE_H
#define AUFGABE4_CIRCLE_H

#include <cmath>
#include "Graph.h"

class Circle : public Graph {
public:
    float radius;
    explicit Circle(float radius, Coordinate origin = Coordinate()) : radius(radius), Graph(origin) {}
    std::string toString() override {
        return "I am a circle. My center is at " + origin.toString() + ". And my radius is " + std::to_string(radius) + ".";
    }
    float calcCircumference() override {
        return M_PI * 2 * radius;
    }
};

#endif //AUFGABE4_CIRCLE_H
