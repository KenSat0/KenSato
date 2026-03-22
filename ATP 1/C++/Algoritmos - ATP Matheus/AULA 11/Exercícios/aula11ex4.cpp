/*

4. Faça um programa que calcule a soma de duas matrizes quadradas de inteiros que
são passadas em um arquivo matriz.txt, a primeira linha do arquivo indica as
dimensões da matriz

*/

#include <stdio.h>
#include <stdlib.h>

//função de alocação dinamica de matriz
//parametro só coluna pq é mtriz quadrada
int **alocar_Matriz(int colunas) 
{
    int **R = (int **) malloc(colunas * sizeof(int *));
    if(R == NULL) return NULL;

    for(int i = 0; i < colunas; ++i) 
    {
        R[i] = (int *) malloc(colunas * sizeof(int));
        if(R[i] == NULL) return NULL;
    }

    return R;
}

void liberar_Matriz(int **matriz, int linhas) //libera a memoraia da matriz
{
    for(int i = 0; i < linhas; ++i) free(matriz[i]);
    free(matriz);
}

void imprime_matriz(int **A, int linhas, int colunas) //função de uma das aulas passadas de imprimir matriz
{
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

int main() 
{
    FILE *matriz = fopen("matriz.txt", "r"); //abre arquivo em modo de leitura
    if(!matriz) return 1; //se não deu pra acessar, retorna erro (no caso 1)

    int size, valor;
    fscanf(matriz, "%d", &size); //scaneia o arquivo e salva em size

    int **matrizResultado = alocar_Matriz(size); //aloca a matriz com o espaço desejado

    for(int i = 0; i < (size * size); ++i) //laço passa por todos os elementos da matriz 
    { 
        fscanf(matriz, "%d", &valor); //escaneia o valor
        matrizResultado[i / size][i % size] = valor; //salva o valor em outra matriz, elemento por elemento
    }
    // i/size retorna a divisão arredondada
    // i%size retorna o reso da divisão
    
    for(int i = 0; i < (size * size); ++i) 
    {
        fscanf(matriz, "%d", &valor);
        matrizResultado[i / size][i % size] += valor; //
    }

    imprime_matriz(matrizResultado, size, size);

    liberar_Matriz(matrizResultado, size);
    fclose(matriz);

    getchar();
    return 0;
}

