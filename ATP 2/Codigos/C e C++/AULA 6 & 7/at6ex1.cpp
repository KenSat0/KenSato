#include <stdio.h>
#include <stdlib.h>

int digito(int numero)
{
    if(numero<10)
    {
        printf("\n%d", numero);
        return 0;
    }
    printf("\n%d", numero%10);
    numero = numero/10;

    return digito(numero);
}

int main()
{
    digito(1945);

    getchar();
    return 0;
}