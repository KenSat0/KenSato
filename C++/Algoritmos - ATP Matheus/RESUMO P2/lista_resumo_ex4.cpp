#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = NULL;
    int tamanho;

    printf("\nTamanho: ");
    scanf("%d", &tamanho);

    array = (int*)malloc(tamanho*sizeof(int));

    if(array==NULL)
    {
        printf("Erro de alocação");
        return 0;
    }

    for (int i = 0; i < tamanho; i++)
    {
        printf("\nDigite o valor de posicao %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\n\nVetor declarado: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("\n%d ", array[i]);
    }

    if ((tamanho%2)==1) tamanho++;

    realloc(array, tamanho/2*sizeof(int));


    printf("\nMetade do Vetor: ");
    for (int i = 0; i < (tamanho/2); i++)
    {
        printf("\n%d ", array[i]);
    }

    free(array);

    return 0;
}