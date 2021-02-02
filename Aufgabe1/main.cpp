#include <iostream>
#include <string>
#include <random>
#include "Taxi.h"

int main()
{
    const int MAX_TAXI = 2;

    Taxi taxis[MAX_TAXI];

    // https://stackoverflow.com/a/19728404
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> km(0, 10000); // guaranteed unbiased
    std::uniform_int_distribution<float> verbrauch(70, 100);
    std::uniform_int_distribution<float> fahrpreisKm(200, 350);
    std::uniform_int_distribution<int> maxTankInhalt(60, 80);

    for (int i = 0; i < MAX_TAXI; i++)
    {
        taxis[i].init(
                km(rng),
                verbrauch(rng) / 10,
                fahrpreisKm(rng) / 100,
                maxTankInhalt(rng),
                "Taxi" + std::to_string(i + 1));
    }

    char input = '0';
    short taxiID = -1;

    do
    {
        switch (input)
        {
        case '0':
        {
            std::cout << "Verfuegbare Taxis: " << std::endl;
            for (int i = 0; i < MAX_TAXI; i++)
                std::cout << (i + 1) << ": " << taxis[i].getName() << std::endl;
            std::cout << std::endl;
            std::cout << "Taxiauswahl: ";

            std::cin >> taxiID;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            taxiID -= 1;

            if (taxiID < 0 || taxiID >= MAX_TAXI || std::cin.fail())
            {
                std::cout << "Ungueltige Taxi ID!" << std::endl << std::endl;
                taxiID = -1;
                continue;
            }
        }break;
        case '1':
        {
            float distance = 0.f;
            int passengers = 0;

            std::cout << "Distanz: ";
            std::cin >> distance;
            if (std::cin.fail())
            {
                std::cout << "Ungueltige Angabe!" << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            
            std::cout << "Passagiere: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> passengers;
            if (std::cin.fail())
            {
                std::cout << "Ungueltige Angabe!" << std::endl << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            taxis[taxiID].fahrtVerbuchen(distance, passengers > 0);
            std::cout << "Fahrt wurde verbucht!" << std::endl << std::endl;

        }break;
        case '2':
        {
            float preisL = 0.f;
            std::cout << "Preis je Liter: ";
            std::cin >> preisL;
            if (std::cin.fail())
            {
                std::cout << "Ungueltige Angabe!" << std::endl << std::endl;
            }
            else
            {
                taxis[taxiID].tanken(preisL);
                std::cout << "Fahrzeug voll betankt!" << std::endl << std::endl;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }break;
        case '3':
        {
            taxis[taxiID].ausgabe();
        }break;
        default:
        {
            std::cout << "Ungueltige Option!" << std::endl;
        }
        }

        std::cout << "Hauptmenue (" << taxis[taxiID].getName() << ")" << std::endl;
        std::cout << "x: Beenden" << std::endl;
        std::cout << "0: Taxi wechseln" << std::endl;
        std::cout << "1: Fahrt verbuchen" << std::endl;
        std::cout << "2: Tanken" << std::endl;
        std::cout << "3: Ausgabe" << std::endl;
        std::cout << "Optionsauswahl: ";
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (input != 'x');

    std::cout << "Beehren Sie uns bald wieder!" << std::endl;

    return 0;
}
