#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i = 2, primo = 1;
    char c;
    printf("Entrada: ");
    scanf("%d", &num);

    if (num <= 1)
    {
        printf("nao e primo");
    }
    else
    {
        while (i<num && primo == 1)
        {
            if (num%i==0)
            {
                primo=0;
            }
            i++;
        }

        if (primo)
        {
            printf("e primo");
        }
        else
        {
            printf("nao e primo");
        }

    }
    scanf("%c", c);
    return(0);
}