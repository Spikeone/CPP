#pragma once

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include "includes.h"

class ComplexNumber
{
public:
    PolarData polar;
    CartasianData cartasian;

public:
    explicit ComplexNumber(PolarData data);

    explicit ComplexNumber(CartasianData data);

    std::string toCartesianString() const;
    std::string toPolarString() const;

    void update(PolarData data);
    void update(CartasianData data);
};

#endif
