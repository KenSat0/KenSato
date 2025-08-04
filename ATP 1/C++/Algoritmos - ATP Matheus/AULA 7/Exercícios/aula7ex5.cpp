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
    int a[100], T;
    
    printf("Tamanho do vetor:\n");
    scanf("%d", &T);

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i<T; i++)
        scanf("%d", &a[i]);

    invert(a, T);

    printf("Vetor invertido:\n");
    for (int i = 0; i<T; i++)
        printf("%d ", a[i]);

    getchar();
    return 0;
}
