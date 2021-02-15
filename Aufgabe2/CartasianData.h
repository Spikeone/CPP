//
// Created by paul on 13.02.21.
//

#ifndef CARTASIANDATA_H
#define CARTASIANDATA_H

#include "includes.h"
class PolarData;

class CartasianData
{
private:
    double realPart = 0;
    double imaginaryPart = 0;

public:
    CartasianData() {}
    CartasianData(PolarData data);
    CartasianData(double a, double b) : realPart(a), imaginaryPart(b) {}


    double getRealPart() const {
        return realPart;
    }

    double getImaginaryPart() const {
        return imaginaryPart;
    }

    void setValues(double real, double imaginary);
    void setRealPart(double real);
    void setImaginaryPart(double imaginary);
    void updateValues(PolarData data);

    std::string toString();
};


#endif //CARTASIANDATA_H
