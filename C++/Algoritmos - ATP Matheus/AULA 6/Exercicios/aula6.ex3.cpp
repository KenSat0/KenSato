/*programa que imprime a quantidade de digitos de um inteiro*/

#include <stdio.h>
#include <Stdlib.h>


int n_de_digitos(int n)
{

    if (n<10) return (1);
    return(1+n_de_digitos(n/10));

}

int main()
{
    int x;
    printf("Digite o numero: ");
    scanf("%d", &x);
    printf("%d", n_de_digitos(x));

    getchar();
    return 0;
}