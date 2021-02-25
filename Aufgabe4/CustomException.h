//
// Created by Fabian Bucher on 25.02.21.
//

#ifndef AUFGABE4_CUSTOMEXCEPTION_H
#define AUFGABE4_CUSTOMEXCEPTION_H

#include <string>

class CustomException {
public:
    CustomException(const std::string& className, const std::string& reason) : m_className(className), m_reason(reason) { }
    std::string getError() const {
        return "Error in class \"" + m_className + "\".\n" + "Reason: " + m_reason;
    }

private:
    std::string m_className;
    std::string m_reason;
};

#endif //AUFGABE4_CUSTOMEXCEPTION_H
