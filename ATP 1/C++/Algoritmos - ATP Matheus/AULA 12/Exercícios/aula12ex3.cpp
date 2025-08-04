#include <stdio.h>
#include <stdlib.h>

typedef struct noValor
{
    int valor;
    struct noValor *prox;
} NoValor;

typedef struct noLinha
{
    NoValor * valores;
    struct noLinha *prox;
} NoLinha;

