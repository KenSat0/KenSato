#include <stdio.h>
#include <stdlib.h>

int primo = 0;

float eh_primo(int i)
{
    if (i <= 1) return 0;
    for (int cont = 2; cont<i; cont++)
    {
        if ((i%cont)==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int x;
    printf("Digite um numero inteiro: ");
    scanf("%d", &x);
    x = eh_primo(x);

    printf("%d", x);
    
    getchar();
    return 0;
}