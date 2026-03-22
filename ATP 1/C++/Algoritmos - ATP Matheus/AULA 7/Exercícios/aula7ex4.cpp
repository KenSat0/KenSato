/*4. Faça uma função que dados dois vetores A e B de tamanho T, imprima os
elementos que estão em ambos os vetores.*/

#include <stdio.h>
#include <stdlib.h>

//alternativa 1

int intersecao(int T, int *A, int *B)
{
    for (int i = 0; i<T; i++)
    {
        for (int j = 0; j<T; j++)
        {
            if (B[i]==A[j]) printf("%d ", B[i]);
        }
    }

    return 0;
}

//alternativa 2

int elemento_presente(int *A, int T, int x) {
    for (int i = 0; i < T; i++) {
        if (A[i] == x) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int A[100], B[100], T;

    printf("Tamanho dos vetores: ");
    scanf("%d", &T);

    printf("Digite os valores do vetor A:\n");
    for (int i = 0; i < T; i++) {
        scanf("%d", &A[i]);
    }

    printf("Digite os valores do vetor B:\n");
    for (int i = 0; i < T; i++) {
        scanf("%d", &B[i]);
    }

    printf("Elementos comuns:\n");
    for (int i = 0; i < T; i++) {
        if (elemento_presente(A, T, B[i])) {
            printf("%d ", B[i]);
        }
    }

    printf("\nElementos comuns:\n");
    intersecao(T, A, B);

    return 0;
}