#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, som, sub, mult, div;

    printf("Digite o valor de a: ");
    scanf("%f", &a);

    printf("Digite o valor de b: ");
    scanf("%f", &b);

    som = a + b;
    sub = a - b;
    mult = a * b;
    div = a / b;

    printf("Soma: %.2f\nSubtracao: %.2f\nMultiplicacao: %.2f\nDivisao: %.2f", som, sub, mult, div);

    getchar();
    return (0);
}