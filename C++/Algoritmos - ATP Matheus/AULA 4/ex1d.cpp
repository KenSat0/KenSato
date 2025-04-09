#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x;
    char dd;

    printf("Digite um numero inteiro: ");
    scanf("%d", &x);

    if (x != 7)
    {
        printf("\nA variavel numero nao e 7");
    }
    

    scanf("%c", &dd);
    return(0);
}