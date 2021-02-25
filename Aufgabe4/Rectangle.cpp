//
// Created by Fabian Bucher on 23.02.21.
//

#include "Rectangle.h"

std::string Rectangle::toString() {
    return "I am a rectangle. My origin is at " + origin.toString() + ". And my spanning corner is at "
           + spanningCorner.toString() + ". I cover an area of " + std::to_string(calcArea()) + " units.";
}

float Rectangle::calcArea() {
    return std::abs(origin.x - spanningCorner.x) * std::abs(origin.y - spanningCorner.y);
}
