#include <stdio.h>
#include <stdlib.h>

float calc_imc(float kg, float m)
{
    float imc = kg/(m*m);
    if (imc < 18.5) return 0;
    if (imc <= 24.9) return 1;
    if (imc <= 29.9) return 2;
    return 3;

}

void imprima_imc(float kg, float m)
{
    int result = calc_imc(kg, m);
    if (result == 0)
    {
        printf("Magreza");
    }
    else if (result == 1)
    {
        printf("Saudavel");
    }
    else if (result == 2)
    {
        printf("Sobrepeso");
    }
    else
    {
        printf("Obesidade");
    }
}

int main()
{
    float kg, m;
    scanf("%f", &kg);
    scanf("%f", &m);
    imprima_imc(kg, m);

    getchar();
    return (0);
}