/*Faça uma função recursiva que calcule e retorne o N-ésimo termo da sequência 
Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89... */

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if (n<=1) return 0;
    if (n==2) return 1;
    return (fibonacci(n-1)+fibonacci(n-2));
}

int main()
{
    int n;
    printf("N: ");
    scanf("%d", &n);

    printf("%d", fibonacci(n));

    getchar();
    return 0;
}