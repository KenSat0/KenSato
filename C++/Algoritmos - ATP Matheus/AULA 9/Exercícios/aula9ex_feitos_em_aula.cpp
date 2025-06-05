//ex 1, 6, 7, 9:

#include <stdio.h>
#include <stdlib.h>

int** alocar_certo(int i, int j)
{
    int **A = NULL;

    A = (int **)malloc(i*sizeof(int*));

    if (A==NULL)
    {
        printf("Erro de alocação 1\n");
        return (NULL);
    }

    for (int k = 0; k < i; k++)
    {
        A[k] = NULL;
        A[k] = (int*)malloc(j*sizeof(int));
        if (A[k]==NULL)
        {
            printf("Erro de alocação 2\n");
            return (NULL);
        }
    }
    return A;
}

void libera(int**A,int linhas)
{
    for (int i = 0; i<linhas; i++) free(A[i]);
    free(A);
}

int main()
{


    getchar();
    return 0;
}

void imprime_matriz(int **A, int linhas, int colunas)
{
    for (int i = 0; i<linhas; i++)
    {
        for (int j = 0; j<colunas; j++)
        {
            printf("%d ", A[i][j]);
        }

    printf("\n");
    }
}

int **soma_matriz(int A[3][3], int B[3][3])
{
    int **C = alocar_certo(3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

int main()
{
    int A[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int **C = soma_matriz(A, B);
    imprime_matriz(C,3,3);
    libera(C,3);
    
    printf("%d", C[0][0]);

    getchar();
    return 0;
}