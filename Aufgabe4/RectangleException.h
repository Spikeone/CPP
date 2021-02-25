//
// Created by Fabian Bucher on 25.02.21.
//

#ifndef AUFGABE4_RECTANGLEEXCEPTION_H
#define AUFGABE4_RECTANGLEEXCEPTION_H

#include <string>
#include "CustomException.h"

class RectangleException : public CustomException {
public:
    explicit RectangleException(const std::string& reason) : CustomException("Rectangle", reason) { }
};

#endif //AUFGABE4_RECTANGLEEXCEPTION_H
