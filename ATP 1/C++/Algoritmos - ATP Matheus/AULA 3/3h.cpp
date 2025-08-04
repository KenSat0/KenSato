#include <stdio.h>
#include <stdlib.h>

int main() 
{
    //codigo que imprime os numeros de 1 a 10 com a função for

    for (int a = 0; a <= 100; a++)
    {
        if ((a%2) == 1) continue;
        printf("%d\n", a);
        //imprime todos os pares de 0 a 100
        //se trocar ((a%2) == 1) por ((a%2) == 0), imprime os impares 
    }

    scanf("%c");
    return(0);
}