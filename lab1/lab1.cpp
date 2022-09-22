#include <iostream>


double FunA(double x) {

    return 3.3 * x * x * x * x + 3 / (0.02 + x * x);
}

double FunB(double x) {

    return  2.7 * std::pow(std::sin(x), 3) + 3.3 * std::pow(std::cos(x), 3);
}

void Print(std::string name,double esp, double point, int counter){

    std::cout << "Method " << name << std::endl;
    std::cout << "Eps = " << esp << "\nPoint min = " << point << "\nFunction value to min point "<< FunA(point) << "\nCounter = " << counter << std::endl;
}

void Dichotomy(double esp, double a,double b, double delta = 0.001){
    int counter = 0; double x1,x2;

    while ((b - a) / 2 > esp) {
        x1 = (a + b - delta) / 2;
        x2 = (a + b + delta) / 2;

        if (FunA(x1) <= FunA(x2)) 
            b = x2;
        else 
            a = x1;
        
        counter++;
    }

    Print("Dichotomy", esp, (a + b) / 2, counter);
}

void GoldenSection(double esp, double a, double b) {
    int counter = 0; double x1, x2;

    while ((b - a) / 2 > esp) {
        x1 = a + (3 - std::sqrt(5)) * (b - a) / 2;
        x2 = a + (std::sqrt(5) - 1) * (b - a) / 2;

        if (FunA(x1) <= FunA(x2))
            b = x2;
        else
            a = x1;

        counter++;
    }

    Print("GoldenSection", esp, (a + b) / 2, counter);
}

int main()
{
    std::cout << "Input interval" << std::endl;
    double a, b;
    std::cin >> a >> b;
    double esp1 = 0.001;
    double esp2 = 0.0001;

    Dichotomy(esp1, a, b, esp1);
    std::cout << "\n\n";
    Dichotomy(esp2, a, b, esp2);
    std::cout << "\n\n";
    GoldenSection(esp1, a, b);
    std::cout << "\n\n";
    GoldenSection(esp2, a, b);
    
    return 0;
}

