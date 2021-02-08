#pragma once

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#define _USE_MATH_DEFINES

#include<string>

class ComplexNumber
{
public:
    // 
    double realPart;
    double imaginaryPart;

    // 
    double polarRealPart;
    double polarPhiPart;

public:
    ComplexNumber(double a, double b) : realPart(a), imaginaryPart(b)
    {
        calculatePolarValues();
    }

    std::string toCartesianString();
    std::string toPolarString();

    /* Carthesian */
    void updateValue(double real, double imaginary);
    void updateRealPart(double real);
    void updateImaginaryPart(double imaginary);

    /* Polar */
    void updateValuePolar(double polar, double phi);
    void updateRealPartPolar(double polar);
    void updatePhipartPolar(double phi);


private:
    void calculatePolarValues();
    void calculateCarthesianValues();
};

#endif