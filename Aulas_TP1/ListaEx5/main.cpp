#include <iostream>
using namespace std;

string lerFrase(const string& msg);
char lerDig(const string& msg);
void contadorVC(string& frs);
string invert(string& frs);
int contadorrp(string& frs, char digt);
string retirar(string& frs, char digit);

int main()
{
    string frase;
    char digito;
    while(true)
    {
        frase = lerFrase("Digite uma frase: ");
        digito = lerDig("Digite um digito extra: ");
        cout << "\tA frase digitada foi: '" << frase << "'. E o digito e: '" << digito << "'\n";
        cout << "\tA frase invertida fica: " << invert(frase);
        contadorVC(frase);
        cout << "\tO caractere '" << digito << "' aparece " << contadorrp(frase, digito) << "vezes!\n";
        cout << "\tA frase sem o caractere fica: '" << retirar(frase, digito) << "'\n";
        cout << endl;
        system("pause");
        system("cls");
    }
}

string lerFrase(const string& msg)
{
    string frs;
    cout << msg;
    getline(cin, frs);
    fflush(stdin);
    return frs;
}

char lerDig(const string& msg)
{
    cout << endl;
    char dig;
    cout << msg;
    cin >> dig;
    fflush(stdin);
    return dig;
}

void contadorVC(string& frs)
{
    int vog = 0, con = 0, spc = 0;
    for (int i = 0; i < frs.length(); i++)
    {
        if (frs[i] == 'a' || frs[i] == 'e' || frs[i] == 'i' || frs[i] == 'o' || frs[i] == 'u' || frs[i] == 'A' || frs[i] == 'E' || frs[i] == 'I' || frs[i] == 'O' || frs[i] == 'U')
            vog++;
        else
        {
            switch (frs[i])
            {
                //space
                case 32:
                    spc++;
                default:
                    con++;
            }
        }
    }
    cout << "\n\tO numero de vogais na frase e: " << vog << endl;
    cout << "\tO numero de consoantes na frase e: " << con - spc << endl;
}

string invert(string& frs)
{
    char invert[frs.length()];
    for (int i = 0, j = frs.length() - 1; i < frs.length(); i++, j--)
    {
        invert[i] = frs[j];
    }
    return invert;
}

int contadorrp(string& frs, char digt)
{
    int vzs = 0;
    for (int i = 0; i < frs.length(); i++)
    {
        if (frs[i] == digt)
            vzs++;
    }
    return vzs;
}

string retirar(string& frs, char digit)
{
    char ret[frs.length()];
    for (int i = 0, j = 0; i < frs.length(); i++)
    {
        if (frs[i] != digit)
        {
            ret[j] = frs[i];
            j++;
        }
    }
    return ret;
}
