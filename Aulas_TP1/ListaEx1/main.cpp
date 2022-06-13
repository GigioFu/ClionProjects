#include <iostream>
using namespace std;

int lerPositivo(const string& msg);
void tipoTiangulo(int a, int b, int c);

int main()
{
    int flag, a, b, c;
    flag = lerPositivo("Quantas vezes deseja repetir esse programa?\n");
    for (int i = 0; i < flag; i++)
    {
        a = lerPositivo("Qual o valor do lado 'a' do triangulo?\n");
        b = lerPositivo("Qual o valor do lado 'b' do triângulo?\n");
        c = lerPositivo("Qual o valor do lado 'c' do triângulo?\n");
        tipoTiangulo(a, b, c);
        system("pause");
    }
}

int lerPositivo(const string& msg)
{
    int num;
    do
    {
        cout << msg << "\n(Insira um numero positivo): ";
        cin >> num;
    }
    while (num < 0);
    system("cls");
    return num;
}

void tipoTiangulo(int a, int b, int c)
{
    // O trângulo exite?
    if ((a + b < c) || (a + c < b) || (b + c < a))
        cout << "Esse triangulo nao existe!\n";
    else
    {
        if (a != b & a != c & b != c)
            cout << "Triangulo Escaleno!\n";
        else if ((a == b & a != c) || (a == c & a != b) || (b == c & b != a))
            cout << "Triangulo isosceles!\n";
        else if (a == b & a == c & b == c)
            cout << "Triangulo equilatero!\n";
    }
}
