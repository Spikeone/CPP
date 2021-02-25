//
// Created by Fabian Bucher on 23.02.21.
//

#ifndef AUFGABE4_CIRCLE_H
#define AUFGABE4_CIRCLE_H

#include <cmath>
#include "Graph.h"
#include "CircleException.h"

class Circle : public Graph {
public:
    float radius;
    explicit Circle(float radius, Coordinate origin = Coordinate()) : radius(radius), Graph(origin) {
        if (radius <= 0) {
            throw CircleException("Circle radius must be bigger than zero.");
        }
    }
    std::string toString() override;
    float calcArea() override;
};

#endif //AUFGABE4_CIRCLE_H
