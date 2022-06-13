/*
 *                  Aluno: Geovane Otávio Marques Rodrigues
 *                  Matrícula: 2021.1.0033.0061-4
 *                  Exercício 2
 */

#include <iostream>
#include <fstream>

using namespace std;

class pessoa
{
private:
    string nome, endereco;
    double peso;
    int idade;

public:
    pessoa()
    {
        nome = endereco = "";
        peso = idade = 0;
    }
    ~pessoa() = default;
    void setPessoa(string& nm, string& end, double pes, int id);
    string getNome();
    string getEndereco();
    double getPeso();
    int getIdade();
};

void pessoa::setPessoa(string& nm, string& end, double pes, int id)
{
    nome = nm,
    endereco = end;
    peso = pes;
    idade = id;
}
string pessoa::getNome()
{
    return nome;
}
string pessoa::getEndereco()
{
    return endereco;
}
double pessoa::getPeso()
{
    return peso;
}
int pessoa::getIdade()
{
    return idade;
}


class testaPessoa
{
private:
    pessoa *obj = new class pessoa;
public:
    static void menu();
};

void testaPessoa::menu()
{
    cout << "Criando objetos do tipo Pessoa:\n";
    unsigned int tp, id;
    string nm, end;
    double pe;
    fstream claPes;
    claPes.open("ClassePessoa.txt", ios::out | ios::app);
    if (claPes.is_open())
    {
        do
        {
            cout << "Insira o nome do objeto Pessoa ->";
            getline(cin, nm);
            fflush(stdin);

            cout << "Insira o endereco do objeto Pessoa ->";
            getline(cin, end);
            fflush(stdin);

            cout << "Insira o peso do objeto Pessoa ->";
            cin >> pe;

            cout << "Insira a idade do objeto Pessoa ->";
            cin >> id;

            cout << "\nDigite '1' para cadastrar outro objeto do tipo Pessoa, ou qualquer outro número para parar!\n";

            claPes << "\nObjeto do tipo Pessoa:\n";
            claPes << "\tNome --> " << nm << ";" << endl;
            claPes << "\tEndereco --> " << end << ";" << endl;
            claPes << "\tPeso --> " << pe << "Kg;" << endl;
            claPes << "\tIdade --> " << id << " anos." << endl;
            cin >> tp;
            fflush(stdin);
        }
        while(tp == 1);
    }
    else
        cout << "Falha na abertura do arquivo!\n";
}

int main()
{
    class testaPessoa ob;
    ob.menu();
    system ("notepad ClassePessoa.txt");
}
