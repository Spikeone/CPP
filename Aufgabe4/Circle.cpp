//
// Created by Fabian Bucher on 23.02.21.
//

#include "Circle.h"

std::string Circle::toString() {
    return "I am a circle. My center is at " + origin.toString() + ". And my radius is " + std::to_string(radius)
           + ". I cover an area of " + std::to_string(calcArea()) + " units.";
}

float Circle::calcArea() {
    return M_PI * radius * radius;
}
