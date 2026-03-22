#include <stdio.h>
#include <stdlib.h>

float a = 2.0f;
float b = 3.0f;
float c = 5.0f;

float quad(float x)
{
    return (a*x*x + b*x + c);
}

int main()
{
    float x;
    printf("Digite o valor de X: ");
    scanf("%f", &x);
    x = quad(x);

    printf("Para o X designado, a funcao 2x^2 + 3x + 5 = %.2f", x);

    getchar();
    return 0;
}
