#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    a = a + b;
    printf("%d", a);

    getchar();
    return (0);
}