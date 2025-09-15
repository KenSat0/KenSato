#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//registro de funcionarios em nó

typedef struct no
{
    char nome[50];
    int matricula;
    no *prox;
} regFunc;

regFunc *listaRFunc;

int cadastrar(regFunc **atual)
{
    //registro temporario com informações do que se quer adicionar
    regFunc *temp;
    temp = (regFunc*)malloc(sizeof(regFunc));
    if(temp==NULL) return 1;

    regFunc *p_anterior = NULL;
    regFunc *p_atual = *atual;

    int numero;
    printf("\nNumero: ");
    scanf("%d", &numero);

    //verifica se é um numero valido
    if (numero <1 || numero >20)
    {
        perror("\nNumero invalido");
        return 1;
    }

    temp->matricula = numero;

    char nome[50];
    printf("\nNome: ");
    scanf("%s", nome);

    strcpy(temp->nome, nome);

    //se não houver nada na lista encadeada
    if((*atual)==NULL)
    {
        temp->prox = NULL;
        *atual = temp;
    }
    //se houver coisa
    else
    {
        //a seguinte parte é o que faz parte da atividade 5
        while(p_atual!=NULL && p_atual->matricula < numero && p_atual->matricula!= numero)
        {
            p_anterior = p_atual;
            p_atual = p_atual->prox;
        }
        if (p_atual->matricula== numero)
        {
            perror("\nNumero repetido");
            free(temp);
            return 1;
        }
        if(p_anterior==NULL)
        {
            temp->prox = *atual;
            *atual = temp;
        }
        else
        {
            p_anterior->prox = temp;
            temp->prox = p_atual;
        }
        /*
        
        para a atividade 4 apenas:

        while(p_atual->prox!=NULL)
        {
            p_atual = p_atual->prox
        }
        p_atual->prox = temp;
        temp->prox = NULL;

        não precisa do p_anterior

        */
    }

    return 0;
}

int imprime(regFunc **atual)
{   
    regFunc *temp = *atual;
    if(*atual == NULL)
    {
        perror("\nLista vazia");
        return 1;
    }
    else
    {
        //enquanto o ponteiro nao chegar no fim
        while(temp!=NULL)
        {
            //imprime informações
            printf("\nNome: %s", temp->nome);
            printf("\nMatricula: %d", temp->matricula);
            //move o ponteiro
            temp = temp->prox;
        }
    }

    return 0;
}

//toda essa função faz parte da atividade 5
int excluir(regFunc**atual)
{
    regFunc *p_anterior = NULL;
    regFunc *p_atual = *atual;

    int numero;
    printf("\nNumero para excluir: ");
    scanf("%d", &numero);

    p_atual = *atual;

    if(*atual == NULL)
    {
        perror("\nLista vazia");
        return 1;
    }
    
    if(p_atual->matricula == numero)
    {
        regFunc *temp = *atual;
        (*atual) = (*atual)->prox;
        free(temp);
    }
    else
    {
        while(p_atual!=NULL && p_atual->matricula!=numero)
        {
            p_anterior = p_atual;
            p_atual = p_atual->prox;
        }
        if(p_atual==NULL)
        {
            printf("\nCadastro nao existe na lista");
        }
        else
        {
            p_anterior->prox = p_atual->prox;
            free(p_atual);
        }
    }
    return 0;
}

int main()
{
    int menu;
    while(true)
    {
        printf("\n1 - Cadastrar\n2 - Imprimir\n3 - Sair\nO que fazer: ");
        scanf("%d", &menu);

        if(menu==1) cadastrar(&listaRFunc);
        if(menu==2) imprime(&listaRFunc);
        if(menu==3) break;
    }

    getchar();
    return 0;
}