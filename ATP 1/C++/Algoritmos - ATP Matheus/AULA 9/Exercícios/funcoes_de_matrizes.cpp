//ex 1, 2, 3, 6, 7, 9:

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

void imprime_matriz(int **A, int linhas, int colunas)
{
    printf("\n");
    for (int i = 0; i<linhas; i++)
    {
        for (int j = 0; j<colunas; j++)
        {
            printf("%d ", A[i][j]);
        }

    printf("\n");
    }
    printf("\n");
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

int **transposta(int A[3][3])
{
    int **C = alocar_certo(3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[j][i];
        }
    }

    return C;
}

void pertence(int A[3][3], int x)
{
        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(x==A[i][j])
            {
                printf("%d pertence a matriz e esta na posicao %d, %d\n", x, i+1, j+1);
            }
        }
    }
    printf("\n");
}

int **produto_vetorial(int **A, int **B, int linhas_a, int colunas_b)
{
    int **Soma = alocar_certo(linhas_a,colunas_b);

    for (int i = 0; i<linhas_a; i++)
    {
        for (int j = 0; j<colunas_b; j++)
        {
            Soma[i][j] = 0;
            for (int k = 0; k <colunas_b; k++)
            {
                Soma[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return Soma;
}

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

int **preencher_matriz(int linhas, int colunas)
{
    int **matriz = alocar_certo(linhas, colunas);

    for (int i = 0; i<linhas; i++)
    {
        for (int j=0; j<colunas; j++)
        {
            int temp = 0;
            printf("\nDigite o valor de posicao (%d, %d): ", i,j);
            scanf("%d", &temp);
            matriz[i][j] = temp;
        }
    }
    return matriz;
}