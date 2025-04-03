#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, p;
    printf("Digite um numero natural: ");
    scanf("%d", &n);

    m = n;
    p = 0;

    while (m != 1)
    {   
        m = m-1;
        while ((n%m)!=0)
        {
            p = 1;
        }
    }
    
    if (p == 0)
    {
        printf("nao e primo");
    }

    else
    {
        printf("e primo");
    }

    scanf("%c");
    return(0);
}