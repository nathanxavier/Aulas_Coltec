/*
    Percepção do Campo Minado através de uma Lista
        Identificação do tipo de elemento;
        Criação de um percurso livre de bombas
    Nathan Xavier
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "CriacaoCampoMinado.h"
#include "BaseLista.h"

using namespace std;

/* void setupCampoMinado(int &X, int &Y, int &Bombas)
    Entradas:
        int &X: Dimensão em X
        int &Y: Dimensão em Y
        int &Bombas: Número de Bombas
    Retorno:
    Função:
        Configuração inicial do Campo Minado
 */
void setupCampoMinado(int &X, int &Y, int &Bombas)
{
    do
    {
        cout << "Dimensão da matriz (X, Y):\n";
        cin >> X >> Y;

        cout << "Digite a quantidade de Bombas: (MAX " << (X * Y) - 2 << ")\n";
        cin >> Bombas;

    } while (X <= 0 || Y <= 0 || Bombas <= 0 || Bombas > (X * Y) - 2);
}

/* int **CriaCampo(int **CampoMinado, int &X, int &Y, int &Bombas)
    Entradas:
        int **CampoMinado: Matriz do Campo Minado
        int &X: Dimensão em X
        int &Y: Dimensão em Y
        int &Bombas: Número de Bombas
    Retorno:
        int **: Campo Minado
    Função:
        Criação, alocação das bombas e numeração do Campo Minado
 */
int **criaCampo(int **CampoMinado, int &X, int &Y, int &Bombas)
{
    CampoMinado = criaMatriz(X, Y);
    CampoMinado = alocaBombas(CampoMinado, X, Y, Bombas);
    CampoMinado = numBombas(CampoMinado, X, Y);

    cout << "\nCampo Minado Criado:\n";
    showMatriz(CampoMinado, X, Y);

    return CampoMinado;
}

int main()
{
    int dimX = 0, dimY = 0;
    int nBomba = 0;
    int **CampoMinado;

    setupCampoMinado(dimX, dimY, nBomba);
    CampoMinado = criaCampo(CampoMinado, dimX, dimY, nBomba);

    int i, j;
    /*
        Definindo a Diagonal
    */
    Lista *diagonal = criaLista();
    for (i = 0; i < dimX; i++)
        insereListaFinal(diagonal, CampoMinado[i][i]);

    printf("\nDiagonal do Campo\n");
    mostraLista(diagonal);

    /*
        Movimentos Ortogonais
    */
    Lista *ortogonal = criaLista();

    for (i = 0, j = 0; j < dimY; j++)
        insereListaFinal(ortogonal, CampoMinado[i][j]);
    for (i++, j--; i < dimX; i++)
        insereListaFinal(ortogonal, CampoMinado[i][j]);
    printf("\nMovimento Ortogonal no Mapa\n");
    mostraLista(ortogonal);

    /*
        Movimentos Ortogonais
    */
    Lista *dinamico = criaLista();

    for (i = 0, j = 0; j < dimY; j++)
    {
        if (CampoMinado[i][j] != -1) // Lado Livre
            insereListaFinal(dinamico, CampoMinado[i][j]);
        else if (CampoMinado[i + 1][j - 1] != -1) // Baixo Livre
            insereListaFinal(dinamico, CampoMinado[++i][--j]);
        else
            break;
    }
    for (i++, j--; i < dimX; i++)
    {
        if (CampoMinado[i][j] != -1) // Lado Livre
            insereListaFinal(ortogonal, CampoMinado[i][j]);
        else
            break;
    }
    printf("\nMovimento Dinâmico no Mapa\n");
    mostraLista(dinamico);
}