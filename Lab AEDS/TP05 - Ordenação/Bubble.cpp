/*
    Comparação da Ordenação Bubble por Array e Lista Encadeada
    Nathan Xavier
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "BaseLista.h"
#include <time.h>

using namespace std;

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("\n\nTempo de Processamento %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)

void arrayBubbleSort(int V[], int tam)
{
    bool cont = false;
    int aux;
    do
    {
        cont = false;
        for (int i = 0; i < tam - 1; i++)
        {
            if (V[i] > V[i + 1])
            {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
                cont = true;
            }
        }
    } while (cont);
}

void listaBubbleSort(Lista *lista)
{
    bool cont = false;
    elemento *ant, *elem = *lista;
    int aux;
    do
    {
        cont = false;
        elem = *lista;
        while (elem->proximo != NULL)
        {
            ant = elem;
            elem = elem->proximo;
            if ((ant->dado) > (elem->dado))
            {
                aux = ant->dado;
                ant->dado = elem->dado;
                elem->dado = aux;
                cont = true;
            }
        }
    } while (cont);
}

void mostraArray(int V[], int tam)
{
    printf("[Início] -> ");
    for (int i = 0; i < tam; i++)
        printf(" %d ->", V[i]);
    printf("[Fim]\n");
}

int main()
{
    int numVar = 1000;
    int vetorArray[numVar];
    int aux;
    Lista *vetorLista = criaLista();

    // Sequência de Números 0 ~ 99
    for (int i = 0; i < numVar; i++)
    {
        vetorArray[i] = i;
        insereListaFinal(vetorLista, i);
    }

    /*
        Trocar Início e Fim
        99 - 1 - 2 - ... - 97 - 98 - 0
    */
    // Array
    aux = vetorArray[0];
    vetorArray[0] = vetorArray[numVar - 1];
    vetorArray[numVar - 1] = aux;

    // Lista
    elemento *elem = *vetorLista;
    aux = elem->dado;
    while (elem->proximo != NULL) //Chegar no fim
    {
        elem = elem->proximo;
    }
    removeListaInicio(vetorLista);
    insereListaInicio(vetorLista, elem->dado);
    removeListaFinal(vetorLista);
    insereListaFinal(vetorLista, aux);

    /*
        Bubble Sort
    */
    TICK(arrayBubble);
    arrayBubbleSort(vetorArray, numVar);
    TOCK(arrayBubble);
    //mostraArray(vetorArray, numVar);

    TICK(listaBubble);
    listaBubbleSort(vetorLista);
    TOCK(listaBubble);
    //mostraLista(vetorLista);
}