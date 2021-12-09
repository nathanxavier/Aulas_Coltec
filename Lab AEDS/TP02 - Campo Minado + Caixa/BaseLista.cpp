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

Lista *criaLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

void liberaLista(Lista *lista)
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

int listaVazia(Lista *lista)
{
    return (lista == NULL || *lista == NULL);
}

int tamanhoLista(Lista *lista)
{
    if (listaVazia(lista))
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

int insereListaInicio(Lista *lista, int valor)
{
    if (lista == NULL)
        return 1;
    elemento *elem = (Lista)malloc(sizeof(elemento));
    elem->dado = valor;
    elem->proximo = *lista;

    *lista = elem;
    return 0;
}

int insereListaFinal(Lista *lista, int valor)
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

int removeListaInicio(Lista *lista)
{
    if (listaVazia(lista))
        return 1;

    elemento *aux = *lista;
    *lista = (*lista)->proximo;
    free(aux);
    return 0;
}

int removeListaFinal(Lista *lista)
{
    if (listaVazia(lista))
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

void mostraLista(Lista *lista)
{
    if (listaVazia(lista))
        return;

    elemento *elem = *lista;
    int posicao = 0;

    printf("[Início] -> ");
    while (elem != NULL)
    {
        if (elem->dado == -1)
            printf(" * ->");
        else
            printf(" %d ->", elem->dado);
        elem = elem->proximo;
        posicao++;
    }
    printf(" [Fim]\n");
}