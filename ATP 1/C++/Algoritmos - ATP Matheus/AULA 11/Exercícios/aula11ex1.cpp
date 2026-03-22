/*

Escreva um programa que receba de argumento, dois números (inicio e fim) e
imprima todos os números primos nesse intervalo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //converte string para int
    int ini = atoi(argv[1]);
    int fim = atoi(argv[2]);

    //printa a quantidade e quais os argumentos foram dados 
    for (int i = 0; i < argc; i++)
    {
        printf("[%d] %s\n", i, argv[i]);
    }

    //verifica os primos dentro do intervalo dado
    for(int i = ini; i<fim; i++)
    {
        int ehPrimo = 1; //começa sempre considerando primo
        for(int cont = 2; cont < i; cont++)
        {
            if (i%cont==0) //se for divisivel, define como não primo
            {
                ehPrimo = 0;
            }
        }
        if (ehPrimo == 1 && i > 1) //se for primo, printa
        {
            ehPrimo = 0;
            printf("%d e primo\n", i);
        }
    }

    getchar();
    return 0;
}