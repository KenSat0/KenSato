#include <stdio.h>
#include <stdlib.h>

int cont = 0;

int soma_int(int numero)
{
    if(numero==0)
    {
        return (cont);
    }
    cont = cont + numero;
    return (soma_int(numero-1));
}

int main()
{
    int numero;
    printf("Numero: ");
    scanf("%d", &numero);
    printf("\nA soma dos %d primeiros inteiros e: %d", numero, soma_int(numero));

    getchar();
    return 0;
}