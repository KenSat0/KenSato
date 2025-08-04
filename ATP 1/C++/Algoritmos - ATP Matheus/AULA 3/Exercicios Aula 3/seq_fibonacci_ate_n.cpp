#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, temp = 1, fib = 0;
    char ch;
    printf("Digite o numero ate o qual voce deseja imprimir: ");
    scanf("%d", &n);

    while (fib<=n)
    {   
        printf("\n%d", fib);
        fib = fib + temp;
        temp = fib - temp;
    }

    scanf("%c", &ch);
    return(0);
}