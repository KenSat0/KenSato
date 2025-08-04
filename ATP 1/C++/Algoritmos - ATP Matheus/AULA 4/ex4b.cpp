/*Imprima o valor 333,546372 em uma largura de campo de 15 caracteres com precisões de 1, 2, 3, 4 e 5. Alinhe a saída
à esquerda. Quais são os cinco valores impressos?*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a = 333.546372;
    char c;

    printf("\n%.1f\n%.2f\n%.3f\n%.4f\n%.5f", a, a, a, a, a);

    scanf("%c", &c);
    return(0);
}