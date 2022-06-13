#include <iostream>
using namespace std;

int lerNum(const string& msg);
int extrairDigito(int num, int dig);
int extrairNumero(int num);
int calcularDigito(int num);
int verificarDigitoCorreto(int num);

int main()
{
    int n, dig;
    n = lerNum("Digite um numero entre 10000 e 99999: ");
    cout << "O numero digitado foi: " << n << endl;
    dig = n % 10;
    if (dig == verificarDigitoCorreto(calcularDigito(extrairNumero(extrairDigito(n, dig)))))
        cout << "O digito esta correto\n";
    else
        cout << "O digito esta errado\n";
    system("pause");
    system("cls");
}

int lerNum(const string& msg)
{
    int num;
    cout << msg;
    cin >> num;
    return num;
}

int extrairDigito(int num, int dig)
{
    int u, d, c, m;
    u = (num % 100 - dig) / 10;
    d = (num % 1000 - u) / 100;
    c = (num % 10000 - d) / 1000;
    m = (num % 100000 - c) / 10000;
    cout << "Os digitos verificadores sao: " << m << ", " << c << ", " << d << " e " << u << endl;
    return (2 * u + 3 * d + 4 * c + 5 * m);
}

int extrairNumero(int num)
{
    return num % 11;
}

int calcularDigito(int num)
{
    return 11 - num;
}

int verificarDigitoCorreto(int num)
{
    if ((num == 10 || num == 11))
        num = 0;
    cout << "O digito verificador e: " << num << endl;
    return num;
}
