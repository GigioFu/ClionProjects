/* ==================================================================================
 *                          Exerício 01 da lista no Teams
 *                     Aluno: Geovane Otávio Marques Rodrigues;
 *                     Matrícula: 2021.1.0033.0061-4
 * ==================================================================================
 */

#include <iostream>

using namespace std;

int mdc(int n1, int n2);

class fracao
{
private:
    int numerador, denominador;
public:
    fracao()
    {
        numerador = denominador = 1;
    }
    ~fracao() = default;
    void setNumerador(int n);
    int getNumerador();
    void setDenominador(int n);
    int getDenominador();
    int soma();
    int subtracao();
    float divide();
    int multiplica();
    int maxdiv();
    void simplifica();
};

class testaFracao
{
private:
    fracao obj;
public:
    void menu()
    {
        int n1, n2, opc;
        do
        {
            cout << "Digite um numero:";
            cin >> n1;
            cout << "Digite outro numero:";
            cin >> n2;
            obj.setNumerador(n1);
            obj.setDenominador(n2);
            cout << "\nOpcoes:\n";
            cout << "\n\t[1] - somar\n\t[2] - subtrair\n\t[3] - dividir\n\t[4] - multiplicar\n\t";
            cout << "[5] - mostrar MDC\n\t[6] - simplificar a fracao\n\t[7] - encerrar programa\n\n";
            cout << "Opcao:";
            cin >> opc;
            switch (opc)
            {
                case 1:
                    cout << "A soma vale: " << obj.soma();
                    break;
                case 2:
                    cout << "A subtracao vale: " << obj.subtracao();
                    break;
                case 3:
                    cout << "A divisao vale: " << obj.divide();
                    break;
                case 4:
                    cout << "A multiplicacao vale: " << obj.multiplica();
                    break;
                case 5:
                    cout << "O MDC eh: " << obj.maxdiv();
                    break;
                case 6:
                    cout << "a versao simplificada da fracao eh: ";
                    obj.simplifica();
                    break;
                default:
                    opc = 7;
            }
            cout << endl;
        } while (opc > 0 and opc < 7);
    }
};

int main()
{
    testaFracao mn;
    mn.menu();
}

void fracao::setNumerador(int n)
{
    numerador = n;
}
void fracao::setDenominador(int n)
{
    denominador = n;
}
int fracao::getNumerador()
{
    return numerador;
}
int fracao::getDenominador()
{
    return denominador;
}
int fracao::soma()
{
    return numerador + denominador;
}
int fracao::subtracao()
{
    return numerador - denominador;
}
float fracao::divide()
{
    try
    {
        if (denominador == 0)
            throw ("Divisão por 0");
        else
            return float (numerador) / float (denominador);
    }
    catch (string msg)
    {
        cout << "Erro por : " << msg << endl;
        return 0;
    }
}
int fracao::multiplica()
{
    return numerador * denominador;
}
int fracao::maxdiv()
{
    return mdc(numerador, denominador);
}
void fracao::simplifica()
{
    cout << (numerador / maxdiv()) << " / " << (denominador / maxdiv());
}

int mdc(int n1, int n2)
{
    if (n1%n2 == 0){
        return n2;
    }else{
        return mdc(n2,n1 % n2);
    }
}
