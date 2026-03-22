#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    node* prox;
} Node;

void addNode(Node** head, int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;

    if(*head == NULL)
    {
        newNode->prox = NULL;
        *head = newNode;
    }
    Node* aux = *head;
    while(aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = newNode;
    newNode->prox = NULL;
}

int addNode_Sorted(Node** head, int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;

    if(*head == NULL)
    {
        newNode->prox = NULL;
        *head = newNode;
    }

    Node* atual = *head;
    Node* anterior = NULL;
    
    while(atual != NULL && x > atual->data)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL)
    {
        anterior->prox = newNode;
        newNode->prox = NULL;
        return (1);
    }
    if (anterior == NULL)
    {
        newNode->prox = atual;
        atual->prox = NULL;
        *head = newNode;
        return (1);
    }
    anterior->prox = newNode;
    newNode->prox = atual;
    return (1);
}

int delNode(Node** head, int x)
{
    Node* aux = *head;
    Node* temp_prev = NULL;
    Node* temp_act = aux;
    while (aux != NULL && aux->data != x)
    {
        temp_prev = temp_act;
        temp_act = aux->prox;
        aux = aux->prox;
    }
    if (aux == NULL) return (-2); //nó não existe
    temp_prev->prox = temp_act->prox;
    return (1);
}

int changeNode(Node** head, int initial_value, int new_value)
{
    Node* aux = *head;
    while (aux != NULL && aux->data != initial_value)
    {
        aux = aux->prox;
    }
    if (aux == NULL) return (-2);
    aux->data = new_value;
    return 1;
}

int changeNode_Sorted(Node**head, int initial_value, int new_value)
{
    delNode(head, initial_value);
    addNode_Sorted(head, new_value);
}

int ListLenght(Node** head)
{
    int lenght = 0;
    if (head == NULL) return (lenght);

    Node* aux = *head;

    while (aux!=NULL)
    {
        aux = aux->prox;
        lenght++;
    }
    return (lenght);
}

int print(Node** head)
{
    Node* aux = *head;
    if(aux == NULL) return (-1);
    while (aux != NULL)
    {
        printf("\n%d", aux->data);
        aux = aux->prox;
    }
    return (1);
}

int NodeIndex(Node** head, int index)
{
    if(head == NULL) return (-1); //lista vazia
    if(index<0) return (-1); //indice invalido

    Node* aux = *head;
    int cont = 0;
    int found_data;
    while (aux != NULL && index != cont)
    {
        aux = aux->prox;
        cont++;
    }
    if(aux == NULL) return (-2); //não existe o indice mencionado na lista
    found_data = aux->data;
    return (found_data);
}

int busca_simples(Node** head, int goal)
{
    if (head == NULL) return (-2);
    Node* aux = *head;
    int cont = 0;
    while (aux != NULL)
    {
        if(aux->data == goal)
        {
            printf("\nElemento %d encontrado na posicao %d", goal, cont+1);
            return(1);
        }
        aux = aux->prox;
        cont++;
    }
    printf("\nElemento nao encontrado (%d iteracoes)", cont);
    return (-1);
}

int busca_simplee_comRep(Node** head, int goal)
{
    if (head == NULL) return (-2);
    Node* aux = *head;
    int cont = 0;
    bool found = false;
    while (aux != NULL)
    {
        if(aux->data == goal)
        {
            printf("\nElemento %d encontrado na posicao %d", goal, cont+1);
            found = true;
        }
        aux = aux->prox;
        cont++;
    }
    if (!found) return (0);
    return (1);
}

int busca_ordenada(Node** head, int goal)
{
    if (head == NULL) return (-2);
    Node* aux = *head;
    int cont = 0;
    while (aux != NULL)
    {
        if(aux->data == goal)
        {
            printf("\nElemento %d encontrado na posicao %d", goal, cont+1);
            return(1);
        }
        if(aux->data > goal) 
        {
            printf("\nElemento nao encontrado (%d iteracoes)", cont);
            return (-1);
        }
        aux = aux->prox;
        cont++;
    }
    printf("\nElemento nao encontrado (%d iteracoes)", cont);
    return (-1);
}

int busca_binaria(Node** head, int size, int goal)
{
    int p_medio, linf, lsup;
    linf = 0;
    lsup = size - 1;
    int cont = 0;

    while(linf <= lsup)
    {
        p_medio = (linf+lsup)/2;
        if(NodeIndex(head, p_medio) == goal) lsup = linf-1;
        else if (NodeIndex(head, p_medio) > goal) lsup = p_medio - 1;
        else linf = p_medio + 1;

        cont++;
    }
    if(NodeIndex(head, p_medio) == goal)
    {
    printf("\nElemento %d encontrado na posicao %d", goal, p_medio + 1);
    printf("\nIteracoes %d", cont);
    return (1);
    }
    else
    {
        printf("\nElemento nao encontrado");
        printf("\nIteracoes %d", cont);
        return (-1);
    };
}

int main()
{
    Node* listaA = NULL;
        addNode(&listaA, 1);
        addNode(&listaA, 3);
        addNode(&listaA, 6);
        addNode(&listaA, 12);
        addNode(&listaA, 8);
        addNode(&listaA, 7);
        addNode(&listaA, 11);
        addNode(&listaA, 9);

        busca_simples(&listaA, 11);
        busca_ordenada (&listaA, 11);
        int sizeA = ListLenght(&listaA);
        busca_binaria(&listaA, sizeA, 11);

        printf("\n");

    Node* listaB = NULL;
        addNode(&listaB, 1);
        addNode(&listaB, 3);
        addNode(&listaB, 6);
        addNode(&listaB, 7);
        addNode(&listaB, 8);
        addNode(&listaB, 9);
        addNode(&listaB, 11);
        addNode(&listaB, 12);

        busca_simples(&listaB, 5);
        busca_ordenada (&listaB, 5);
        int sizeB = ListLenght(&listaB);
        busca_binaria(&listaB, sizeB, 5);
    
        printf("\n");

    Node* listaC = NULL;
        addNode(&listaC, 1);
        addNode(&listaC, 4);
        addNode(&listaC, 8);
        addNode(&listaC, 9);
        addNode(&listaC, 11);
        addNode(&listaC, 12);
        addNode(&listaC, 17);
        addNode(&listaC, 19);
        addNode(&listaC, 20);
        addNode(&listaC, 22);
        addNode(&listaC, 30);
        addNode(&listaC, 33);
        addNode(&listaC, 1);
        addNode(&listaC, 47);
        addNode(&listaC, 49);
        addNode(&listaC, 50);
        addNode(&listaC, 61);
        addNode(&listaC, 67);

        busca_simples(&listaC, 33);
        busca_simplee_comRep(&listaC, 1);
        busca_ordenada(&listaC, 17);
        int sizeC = ListLenght(&listaC);
        busca_binaria(&listaC, sizeC, 67);
}