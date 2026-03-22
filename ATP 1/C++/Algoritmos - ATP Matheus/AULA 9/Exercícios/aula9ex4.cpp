//Calcule a soma dos elementos da diagonal principal de uma matriz 3x3.

#include <stdio.h>
#include <stdlib.h>

#include "funcoes_de_matrizes.cpp"

int soma_diagonal(int A[3][3])
{
    int soma_diagonal = 0;
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            if (i==j)
            {
                soma_diagonal = soma_diagonal + A[i][j];
            }
        }
    }
    return soma_diagonal;
}

int main()
{
    int matriz[3][3] = 
    {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    printf("A soma da diagonal principal e %d\n", soma_diagonal(matriz));

    getchar();
    return 0;
}
