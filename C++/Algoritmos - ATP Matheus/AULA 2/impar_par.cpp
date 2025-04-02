#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    printf("Digite um numero inteiro: ");
    scanf("%d", &a);
    //recebe input inteiro e guarda na variavel a

    if (a%2)
    //se o resto é 1, o "if" le como verdadeiro, e roda o comando abaixo, caso o resto seja zero, pula para "else"
    {
        printf("%d e impar", a);
        //resto = 1, numero impar
    }
    else
    {
        printf("%d e par", a);
        //resto diferente de 1 (no caso zero) par
    }

    getchar();
    return(0);
}