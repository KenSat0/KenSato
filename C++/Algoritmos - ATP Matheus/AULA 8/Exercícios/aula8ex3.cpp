#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v = NULL;
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

    for (int i = 0; i < T; i++) printf("%d ", v[i]);

    free(v);        
    getchar();
    return 0;
}