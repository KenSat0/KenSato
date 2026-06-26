#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node No;

No *novoNo(int x);

void insert(No **head, int x);

void removeComHead(No **head, int valor_requisitado);

void removeSemHead(No *no_qualquer, int valor_requisitado);

void check(No **head);

int main(){
    No *lista = NULL;

    insert(&lista, 2);
    insert(&lista, 3);
    insert(&lista, 67);
    insert(&lista, 11);

    check(&lista);

    removeComHead(&lista, 3);

    check(&lista);

    return 0;
}

No *novoNo(int x){
    No *node = (No*)malloc(sizeof(No));
    node->data = x;
    node->next = NULL;
    return node;
}

void insert(No **head, int x){
    printf("\n CHAMOU INSERT");
    No *node = novoNo(x);
    if ((*head)==NULL){
        *head = node;
        node->next = (*head);
        return;
    }
    No *aux = *head;
    while(aux->next != *head){
        aux = aux->next;
    }
    aux->next = node;
    node->next = (*head);
}

void removeComHead(No **head, int valor_requisitado){
    if (*head == NULL) return;
    No *aux = *head;
    No *ant = NULL;


    if (aux->data == valor_requisitado) {
        *head = aux->next;
        free(aux);
        return;
    }

    while (aux != NULL && aux->data != valor_requisitado) {
        ant = aux;
        aux = aux->next;
    }

    if (aux == NULL) return;
    ant->next = aux->next;
    free(aux);
}

void removeSemHead(No *no_qualquer, int valor_requisitado){
    No *ant, *aux;
    aux = no_qualquer->next;
    while(aux->data != valor_requisitado && aux != no_qualquer){
        ant = aux;
        aux = aux->next;
    }
    if(aux == no_qualquer){
    printf("\nErro: Valor Inexistente");
    }else{
        ant->next = aux->next;
        free(aux);
    }
}

void check(No **head){
    No *aux = *head;
    No *ant = *head;
    printf("\n");
    while (ant->next != (*head)){
        printf("    %d", aux->data);
        ant = aux;
        aux = aux->next;
    }
    printf("\n");
    return;
};