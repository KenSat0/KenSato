#include <stdio.h>
#include <stdlib.h>

int eh_palindromo(int numero) 
{
    if (numero < 0) return 0;

    int original = numero;
    int invertido = 0;

    while (numero != 0)
    {
        int digito = numero % 10;
        invertido = invertido * 10 + digito;
        numero = numero / 10;
    }

    // o laço extrai o ultimo digito com "numero%10" e armazena em "invertido", depois esse digito é tirado de "numero" com "numero / 10"
    // depois o proximo digito é tirado, "invertido * 10 + digito" começa a armazenar os numeros em ordem contraria
    // isso se repete até que todos os digitos tenham sido armazenados em Invertido 

    if (original == invertido)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int pal = eh_palindromo(121);

    printf("%d", pal);

    return 0;
}