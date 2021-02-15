//
// Created by paul on 13.02.21.
//

#ifndef POLARDATA_H
#define POLARDATA_H

#include "CartasianData.h"

class PolarData
{
private:
    double realPart = 0;
    double phiPart = 0;

public:
    PolarData() {};
    PolarData(double real, double phi) : realPart(real), phiPart(phi) { }
    PolarData(CartasianData data);

    double getRealPart() const {
        return realPart;
    }

    double getPhiPart() const {
        return phiPart;
    }

    void setValues(double real, double phi);
    void setRealPart(double real);
    void setPhiPart(double phi);
    void updateValues(CartasianData data);

    std::string toString() const;
};

#endif //POLARDATA_H
