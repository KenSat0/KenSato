#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nome[50];
    int numero;
    float peso_entrada;
    float peso_saida;
    int dias;
    float *calorias;
    int alta;
} Registro;

Registro *hospedes[20];
int qnt_hosp = 0;

void imprime(int numero)
{
    printf("\n\n");
    printf("\n--------------------");
    printf("\nNome: %s", hospedes[numero-1]->nome);
    printf("\nNumero: %d", hospedes[numero-1]->numero);
    printf("\nPeso na entrada: %.2f", hospedes[numero-1]->peso_entrada);
    printf("\nDias: %d", hospedes[numero-1]->dias);
    for(int i = 0; i<hospedes[numero-1]->dias; i++)
    {
        printf("\n\tDia %d: %.2f", i+1, hospedes[numero-1]->calorias[i]);
    }
    if(hospedes[numero-1]->alta==1)
    {
        printf("\nPeso ao sair: %.2f", hospedes[numero-1]->peso_saida);
        float diferenca = hospedes[numero-1]->peso_entrada - hospedes[numero-1]->peso_saida;
        printf("\n\tPeso perdido: %.2f", diferenca);
    }
    else
    {
        printf("\nPeso ao sair: Nao registrado");
    }
    printf("\n--------------------");
    return;
}

void cadastrar()
{
    printf("\n\n");
    int numero;
    if (qnt_hosp == 20)
    {
        perror("\nSPA Cheio");
        return;
    }

    printf("\nNumero: ");
    scanf("%d", &numero);

    if(hospedes[numero-1] != NULL)
    {
        perror("\nFIcha ocupada");
        return;
    }

    if(numero < 1 || numero > 20)
    {
        perror("\nNumero invalido");
        return;
    }

    hospedes[numero-1] = (Registro*)malloc(sizeof(Registro));
    if(hospedes[numero-1]==NULL)
    {
        perror("\nFalha em alocacao");
        return;
    }

    hospedes[numero-1]->numero = numero;

    char nome[50];
    
    printf("\nNome: ");
    scanf("%s", nome);
    strcpy(hospedes[numero-1]->nome, nome);

    printf("\nDias: ");
    scanf("%d", &hospedes[numero-1]->dias);

    printf("\nPeso Inicial: ");
    scanf("%f", &hospedes[numero-1]->peso_entrada);

    hospedes[numero-1]->calorias = (float*)malloc(hospedes[numero-1]->dias * sizeof(float));
    for(int i = 0; i < hospedes[numero-1]->dias; i++)
    {
        printf("\nCalorias no dia %d: ", i+1);
        scanf("%f", &hospedes[numero-1]->calorias[i]);
    }

    hospedes[numero-1]->alta = 0;
    imprime(numero);
    qnt_hosp++;
    return;
}

void alta()
{
    printf("\n\n");
    int numero;
    
    printf("\nNumero: ");
    scanf("%d", &numero);

    if(qnt_hosp == 0)
    {
        perror("\nSPA Vazio");
        return;
    }
    if(numero <1 || numero >20)
    {
        perror("\nNumero invalido");
        return;
    }
    if(hospedes[numero-1]==NULL)
    {
        perror("\nFicha nao existe");
        return;
    }

    hospedes[numero-1]->alta=1;

    printf("\nPeso ao sair: ");
    scanf("%f", &hospedes[numero-1]->peso_saida);

    imprime(numero);

    printf("\nObs.: Registre a ficha em meio fisico antes de fechar o programa");

    free(hospedes[numero-1]->calorias);
    free(hospedes[numero-1]);
}

int main()
{
    int menu;
    while(true)
    {
        printf("\n\n\n1 - Cadastrar\n2 - Alta\n3 - Sair\nO que deseja fazer: ");
        scanf("%d", &menu);
        if(menu==1) cadastrar();
        if(menu==2) alta();
        if(menu==3) return 0;
    }
}