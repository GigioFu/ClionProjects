#include "main.h"

int main()
{
    // Alocação dinâmica;
    Pessoa *pess1 = new class Pessoa;
    pess1->setNome("Geovane");
    pess1->getNome();
    cout << endl;
    pess1->setIdade(19);
    pess1->getIdade();
    cout << endl;

    // Alocação estática;
    Pessoa pess2;
    pess2.setNome("Luisa");
    pess2.getNome();
    cout << endl;
    pess2.setIdade(18);
    pess2.getIdade();
}
