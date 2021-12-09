#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int **criaMatriz(int nrows, int ncols)
{
    int **matriz;

    matriz = (int **)calloc(nrows, sizeof(int *));
    for (int i = 0; i < nrows; i++)
    {
        matriz[i] = (int *)calloc(ncols, sizeof(int));
    }
    return matriz;
}

int **alocaBombas(int **matriz, int nrows, int ncols, int nBombas)
{
    bool fAloca = false;
    int posTeste = 0, nAlocadas = 0;
    int posBombas[nBombas];

    for (int i = 0; i < nBombas; i++)
    {
        do
        {
            posTeste = rand() % (nrows * ncols);
            fAloca = true;
            if (posTeste == 0 || posTeste == (nrows * ncols)-1)
                fAloca = false; // Recusa 1ª e Última posições
            else if (i == 0)
                break;
            else
                for (int j = 0; j < nAlocadas; j++)
                    if (posBombas[j] == posTeste)
                    {
                        // Posição Inválida
                        fAloca = false;
                        break;
                    }
        } while (fAloca == false);

        // Posição Válida
        posBombas[i] = posTeste;
        matriz[posBombas[i] / ncols][posBombas[i] % ncols] = -1;
        nAlocadas++;
    }
    return matriz;
}

int **numBombas(int **matriz, int nrows, int ncols)
{
    int count = 0;

    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
        {
            if (matriz[i][j] == -1)
                continue;
            count = 0;
            for (int k = i - 1; k <= i + 1; k++)
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < nrows && l >= 0 && l < ncols)
                        if (matriz[k][l] == -1)
                            count++;
                }
            matriz[i][j] = count;
        }
    return matriz;
}

void showMatriz(int **matriz, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
            if (matriz[i][j] == 0)
                cout << ' ' << "\t";
            else if (matriz[i][j] == -1)
                cout << '*' << "\t";
            else
                cout << matriz[i][j] << "\t";
        cout << endl;
    }
}