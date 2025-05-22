/*4. Faça uma função que dados dois vetores A e B de tamanho T, imprima os
elementos que estão em ambos os vetores.*/

#include <stdio.h>
#include <stdlib.h>

int intersecao(int t, int *a, int *b)
{
    for (int i = 0; i<t; i++)
    {
        for (int j = 0; j<t; j++)
        {
            if (b[i]==a[j]) printf("%d", b[i]);
        }
    }

    return 0;
}

int main ()
{
    int a[5] = {1,3,5,7,9};
    int b[5] = {2,3,5,7,11};
    
    intersecao(5, a, b);

    getchar();
    return 0;
}
