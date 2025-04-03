#include <stdio.h>
#include <stdlib.h>

int main()
{
    int op, a, b;
    char oi;

    while (op != 5)
    {
    printf("Escolha uma operacao\n");
    printf("1: Adicao\n");
    printf("2: Subtracao\n");
    printf("3: Produto\n");
    printf("4: Quociente\n");
    printf("5: Fechar calculadora\n");
    printf("Entrada: ");
    scanf("%d", &op);

        if (op == 1)
        {
            printf("Digite valores para A e B: \n");
            scanf("%d %d", &a, &b);

            a=a+b;

            printf("%d\n", a);
        }
        else if (op == 2)
        {
            printf("Digite valores para A e B: \n");
            scanf("%d %d", &a, &b);

            a=a-b;

            printf("%d\n", a);
        }
        else if (op == 3)
        {
            printf("Digite valores para A e B: \n");
            scanf("%d %d", &a, &b);

            a=a*b;

            printf("%d\n", a);
        }
        else if (op == 4)
        {
            printf("Digite valores para A e B: \n");
            scanf("%d %d", &a, &b);

            a=a/b;

            printf("%d\n", a);
        }
    }

    scanf("%c", oi);
    return(0);
}
