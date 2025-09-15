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

int cadastro_ordenado(regFunc**atual)
{
    regFunc *temp = (regFunc*)malloc(sizeof(regFunc));
    if(temp==NULL)
    {
        perror("\nTemp nao alocado");
        return 1;
    }

    regFunc *p_atual = *atual;
    regFunc *p_anterior = NULL;

    printf("\nMatricula: ");
    scanf("%d", &temp->matricula);
    if(temp->matricula < 1 || temp->matricula > 10)
    {
        perror("\nNumero de cadastro invalido");
        free(temp);
        return 1;
    }

    char nome[50];
    printf("\nNome: ");
    scanf("%s", nome);
    strcpy(temp->nome, nome);

    if((*atual)==NULL)
    {
        temp->prox = NULL;
        *atual = temp;
    }
    else
    {
        while(p_atual!=NULL && p_atual->matricula<temp->matricula && p_atual->matricula!=temp->matricula)
        {
            p_anterior = p_atual;
            p_atual = p_atual->prox;
        }
        if(p_atual!=NULL && temp->matricula == p_atual->matricula)
        {
            perror("\nNumero de matricula repetido");
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
    }
    return 0;
}

int listar(regFunc**atual)
{
    regFunc *p_atual = *atual;
    
    if((*atual)==NULL)
    {
        perror("\nLista vazia");
        return 1;
    }
    else
    {
        while(p_atual!=NULL)
        {
            printf("\n\n");
            printf("\nNome: %s", p_atual->nome);
            printf("\nMatricula: %d", p_atual->matricula);
            p_atual = p_atual->prox;  
        }
    }
    return 0;
}

int excluir(regFunc**atual)
{
    regFunc *p_atual = *atual;
    regFunc *p_anterior = NULL;

    int numero;
    printf("\nMatricula a ser removida: ");
    scanf("%d", &numero);

    if((*atual)==NULL)
    {
        perror("\nLista vazia");
        return 1;
    }
    if (p_atual->matricula == numero)
    {
        regFunc *aux = *atual;
        (*atual) = (*atual)->prox;
        free(aux);

        return 0;
    }
    else
    {
        while(p_atual!=NULL && numero!=p_atual->matricula)
        {
            p_anterior = p_atual;
            p_atual = p_atual->prox;
        }
        if(p_atual==NULL)
        {
            perror("\nCadastro nao existe na lista");
            return 1;
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
        printf("\n1 - Cadastro\n2 - Listar\n3 - Excluir\n4 - Sair\no que fazer: ");
        scanf("%d", &menu);
        if(menu==1) cadastro_ordenado(&listaRFunc);
        if(menu==2) listar(&listaRFunc);
        if(menu==3) excluir(&listaRFunc);
        if(menu==4) break;
    }

    getchar();
    return 0;
}