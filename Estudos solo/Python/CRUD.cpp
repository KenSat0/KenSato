#include <stdio.h>
#include <stdlib.h>

//Create, Read, Update, Delete

struct no{
    char* nome;
    int numero;
    struct no* prox;
};

int printReg(struct no **head)
{
    if (*head==NULL)
    {
        printf("\nRegistro vazio");
        return 1;
    }
    else
    {
        struct no *temp;
        temp = *head;
        while(temp!=NULL)
        {
            printf("\nNome: %s", temp->nome);
            printf("\nNumero: %d", temp->numero);
            printf("\n============");
            temp = temp->prox;
        }
    }
    printf("\nRegistro Impresso");
    return 0;
}

int addReg(struct no** head)
{
    char *name;
    int number;

    printf("\nDigite o nome do Registro:");
    scanf("%s", name);

    printf("\nDigite o número do Registro:");
    scanf("%n", &number);

    struct no *aux = (struct no*)malloc(sizeof(struct no));
    aux->nome = name;
    aux->numero = number;

    if(*head==NULL)
    {
        aux -> prox = NULL;
        *head = aux;
    }
    else
    {
        struct no *temp;
        temp = *head;
        while(temp->prox!=NULL)
        {
            if(temp->numero==number)
            {
                printf("\nNumero de registro já utilizado");
                printf("\nNome de registro encontrado: %s", temp->nome);
                printf("\nAbra o registro completo para verificar os numeros ja registrados");
                printf("\n============");
                return 1;
            }
            temp = temp->prox;
        }
        temp->prox = aux;
        aux->prox = NULL;
    }
    return 0;
}

int readReg(struct no**head, int num)
{
    if (*head==NULL)
    {
        printf("\nRegistro vazio");
        return 1;
    }
    struct no* temp = *head;
    while(temp!=NULL && temp->numero!=num)
    {
        temp = temp->prox;
    }
    if(temp==NULL)
    {
        printf("\nNumero não encontrado");
        return 1;
    }
    else
    {
        printf("\nRegistro encontrado!");
        printf("\nNome: %s", temp->nome);
        printf("\nNumero: %d", temp->numero);
        printf("\n============");
    }
}

int updReg(struct no**head, int num)
{
    if (*head==NULL)
    {
        printf("\nRegistro vazio");
        return 1;
    }
    struct no* temp = *head;
    while(temp!=NULL && temp->numero!=num)
    {
        temp = temp->prox;
    }
    if(temp==NULL)
    {
        printf("\nNumero não encontrado");
        return 1;
    }
    else
    {
        printf("\nRegistro encontrado!");
        printf("\nNome: %s", temp->nome);
        printf("\nNumero: %d", temp->numero);
        printf("\n============");
    }
    int x;
    printf("\nDeseja alterar o nome ou o numero registrado?\nNome (1)\nNumero (2)\nSair (Qualquer outro numero)\nDigite aqui:");
    scanf("%d", &x);
    if (x==1)
    {
        char *new_name;
        printf("\nDigite o novo nome:");
        scanf("%s", new_name);
        temp->nome = new_name;
        printf("\nRegistro atualizado");
        return 0;
    }
    else if (x==2)
    {
        int new_num;
        printf("\nDigite o novo numero:");
        scanf("%d", &new_num);

        struct no* aux = *head;
        while(aux!=NULL)
        {
            if (aux->numero=new_num)
            {
                printf("\nNumero de registro já utilizado");
                printf("\nNome de registro encontrado: %s", aux->nome);
                printf("\nAbra o registro completo para verificar os numeros ja registrados");
                printf("\n============");
                return 1;
            }
            aux = aux->prox;
        }
            temp->numero = new_num;
            printf("\nRegistro atualizado");
            return 0;
    }
    else return 0;
}

int deleteReg(struct no**head, int num)
{
    if (*head==NULL)
    {
        printf("\nRegistro vazio");
        return 1;
    }
    struct no* temp = *head;
    struct no* prev = NULL;
    while(temp!=NULL && temp->numero!=num)
    {
        prev = temp;
        temp = temp->prox;
    }
    if (temp==NULL)
    {
        printf("\nREgistro não encointrado");
        return 1;
    }
    if (prev == NULL)
    {
        *head = temp->prox;
        printf("\nRegistro %d encontrado e removido", num);
        return 0;
    }
    prev->prox = temp->prox;
    printf("\nRegistro %d encontrado e removido", num);
    return 0;
}

int main()
{

}