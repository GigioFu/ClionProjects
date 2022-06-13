#include <iostream>
using namespace std;

class calculadora
{
private:
    double a, b;
public:
    calculadora()
    {
        a = b = 0.0;
    }
    ~calculadora() = default;
    void setA(double n);
    void setB(double n);
    double getA()const;
    double getB()const;
    double somar()const;
    double subtrair()const;
    double multiplicar()const;
    double dividir()const;
};
void calculadora::setA(double n)
{
    a = n;
}
void calculadora::setB(double n)
{
    b = n;
}
double calculadora::getA()const
{
    return a;
}
double calculadora::getB()const
{
    return b;
}
double calculadora::somar()const
{
    return a + b;
}
double calculadora::subtrair()const
{
    return a - b;
}
double calculadora::multiplicar()const
{
    return a * b;
}
double calculadora::dividir()const
{
    if (b == 0)
        throw ("Divisão por 0!");
    else
        return a / b;
}

class testaCalculadora
{
private:
    calculadora calc;
public:
    void menu()
    {
        double n1, n2;
        unsigned int tp;
        do
        {
            cout << "Digite um valor para a: ";
            cin >> n1;
            calc.setA(n1);
            cout << "Digite um valor para b: ";
            cin >> n2;
            calc.setB(n2);
            cout << "Opcoes:\n";
            cout << "\t1 - SOMAR\n\t2 - SUBTRAIR\n\t3 - MULTIPLICAR\n\t4 - DIVIDIR\n\t5 - ENCERRAR\nOpcao: ";
            cin >> tp;
            try
            {
                switch (tp)
                {
                    case 1:
                        cout << calc.getA() << " + " << calc.getB() << " = " << calc.somar();
                        break;
                    case 2:
                        cout << calc.getA() << " - " << calc.getB() << " = " << calc.subtrair();
                        break;
                    case 3:
                        cout << calc.getA() << " * " << calc.getB() << " = " << calc.multiplicar();
                        break;
                    case 4:
                        cout << calc.getA() << " / " << calc.getB() << " = " << calc.dividir();
                        break;
                    case 5:
                        cout << "Encerrando programa!!" << endl;
                        break;
                }
                cout << endl;
            }
            catch (string msg)
            {
                cout << "Erro por: " << msg << endl;
            }
        } while (tp >= 1 && tp < 5);
    }
};

int main()
{
    testaCalculadora *test = new class testaCalculadora;
    test ->menu();
}
