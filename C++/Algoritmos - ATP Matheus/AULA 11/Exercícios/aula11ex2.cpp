/*Faça uma função para arredondar valor para dada casas. Se casas não for
fornecido, arredonde para 0 casas decimais (casas = 0).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float arredondar(float valor, int casas = 0)
{
    float fator = 1.0;

    for (int i = 0; i < casas; i++) fator = fator * 10.0;
    
    if (valor >= 0) return (int)(valor * fator +0.5)/fator;
    else return (int)(valor * fator - 0.5)/fator;

}

int main(int argc, char *argv[])
{
    float valor = atof(argv[1]);
    int casas = atoi(argv[2]);

    printf("\n%f", arredondar(valor, casas));

    getchar();
    return 0;
}