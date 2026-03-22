/*

Faça uma função para arredondar valor para dada casas. Se casas não for
fornecido, arredonde para 0 casas decimais (casas = 0).

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // para usar round()

double round_custom(double valor, int casas) {
    double fator = pow(10.0, casas); //cada casa representa uma potencia de 10 (1=10 / 2=100...)

    return round(valor * fator) / fator;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <valor> <casas_decimais>\n", argv[0]);
        return 1;
    } //verifica a quantidade de argumentos de entrada

    //converte string em float e int
    double valor = atof(argv[1]);
    int casas = atoi(argv[2]);

    double resultado = round_custom(valor, casas);

    printf("Resultado: %.*f\n", casas, resultado);

    return 0;
}