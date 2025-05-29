#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v = NULL;
    int n;

    printf("\nDigite o tamanho do vetor:");
    scanf("%d", &n);

    v = (int*) malloc(n * sizeof(int));

    if (v==NULL) 
    {
        printf("Erro de alocação");
        return 1;
    }

    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    printf("O vetor e:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

        free(v);
        getchar();
        return 0;
}