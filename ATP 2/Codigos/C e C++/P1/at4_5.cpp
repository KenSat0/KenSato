#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct no
{
    char nome[50];
    int matricula;
    no *prox;
} regFunc;

regFunc *listaRFunc;

int cadastrar(regFunc **atual)
{
    regFunc *temp;
    temp = (regFunc*)malloc(sizeof(regFunc));
    if(temp==NULL) return 1;

    regFunc *p_anterior = NULL;
    regFunc *p_atual = *atual;

    int numero;
    printf("\nNumero: ");
    scanf("%d", &numero);

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

    if((*atual)==NULL)
    {
        temp->prox = NULL;
        *atual = temp;
    }
    else if(p_atual->matricula >= numero)
    {
        if(p_atual->matricula == numero)
        {
            perror("\nNumero ja cadastrado");
            return 1;
        }        
        temp->prox = p_atual;
        (*atual) = temp;
    }
    else
    {
        while(p_atual!=NULL && p_atual->matricula <= numero)
        {
            if(p_atual->matricula == numero)
            {
                perror("\nNumero ja cadastrado");
                return 1;
            }
            p_anterior = p_atual;
            p_atual = p_atual->prox;
        }
        if(p_atual==NULL)
        {
            p_anterior->prox = temp;
            temp->prox = NULL;
        }
        else
        {
            p_anterior->prox = temp;
            temp->prox = p_atual;
        }
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
        while(temp!=NULL)
        {
            printf("\nNome: %s", temp->nome);
            printf("\nMatricula: %d", temp->matricula);
            temp = temp->prox;
        }
    }

    return 0;
}

int excluir(regFunc**atual)
{
    regFunc *p_anterior = NULL;
    regFunc *p_atual = *atual;

    int numero;
    printf("\nNumero para excluir: ");
    scanf("%d", &numero);

    atl = *atual;

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