#include <iostream>

double lePositivo();
double area(double a, double b);
double per(double a, double b);

int main() {
    do {
        double a, b;
        std::cout << "Defina o valor da BASE do retangulo:\n";
        b = lePositivo();
        std::cout << "\nDefina o valor da ALTURA do retangulo:\n";
        a = lePositivo();

        std::cout << "A area do retangulo e de " << area(a, b) << "u.a. e o perimetro e de " << per(a, b) << "u.p.\n";
        std::cout << "----------------------------------------------------------------------\n";
    } while (true);
}

double lePositivo() {
    double num;
    do {
        std::cout << "Digite um numero positivo: ";
        std::cin >> num;
    } while (num <= 0);
    return num;
}

double area(double a, double b) {
    return b * a;
}

double per(double a, double b) {
    return 2 * (a + b);
}
