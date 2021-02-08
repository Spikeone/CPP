#include "Taxi.h"
#include <iostream>
#include <sstream>

/* PUBLIC */
void Taxi::init(float km, float verbrauch, float fahrpreisKM, float maxTankInhalt, std::string name)
{
    // Input: initialer Kilometerstand, Verbrauch, Fahrpreis, maximaler Tankinhalt
    // => Kilometerstand wird nicht mit 0 intialisiert!
    this->kilometerStand = km;
    this->verbrauchKM = verbrauch * 0.01f;
    this->fahrpreisKM = fahrpreisKM;
    this->maxTankInhalt = maxTankInhalt;
    // Tankinhalt ist max!
    this->tankInhalt = this->maxTankInhalt;
    this->bilanz = 0;
    this->name = name;
}

bool Taxi::fahrtVerbuchen(float distanz, bool passagiere)
{
    if (distanz <= 0.f)
        return false;

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

bool Taxi::tanken(float preisL)
{
    if (preisL <= 0.f)
        return false;

    if (this->bilanz <= 0.f)
        return false;

    float fLiterBenoetigt = this->maxTankInhalt - this->tankInhalt;
    float fGeldBenoetigt = fLiterBenoetigt * preisL;

    if (fGeldBenoetigt > this->bilanz)
    {
        this->tankInhalt += this->bilanz / preisL;
        this->bilanz = 0;
    }
    else
    {
        this->tankInhalt = this->maxTankInhalt;
        this->bilanz -= fGeldBenoetigt;
    }

    return true;
}

std::string Taxi::ausgabe()
{
    std::ostringstream ostream;

    ostream << "=== " << this->name.c_str() << " ===" << std::endl;
    ostream << "Kilometerstand: " << this->kilometerStand << std::endl;
    ostream << "Tankinhalt:     " << this->tankInhalt << "/" << this->maxTankInhalt << std::endl;
    ostream << "Geldbilanz:     " << this->bilanz << std::endl;
    
    return ostream.str();
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