#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct elemento
{
    int dado;
    struct elemento *proximo;
} elemento;

typedef elemento *Lista;

Lista *cria_lista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

void libera_lista(Lista *lista)
{
    if (lista == NULL)
        return;

    elemento *aux;
    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->proximo;
        free(aux);
    }
    free(lista);
}

int lista_vazia(Lista *lista)
{
    return (lista == NULL || *lista == NULL);
}

int tamanho_lista(Lista *lista)
{
    if (lista_vazia(lista))
        return 0;
    int tam = 0;
    elemento *elem = *lista;
    while (elem != NULL)
    {
        tam++;
        elem = elem->proximo;
    }

    return tam;
}

int insere_lista_inicio(Lista *lista, int valor)
{
    if (lista == NULL)
        return 1;
    elemento *elem = (Lista)malloc(sizeof(elemento));
    elem->dado = valor;
    elem->proximo = *lista;

    *lista = elem;
    return 0;
}

int insere_lista_final(Lista *lista, int valor)
{
    if (lista == NULL)
        return 1;
    elemento *elem = (Lista)malloc(sizeof(elemento));
    elem->dado = valor;
    elem->proximo = NULL;

    if (*lista == NULL)
    {
        *lista = elem;
        return 0;
    }

    elemento *aux = *lista;
    while (aux->proximo != NULL)
        aux = aux->proximo;
    aux->proximo = elem;
    return 0;
}

int remove_lista_inicio(Lista *lista)
{
    if (lista_vazia(lista))
        return 1;

    elemento *aux = *lista;
    *lista = (*lista)->proximo;
    free(aux);
    return 0;
}

int remove_lista_final(Lista *lista)
{
    if (lista_vazia(lista))
        return 1;
    elemento *anterior, *elem = *lista;
    while (elem->proximo != NULL)
    {
        anterior = elem;
        elem = elem->proximo;
    }

    if (elem == *lista)
        *lista = NULL;
    else
    {
        anterior->proximo = NULL;
        free(elem);
    }
    return 0;
}

void mostra_lista(Lista *lista)
{
    if (lista_vazia(lista))
        return;

    elemento *elem = *lista;
    int posicao = 0;

    printf("-------\n");
    while (elem != NULL)
    {
        printf("[%d]: %d\n", posicao, elem->dado);
        elem = elem->proximo;
        posicao++;
    }
    printf("-------\n");
}