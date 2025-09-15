#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//criando o bloco de dados registro

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

//vetor de registro para no total 20 hospedes
Registro *hospedes[20];

//variavel que acompanha quantidade de hospedes
int qnt_hosp = 0;


//função recebe numero e imprime a ficha desse numero
void imprime(int numero)
{

    //usamos o indice [numero-1] pois em um vetor de 20 posições, o inicio é 0 e o fim é 19
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
    //verifica a condição alta para saber se o peso final ja foi registrado
    if(hospedes[numero-1]->alta==1)
    {
        //se alta == 1, imprime peso final e perda de peso
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

    //se spa estiver cheio, retorna a função, ja que não da mais para cadastrar
    if (qnt_hosp == 20)
    {
        perror("\nSPA Cheio");
        return;
    }

    printf("\nNumero: ");
    scanf("%d", &numero);

    //verifica se a ficha esta disponivel
    if(hospedes[numero-1] != NULL)
    {
        perror("\nFIcha ocupada");
        return;
    }

    //verifica a validade do numero 
    if(numero < 1 || numero > 20)
    {
        perror("\nNumero invalido");
        return;
    }

    //aloca memoria para a ficha caso ela tenha passado pelas verificações 
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

    //aloca memoria de vetor float para o termo calorias de hospedes, pois cada dia tem sua caloria
    hospedes[numero-1]->calorias = (float*)malloc(hospedes[numero-1]->dias * sizeof(float));
    for(int i = 0; i < hospedes[numero-1]->dias; i++)
    {
        printf("\nCalorias no dia %d: ", i+1);
        scanf("%f", &hospedes[numero-1]->calorias[i]);
    }

    //alta = falso para a verificação de imprime()
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

    //alta = verdade para a verificação de imprime()
    hospedes[numero-1]->alta=1;

    printf("\nPeso ao sair: ");
    scanf("%f", &hospedes[numero-1]->peso_saida);

    imprime(numero);

    printf("\nObs.: Registre a ficha em meio fisico antes de fechar o programa");

    //libera a memoria para as variaveis alocadas dinamicamente
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