#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, soma;
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    soma = a + b;
    printf("%d", soma);

    getchar();
    return (0);
}