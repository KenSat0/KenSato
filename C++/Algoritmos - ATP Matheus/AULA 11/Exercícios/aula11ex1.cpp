/*Escreva um programa que receba de argumento, dois números (inicio e fim) e
imprima todos os números primos nesse intervalo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int ini = atoi(argv[1]);
    int fim = atoi(argv[2]);

    for (int i = 0; i < argc; i++)
    {
        printf("[%d] %s\n", i, argv[i]);
    }

    for(int i = ini; i<fim; i++)
    {
        int ehPrimo = 1;
        for(int cont = 2; cont < i; cont++)
        {
            if (i%cont==0)
            {
                ehPrimo = 0;
            }
        }
        if (ehPrimo == 1 && i > 1)
        {
            ehPrimo = 0;
            printf("%d e primo\n", i);
        }
    }

    getchar();
    return 0;
}