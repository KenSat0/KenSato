#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int numero_de_ficha;
    int dias;
    int *calorias;
    float peso_inicial;
    float peso_final;
    int alta;

} Registro;

Registro *hospedes[20];

int qnt_hospedes = 0;

int cadastro()
{
    while (true)
    {
        int ficha = 0; 
        int dias, cal; 
        float peso_ini;

        printf("\nNumero da ficha (-1 para terminar): ");
        scanf("%d", &ficha);

        if(ficha<1)
        {
            printf("\nNumero inválido de ficha");
            return 2;
        }

        if (qnt_hospedes >= 20)
        {
            printf("\nO Spa esta lotado");
            return 1;
        }

        if (ficha == -1) return 1;

        if(hospedes[ficha-1] != NULL)
        {
            if(hospedes[ficha-1]->alta==1)
            {
                printf("\nEssa ficha ja recebeu alta");
                return 2;
            }
            else
            {
                printf("\nEssa ficha esta em uso e ainda nao teve alta");
                return 2;
            }
        }

        hospedes[ficha-1] = (Registro*)malloc(sizeof(Registro));
        if (hospedes[ficha-1] == NULL)
        {
            printf("\nErro ao alocar memoria\n");
        }

        hospedes[ficha-1]->numero_de_ficha = ficha;

        printf("\nNome: ");
        scanf("%s", hospedes[ficha-1]->nome);

        printf("\nPeso ao entrar: ");
        scanf("%f", &peso_ini);
        hospedes[ficha-1]->peso_inicial = peso_ini;

        printf("\nDias: ");
        scanf("%d", &dias);
        if (dias > 30)
        {
            printf("\nQuantidade de dias maxima excedida");
            return 0;
        }
        hospedes[ficha-1]->dias = dias;

        hospedes[ficha-1]->calorias = (int*)malloc(dias * sizeof(int));

        for (int i = 0; i<dias; i++)
        {
            printf("\nCalorias no dia %d: ", i+1);
            scanf("%d",  &cal);
            hospedes[ficha-1]->calorias[i] = cal;
        }
    
        printf("\n============");
        printf("\nFicha n: %d", hospedes[ficha-1]->numero_de_ficha);
        printf("\n======");
        printf("\nNome: %s", hospedes[ficha-1]->nome);
        printf("\nPeso ao entrar: %.2f kg", hospedes[ficha-1]->peso_inicial);
        printf("\n======");
        printf("\nDias de Tratamento: %d", hospedes[ficha-1]->dias);
        printf("\n");
        printf("\nQtd de calorias permitidas em cada dia: ");
        for (int i = 0; i<dias; i++)
        {
            printf("\nDia %d: %d", i+1, hospedes[ficha-1]->calorias[i]);
        }
        printf("\n============\n");

        qnt_hospedes++;
        hospedes[ficha-1]->alta = 0;
    }
    return 0;
}

int dar_baixa()
{
    while(true)
    {

        int ficha;
        float peso_fim;
        printf("\nNumero da ficha: ");
        scanf("%d", &ficha);

        if (hospedes[ficha-1 != NULL])
        {
            if (hospedes[ficha-1]->alta==1)
            {
                printf("Essa ficha ja recebeu alta");
                return 2;
            }
        }

        printf("Peso ao sair: ");
        scanf("%f", &peso_fim);
        hospedes[ficha-1]->peso_final = peso_fim;

        float perda = hospedes[ficha-1]->peso_inicial - hospedes[ficha-1]->peso_final;
        printf("Peso perdido: %.2f kg\n", perda);

        qnt_hospedes--;
        hospedes[ficha-1]->alta = 1;

        printf("\n============");
        printf("\nFicha n: %d", hospedes[ficha-1]->numero_de_ficha);
        printf("\nAlta (X)");
        printf("\n======");
        printf("\nNome: %s", hospedes[ficha-1]->nome);
        printf("\nPeso ao entrar: %.2f kg", hospedes[ficha-1]->peso_inicial);
        printf("\nPeso ao sair: %.2f kg", hospedes[ficha-1]->peso_final);
        printf("\n======");
        printf("\nDias de Tratamento: %d", hospedes[ficha-1]->dias);
        printf("\n");
        printf("\nQtd de calorias permitidas em cada dia: ");
        for (int i = 0; i<hospedes[ficha-1]->dias; i++)
        {
            printf("\nDia %d: %d", i+1, hospedes[ficha-1]->calorias[i]);
        }
        printf("\n============\n");

        int opcao = 0;
        printf("\nDar nova baixa?\n1- Sim\n2- Fechar\n");
        scanf("%d", &opcao);
        if(opcao==2) return 1;
    }
    return 0;
}

int main()
{
    while(true)
    {
        int menu=0;
        printf("\nO que deseja fazer:\n1- Cadastrar Ficha\n2- Dar Baixa\n3- Fechar\n");
        scanf("%d", &menu);
        if (menu==1) cadastro();
        if (menu==2) dar_baixa();
        if (menu==3) return 1;
    }
    
    getchar();
    return 0;
}