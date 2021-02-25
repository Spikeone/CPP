//
// Created by Fabian Bucher on 25.02.21.
//

#ifndef AUFGABE4_CIRCLEEXCEPTION_H
#define AUFGABE4_CIRCLEEXCEPTION_H

#include <string>
#include "CustomException.h"

class CircleException : public CustomException {
public:
    explicit CircleException(const std::string& reason) : CustomException("Circle", reason) { }
};

#endif //AUFGABE4_CIRCLEEXCEPTION_H
