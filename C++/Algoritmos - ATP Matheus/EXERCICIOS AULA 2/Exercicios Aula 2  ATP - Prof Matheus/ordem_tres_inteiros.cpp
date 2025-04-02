#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, temp;

    printf("Digite os tres numeros: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    // recebe 3 inputs inteiros e guarda nas variaveis num1, num2 e num3

    if (num1 > num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    //se o num1 for maior num2, ele troca
    }

    if (num1 > num3)
    {
        temp = num1;
        num1 = num3;
        num3 = temp;
     //se o num1 for maior num3, ele troca
    }
    
    if (num2 > num3)
    {
        temp = num2;
        num2 = num3;
        num3 = temp;
     //se o num2 for maior que num3, ele troca
    }

    printf("A ordem e: %d %d %d", num1, num2, num3);

    getchar();
    return(0);
}