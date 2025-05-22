/*Crie um programa que:
○ Declare dois vetores A e B de tamanho 5;
○ Leia os valores para ambos os vetores;
○ Imprima os valores de maneira intercalada (A[0], B[0], A[1], B[1]...). */

#include <stdio.h>
#include <stdlib.h>


int main ()
{
    int vetor_a[5] = {0, 2, 4, 6, 8};
    int vetor_b[5] = {1, 3, 5, 7, 9};

    for (int i = 0; i < 5; i++)
    {
        printf("%d %d ", vetor_a[i], vetor_b[i]);
    }
    

    getchar();
    return 0;
}
