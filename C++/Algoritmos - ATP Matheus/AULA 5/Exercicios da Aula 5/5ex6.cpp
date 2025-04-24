#include <stdio.h>
#include <stdlib.h>

int eh_palindromo(int numero) 
{
    if (numero < 0) return 0;  // Números negativos não são palíndromos

    int original = numero; // original guarda o numero em sua ordem de digitos orignal
    int invertido = 0;

    while (numero != 0) 
    {
        int digito = numero % 10; //ao realizar numero%10, temos o ultimo digito, que é guardado em digito
        invertido = invertido * 10 + digito; //invertido guarda o ultimo digito, e depois multiplica ele por 10, para guardar o proximo digito na casa das unidades (portanto guardando o numero em ordem invertida)
        numero = numero / 10; //numero é dividido por 10, por se tratar de uma variavel inteira, o resto é ignorado, portanto excluindo o ultimo digito ja guardado em "Invertido"
    }

    if (original == invertido) 
    
{
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int pal = eh_palindromo(121);

    printf("%d", pal);

    return 0;
}