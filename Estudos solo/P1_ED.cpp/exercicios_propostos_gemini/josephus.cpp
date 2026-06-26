#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *prox;
};

typedef struct node node;

node *criaNo(int x);
void insert(node **head, int x);
void remove(node **head, int x);
void check(node **head);
void josephus(node **head, int M);

int main(){
    node *L = NULL;

    insert(&L, 1);
    insert(&L, 2);
    insert(&L, 3);
    insert(&L, 4);
    insert(&L, 5);
    insert(&L, 6);
    insert(&L, 7);
    insert(&L, 8);

    josephus(&L, 4);

}

node *criaNo(int x){
    node *novo = (node*)malloc(sizeof(node));
    novo->info = x;
    novo->prox = NULL;
    return novo;
}

void insert(node **head, int x){
    node *novo = criaNo(x);
    if((*head)==NULL){
        novo->prox = novo;
        *head = novo;
    } else {
        node *temp = (*head);
        while(temp->prox != (*head)){
            temp = temp->prox;
        }
        novo->prox = *head;
        temp->prox = novo;
        *head = novo;
    }
}

void remove(node **head, int x){
    if((*head)==NULL){
        printf("\nErro: Lista Vazia");
        return;
    }

    node *aux = *head;
    node *ant = NULL;

    if((*head)->prox == *head && (*head)->info == x){
        free(*head);
        *head = NULL;
        return;
    }

    do{
        if(aux->info == x) break;
        ant = aux;
        aux = aux->prox;
    } while (aux != *head);

    if(aux->info != x){
        printf("\nErro: Valor Inexistete");
        return;
    }

    if(aux == *head){
        node *ultimo = *head;
        while(ultimo->prox != *head){
            ultimo = ultimo->prox;
        }
        *head = (*head)->prox;
        ultimo->prox = *head;
    }else{
        ant->prox = aux->prox;
    }
    free(aux);
}

void check(node **head){
    if((*head)==NULL) return;
    node *aux = *head;
    printf("\n");
    do{
        printf("    %d", aux->info);
        aux = aux->prox;
    }while(aux != (*head));
}

void josephus(node **head, int M){
    if((*head)==NULL) return;
    while(*head){
        check(head);
        node *aux = *head;
        printf("\nBuscando elemento:");
        for(int i = M; i > 0; i--){
            printf("\n#%d: %d", M-i, aux->info);
            aux = aux->prox;
        }
        printf("\nRemovido (#%d): %d", M, aux->info);
        remove(head, aux->info);
    }
    printf("\nLista Esvaziada");
}