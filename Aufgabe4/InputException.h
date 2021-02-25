//
// Created by Fabian Bucher on 25.02.21.
//

#ifndef AUFGABE4_INPUTEXCEPTION_H
#define AUFGABE4_INPUTEXCEPTION_H


#include <string>
#include "CustomException.h"

class InputException : public CustomException {
public:
    explicit InputException(const std::string& reason) : CustomException("std::cin", reason) { }
};


#endif //AUFGABE4_INPUTEXCEPTION_H
