#include <stdio.h>
#include <stdlib.h>

int main ()
{

    int vetor[5] = {1, 2, 3, 4, 5}; //vetor de 5 "itens"
    int *point = vetor;

    printf("%d", *point);

    /* se o point chamar o vetor [5], a saída retornará um valor "aleatorio" 
    pois não há nenhum valor endereçado ao pedaço de memoria que foi chamado*/

    getchar();
    return 0;
}