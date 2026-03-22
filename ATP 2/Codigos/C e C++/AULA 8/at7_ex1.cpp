#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int soma = 0;

int soma_digitos (int x)
{
    if(x < 10)
    {
        soma += x;
        return soma;
    }
    soma += x%10;
    return(soma_digitos(x/10));
}

int main()
{
    printf("\n%d", soma_digitos(123));

    getchar();
    return 0;
}
