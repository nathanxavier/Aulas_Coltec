#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "CampoMinado.h"

using namespace std;

typedef struct elemento
{
    int dado;
    struct elemento *proximo;
} elemento;


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
    showMatriz(CampoMinado, dimX, dimY);
    cout << "\nAlocando Bombas\n";
    CampoMinado = alocaBombas(CampoMinado, dimX, dimY, nBomba);
    showMatriz(CampoMinado, dimX, dimY);

    cout << "\nNumerando Bombas\n";
    CampoMinado = numBombas(CampoMinado, dimX, dimY);
    showMatriz(CampoMinado, dimX, dimY);

    return 0;
}