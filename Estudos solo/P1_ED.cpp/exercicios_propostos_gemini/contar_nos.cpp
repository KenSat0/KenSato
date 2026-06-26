#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node No;

No *novoNo(int x);

void insert(No **head, int x);

void remove(No **head, int x);

void check(No **head);

int contaNo(No **head);

int main(){
    No *lista = NULL;

    insert(&lista, 2);
    insert(&lista, 3);
    insert(&lista, 67);
    insert(&lista, 11);

    check(&lista);
    printf("\n%d", contaNo(&lista));

    remove(&lista, 3);

    check(&lista);
    printf("\n%d", contaNo(&lista));

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

void remove(No **head, int x){
    if((*head)==NULL){
        printf("\nErro: Lista Vazia");
        return;
    }

    No *aux = *head;
    No *ant = NULL;

    if((*head)->next == *head && (*head)->data == x){
        free(*head);
        *head = NULL;
        return;
    }

    do{
        if(aux->data == x) break;
        ant = aux;
        aux = aux->next;
    } while (aux != *head);

    if(aux->data != x){
        printf("\nErro: Valor Inexistete");
        return;
    }

    if(aux == *head){
        No *ultimo = *head;
        while(ultimo->next != *head){
            ultimo = ultimo->next;
        }
        *head = (*head)->next;
        ultimo->next = *head;
    }else{
        ant->next = aux->next;
    }
    free(aux);
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
}

int contaNo(No **head){
    No *aux = *head;
    No *ant = *head;
    int cont = 0;
    while (ant->next != (*head)){
        cont++;
        ant = aux;
        aux = aux->next;
    }
    printf("\n");
    return cont;
}