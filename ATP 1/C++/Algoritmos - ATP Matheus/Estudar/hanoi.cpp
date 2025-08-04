#include <stdio.h>
#include <stdlib.h>

void move(int discos, char inicial, char aux, char fim)
{
    if (discos>=1)
    {
        move(discos-1, inicial, fim, aux);
        printf("o disco %d passou da torre %c para a torra %c\n", discos, inicial, fim);
        move(discos-1, aux, inicial, fim);
    }
}

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        printf("O numero de argumentos %d é diferente do esperado\n", argc);
        printf("Dê 1 argumento de entrada para a quantidade de discos");
        return 0;
    }

    int discos = atoi(argv[1]);
    move(discos, 'A', 'B', 'C');

    getchar();
    return 0;
}