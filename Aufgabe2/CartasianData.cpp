//
// Created by paul on 13.02.21.
//

#include <cmath>
#include "CartasianData.h"

CartasianData::CartasianData(PolarData data) {
    updateValues(data);
}

void CartasianData::setValues(double real, double imaginary) {
    setRealPart(real);
    setImaginaryPart(imaginary);
}

void CartasianData::setRealPart(double real) {
    realPart = real;
}

void CartasianData::setImaginaryPart(double imaginary) {
    imaginaryPart = imaginary;
}

void CartasianData::updateValues(PolarData data) {
    realPart = data.getRealPart() * std::cos(data.getPhiPart());
    imaginaryPart = data.getRealPart() * std::sin(data.getPhiPart());
}
