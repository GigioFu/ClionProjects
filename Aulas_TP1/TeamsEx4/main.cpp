/* ==================================================================================
 *                          Exerício 04 da lista no Teams
 *                     Aluno: Geovane Otávio Marques Rodrigues;
 *                     Matrícula: 2021.1.0033.0061-4
 * ==================================================================================
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class equacao2Grau
{
private:
    int a, b, c;
public:
    equacao2Grau()
    {
        a = b = c = 0.0;
    }
    ~equacao2Grau() = default;
    void setEquacao(int n1, int n2, int n3);
    void setEquacao(float n1, float n2, float n3);
    void getEquacao();
    double calcularaiz();
    void calculaValores();
};

class testaEquacao2Grau
{
private:
    equacao2Grau obj1;
public:
    void menu()
    {
        float n1, n2, n3;
        cout << "Equacao de 2Grau eh ax^2 + bx + c = 0, assim digite os valores de:";
        cout << "\n      a =";
        cin >> n1;
        cout << "      b =";
        cin >> n2;
        cout << "      c =";
        cin >> n3;
        if (n1 == 0)
            cout << "\nComo a = 0, não é uma equacao de 2Grau.";
        else
        {
            obj1.setEquacao(n1, n2, n3);
            cout << "\nCaso o valor da raiz seja inferior a 0, serah atribuido 0;\n\n";
            cout << "Com esses valores atribuidos, a equacao serah =\n\t";
            obj1.getEquacao();
            cout << ".\t\tA raiz dessa equacao eh = " << obj1.calcularaiz() << endl;
            obj1.calculaValores();
        }
        cout << "\nEncerrando programa!\n";
    }
};

int main()
{
    cout << fixed << setprecision(2);
    testaEquacao2Grau tst;
    tst.menu();
}
void equacao2Grau::setEquacao(int n1, int n2, int n3)
{
    a = n1;
    b = n2;
    c = n3;
}
void equacao2Grau::setEquacao(float n1, float n2, float n3)
{
    a = n1;
    b = n2;
    c = n3;
}
void equacao2Grau::getEquacao()
{
    cout << a << "x^2 + (" << b << "x) + (" << c << ") = 0";
}
double equacao2Grau::calcularaiz()
{
    double result = (b * b) - (4 * a * c);
    if (result <= 0)
        return 0;
    return sqrt(result);
}
void equacao2Grau::calculaValores()
{
    cout << "\nPrimeiro. valor = " << (-b + calcularaiz()) / (2 * a) << endl;
    cout << "Segundo. valor =  " << (-b - calcularaiz()) / (2 * a) << endl;
}
