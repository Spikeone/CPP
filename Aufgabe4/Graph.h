//
// Created by Fabian Bucher on 23.02.21.
//

#ifndef AUFGABE4_GRAPH_H
#define AUFGABE4_GRAPH_H

#include <string>
#include "Coordinate.h"

class Graph {
public:
    Coordinate origin;

    virtual std::string toString() = 0;

    virtual float calcArea() = 0;
protected:
    explicit Graph(Coordinate coordinate = Coordinate(0, 0)): origin(coordinate) {}
};

#endif //AUFGABE4_GRAPH_H
