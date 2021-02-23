#include <iostream>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"

void testBaseClassCall(Graph* graph) {
    std::cout << graph->calcCircumference() << std::endl;
}

int main()
{
    // Aufgabe 1 - 3
    Circle c1 = Circle(1, Coordinate(0, 0));
    Rectangle r1 = Rectangle(Coordinate(1, 1), Coordinate(0, 0));
    std::cout << c1.toString() << std::endl;
    std::cout << r1.toString() << std::endl;

    // Aufgabe 1 - 3
    Circle c2 = Circle(2);
    Rectangle r2 = Rectangle(Coordinate(2, 2));
    std::cout << c2.toString() << std::endl;
    std::cout << r2.toString() << std::endl;

    // Aufgabe 4
    // Ja, es ist Sinnvoll, da der Konstuktor nicht von außen aufgerufen werden kann.
    // Nur Klassen, die von Graph erben können den Kontruktor verwenden.
    // Die Klasse Graph soll nicht alleinstehend instatziert werden können.
    //Graph(Coordinate(1, 1));
    // ^ funktioniert nicht, da protected. Soll aber so ;)

    // Aufgabe 5
    auto* g = new Circle(1);
    testBaseClassCall(g);

    // Aufgabe 6
    char option = 'q';
    std::vector<Graph*> list = std::vector<Graph*>();
    do {
        std::cout << "q - Quit" << std::endl;
        std::cout << "n - New Graph" << std::endl;
        std::cout << "v - View Graphs" << std::endl;

        std::cin >> option;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (option) {
            case 'q': {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            case 'v': {
                char viewOption = 'b';
                do {
                    std::cout << "m - view mixed, sorted by creation order" << std::endl;
                    std::cout << "s - view separated, circles first" << std::endl;
                    std::cout << "b - back" << std::endl;
                    std::cin >> viewOption;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    switch(viewOption) {
                        case 'm': {
                            std::cout << "Exciting, we have " + std::to_string(list.size()) + " graphs to view:" << std::endl;
                            float totalCircumference = 0;
                            for (auto & it : list) {
                                std::cout << "    " + it->toString() << std::endl;
                                totalCircumference += it->calcCircumference();
                            }
                            std::cout << "Total circumference: " + std::to_string(totalCircumference) + "." << std::endl;
                            break;
                        }
                        case 's': {
                            std::cout << "Exciting, we have " + std::to_string(list.size()) + " graph(s) to view:" << std::endl;
                            float totalCircumference = 0;
                            for (auto & it : list) {
                                if (dynamic_cast<Circle*>(it)) {
                                    std::cout << "    " + it->toString() << std::endl;
                                    totalCircumference += it->calcCircumference();
                                }
                            }
                            std::cout << "Total *circle* circumference: " + std::to_string(totalCircumference) + "." << std::endl;

                            totalCircumference = 0;
                            for (auto & it : list) {
                                if (dynamic_cast<Rectangle*>(it)) {
                                    std::cout << "    " + it->toString() << std::endl;
                                    totalCircumference += it->calcCircumference();
                                }
                            }
                            std::cout << "Total *rectangle* circumference: " + std::to_string(totalCircumference) + "." << std::endl;
                            break;
                        }
                        default: {
                            std::cout << "Invalid option." << std::endl;
                        }
                    }
                } while (viewOption != 'b');
                break;
            }
            case 'n': {
                char graphOption = 'b';
                do {
                    std::cout << "c - new circle" << std::endl;
                    std::cout << "r - new rectangle" << std::endl;
                    std::cout << "b - back" << std::endl;
                    std::cin >> graphOption;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    switch(graphOption) {
                        case 'c': {
                            std::cout << "Please enter origin x, origin y and radius (space separated, eg. '0 0 1'):" << std::endl;
                            float r, x, y;
                            std::cin >> x >> y >> r;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            list.push_back(new Circle(r, Coordinate(x, y)));
                            std::cout << "Added. *boom*" << std::endl;
                            break;
                        }
                        case 'r': {
                            std::cout << "Please enter origin and spanning corner as coordinates (space separated, eg. '0 0 1 1'):" << std::endl;
                            float x1, y1, x0, y0;
                            std::cin >> x1 >> y1 >> x0 >> y0;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            list.push_back(new Rectangle(Coordinate(x1, y1), Coordinate(x0, y0)));
                            std::cout << "Added. *shroom*" << std::endl;
                            break;
                        }
                        default: {
                            std::cout << "Invalid option." << std::endl;
                        }
                    }
                } while (graphOption != 'b');
                break;
            }
            default: {
                std::cout << "Invalid option." << std::endl;
            }
        }
        for (int n = 0; n < 10; n++) {
            std::cout << std::endl;
        }
    } while (option != 'q');
    return 0;
}
