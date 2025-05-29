#include <stdio.h>
#include <stdlib.h>

int *separa_par (int *v, int n)
{
    int *s = NULL;
    int cont = 0, j = 0;
    for(int i = 0; i < n; i++)
    {
        if (v[i]%2 == 0)
        {
            cont++;
        }
    }

    s = (int*) malloc(cont*sizeof(int));

    if (s==NULL) return NULL;

    for (int i = 0; i<cont; i++)
    {
        if (v[i]%2 == 0)
        {
            s[j]=v[i];
            j++;
        }  
    }


    return (s);
}

int main()
{
    int *v = NULL;
    int *v2 = NULL;
    int x = 0, T = 0;

    v = (int*) malloc(sizeof(int));

    if (v==NULL) return 1;

    while(x!=-1)
    {
        scanf("%d", &x);
        getchar();

        if (x!=-1)
        {
            T++;
            realloc(v, T * sizeof(int));

            v[T-1] = x;
        }
    }

    v2 = separa_par(v, T);
    for (int i = 0; i< sizeof(v2)/sizeof(int); i++) printf("%d", v2[i]);

    free(v);
    free(v2);
    getchar();
    return 0;
}