#include <stdio.h>
#include <stdlib.h>

//recurssividade em estruturas

typedef struct no
{
    int valor;
    struct no *prox;
} No;

//Boas praticas: minusculo representa estrutura, maiusculo representa tipo
//no caso: tipo No com estruturas no

No* iniciar(int valor)
{
    No *lista = (No*)malloc(sizeof(No));

    if (lista != NULL) 
    {
    lista -> valor = valor;
    lista -> prox = NULL;

    return lista;
    }

    return NULL;
}

No *adicionar(No *lista, int valor)
{
    if(lista->prox == NULL)
    {
        No *novo = iniciar(valor);
        lista->prox = novo;
        return (novo);

    }
    else
    {
        return(adicionar(lista->prox, valor));
    }
}

void liberar_No(No *lista)
{
    No *temp, *atual = lista;

    while(atual != NULL)
    {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

void imprimir(No *lista)
{
    No *atual = lista;
    while (atual != NULL)
    {
        printf("%d\n", atual->valor);
        atual = atual -> prox;
    }
}

int main()
{
    No *lista = iniciar(1);

    adicionar(lista, 2);
    adicionar(lista, 3);
    adicionar(lista, 7);

    imprimir(lista);

    liberar_No(lista);

    getchar();
    return 0;
}