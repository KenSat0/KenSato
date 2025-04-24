#include <stdio.h>
#include <stdlib.h>

float perimetro, area;

void calcular_circulo(float *raio)
{
    perimetro = 3.14 * 2 * *raio;
    area = 3.14 * *raio * *raio;
    
}

int main()
{
    float raio = 3;

    calcular_circulo(&raio);

    printf("%f\n%f", perimetro, area);

    return 0;
}