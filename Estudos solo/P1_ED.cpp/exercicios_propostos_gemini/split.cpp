#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *prox;
};

typedef struct node node;

node *createNode(int x);

void insert(node **head, int x);

void show(node **head);

void split(node **head, node**hodd, node**heven);

int main(){
    node *L = NULL;
    node *A = NULL;
    node *B = NULL;

    insert(&L, 1);
    insert(&L, 2);
    insert(&L, 3);
    insert(&L, 4);
    insert(&L, 5);
    insert(&L, 6);
    insert(&L, 7);
    insert(&L, 8);
    
    show(&L);

    split(&L, &A, &B);

    show(&A);
    show(&B);

    return 0;
}

node *createNode(int x){
    node *novo = (node*)malloc(sizeof(node));
    novo->info = x;
    novo->prox = NULL;
    return novo;
}

void insert(node **head, int x){
    node *novo = createNode(x);
    if((*head)==NULL){
        (*head) = novo;
        return;
    }
    node *aux = (*head);
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return;
}

void show(node **head){
    if((*head)==NULL) return;
    node *aux = (*head);
    printf("\n");
    while(aux!=NULL){
        printf("    %d", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void split(node **head, node**hodd, node**heven){
    if((*head)==NULL) return;
    node *aux = *head;
    while(aux!=NULL){
        if(aux->info%2==0) insert(heven, aux->info);
        if(aux->info%2==1) insert(hodd, aux->info);
        aux = aux->prox;
    }
    return;
}