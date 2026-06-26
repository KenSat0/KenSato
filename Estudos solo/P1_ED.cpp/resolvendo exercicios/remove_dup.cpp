#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no* prox;
};

typedef struct no node;

node *criaNo(int x);

void insert(node **head, int x);

void remove(node **head, int x);

void removeDup(node *lista);

void printList(node **head);

int main(){
    node *lista = NULL;

    insert(&lista, 1);
    insert(&lista, 2);
    insert(&lista, 3);
    insert(&lista, 4);
    insert(&lista, 5);
    insert(&lista, 6);
    insert(&lista, 7);
    insert(&lista, 8);
    insert(&lista, 3);
    insert(&lista, 5);
    insert(&lista, 1);

    printList(&lista);

    removeDup(lista);

    printList(&lista);

    return 0;
}

node *criaNo(int x){
    node *novo = (node*)malloc(sizeof(node));
    novo->info = x;
    novo->prox = NULL;
    return novo;
}

void insert(node **head, int x){
    node *novo = criaNo(x);

    novo->prox = (*head);
    *head = novo;
    return;
}

void remove(node **head, int x){
    if(*head == NULL) return;
    node *aux = *head;

    node *ant = NULL;
    while(aux != NULL && aux->info != x){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("\nErro: Elemento Inexistente");
        return;
    }
    if(ant == NULL){
        node *temp = *head;
        *head = (*head)->prox;
        free(temp);
        return;
    }
    ant->prox = aux->prox;
    free(aux);
    return;
}

void removeDup(node *lista){
    if(lista == NULL) return;
    node *aux1 = lista;

    while(aux1 != NULL){
        node *aux2 = aux1;
        while(aux2->prox != NULL){
            if(aux1->info == aux2->prox->info){
                node *temp = aux2->prox;
                aux2->prox = aux2->prox->prox;
                free(temp);
            }else{
                aux2 = aux2->prox;
            }
        }
        aux1 = aux1->prox;
    }
}

void printList(node **head){
    if(*head == NULL) return;
    node *aux = *head;
    while(aux != NULL){
        printf("    %d", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}