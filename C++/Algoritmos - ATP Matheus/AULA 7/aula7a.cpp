#include <stdio.h>
#include <stdlib.h>

void dobro(int *n)
{
    *n = *n * 2;
}

int main ()
{

    int vetor[5]; //vetor de 5 "itens"
    char nome[100]; //isso também é vetor

    vetor[0] = 1; //vetor de endereço 0
    vetor[1] = 2;
    vetor[2] = 3;
    vetor[3] = 4;
    vetor[4] = 5;

    /*ou
    int vetor [5] = {1, 2, 3, 4, 5};
    */

    for (int i = 0; i<5; i++)
    {
        dobro(&vetor[i]);
        printf("%d", vetor[i]);
    }

    getchar();
    return 0;
}