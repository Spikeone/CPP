#include "includes.h"
#include "ComplexNumber.h"


int ComplexNumber::instanceCount = 0;

std::string ComplexNumber::toCartesianString() const
{
    return cartasian.toString();
}

std::string ComplexNumber::toPolarString() const
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

// Aufgabe 5: hier könnte man die Initialisierungsliste verwenden, ergibt aber für unseren Anwendungsfall keinen Sinn,
//     da wir jeweils die update Funktion aufrufen. unten analog
ComplexNumber::ComplexNumber(PolarData data)
{
    instanceCount++;
    update(data);
}

ComplexNumber::ComplexNumber(CartasianData data)
{
    instanceCount++;
    update(data);
}

ComplexNumber::~ComplexNumber() {
    instanceCount--;
}
