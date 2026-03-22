#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int numero;
    int dias;
    float *calorias;
    float peso_inicial;
    float peso_final;
    int alta;

} Registro;

Registro *hospedes[20];
int qnt_hosp = 0;

int imprime(int num)
{
    printf("\nNome: %s", hospedes[num-1]->nome);
    printf("\nDias: %d", hospedes[num-1]->dias);
    printf("\nCalorias por dia: ");

    for (int i = 0; i<hospedes[num-1]->dias; i++)
    {
        printf("\n    Dia %d: %f", i+1, hospedes[num-1]->calorias[i]);
    }

    printf("\nPeso inicial: %f", hospedes[num-1]->peso_inicial);
    
    if(hospedes[num-1]->alta==1)
    {
        printf("\nPeso final: %f", hospedes[num-1]->peso_final);
    }
    else
    {
        printf("\nPeso final: nao registrado");
    }

    printf("\n\n\n");
    return 0;
}

int cadastro()
{
    int num;

    if(qnt_hosp == 20)
    {
        perror("\nspa cheio");
        return 1;
    }

    printf("\nNumero de ficha (1-20): ");
    scanf("%d", &num);
    
    if (num < 1 || num > 20)
    {
        perror("\nnumero invalido");
        return 1;
    }

    if (hospedes[num-1] != NULL)
    {
        perror("\nficha sendo utilizada");
        return 1;
    }

    hospedes[num-1] = (Registro*)malloc(sizeof(Registro));

    hospedes[num-1]->numero = num;

    if (hospedes[num-1]==NULL)
    {
        perror("\nalocacao de memoria falhou");
        return 1;
    }

    hospedes[num-1]->alta=0;

    printf("\nNome: ");
    scanf("%s", hospedes[num-1]->nome);

    printf("\nPeso Inicial: ");
    scanf("%f", &hospedes[num-1]->peso_inicial);

    printf("\nDias: ");
    scanf("%d", &hospedes[num-1]->dias);

    hospedes[num-1]->calorias = (float*)malloc(hospedes[num-1]->dias * sizeof(float));
    if (hospedes[num-1]->calorias == NULL)
    {
        perror("falha na alocacao de memoria para calorias");
        return 1;
    }

    for(int i=0; i<hospedes[num-1]->dias; i++)
    {
        float cont = 0;

        printf("\ncalorias no dia %d: ", i+1);
        scanf("%f", &cont);

        hospedes[num-1]->calorias[i]=cont;
    }

    printf("\n\n\n");

    imprime(num);

    qnt_hosp++;

    return 0;
}

int baixa()
{
    int num;
    if(qnt_hosp == 0)
    {
        perror("\nspa vazio");
        return 1;
    }
    
    printf("\nNumero de ficha: ");
    scanf("%d", &num);

    if (num < 1 || num > 20)
    {
        perror("\nnumero invalido");
        return 1;
    }

    if(hospedes[num-1]==NULL)
    {
        perror("\nficha inexistente");
        return 1;
    }

    hospedes[num-1]->alta=1;

    printf("\nPeso final: ");
    scanf("%f", &hospedes[num-1]->peso_final);

    printf("\n\n\n");

    imprime(num);

    printf("\nResultado: %f quilos foram perdidos", hospedes[num-1]->peso_inicial-hospedes[num-1]->peso_final);

    free(hospedes[num-1]->calorias);
    free(hospedes[num-1]);

    qnt_hosp--;

    return 0;
}

int main()
{  
    while(true)
    {
        int menu = 0;
        printf("\n1 - Cadastrar ficha");
        printf("\n2 - Dar baixa em ficha");
        printf("\n3 - Encerrar programa");

        printf("\nO que deseja fazer: ");

        scanf("%d", &menu);

        printf("\n\n(Obs.: Guarde registros fisicos das fichas antes de dar alta)\n");

        if(menu==1) cadastro();
        if(menu==2) baixa();
        if(menu==3) return 0;
    }

    getchar ();
    return 0;
}