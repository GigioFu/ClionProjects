#include <iostream>
using namespace std;
// Declaração da classe Pessoa:
class Pessoa
{
    // Atributos:
    private:
        string nome;
        int idade;
    // Métodos:
    public:
        Pessoa() // Contrutor;
        {
            nome.clear();
            idade = 0;
        }
        ~Pessoa()= default; // Destrutor;               ~Pessoa() = default; ==> ~Pessoa() {}
        void setNome(string nm); // Prot. Obtem nome;
        void setIdade(int ID); // Prot. Obtem idade;
        void getNome(); // Prot. Mostra nome;
        void getIdade(); // Prot. Mostra idade;
};

void Pessoa::setNome(string nm) // Def. Método;
{
    nome = nm;
}

void Pessoa::setIdade(int ID) // Def. Método;
{
    idade = ID;
}

void Pessoa::getNome() // Def. Método;
{
    cout << nome;
}

void Pessoa::getIdade() // Def. Método;
{
    cout << idade;
}
