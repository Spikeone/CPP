#include "includes.h"

std::string ComplexNumber::toCartesianString()
{
    return cartasian.toString();
}

std::string ComplexNumber::toPolarString()
{
    return polar.toString();
}

void ComplexNumber::update(CartasianData data)
{
    cartasian = data;
    polar.updateValues(data);
}

void ComplexNumber::update(PolarData data)
{
    polar = data;
    cartasian.updateValues(data);
}

ComplexNumber::ComplexNumber(PolarData data)
{
    update(data);
}

ComplexNumber::ComplexNumber(CartasianData data)
{
    update(data);
}
