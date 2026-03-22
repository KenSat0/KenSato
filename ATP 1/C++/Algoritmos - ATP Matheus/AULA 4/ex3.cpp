//Escreva um programa que peça ao usuário que digite dois inteiros, obtenha os números e 
//depois imprima o maior número seguido das palavras 'é maior'. Se os números forem iguais,
//imprima a mensagem "Esses números são iguais". Use apenas a forma de seleção única da
//instrução if que você aprendeu neste capítulo.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char dd;

    printf("Digite dois numeros inteiros: \n");
    scanf("%d %d", &a, &b);

    if (a>b)
    {
        printf("%d e maior que %d\n", a, b);
    }
    if (b > a)
    {
        printf("%d e maior que %d\n", b, a);
    }
    if (a==b)
    {
        printf("Os numeros sao iguais");
    }

    scanf("%c", &dd);
    return(0);
}