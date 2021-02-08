#include <iostream>
#include "ComplexNumber.h"

int main()
{
    ComplexNumber cnumber = ComplexNumber(10, 20);
    ComplexNumber cnumber2(10, 20);
    ComplexNumber cnumber3 = ComplexNumber(cnumber);
    ComplexNumber cnumber4(cnumber);
    ComplexNumber *cnumber5 = new ComplexNumber(10, 20);
    ComplexNumber *cnumber6(&cnumber);

    std::cout << "1: " << cnumber.toCartesianString() << std::endl;
    std::cout << "1: " << cnumber.toPolarString() << std::endl;
    std::cout << "2: " << cnumber2.toCartesianString() << std::endl;
    std::cout << "2: " << cnumber2.toPolarString() << std::endl;
    std::cout << "3: " << cnumber3.toCartesianString() << std::endl;
    std::cout << "3: " << cnumber3.toPolarString() << std::endl;
    std::cout << "4: " << cnumber4.toCartesianString() << std::endl;
    std::cout << "4: " << cnumber4.toPolarString() << std::endl;
    std::cout << "5: " << cnumber5->toCartesianString() << std::endl;
    std::cout << "5: " << cnumber5->toPolarString() << std::endl;
    std::cout << "6: " << cnumber6->toCartesianString() << std::endl;
    std::cout << "6: " << cnumber6->toPolarString() << std::endl;

    ComplexNumber tester = ComplexNumber(10, 20);
    std::cout << "tester: " << tester.toCartesianString() << std::endl;
    std::cout << "tester: " << tester.toPolarString() << std::endl;

    ComplexNumber tester2 = ComplexNumber(30, 60);
    tester2.updateValuePolar(22.36, 1.107);
    std::cout << "tester2: " << tester2.toCartesianString() << std::endl;
    std::cout << "tester2: " << tester2.toPolarString() << std::endl;



    return 0;
}