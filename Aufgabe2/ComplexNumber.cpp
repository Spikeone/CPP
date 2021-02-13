#include "ComplexNumber.h"
#include <cmath>

std::string ComplexNumber::toCartesianString()
{
    return "z = " + std::to_string(realPart) + " + " + std::to_string(imaginaryPart) + "i";
}

std::string ComplexNumber::toPolarString()
{
    return "z = " + std::to_string(polarRealPart) + "*e^(i*" + std::to_string(polarPhiPart) + ")";
}

void ComplexNumber::calculatePolarValues()
{
    polarRealPart = std::sqrt(std::pow(realPart, 2) + std::pow(imaginaryPart, 2)); ;

    if (realPart < 0 && imaginaryPart < 0)
        polarPhiPart = std::atan(imaginaryPart / realPart) - M_PI;
    else if (realPart == 0 && imaginaryPart < 0)
        polarPhiPart = M_PI / -2;
    else if (realPart == 0 && imaginaryPart > 0)
        polarPhiPart = M_PI / 2;
    else if (realPart < 0 && imaginaryPart >= 0)
        polarPhiPart = std::atan(imaginaryPart / realPart) + M_PI;
    else
        polarPhiPart = std::atan(imaginaryPart / realPart);
}

void ComplexNumber::calculateCarthesianValues()
{
    realPart = polarRealPart * std::cos(polarPhiPart);
    imaginaryPart = polarRealPart * std::sin(polarPhiPart);
}

void ComplexNumber::updateValue(double real, double imaginary)
{
    realPart = real;
    imaginaryPart = imaginary;
    calculatePolarValues();
}

void ComplexNumber::updateRealPart(double real)
{
    updateValue(real, imaginaryPart);
}

void ComplexNumber::updateImaginaryPart(double imaginary)
{
    updateValue(realPart, imaginary);
}

void ComplexNumber::updateValuePolar(double polar, double phi)
{
    polarRealPart = polar;
    polarPhiPart = phi;
    calculateCarthesianValues();
}

void ComplexNumber::updateRealPartPolar(double polar)
{
    updateValuePolar(polar, polarPhiPart);
}

void ComplexNumber::updatePhipartPolar(double phi)
{
    updateValuePolar(polarRealPart, phi);
}

ComplexNumber::ComplexNumber(const PolarData data)
{
    cartasian = CartasianData(data);
}
