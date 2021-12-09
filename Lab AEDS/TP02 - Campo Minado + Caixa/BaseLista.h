#ifndef BaseLista_H
#define BaseLista_H

#include "BaseLista.cpp"

/* Lista* criaLista()
    Entradas:
    Retorno:
        Lista*: Estrutura Lista
    Função:
        Criação de uma lista vazia
 */
Lista *criaLista();

/* void liberaLista(Lista* lista)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
    Função:
        Deleta completamente uma lista
 */
void liberaLista(Lista *lista);

/* int listaVazia(Lista* lista)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
        int: 0 ou 1
    Função:
        Verifica se uma lista é vazia
 */
int listaVazia(Lista *lista);

/* int tamanhoLista(Lista* lista)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
        int: Tamanho da lista
    Função:
        Calcula o tamanho da lista
 */
int tamanhoLista(Lista *lista);

/* int insereListaInicio(Lista* lista, int valor)
    Entradas:
        Lista* lista: Estrutura Lista
        int valor: Valor
    Retorno:
        int: 0 (Sucesso) ou 1 (Erro)
    Função:
        Adiciona um valor no início da lista
 */
int insereListaInicio(Lista *lista, int valor);

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        Lista* lista: Estrutura Lista
        int valor: Valor
    Retorno:
        int: 0 (Sucesso) ou 1 (Erro)
    Função:
        Adiciona um valor no final da lista
 */
int insereListaFinal(Lista *lista, int valor);

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
        int: 0 (Sucesso) ou 1 (Erro)
    Função:
        Remove primeiro valor
 */
int removeListaInicio(Lista *lista);

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
        int: 0 (Sucesso) ou 1 (Erro)
    Função:
        Remove último valor
 */
int removeListaFinal(Lista *lista);

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
    Função:
        Mostrar a lista
 */
void mostraLista(Lista *lista);

#endif