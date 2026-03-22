#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*

cadastro de SPA com 20 hospedes com funções:
    cadastrar
    alta
    (imprimit) -> faciita

*/

typedef struct
{
    char nome[100];
    int numero;
    int dias;
    float peso_entrada;
    float peso_saida;
    float* calorias;
    int alta;

} Ficha;

Ficha *hospedes[20];
int qnt_hosp = 0;

int imprime(int numero)
{
    printf("\n====================");
    printf("\nNome: %s", hospedes[numero-1]->nome);
    printf("\tFicha: %d", hospedes[numero-1]->numero);
    printf("\nDias: %d", hospedes[numero-1]->dias);
    for(int i = 0; i<hospedes[numero-1]->dias; i++)
    {
        printf("\n\tCalorias no Dia %d: %.2f", i+1, hospedes[numero-1]->calorias[i]);
    }
    printf("\nPeso Inicial: %.1f", hospedes[numero-1]->peso_entrada);
    if(hospedes[numero-1]->alta)
    {
        printf("\tPeso Final: %.1f", hospedes[numero-1]->peso_saida);
        printf("\nPerda de peso: %.1f", hospedes[numero-1]->peso_entrada-hospedes[numero-1]->peso_saida);
    }
    else
    {
        printf("\tPeso Final: nao registrado");
    }
    printf("\n====================");

    return 0;
}

int cadastro()
{
    if(qnt_hosp>=20) return 1;
    int numero;

    printf("\nNumero: ");
    scanf("%d", &numero);

    if(numero<1 || numero>20) return 1;
    if(hospedes[numero-1]!=NULL) return 1;

    hospedes[numero-1] = (Ficha*)malloc(sizeof(Ficha));
    if (hospedes[numero-1]==NULL) return 1;

    hospedes[numero-1]->alta=0;
    hospedes[numero-1]->numero = numero;

    char str[100];
    printf("\nNome: ");
    scanf("%s", str);
    strcpy(hospedes[numero-1]->nome, str);

    printf("\nPeso Inicial: ");
    scanf("%f", &hospedes[numero-1]->peso_entrada);

    printf("\nDias: ");
    scanf("%d", &hospedes[numero-1]->dias);

    hospedes[numero-1]->calorias = (float*)malloc(hospedes[numero-1]->dias * sizeof(float));
    if(hospedes[numero-1]->calorias == NULL) return 1;

    for(int i = 0; i<hospedes[numero-1]->dias; i++)
    {
            printf("\nCalorias no dia %d: ", i+1);
            scanf("%f", &hospedes[numero-1]->calorias[i]);
    }

    qnt_hosp++;

    imprime(numero);
    return 0;
}

int baixa()
{
    if(qnt_hosp<1) return 1;

    int numero;

    printf("\nNumero: ");
    scanf("%d", &numero);

    if(numero<1 || numero>20) return 1;
    if(hospedes[numero-1]==NULL) return 1;

    hospedes[numero-1]->alta = 1;
    printf("\nPeso Final: ");
    scanf("%f", &hospedes[numero-1]->peso_saida);

    imprime(numero);

    free(hospedes[numero-1]->calorias);
    free(hospedes[numero-1]);

    return 0;
}

int main()
{
    int menu;
    while(true)
    {
        printf("\n1 - Cadastrar\n2 - Alta\n3 - Sair\nO que fazer: ");
        scanf("%d", &menu);
        if(menu==1) cadastro();
        if(menu==2) baixa();
        if(menu==3) break;
    }

    getchar();
    return 0;
}