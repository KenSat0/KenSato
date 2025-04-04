#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, temp = 1, fib = 0;
    char ch;
    printf("Digite a posicao do termo de fibonacci que voce deseja: ");
    scanf("%d", &n);

    while (n > 1)
    {   
        n--; 
        fib = fib + temp;
        temp = fib - temp;
    }

    printf("O termo e: %d", fib);

    scanf("%c", &ch);
    return(0);
}