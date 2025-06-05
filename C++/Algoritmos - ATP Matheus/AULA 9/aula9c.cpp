#include <stdio.h>
#include <stdlib.h>

//problema atual: memoria estatica, ou seja, é o codigo que define o tamanho da matriz

int main()
{
    int **matriz = NULL;

    matriz = (int* *)malloc(sizeof(2*sizeof(int*)));
    
    //alocação de espaço para 2 vetores

    if (matriz==NULL) 
    {
    printf("Erro de alocação");
    return 1;
    }

    for (int i = 0; i < 2; i++)
    {
        matriz [i] = NULL;

        matriz[i] = (int*)malloc(3*sizeof(int));
        if (matriz[i]==NULL) return 1;
    }

    for (int i = 0; i < 2; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    getchar();
    return 0;
}