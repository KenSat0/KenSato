//usuario preenche matriz dinamica

#include <stdio.h>
#include <stdlib.h>

#include "funcoes_de_matrizes.cpp"

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

int main()
{
    int linhas, colunas;

    printf("\nDigite a quantidade de linhas: ");
    scanf("%d", &linhas);

    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &colunas);

    int**matriz = alocar_certo(linhas, colunas);

    matriz = preencher_matriz(linhas, colunas);

    imprime_matriz(matriz, linhas, colunas);

    getchar();
    return 0;
}
