#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b = 1;
    char ch;
    printf("Digite um numero para a altura do triangulo: ");
    scanf("%d", &n);

    while (b <= n)
    {
        a = b;
        while (b != 0)
        {   
            printf("*");
            b--;
        }
        printf("\n");
        a++;
        b = a;

    }

    scanf("%c", &ch);
    return(0);
}