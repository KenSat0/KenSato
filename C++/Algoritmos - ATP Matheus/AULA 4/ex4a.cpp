//Somar os inteiros ímpares entre 1 e 99 usando uma estrutura for. Considere que as variáveis inteiras soma e contador
//tenham sido declaradas.

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int soma = 0;
    char c;

    for (int cont = 1; cont <= 100; cont++)
    // para todos os numeros de 1 a 100
    {
        if (cont % 2 != 0) {
        //quando o numero for impar
            soma = soma + cont;

        // soma recebe seu valor anterios (0 no inicio) + a contagem
        }
    }

    printf("%d\n", soma); // Deve imprimir 2500

    scanf(" %c",&c);
    return 0;
}