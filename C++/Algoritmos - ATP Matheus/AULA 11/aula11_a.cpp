#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Arquivos:
//  valores padroes em funções
//  argumentos
//  leitura e escrita em arquivos

void imprimirNome(char *nome = "ninguem") //se não receber um argumento, ele usa o valor padrão "ninguem"
{
    printf("Saudacoes, %s!", nome);
}

int main(int argc, char *argv[])
{
    float num0 = atof(argv[1]);
    char op = argv[2][0];
    float num1 = atof(argv[3]);

    if (op == '+') printf("%f\n", num0+num1);
    else if (op == '-') printf("%f\n", num0-num1);

    for (int i = 0; i < argc; i++)
    {
        printf("[%d] %s\n", i, argv[i]);
    }

    //obs.: tentar fazer uma calculadora usando argc e argv, com as quatro operações basicas e prioridade de operações (* e / antes de + e -)
    //extra: com isso ja da pra fazer até a prioridade de parentesis

    /*

    Funções da biblioteca string.h 
    
    atoi (a to i): transforma string em int
    atol (a to l); transforma em long int
    atoll: long long int
    atof (a to f): string para double (ponto flutuante de dupla precisão)
    strtol: transforma string em long int com base especificada
    strtoll: long long int com base especificada

    */

    getchar();
    return 0;
}