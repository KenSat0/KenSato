//Implemente o produto vetorial de duas matrizes 3x3.

#include <stdio.h>
#include <stdlib.h>

#include "funcoes_de_matrizes.cpp"

int **produto_vetorial(int A[3][3], int B[3][3])
{
    int **Soma = alocar_certo(3, 3);

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            Soma[i][j] = 0;
            for (int k = 0; k <3; k++)
            {
                Soma[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return Soma;
}

int main()
{
    int A[3][3] = 
    {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}
    };

    int B[3][3] =
    {
        {3, 3, 3},
        {2, 2, 2},
        {1, 1, 1}
    };

    int **C = alocar_certo(3, 3);
    C = produto_vetorial(A, B);

    imprime_matriz(C, 3, 3);

    getchar();
    return 0;
}
