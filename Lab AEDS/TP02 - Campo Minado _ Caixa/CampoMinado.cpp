#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "CriacaoCampoMinado.h"
#include "BaseLista.h"

using namespace std;

int main()
{
    int dimX = 3, dimY = 3;
    int nBomba = 0;
    int **CampoMinado;

    do
    {
        cout << "Dimensão da matriz (X, Y):\n";
        cin >> dimX >> dimY;

        cout << "Digite a quantidade de Bombas: (MAX " << dimX * dimY << ")\n";
        cin >> nBomba;

    } while (dimX <= 0 || dimY <= 0 || nBomba <= 0 || nBomba > dimX * dimY);

    CampoMinado = criaMatriz(dimX, dimY);
    CampoMinado = alocaBombas(CampoMinado, dimX, dimY, nBomba);
    CampoMinado = numBombas(CampoMinado, dimX, dimY);
    
    cout << "\nCampo Minado Criado:\n";
    showMatriz(CampoMinado, dimX, dimY);



    return 0;
}