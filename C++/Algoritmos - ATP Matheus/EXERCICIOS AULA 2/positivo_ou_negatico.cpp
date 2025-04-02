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
        printf("\n%d e negativo", a);
        //no caso de a<0, a é negativo
    }
    else if (a>0)
    {
        printf("\n%d e positivo", a);
        //no caso de a>0, a é positivo
    }
    else
    {
        printf("\n%d e neutro/nulo", a);
        //se nenhum dos casos anteriores acontecem a=0, então é nulo/neutro
    }

    getchar();
    return(0);
}