#include <stdio.h>
#include <stdlib.h>

struct no
{
    int cadastro;
    char nome[100];
    struct no *prox;
};

void regFunc(struct **no, int num, char *nome)
{

    struct no *aux;
    aux = (struct no*)malloc(sizeof(struct no));
    aux -> cadastro = num;
    aux -> prox = *no;
    *no = aux;

}


int main()
{
    struct no *listaRFunc;
}