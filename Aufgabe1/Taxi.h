#pragma once

#ifndef TAXI_H
#define TAXI_H

#include <iostream>

class Taxi
{
public:
    void init(float km, float verbrauch, float fahrpreisKM, float maxTankInhalt, std::string name);
    bool fahrtVerbuchen(float distanz, bool passagiere);
    void tanken(float preisL);
    void ausgabe();
    std::string getName() { return this->name; }

private:
    float kilometerStand; // in KM
    float tankInhalt; // in L
    float verbrauchKM; // in €
    float fahrpreisKM; // in €
    float maxTankInhalt; // in L
    float bilanz; // in €
    std::string name;

    float benzinFuerStrecke(float /*distanz*/);
    bool hatBenzinFuerStrecke(float /*distanz*/);
};

#endif // !TAXI_H
