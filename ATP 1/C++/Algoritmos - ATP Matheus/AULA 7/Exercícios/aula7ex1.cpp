/*escreva um programa que receba uma string e imprime a primeira letra dela no formato:

<palavra> começa com <letra> */

#include <stdio.h>
#include <stdlib.h>


int main ()
{
    char palavra[100];

    printf("Digite a palavra: ");
    scanf("%s", palavra);

    printf("%s comeca com %c\n", palavra, palavra[0]);

    getchar();
    return 0;
}
