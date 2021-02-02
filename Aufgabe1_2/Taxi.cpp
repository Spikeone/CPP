#include "Taxi.h"
#include <iostream>

/* PUBLIC */
void Taxi::init(float km, float verbrauch, float fahrpreisKM, float maxTankInhalt, std::string name)
{
    this->kilometerStand = km;
    this->verbrauchKM = verbrauch * 0.01;
    this->fahrpreisKM = fahrpreisKM;
    this->maxTankInhalt = maxTankInhalt;
    this->tankInhalt = this->maxTankInhalt;
    this->bilanz = 0;
    this->name = name;
}

bool Taxi::fahrtVerbuchen(float distanz, bool passagiere)
{
    bool gefahren = false;

    if (this->hatBenzinFuerStrecke(distanz))
    {
        this->kilometerStand += distanz;
        this->tankInhalt -= this->benzinFuerStrecke(distanz);
        
        if (passagiere)
            this->bilanz += distanz * this->fahrpreisKM;

        gefahren = true;
    }

    return gefahren;
}

void Taxi::tanken(float preisL)
{
    this->bilanz -= (this->maxTankInhalt - this->tankInhalt) * preisL;
    this->tankInhalt = this->maxTankInhalt;
}

void Taxi::ausgabe()
{
    std::cout << "=== " << this->name.c_str() << " ===" << std::endl;
    std::cout << "Kilometerstand: " << this->kilometerStand << std::endl;
    std::cout << "Tankinhalt:     " << this->tankInhalt << "/" << this->maxTankInhalt << std::endl;
    std::cout << "Geldbilanz:     " << this->bilanz << std::endl << std::endl;
}

/* PRIVATE */
float Taxi::benzinFuerStrecke(float distanz)
{
    return distanz * this->verbrauchKM;
}

bool Taxi::hatBenzinFuerStrecke(float distanz)
{
    return this->tankInhalt >= this->benzinFuerStrecke(distanz);
}