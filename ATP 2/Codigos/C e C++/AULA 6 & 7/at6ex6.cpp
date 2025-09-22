#include <stdio.h>
#include <stdlib.h>

int fibonacci(int termo)
{   
    if (termo==1) return 0;
    if (termo==2) return 1;
    int numero = fibonacci(termo-1)+fibonacci(termo-2);
    return(numero);
}   

int main()
{
    int numero;
    printf("Termo: ");
    scanf("%d", &numero);

    printf("Termo %d de fibonacci e: %d", numero, fibonacci(numero));

    getchar();
    return 0;
}