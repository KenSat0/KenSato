#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no * prox;
}No;

No *criaNo(int x);
void insert(No **head, int x);
void remove(No *no, int v);
void print(No **no);

int main(){
    No *L = NULL;

    insert(&L, 2);
    insert(&L, 3);
    insert(&L, 67);
    insert(&L, 11);
    print(&L);

    return 0;
}

No *criaNo(int x){
    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = NULL;
    return novo;
}

void insert(No **head, int x){
    No *novo = criaNo(x);
    if((*head)==NULL){
        novo->prox = novo;
        *head = novo;
    }else{
        No *temp = *head;
        while(temp->prox != (*head)){
            temp = temp->prox;
        }
        novo->prox = (*head);
        temp->prox = novo;
        *head = novo;
    }
}

void remove(No *no, int v){
    No *ant, *aux = no->prox;
    while(aux->info != v && aux != no){
        ant = aux;
        aux = aux->prox;
    }
    if(aux==no) return;
    ant->prox = aux->prox;
    free(aux);
}

void print(No **no){
    No *ant = NULL;
    No *temp = *no;
    printf("\n");
    do{
            printf("%d  ", temp->info);
            ant = temp;
            temp = temp->prox;
    }while(ant->prox != *no);
}