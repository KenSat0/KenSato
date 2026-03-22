#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, temp;

    printf("\nDigite o tamanho dos lados do triangulo: ");
    scanf("%d %d %d", &a, &b, &c);
    //recebe 3 valores inteiros e guarda nas variaves a, b e c

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if (a > c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    //ordena o tamanho dos lados de menor para maior, no caso do input ser desordenado, deixando a variavel C como hipotenusa

    if ((a*a)+(b*b)==(c*c))
    {
        printf("\nO triangulo e retangulo");
        //se o teorema de pitagoras for verdadeiro, é retangulo
    }
    else
    {
        printf("\nO triangulo nao e retangulo");
        //se não se aplica o teorema de pitagoras, então não é retangulo
    }

    getchar();
    return(0);
}