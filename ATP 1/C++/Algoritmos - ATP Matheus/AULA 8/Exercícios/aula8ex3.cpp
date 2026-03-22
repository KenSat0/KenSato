#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v = NULL;
    int x = 0, T = 0;

    printf("Digite os valores do vetor (-1 = parar interacao):\n");
    while(x!=-1)
    {

        printf("Valor %d:\n", T+1);
        scanf("%d", &x);

        if (x!=-1)
        {
            T++;
            int*temp = (int*)realloc(v, T * sizeof(int));

            if (temp == NULL)
            {
            printf("Erro na realocacao de memoria\n");
            free(v);
            return 1;
            }

            v = temp;
            v[T-1] = x;
        }
    }

    printf("Vetor final:\n");
    for (int i = 0; i < T; i++) printf("%d ", v[i]);

    free(v);        
    getchar();
    return 0;
}