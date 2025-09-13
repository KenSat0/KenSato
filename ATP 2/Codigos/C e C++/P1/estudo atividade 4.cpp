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

void *cadastro(regFunc **atual)
{
    regFunc *aux;
    aux = (regFunc*)malloc(sizeof(regFunc));
    if (aux == NULL)
    {
        perror("\nerro de alocacao em aux");
        return 0;
    }

    int numero;
    char nome[100];

    printf("\nNumero: ");
    scanf("%d", &numero);
    aux -> num_mat = numero;

    printf("\nNome: ");
    scanf("%s", nome);
    strcpy(aux->nome, nome);

    if(*atual == NULL)
    {
        *atual = aux;
        aux -> prox = NULL;
    }
    else
    {
        regFunc *temp = *atual;

        while(temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = aux;
        aux->prox = NULL;
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
            cadastro (&listaRFunc);
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