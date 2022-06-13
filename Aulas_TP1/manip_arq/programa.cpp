/*
 *                  Aluno: Geovane Otávio Marques Rodrigues
 *                  Matrícula: 2021.1.0033.0061-4
 *                  Exercício 1
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string linha;
    fstream file1, file2;
    file1.open("copiar.txt", ios::in);
    file2.open("copia.txt", ios::out);
    if(file1.is_open() && file2.is_open())
    {
        while(file1.good())
        {
            getline(file1, linha);
            file2 << linha << endl;
            cout << linha << endl;
        }
        file1.close();
        file2.close();
        cout << "Sucesso!\n";
        system("notepad copiar.txt");
        system("notepad copia.txt");
    }
    else
        cout << "Erro de abertura\n";
}
