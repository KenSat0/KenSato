#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b;
    printf("Digite o valor de a: ");
    scanf("%f", &a);

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    a = a + b;
    printf("%f", a);

    getchar();
    return (0);
}