#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prox;
    struct node *ant;
};

struct node *createNode(int x);

void insert(struct node **L, int x);

void remove(struct node **L, int x);

void checkList(struct node **L);

void swap(struct node **L, int x, int y);

int main(){
    struct node *Lista = NULL;

    insert(&Lista, 3);
    insert(&Lista, 11);
    insert(&Lista, 5);
    insert(&Lista, 1);
    insert(&Lista, 67);

    checkList(&Lista);

    swap(&Lista, 67, 1);
    printf("\n");

    checkList(&Lista);

    return 0;
}

struct node *createNode(int x){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->prox = NULL;
    new_node->ant = NULL;
    return new_node;
}

void insert(struct node **L, int x){
    struct node *new_node = createNode(x);
    if((*L)==NULL){
        *L = new_node;
        return;
    }
    struct node *aux = *L;
    while(aux->prox!=NULL){
        aux = aux->prox;
    }
    aux->prox = new_node;
    new_node->ant = aux;
    return;
}

void remove(struct node **L, int x){
    if((*L)==NULL){
        printf("\nErro: Lista Vazia");
        return;
    }
    struct node *att = *L;
    while(att != NULL && att->data != x){
        att = att->prox;
    }
    if(att == NULL){
        printf("\nErro: Elemento nao encontrado");
        return;
    }
    if (att->ant != NULL) {
        att->ant->prox = att->prox;
    } else {
        *L = att->prox;
    }

    if (att->prox != NULL) {
        att->prox->ant = att->ant;
    }

    free(att);
    return;
}


void checkList(struct node **L){
    if((*L)==NULL){
        printf("\nErro: Lista Vazia");
        return;
    }
    struct node *aux = *L;
    while(aux!=NULL){
        printf("%d  ", aux->data);
        aux = aux->prox;
    }
}

void swap(struct node **L, int x, int y){
    if((*L)==NULL){
        printf("\nErro: Lista Vazia");
        return;
    }
    struct node *att = *L;
    while(att != NULL && att->data != x){
        att = att->prox;
    }
    if(att == NULL){
        printf("\nErro: Elemento X nao encontrado");
        return;
    }
    if (att->ant != NULL && att->ant->data == y) {
        //achou y como anterior a x
        int temp = att->data; 
        att->data = att->ant->data;
        att->ant->data = temp;

        return;
    } else if (att->prox != NULL && att->prox->data == y) {
        //achou y como sucessor de x
        int temp = att->data; 
        att->data = att->prox->data;
        att->prox->data = temp;
        return;
    }
    printf("\nErro: Valor Y Inexistente");
    return;
}