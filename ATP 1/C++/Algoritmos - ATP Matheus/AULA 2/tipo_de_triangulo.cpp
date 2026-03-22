#include <stdio.h>
#include <stdlib.h>

int main()
{
    int La, Lb, Lc;

    printf("Digite o tamanho dos tres lados: ");
    scanf("%d %d %d", &La, &Lb, &Lc);

    if(La > Lb + Lc || Lb > Lc + La || Lc > La + Lb)
    {
        printf("Invalido");
        // a soma de 2 lados precisa necessariamente ser maior do que o outro lado para o triangulo existir
    }
    else if (La==Lb==Lc)
    {
        printf("O triangulo e equilatero");
        // quando os tres lados sao iguais
    }
    else if (La == Lb || Lb == Lc || Lc == La)
    {
        printf("O triangulo e isoceles");
        // quando existem dois lados iguais (dado que a possibilidade dos 3 serem iguais ja foi descartada)
    }
    else
    {
        printf("O triangulo e escaleno");
        //se não é equilatero ou isoceles, só pode ser escaleno
    }

    getchar();
    return(0);
}