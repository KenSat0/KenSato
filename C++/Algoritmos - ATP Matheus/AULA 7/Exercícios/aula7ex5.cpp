/*Escreva uma função que Use dois ponteiros para inverter a ordem dos elementos
de um array.*/

#include <stdio.h>
#include <stdlib.h>

void invert(int *a)
{
    int temp;
    temp = a[0];
    a[0] = a[4];
    a[4] = temp;

    temp = a[1];
    a[1] = a[3];
    a[3] = temp;
}

int main ()
{
    int a[5] = {1,2,3,4,5};
    
    invert(a);

    for (int i = 0; i<5; i++)
    printf("%d", a[i]);

    getchar();
    return 0;
}
