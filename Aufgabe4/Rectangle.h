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
    std::string toString() override;
    float calcArea() override;
};

#endif //AUFGABE4_RECTANGLE_H
