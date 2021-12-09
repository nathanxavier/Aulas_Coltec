#ifndef CriacaoCampoMinado_H
#define CriacaoCampoMinado_H

#include "CriacaoCampoMinado.cpp"

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        int ncols: Número de Colunas
        int nrows: Número de Linhas
    Retorno:
        int **: Matriz
    Função:
        Alocação da memória da matriz
 */
int **criaMatriz(int nrows, int ncols);

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
int **alocaBombas(int **matriz, int nrows, int ncols, int nBombas);

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
int **numBombas(int **matriz, int nrows, int ncols);

/* void showMatriz(int **matriz, int ncols, int nrows)
    Entradas:
        int **matriz: Matriz
        int ncols: Número de Colunas
        int nrows: Número de Linhas
    Retorno:
    Função:
        Print do conteúdo da matriz
 */
void showMatriz(int **matriz, int nrows, int ncols);

#endif