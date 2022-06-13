/* ==================================================================================
 *                          Exerício 03 da lista no Teams
 *                     Aluno: Geovane Otávio Marques Rodrigues;
 *                     Matrícula: 2021.1.0033.0061-4
 * ==================================================================================
 */

#include <iostream>
using namespace std;

typedef struct {
    int dia;
    int mes;
    int ano;
} Date;

int bissexto (int ano);
unsigned long dist_dias (Date inicio, Date fim);

class Data
{
private:
    int dia, mes, ano;
public:
    Data()
    {
        dia = mes = ano = 0;
    }
    ~Data() = default;
    void setData(int d, int m, int a);
    void getData();
    void validaData();
    void determinaDiaSemana();
    void calculaDiaEntreDatas(Date d1, Date d2);
};

class testaData
{
private:
    Data obj1, obj2;
public:
    void menu()
    {
        int d, m ,a, d1, m1, a1;
        Date dia1, dia2;
        cout << "Digite a data inicial:\n";
        cout << "      Dia:";
        cin >> d;
        cout << "      Mes:";
        cin >> m;
        cout << "      Ano:";
        cin >> a;
        obj1.setData(d, m, a);
        cout << "Digite a data final:\n";
        cout << "      Dia:";
        cin >> d1;
        cout << "      Mes:";
        cin >> m1;
        cout << "      Ano:";
        cin >> a1;
        obj2.setData(d1, m1, a1);

        cout << "A dia da semana de cada data:\n\n";
        obj1.validaData();
        obj2.validaData();

        dia1.dia = d;
        dia1.mes = m;
        dia1.ano = a;
        dia2.dia = d1;
        dia2.mes = m1;
        dia2.ano = a1;

        cout << endl;
        obj1.calculaDiaEntreDatas(dia1, dia2);
        cout << endl;
    }
};

int main()
{
    testaData tst;
    tst.menu();
}

void Data::setData(int d, int m, int a)
{
    dia = d;
    mes = m;
    ano = a;
}
void Data::getData()
{
    cout << dia << "/" << mes << "/" << ano;
}
void Data::validaData()
{
    // Verifica se é "um ano Bissexto, se o dia está entre ( 01- 31 ) e o mês está entre ( 01 - 12 );
    if ((ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) && (dia > 0 && dia <= 31) && (mes > 0 && mes <= 12))
    {
        // Verifica se os meses de até 30 dias não estão corretos;
        if (mes == 2 && dia > 29 || mes == 4 && dia > 30 || mes == 6 && dia > 30 || mes == 9 && dia > 30 ||
            mes == 11 && dia > 30)
        {
            cout << "A data " << dia << "/" << mes << "/" << ano << " nao existe no calendario Gregoriano. \n\n";
        }else Data::determinaDiaSemana();
    }
        // Verifica se não é um ano Bissexto, se o dia está entre ( 01- 31 ) e o mês está entre ( 01 - 12 );
    else if (!(ano % 4 == 0 && (ano % 400 == 0 || ano % 100 != 0)) && (dia > 0 && dia <= 31) &&
             (mes > 0 && mes <= 12))
    {
        // Verifica se os meses de até 30 dias não estão corretos;
        if (mes == 2 && dia > 28 || mes == 4 && dia > 30 || mes == 6 && dia > 30 || mes == 9 && dia > 30 ||
            mes == 11 && dia > 30)
        {
            cout << "A data " << dia << "/" << mes << "/" << ano << " nao existe.\n";
        }else Data::determinaDiaSemana();
    }
    else cout << "A data " << dia << "/" << mes << "/" << ano << " nao existe.\n";
}
void Data::determinaDiaSemana()
{
    int dia_semana, formula, di, me, an;
    di = dia;
    me = mes;
    an = ano;

    if (me == 01) // mês de janeiro será o mês 13 do an anterior;
    {
        me = 13;
        an = an - 1;
    }
    if (me == 02) // mês de favereiro será o mês 14 do an anterior;
    {
        me = 14;
        an = an - 1;
    }

    formula = di + 2 * me + (3 * (me + 1) / 5) + an + an / 4 - an / 100 + an / 400 + 2;  // Formula para calcular o dia da semana;
    dia_semana = formula % 7;   // Resto da divisão do valor encontrado na formula por 7;

    if (me == 13) // Se for mês de Janeiro, coloca o valor certo do Mês e do ano para mostrar na tela;
    {
        me = 1;
        an = an + 1;
    }
    if (me == 14) // Se for mês de Fevereiro, coloca o valor certo do Mês e do ano para mostrar na tela;
    {
        me = 2;
        an = an + 1;
    }

    switch (dia_semana)  // Switch case para saber qual dia da semana é;
    {
        case 0:// é um Sábado;
            cout << "A data "; getData(); cout << " cai em um Sabado.\n";
            break;

        case 1:// é um Domingo;
            cout << "A data "; getData(); cout << " cai em um Domingo.\n";
            break;

        case 2:// é uma segunda-feira;
            cout << "A data "; getData(); cout << " cai em uma Segunda-feira.\n";
            break;

        case 3:// é uma terça-feira;
            cout << "A data "; getData(); cout << " cai em uma Terca-feira.\n";
            break;

        case 4:// é uma quarta-feira;
            cout << "A data "; getData(); cout << " cai em uma Quarta-feira.\n";
            break;

        case 5:// é uma quinta-feira;
            cout << "A data "; getData(); cout << " cai em uma Quinta-feira.\n";
            break;

        case 6:// é uma Sexta-feira;
            cout << "A data "; getData(); cout << " cai em uma Sexta-feira.\n";
            break;
    }
}

// guarda o numero de dias em cada mes para anos normais e bissextos */
int dias_mes[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                       {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

void Data::calculaDiaEntreDatas(Date d1, Date d2)
{
    cout << "A distancia em dias : " << dist_dias(d1, d2);
}
// Retorna 1 caso 'ano' seja bissexto, 0 caso contrário
int bissexto (int ano)
{
    return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

// Retorna a distancia entre inicio e fim em dias.
unsigned long dist_dias (Date inicio, Date fim) {
    unsigned long idias, fdias;	// guarda qtos dias tem da Data ate o comeco do ano */
    unsigned long def_anos = 0;	// guarda diferença entre anos das Datas inicio e fim medida em dias */
    int i;
    int dbissexto;

    idias = inicio.dia;
    dbissexto = bissexto (inicio.ano);
    for (i = inicio.mes - 1; i > 0; --i)
        idias += dias_mes[dbissexto][i];

    fdias = fim.dia;
    dbissexto = bissexto (fim.ano);
    for (i = fim.mes - 1; i > 0; --i)
        fdias += dias_mes[dbissexto][i];

    while (inicio.ano < fim.ano)
        def_anos += 365 + bissexto(inicio.ano++);

    return def_anos - idias + fdias;
}
