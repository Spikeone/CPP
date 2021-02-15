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

// Aufgabe 5: hier könnte man die Initialisierungsliste verwenden, ergibt aber für unseren Anwendungsfall keinen Sinn,
//     da wir jeweils die update Funktion aufrufen. unten analog
ComplexNumber::ComplexNumber(PolarData data)
{
    update(data);
}

ComplexNumber::ComplexNumber(CartasianData data)
{
    update(data);
}
