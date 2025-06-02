#include <stdio.h>
#include <stdlib.h>

int *separa_par (int *v, int n, int *n_t)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i]%2 == 0) count++; //contagem ed quantos pares tem em V
    }
    
    int *s = (int*)malloc(count*sizeof(int)); //alocação de espaço para S
    if (s==NULL)
    {
        *n_t = 0;
        return NULL;  //falha na alocação
    }

    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i]%2 == 0)
        {
            s[a++] = v[i];
        }
    }
    
    *n_t = count;

    return (s);
}

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(v)/sizeof(v[0]);

    int t_s;
    int *s = separa_par(v, n, &t_s);

    printf("\nVetor de pares: ");
    for (int i = 0; i < t_s; i++) 
    {
        printf("%d ", s[i]);
    }

    free(s);
    getchar();
    return 0;
}