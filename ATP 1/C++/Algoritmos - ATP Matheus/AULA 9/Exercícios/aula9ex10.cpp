//realiza o produto vetorial de duas matrisez alocadas dinamicamente

#include <stdio.h>
#include <stdlib.h>

#include "funcoes_de_matrizes.cpp"

int main()
{
    int linhas_a, colunas_a;
    int linhas_b, colunas_b;
    int **resultado;

    printf("\nDigite a quantidade de linhas da primeira matriz: ");
    scanf("%d", &linhas_a);

    printf("\nDigite a quantidade de colunas da primeira matriz: ");
    scanf("%d", &colunas_a);

    int**matriz = alocar_certo(linhas_a, colunas_a);

    matriz = preencher_matriz(linhas_a, colunas_a);

    imprime_matriz(matriz, linhas_a, colunas_a);

    printf("\nDigite a quantidade de linhas da segunda matriz: ");
    scanf("%d", &linhas_b);

    printf("\nDigite a quantidade de colunas da segunda matriz: ");
    scanf("%d", &colunas_b);

    int**matriz_2 = alocar_certo(linhas_b, colunas_b);

    matriz_2 = preencher_matriz(linhas_b, colunas_b);

    imprime_matriz(matriz_2, linhas_b, colunas_b);

    resultado = alocar_certo(linhas_a, colunas_b);

    if (linhas_a == colunas_b && linhas_a != 0)
    {
        resultado = produto_vetorial(matriz, matriz_2, linhas_a, colunas_b);
        
        printf("O produto das matrizes e:");
        imprime_matriz(resultado, linhas_a, colunas_b);
    }
    else
    {
        printf("Nao e possievl fazer o produto");
    }

    getchar();
    return 0;
}
