#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int total, entrada;

    total = 0;
    entrada = 0;

    while(entrada != 4)
    {
        printf("Posso anotar seu pedido?\n\n");
        printf("1: X-Burger - R$12\n");
        printf("2: Batata - R$8\n");
        printf("3: Refri - R$6\n");
        printf("4: Encerrar pedido \n");
        printf("Entrada: ");
        scanf("%d", &entrada);

        if (entrada == 1)
        {
            total = total + 12;
        }

        else if (entrada == 2)
        {
            total = total + 8;
        }
        
        else if (entrada == 3)
        {
            total = total + 6;
        }
    }

        printf("Seu total e R$%d,00", total);

    scanf("%c");
    return(0);
}