#include <stdio.h>
#include <stdlib.h>

int main() 
{
    //codigo que imprime os numeros de 1 a 20 com a função for

    int x = 1;

    for (int x = 1; x <= 20; x++)
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
    }

    scanf("%c");
    return(0);
}