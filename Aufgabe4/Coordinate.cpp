//
// Created by Fabian Bucher on 23.02.21.
//

#include "Coordinate.h"

std::string Coordinate::toString() const {
    return "x: " + std::to_string(x) + ", y: " + std::to_string(y);
}
