#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, f = 1;
    char a;
    printf("Digite um numero natural: ");
    scanf("%d", &n);

    while (n > 0)
    {
        f = f * n;
        n--;
    }

    printf("Fatorial: %d", f);

    scanf("%c", a);
    return(0);
}