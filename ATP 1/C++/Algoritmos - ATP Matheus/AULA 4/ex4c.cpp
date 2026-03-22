/*Calcule o valor de 2.5 elevado à potência 3 usando a função pow. Imprima o resultado com uma precisão de 2 em uma
largura de campo de 10 posições. Qual é o valor impresso?*/

//não entendi o que quer dizer "largura de campo de 10 posições"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a = 2.5;
    char c;

    a = pow(a, 3);

    printf("%.2f", a);

    scanf("%c", &c);
    return(0);
}