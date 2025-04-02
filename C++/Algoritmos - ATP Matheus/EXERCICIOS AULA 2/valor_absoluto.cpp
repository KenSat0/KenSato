#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    printf("Digite um numero inteiro: ");
    scanf("%d", &a);
    //recebe um input inteiro e guarda ele na variavel a

    if (a<0)
    {
        a = -a;
        printf("\nValor Absoluto: %d", a);
        //se a é negativo, o absoluto é o oposto
    }
    else
    {
        printf("\nValor Absoluto: %d", a);
        //se a é positivo (ou zero), o absoluto é o mesmo de a
    }

    getchar();
    return(0);
}