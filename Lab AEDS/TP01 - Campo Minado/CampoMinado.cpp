/*
    Criação básica de um Campo Minado
        Definição das posições das bombas;
        Cálculo de bombas ao redor.

    Nathan Xavier
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        int ncols: Número de Colunas
        int nrows: Número de Linhas
    Retorno:
        int **: Matriz
    Função:
        Alocação da memória da matriz
 */
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

/* int **alocaBombas(int **matriz, int ncols, int nrows, int nBombas)
    Entradas:
        int **matriz: Matriz
        int ncols: Número de Colunas
        int nrows: Número de Linhas
        int nBombas: Número total de bombas
    Retorno:
        int **: Matriz
    Função:
        Identifica e posiciona as bombas na matriz do Campo Minado
 */
int **alocaBombas(int **matriz, int nrows, int ncols, int nBombas)
{
    bool fAloca = false;
    int posTeste = 0, nAlocadas = 0;
    int posBombas[nBombas];

    for (int i = 0; i < nBombas; i++)
    {
        do
        {
            posTeste = rand() % ((nrows * ncols));
            fAloca = true;
            if (i == 0)
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

/* int **numBombas(int **matriz, int ncols, int nrows)
    Entradas:
        int **matriz: Matriz
        int ncols: Número de Colunas
        int nrows: Número de Linhas
    Retorno:
        int **: Matriz
    Função:
        Preenchimento das células com quantidade de bombas ao redor
 */
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

/* void showMatriz(int **matriz, int ncols, int nrows)
    Entradas:
        int **matriz: Matriz
        int ncols: Número de Colunas
        int nrows: Número de Linhas
    Retorno:
    Função:
        Print do conteúdo da matriz
 */
void showMatriz(int **matriz, int nrows, int ncols)
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
            cout << matriz[i][j] << "\t";
        cout << endl;
    }
}

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