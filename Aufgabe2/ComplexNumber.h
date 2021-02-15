#pragma once

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include<string>
#include "PolarData.h"
#include "CartasianData.h"

class ComplexNumber
{
public:
    PolarData polar;
    CartasianData cartasian;

public:
    explicit ComplexNumber(PolarData data);

    explicit ComplexNumber(CartasianData data);

    std::string toCartesianString();
    std::string toPolarString();

    void update(PolarData data);
    void update(CartasianData data);
};

#endif
