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

int main ()
{
    int v[100], t, x;

    printf("Tamanho do vetor: ");
    scanf("%d", &t);

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < t; i++) 
    {
        scanf("%d", &v[i]);
    }

    printf("Digite o elemento a procurar: ");
    scanf("%d", &x);

    if (pertence(t, x, v))
        printf("Elemento %d encontrado.\n", x);
    else
        printf("Elemento %d nao encontrado.\n", x);

    getchar();
    return 0;
}
