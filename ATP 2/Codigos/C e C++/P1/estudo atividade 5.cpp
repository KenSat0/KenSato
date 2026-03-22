#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct no 
{
    int num_mat;
    char nome[100];
    struct no *prox;
} regFunc;

    regFunc *listaRFunc = NULL;

void *cadastro_ordenado(regFunc **lista)
{
    int valor;
    char nome[100];

    regFunc *temp = (regFunc*)malloc(sizeof(regFunc));

    if (temp == NULL)
    {
        perror("\nerro de alocacao em temp");
        return 0;
    }

    printf("\nNumero: ");
    scanf("%d", &valor);

    printf("\nNome: ");
    scanf("%s", nome);

    strcpy(temp->nome, nome);

    temp->num_mat = valor;

    regFunc *p_atual = (*lista);
    regFunc *p_anterior = NULL;
    if(p_atual == NULL)
    {
        p_atual = (regFunc*)malloc(sizeof(regFunc));
        p_atual->num_mat = valor;
        strcpy(p_atual->nome, temp->nome);
        p_atual->prox = NULL;
        (*lista) = p_atual;
    }
    else if (p_atual->num_mat > valor)
    {
        temp->prox = (*lista);
        (*lista) = temp;
    }
    else
    {
        while(p_atual != NULL && p_atual->num_mat < valor)
        {
            p_anterior = p_atual;
            p_atual = p_atual->prox;
        }
        if (p_atual == NULL)
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
}

void imprime(regFunc *atual)
{
    regFunc *temp = atual;

    while(temp != NULL)
    {
        printf("\nNumero: %d",temp->num_mat);
        printf("\nNome: %s", temp->nome);

        temp = temp->prox;        
    }
}

void excluir(regFunc **lista)
{
    if((*lista)==NULL)
    {
        printf("\nNao existe lista");
        return;
    }

    regFunc *temp = *lista;
    int num_ex;
    printf("\nQual numero de registro deseja excluir: ");
    scanf("%d", &num_ex);

    if(num_ex == temp->num_mat)
    {
        (*lista) = (*lista)->prox;
        free(temp);
    }
    else
    {
        regFunc *p_atual = *lista;
        regFunc *p_anterior = NULL;

        while(num_ex != p_atual->num_mat && p_atual !=NULL)
        {
            p_anterior = p_atual;
            p_atual = p_atual->prox;
        }
        if(p_atual == NULL)
        {
            printf("\nO registro %d nao existe", num_ex);
            return;
        }
        else
        {
            p_anterior->prox = p_atual->prox;
            free(p_atual);
        }
    }
}

void liberar(regFunc **lista)
{
    regFunc *temp;

    while(*lista != NULL)
    {
        temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }
}

int main()
{
    int menu = 0;

    while(menu!=4)
    {
        printf("\n1 - Cadastrar\n2 - Imprimir\n3 - Excluir\n4 - Sair\nMenu: ");
        scanf("%d", &menu);
        if(menu==1)
        {
            cadastro_ordenado(&listaRFunc);
        }
        if(menu==2)
        {
            imprime(listaRFunc);
        }
        if(menu==3)
        {
            excluir(&listaRFunc);
        }
    }

    liberar(&listaRFunc);

    getchar();
    return 0;
}