#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a;
    char ch;
    printf("Digite um numero para a altura do triangulo: ");
    scanf("%d", &n);

    a = n;
    while (a > 0)
    {
        while (n > 0)
        {   
            printf("*");
            n--;
        }
        printf("\n");
        a--;
        n = a;
    }

    scanf("%c", &ch);
    return(0);
}