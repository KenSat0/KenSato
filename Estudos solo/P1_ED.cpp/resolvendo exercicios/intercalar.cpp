#include <stdio.h>
#include <stdlib.h>

struct no{
    int data;
    struct no *prox;
};

typedef struct no node;

node *createNode(int x);

void insert(node **L, int x);

void remove(node **L, int x);

void checkList(node **L);

node *intercalar(node *La, node *Lb);

int main(){
    node *a = NULL;
    node *b = NULL;
    node *c = NULL;


    insert(&a, 1);
    insert(&a, 3);
    insert(&a, 5);
    insert(&b, 2);
    insert(&b, 4);
    insert(&b, 6);

    checkList(&a);
    checkList(&b);

    c = intercalar(a ,b);
    checkList(&c);


}

node *createNode(int x){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = x;
    new_node->prox = NULL;
    return new_node;
}

void insert(node **L, int x){
    node *new_node = createNode(x);
    if((*L)==NULL){
        *L = new_node;
        return;
    }
    node *aux = *L;
    while(aux->prox!=NULL){
        aux = aux->prox;
    }
    aux->prox = new_node;
    return;
}

void remove(node **L, int x){
    if((*L)==NULL){
        printf("\nErro: Lista Vazia");
        return;
    }
    node *att = *L;
    node *ant = NULL;
    while(att != NULL && att->data != x){
        ant = att;
        att = att->prox;
    }
    if(att == NULL){
        printf("\nErro: Elemento nao encontrado");
        return;
    }
    if(ant == NULL){
        *L = (*L)->prox;
    }else{
        ant->prox = att->prox;
    }

    free(att);
    return;
}


void checkList(node **L){
    if((*L) == NULL) return;
    node *aux = *L;

    printf("\n");
    while(aux != NULL){
        printf("    %d", aux->data);
        aux = aux->prox;
    }
    printf("\n");
}

node *intercalar(node *La, node *Lb){
    node *auxA = La;
    node *auxB = Lb;
    node *Lc = NULL;

    while(auxA != NULL && auxB != NULL){
        insert(&Lc, auxA->data);
        insert(&Lc, auxB->data);
        auxA = auxA->prox;
        auxB = auxB->prox;
    }
    //a função irá terminar chegando ao fim da menor lista

    while(auxA != NULL){
        insert(&Lc, auxA->data);
        auxA = auxA->prox;
    }

    while(auxB != NULL){
        insert(&Lc, auxB->data);
        auxB = auxB->prox;
    }

    return(Lc);
}