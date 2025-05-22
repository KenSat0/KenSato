/*Crie uma função que verifique se um elemento x está presente no vetor A de
tamanho T.*/

#include <stdio.h>
#include <stdlib.h>

int pertence(int t, int x, int *v)
{
    for (int i = 0; i<t; i++)
    {
        if (x==v[i]) return 1;
    }

    return 0;
}

//alternativa para o ex4

void intersecao(int *a, int *b, int t)
{
    for (int i = 0; i<t; i++)
    {
        if (pertence(5, a[i], b)) printf("\n%d", (a[i]));
    }
}

int main ()
{
    int a[5] = {1,3,5,7,9};

    int b[5] = {0,3,6,8,5};
    
    printf("%d",pertence(5, 2, a));

    intersecao(a, b, 5);

    getchar();
    return 0;
}
