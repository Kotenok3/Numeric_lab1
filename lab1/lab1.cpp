#include <iostream>


double Fun(double x) {

    return 3.3 * x * x * x * x + 3 / (0.02 + x * x);
}

void Print(double esp, double point, int counter){

    std::cout << "Eps = " << esp << "\nPoint min = " << point << "\nFunction value to min point "<< Fun(point) << "\nCounter = " << counter << std::endl;
}

void Dichotomy(double esp, double a,double b){
    int counter = 0; double x1,x2;

    while ((b - a) / 2 > esp) {
        x1 = (a + b - esp) / 2;
        x2 = (a + b + esp) / 2;

        if (Fun(x1) <= Fun(x2)) 
            b = x2;
        else 
            a = x1;
        
        counter++;
    }

    Print(esp,(a+b)/2,counter);
    
}

int main()
{
    std::cout << Fun(0) << std::endl;

    std::cout << "Input interval" << std::endl;
    double a, b;
    std::cin >> a >> b;
    double esp1 = 0.001;
    double esp2 = 0.0001;

    std::cout << "Metod Dichotomy" << std::endl;
    Dichotomy(esp1,a,b);
    std::cout << "\n\n";
    Dichotomy(esp2,a,b);
    

}

