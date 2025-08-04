/*programa que calcula potencia*/

#include <stdio.h>
#include <Stdlib.h>


int potencia(int base, int expo)
{
    if (expo==1) return(base);
    if (expo<=0) return (1);
    return(base*potencia(base, expo - 1));
}

int main()
{
    int x, y;
    printf("Digite a base: ");
    scanf("%d", &x);
    printf("Digite o expoente (nao suporta expoentes negativos): ");
    scanf("%d", &y);
    printf("%d", potencia(x, y));

    getchar();
    return 0;
}