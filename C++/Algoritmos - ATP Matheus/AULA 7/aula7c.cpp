#include <stdio.h>
#include <stdlib.h>

int main ()
{

    int vetor[5] = {1, 25, 3, 4, -1}; //vetor de 5 "itens"
    int *point;

    for (point = vetor; *point != -1; point++)

    printf("%d\n", *point);

    getchar();
    return 0;
}