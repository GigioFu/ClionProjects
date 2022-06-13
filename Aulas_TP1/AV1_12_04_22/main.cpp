#include <iostream>

using namespace std;

int lerPositivo(string msg)
{
    int n;
    do
    {
        cout << msg;
        cin >> n;
    } while (n < 3 or n > 15);
    return n;
}

// ==============================================================================================

class Vetor
{
private:
    int tamanho;
    double *vet = nullptr;
    double soma;
public:
    Vetor()
    {
        tamanho = 0;
        vet = new double[0];
        soma = 0;
    }
    ~Vetor() = default;     // ~Vetor() = default; == ~Vetor() {}
    void setTam();
    void setVetor();
    double somaVetor();
    double mediaVetor();
    void mostraVetor();

};
void Vetor::setTam()
{
    string msg = "Digite o tamanho do vetor [de 3 a 15]:\n";
    tamanho = lerPositivo(msg);
    cout << "Tamanho definido!\n";
}
void Vetor::setVetor()
{
    for (int i = 0; i < tamanho; i++)
    {
        cout << "Preencha a " <<i + 1<< "a. posicao do vetor:\n";
        cin >> vet[i];
    }
}
double Vetor::somaVetor()
{
    for (int i = 0; i < tamanho; i++)
    {
        soma += vet[i];
    }
    return soma;
}
double Vetor::mediaVetor()
{
    double med;
    med = soma / tamanho;
    return med;
}
void Vetor::mostraVetor()
{
    cout << "O vetor foi preenchido por:\n\tvet = [";
    for (int i = 0; i < tamanho; i++)
    {
        if (i != tamanho - 1)
            cout << vet[i] << ", ";
        else
            cout << vet[i] << "].";
    }
}

// ==============================================================================================


class TestaVetor
{
private:
    Vetor *vec = new class Vetor;
public:
    void menu();
};
void TestaVetor::menu()
{
    vec -> setTam();
    vec -> setVetor();
    cout << "=========================================================================================\n";
    vec -> mostraVetor();
    cout << "\n\nO valor da soma de todos os elemetos do vetor vale: " << vec->somaVetor() << endl;
    cout << "O valor da media de todos os elemetos do vetor vale: " << vec->mediaVetor() << endl;
}


int main()
{
    TestaVetor *test = new class TestaVetor;
    test ->menu();
}
