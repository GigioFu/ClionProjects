/* ==================================================================================
 *                          Exerício 02 da lista no Teams
 *                     Aluno: Geovane Otávio Marques Rodrigues;
 *                     Matrícula: 2021.1.0033.0061-4
 * ==================================================================================
 */
#include <iostream>
using namespace std;

class tempo
{
private:
    int horas, minutos, segundos;
public:
    tempo()
    {
        horas = minutos = segundos = 0;
    }
    ~tempo() = default;
    void validaTempo();
    long long converteTempoSegundos();
    void converteSegundosTempo(long long t1, long long t2);
    void setTempo(int h, int m, int s);
    void getTempo();
};

class testaTempo
{
private:
    tempo obj1, obj2;
public:
    void menu()
    {
        // Primeiro tempo;
        int h1, h2, m1, m2, s1, s2;
        cout << "\t Digite o primeiro tempo:\nHoras =";
        cin >> h1;
        cout << "Minutos =";
        cin >> m1;
        cout << "Segundos =";
        cin >> s1;
        obj1.setTempo(h1, m1, s1);
        fflush(stdin);
        obj1.validaTempo();

        // Segundo tempo;
        cout << "\n\tDigite o segundo tempo:\nHoras =";
        cin >> h2;
        cout << "Minutos =";
        cin >> m2;
        cout << "Segundos =";
        cin >> s2;
        obj2.setTempo(h2, m2, s2);
        fflush(stdin);
        obj2.validaTempo();

        // Mostra tempo;
        cout << "\nO primeiro tempo eh = "; obj1.getTempo(); cout << endl;
        cout << "Ele possui um total de " << obj1.converteTempoSegundos() << " segundos.\n";
        cout << "O segundo tempo eh = "; obj2.getTempo(); cout << endl;
        cout << "Ele possui um total de " << obj2.converteTempoSegundos() << " segundos.\n";

        // Diferença de horários;
        cout << "\nA diferenca dos horarios eh de " << abs(obj1.converteTempoSegundos() - obj2.converteTempoSegundos());
        cout << " segundos\n";
        cout << "Ou seja: "; obj1.converteSegundosTempo(obj1.converteTempoSegundos(), obj2.converteTempoSegundos());cout << endl;
    }
};

int main()
{
    testaTempo obj;
    obj.menu();
}

void tempo::validaTempo()
{
    for (; segundos >= 60; minutos++)
        segundos -= 60;

    for (; minutos >= 60; horas++)
        minutos -= 60;
}
long long tempo::converteTempoSegundos()
{
    long long segs = 0;
    segs += segundos;
    segs += minutos * 60;
    segs += horas * 3600;
    return segs;
}
void tempo::converteSegundosTempo(long long t1, long long t2)
{
    long long difs = abs(t1 - t2);
    int dm, dh;
    dm = dh = 0;
    for (; difs >= 3600; dh++)
        difs -= 3600;

    for (; difs >= 60; dm++)
        difs -= 60;

    cout << dh << ":" << dm << ":" << difs;
}
void tempo::setTempo(int h, int m, int s)
{
    horas = h;
    minutos = m;
    segundos = s;
}
void tempo::getTempo()
{
    cout << horas << ":" << minutos << ":" << segundos;
}
