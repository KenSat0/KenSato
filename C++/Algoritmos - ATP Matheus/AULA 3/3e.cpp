#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int a;
    a = 1;
    //codigo que imprime os numeros de 1 a 10 com a função do-while

    do
    {
        printf("%d\n", a);
        a++;
    }
    while (a <= 10);

    scanf("%c");
    return(0);
}