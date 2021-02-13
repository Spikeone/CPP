#pragma once

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#define _USE_MATH_DEFINES

#include<string>
#include "PolarData.h"
#include "CartasianData.h"

class ComplexNumber
{
public:
    PolarData polar;
    CartasianData cartasian;

public:
    ComplexNumber(const PolarData data);

    ComplexNumber(const CartasianData data);

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