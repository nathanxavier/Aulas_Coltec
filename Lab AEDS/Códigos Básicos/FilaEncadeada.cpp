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

void mostra_lista(Lista *lista)
{
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

int main()
{
    Lista *lista = cria_lista();
    insere_lista_final(lista, 10);
    insere_lista_final(lista, 20);
    insere_lista_inicio(lista, 30);

    mostra_lista(lista);
}