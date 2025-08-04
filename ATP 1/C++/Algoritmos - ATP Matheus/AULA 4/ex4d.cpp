#include <stdio.h>
#include <stdlib.h>

int main() 
{
    //codigo que imprime os numeros de 1 a 20 com a função while

    int x = 1;
    char c;

    while (x <= 20)
    {
        printf("%d", x);

        if(x%5==0)
        {
            printf("\n");
        }
        else
        {
            printf("    ");
        }

        x++;
    }

    scanf("%c",&c);
    return(0);
}