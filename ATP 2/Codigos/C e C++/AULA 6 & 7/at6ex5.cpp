#include <stdio.h>
#include <stdlib.h>

int primo(int numero, int cont)
{   
    if(numero<=1) return 0;
    if(cont==1)
    {
        return 1;
    }
    if(numero%cont==0)
    {
        return 0;
    }
    return(primo(numero, cont - 1));
}   

int main()
{
    int result = primo(11, 10);

    if (result)
    {
        printf("\nE primo");
    }
    else
    {
        printf("\nNao e primo");
    }

    result = primo(10, 9);

    if (result)
    {
        printf("\nE primo");
    }
    else
    {
        printf("\nNao e primo");
    }

    getchar();
    return 0;
}