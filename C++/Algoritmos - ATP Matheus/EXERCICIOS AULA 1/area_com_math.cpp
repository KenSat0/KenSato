#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float raio, area;

    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);

    area = 3.1415 * pow(raio, 2);

    printf("A area e %.4f", area);

    return(0);
//area = pi*r²
}