//
// Created by paul on 13.02.21.
//

#include <cmath>
#include "includes.h"

PolarData::PolarData(CartasianData data) {
    updateValues(data);
}

void PolarData::setValues(double real, double phi) {
    setRealPart(real);
    setPhiPart(phi);
}

void PolarData::setRealPart(double real) {
    realPart = real;
}

void PolarData::setPhiPart(double phi) {
    phiPart = phi;
}

void PolarData::updateValues(CartasianData data) {
    double cartasianImaginaryPart = data.getImaginaryPart();

    realPart = std::sqrt(std::pow(data.getRealPart(), 2) + std::pow(cartasianImaginaryPart, 2)); ;

    if (realPart < 0 && cartasianImaginaryPart < 0)
        phiPart = std::atan(cartasianImaginaryPart / realPart) - M_PI;
    else if (realPart == 0 && cartasianImaginaryPart < 0)
        phiPart = M_PI / -2;
    else if (realPart == 0 && cartasianImaginaryPart > 0)
        phiPart = M_PI / 2;
    else if (realPart < 0 && cartasianImaginaryPart >= 0)
        phiPart = std::atan(cartasianImaginaryPart / realPart) + M_PI;
    else
        phiPart = std::atan(cartasianImaginaryPart / realPart);
}

std::string PolarData::toString() const {
    return "z = " + std::to_string(realPart) + "*e^(i*" + std::to_string(phiPart) + ")";
}
