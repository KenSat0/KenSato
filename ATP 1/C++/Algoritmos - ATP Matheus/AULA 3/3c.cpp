#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int a;
    a = 1;
    //codigo que imprime os numeros pares de 0 a 10 com a função de loop
    
    while (a <= 10)
    {
        printf("%d\n", a);
        a = a + 2;
    }

    scanf("%c");
    return(0);
}