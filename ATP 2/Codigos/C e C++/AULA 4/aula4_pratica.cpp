#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *prox;
};

void insert_ini(struct no **atual, int v)
{

    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));
    aux -> info = v;
    aux -> prox = *atual;
    *atual = aux;

}

int main()
{

    struct no *p = NULL;
    int valor;

    insert_ini(&p, valor);

}