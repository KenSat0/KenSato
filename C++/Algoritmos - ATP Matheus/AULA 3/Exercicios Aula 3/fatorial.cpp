#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m = -1;
    printf("Digite um numero natural: ");
    scanf("%d", &n);

    while (n > 0)
    {
        m = m * n;
        n--;
    }

    printf("Fatorial: %d", n);

    scanf("%c");
    return(0);
}