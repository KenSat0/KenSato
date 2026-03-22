#include <stdio.h>
#include <stdlib.h>

int cont = 0;

int potencia(int numero, int expoente)
{
    if(expoente==1)
    {
        return (numero);
    }
    numero = numero * numero;
    expoente--;
    return (potencia(numero, expoente));
}

int main()
{
    int result = potencia(3, 2);

    printf("\n%d", result);

    getchar();
    return 0;
}