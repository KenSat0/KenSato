/*Crie um programa que:
○ Declare dois vetores A e B de tamanho 5;
○ Leia os valores para ambos os vetores;
○ Imprima os valores de maneira intercalada (A[0], B[0], A[1], B[1]...). */

#include <stdio.h>
#include <stdlib.h>


int main ()
{
    int vetor_a[5];
    int vetor_b[5];

    printf("Digite 5 valores para o vetor A:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vetor_a[i]);
    }

    printf("Digite 5 valores para o vetor B:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &vetor_b[i]);
    }

    printf("Valores Intercalados:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d %d ", vetor_a[i], vetor_b[i]);
    }

    getchar();
    return 0;
}
