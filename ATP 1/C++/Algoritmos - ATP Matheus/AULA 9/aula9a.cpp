// Declaração e manipulação de matrizes
// Matrizes estaticas e dinamicas
// Ponteiros com acessos a matrizes

/*
Definição de Matriz:
    Vetor de vetores
    Array Bidimensional
    Linhas e colunas
    Tabelas

obs.: vetor reserva espaço, ponteiro só aponta (diferença entre vetor e ponteiro)

int v[3] implica uma vizinhança de 3 valores
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int vetor[6] = {1, 2, 3, 4, 5, 6};
    int matriz [2][3] = 
    {
        {1, 2, 3},
        {4, 5, 6}
    }; 
    //logica de tabela 2 linhas 3 colunas

    for (int j = 0; j<6; j++)
    {  
        printf("%d ", vetor[j]);
    }

    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++) printf("%d - %d ", matriz[i][j], vetor[i*3+j]);
        printf("\n");
    }

    getchar();
    return 0;
}