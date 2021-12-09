#ifndef BaseLista_H
#define BaseLista_H

#include "BaseLista.cpp"

/* Lista* cria_lista()
    Entradas:
    Retorno:
        Lista*: Estrutura Lista
    Função:
        Criação de uma lista vazia
 */
Lista *cria_lista();

/* void libera_lista(Lista* lista)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
    Função:
        Deleta completamente uma lista
 */
void libera_lista(Lista *lista);

/* int lista_vazia(Lista* lista)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
        int: 0 ou 1
    Função:
        Verifica se uma lista é vazia
 */
int lista_vazia(Lista *lista);

/* int tamanho_lista(Lista* lista)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
        int: Tamanho da lista
    Função:
        Calcula o tamanho da lista
 */
int tamanho_lista(Lista *lista);

/* int insere_lista_inicio(Lista* lista, int valor)
    Entradas:
        Lista* lista: Estrutura Lista
        int valor: Valor
    Retorno:
        int: 0 (Sucesso) ou 1 (Erro)
    Função:
        Adiciona um valor no início da lista
 */
int insere_lista_inicio(Lista *lista, int valor);

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        Lista* lista: Estrutura Lista
        int valor: Valor
    Retorno:
        int: 0 (Sucesso) ou 1 (Erro)
    Função:
        Adiciona um valor no final da lista
 */
int insere_lista_final(Lista *lista, int valor);

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
        int: 0 (Sucesso) ou 1 (Erro)
    Função:
        Remove primeiro valor
 */
int remove_lista_inicio(Lista *lista);

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
        int: 0 (Sucesso) ou 1 (Erro)
    Função:
        Remove último valor
 */
int remove_lista_final(Lista *lista);

/* int **criaMatriz(int ncols, int nrows)
    Entradas:
        Lista* lista: Estrutura Lista
    Retorno:
    Função:
        Mostrar a lista
 */
void mostra_lista(Lista *lista);

#endif