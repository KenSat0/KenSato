#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v = NULL;
    
    v = (int*) malloc(9 * sizeof(int));

    if (v==NULL) printf("Falha no alocamento");
    
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i<3; i++)
    {
        
        for (int j = 0; j<3; j++)
        {
            printf("%d ", v[i * 3 + j]);
        }

        printf("\n");
    }

    free(v);
    getchar();
    return 0;
}