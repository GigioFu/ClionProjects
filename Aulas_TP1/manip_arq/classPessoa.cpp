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
        classePessoa.open("ClassePessoa.txt", ios::out | ios::app);
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
                classePessoa << "\tNome -> " << obj->getNome() << ".\n";
                classePessoa << "\tEndereco -> " << obj->getEndereco() << ".\n";
                classePessoa << "\tPeso -> " << obj->getPeso() << " Kg.\n";
                classePessoa << "\tIdade -> " << obj->getIdade() << " anos.\n";

                delete obj;
                delete name;
                delete address;
                delete weight;
                delete age;

                cout << "\nDigite 1 para continuar a cadastrar novos objetos Pessoa;\n"
                        "Digite 0 para parar de cadaster novos objetos Pessoa;\n\n";
                do
                {
                    cout << "Digite aqui ->";
                    cin >> tp;
                    if (tp != 0 and tp != 1)
                        cout << "\nDigite novamente!! Numero nao identificado.\n\n";
                    fflush(stdin);
                }
                while (tp != 0 and tp != 1);
            }
            while (tp == 1);
            cout << "Encerrando cadastro!\n\n";
            classePessoa.close();
        }
        else
            cout << "Problema na abertura do arquivo!!\n";

        classePessoa.open("ClassePessoa.txt", ios::in);
        if (classePessoa.is_open())
        {
            string linha;
            cout << "Lendo o arquivo:\n\n"
                    "============================================================\n";
            while (classePessoa.good())
            {
                getline(classePessoa, linha);
                cout << linha << endl;
            }
            cout << "============================================================"
                    "\nSucesso!\n";
            }
        else
            cout << "Problema na abertura do arquivo!!\n";
        classePessoa.close();
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
    system ("notepad ClassePessoa.txt");
}
