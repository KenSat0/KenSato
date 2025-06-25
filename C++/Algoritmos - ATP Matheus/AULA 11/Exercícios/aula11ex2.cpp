/*Faça uma função para arredondar valor para dada casas. Se casas não for
fornecido, arredonde para 0 casas decimais (casas = 0).*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // para usar round()

double round_custom(double valor, int casas) {
    double fator = pow(10.0, casas);

    return round(valor * fator) / fator;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <valor> <casas_decimais>\n", argv[0]);
        return 1;
    }

    double valor = atof(argv[1]);
    int casas = atoi(argv[2]);

    double resultado = round_custom(valor, casas);

    printf("Resultado: %.*f\n", casas, resultado);

    return 0;
}