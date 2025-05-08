/*programa que imprime a somatoria de um n+(n-1)...+1*/

#include <stdio.h>
#include <Stdlib.h>
#include <time.h>

int somatorio(int n)
{
    if (n==1) return (1);
    return(n+somatorio(n-1));
}

int main()
{
    int x;
    printf("Digite o numero para realizar a somatorio: ");
    scanf("%d", &x);
    printf("%d", somatorio(x));

    getchar();
    return 0;
}