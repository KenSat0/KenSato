/*Escreva uma função que Use dois ponteiros para inverter a ordem dos elementos
de um array.*/

#include <stdio.h>
#include <stdlib.h>

void invert(int *a, int t)
{
    int *inicio = a;
    int *final = a+t-1;

    while (inicio < final)
    {
        int temp;

        temp = *inicio;
        *inicio = *final;
        *final = temp;

        inicio++;
        final--;
    }
    
}

int main ()
{
    int a[5] = {1,2,3,4,5};
    
    invert(a, 5);

    for (int i = 0; i<5; i++)
    printf("%d ", a[i]);

    getchar();
    return 0;
}
