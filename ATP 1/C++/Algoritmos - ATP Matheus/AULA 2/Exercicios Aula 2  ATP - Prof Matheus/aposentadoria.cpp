#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade, servico;

    printf("\nDigite sua idade e tempo de servico: ");
    scanf("%d %d", &idade, &servico);
    //recebe input inteiro para idade e tempo de serviço

    if (idade<servico)
    {
        printf("Voce esta mentindo");
        //não tem como trabalhar mais do que a sua idade
    }
    else if (idade >= 65 || servico >= 30 || (idade>=60 && servico >=25))
    {
        printf("Pode aposentar");
        //pode aposentar para as condições 
            //idade maior ou igual a 65
            //tempo de serviço maior ou igual a 30
            //idade maior ou igual a 60 E tempo de serviço maior ou igual a 25
    }
    else
    {
        printf("Nao pode aposentar");
        // fora das condições, não aposenta
    }

    getchar();
    return(0);
}