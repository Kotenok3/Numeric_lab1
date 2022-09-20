// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


double Fun(double x) {

    return 3.3 * x * x * x * x + 3 / (0.02 + x * x);
}

int main()
{
    std::cout << Fun(0) << std::endl;

    std::cout << "Input interval" << std::endl;
    double a, b;
    std::cin >> a >> b;
    double x1,x2;
    double esp1 = 0.001;
    double esp2 = 0.0001;
    int counter1 = 0; double counter2 = 0;
    double a1 = a; double a2 = a;
    double b1 = b; double b2 = b;

    while ((b1 - a1) / 2 > esp1) {
        x1 = (a1 + b1 - esp1) / 2;
        x2 = (a1 + b1 + esp1) / 2;

        if (Fun(x1) <= Fun(x2)) {
            a1 = a1;
            b1 = x2;
        }
        else {
            a1 = x1;
            b1 = b1;
        }
        counter1++;
    }

    while ((b2 - a2) / 2 > esp2) {
        x1 = (a2 + b2 - esp2) / 2;
        x2 = (a2 + b2 + esp2) / 2;

        if (Fun(x1) <= Fun(x2)) {
            a2 = a2;
            b2 = x2;
        }
        else {
            a2 = x1;
            b2 = b2;
        }
        counter2++;
    }



    std::cout << "Eps = " << esp1 << "\nPoint min = " << (a1 + b1) / 2 << "\nFunction value to min point "<< Fun((a1 + b1) / 2) << "\nCounter = " << counter1 << std::endl;
    std::cout << "\n\n";
    std::cout << "Eps = " << esp2 << "\nPoint min = " << (a2 + b2) / 2 << "\nFunction value to min point " << Fun((a2 + b2) / 2) << "\nCounter = " << counter2 << std::endl;


}

