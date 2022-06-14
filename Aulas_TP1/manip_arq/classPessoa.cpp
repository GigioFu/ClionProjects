/*
 *                  Aluno: Geovane Otávio Marques Rodrigues
 *                  Matrícula: 2021.1.0033.0061-4
 *                  Exercício 2
 */

#include <iostream>
#include <fstream>

using namespace std;

//  ===================== Classes =====================
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
    void setNome(string& nm);
    void setEndereco(string& ende);
    void setPeso(double pes);
    void setIdade(int ida);
    string getNome();
    string getEndereco();
    double getPeso() const;
    int getIdade() const;
};

class testaPessoa
{
private:
    pessoa *obj;
public:
    testaPessoa()
    {
        obj = nullptr;
    }
    ~testaPessoa() = default;
    void menu()
    {
        string *name = nullptr, *address = nullptr;
        double *weight = nullptr;
        int *age = nullptr, tp;
        fstream classePessoa;
        classePessoa.open("ClassePessoa.txt", ios::out | ios::in | ios::app);
        if (classePessoa.is_open())
        {
            do
            {
                obj = new class pessoa;
                name = new string;
                address = new string;
                weight = new double;
                age = new int;

                cout << "Objeto tipo pessoa:\n";
                cout << "Digite o nome do objeto Pessoa ->";
                getline (cin, *name);
                cout << "Digite o endereco do objeto Pessoa ->";
                getline (cin, *address);
                cout << "Digite o peso do objeto Pessoa ->";
                cin >> *weight;
                cout << "Digite a idade do objeto Pessoa ->";
                cin >> *age;

                obj->setNome(*name);
                obj->setEndereco(*address);
                obj->setPeso(*weight);
                obj->setIdade(*age);

                classePessoa << "Objeto tipo pessoa:\n";
                classePessoa << "\tNome ->" << obj->getNome() << endl;
                classePessoa << "\tEndereco -> " << obj->getEndereco() << endl;
                classePessoa << "\tPeso -> " << obj->getPeso() << endl;
                classePessoa << "\tIdade -> " << obj->getIdade() << "\n";

                delete obj;
                delete name;
                delete address;
                delete weight;
                delete age;

                cout << "Digite 1 para continuar a cadastrar novos objetos Pessoa;\n"
                        "Digite 0 para parar de cadaster novos objetos Pessoa;\n";
                do
                {
                    cout << "Digite aqui ->";
                    cin >> tp;
                    if (tp != 0 and tp != 1)
                        cout << "Digite novamente!! Numero nao identificado.\n\n";
                }
                while (tp != 0 and tp != 1);
            }
            while (tp == 1);
            cout << "Encerrando cadastro!\n\n";
            classePessoa << "\n\n";
        }
        else
            cout << "Problema na abertura do arquivo!!\n";
        system ("notepad ClassePessoa.txt");
    }
};

//  ===================== Methods =====================

void pessoa::setNome(string& nm)
{
    nome = nm;
}
void pessoa::setEndereco(string& ende)
{
    endereco = ende;
}
void pessoa::setPeso(double pes)
{
    peso = pes;
}
void pessoa::setIdade(int ida)
{
    idade = ida;
}
string pessoa::getNome()
{
    return nome;
}
string pessoa::getEndereco()
{
    return endereco;
}
double pessoa::getPeso() const
{
    return peso;
}
int pessoa::getIdade() const
{
    return idade;
}

//  =====================   main  =====================

int main()
{
    testaPessoa pess1;
    pess1.menu();
}
