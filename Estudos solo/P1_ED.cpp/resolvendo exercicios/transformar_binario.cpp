#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

struct node{
    int info;
    struct node *prox;
};

typedef struct node no;

void insert(no **head, int x);

int pop(no **head);

void stackprint(no **head);

int binary(int x);

int main(){
    binary(2);
    binary(4);
    binary(8);
    binary(16);
    binary(21);

    return 0;
}



void insert(no **head, int x){
    no *novo = (no*)malloc(sizeof(no));
    if(novo == NULL) return;

    novo->info = x;
    novo->prox = (*head);
    (*head) = novo;
}

int pop(no **head){
    if((*head) == NULL) return -1;

    no *aux = *head;
    int x = aux->info;
    
    (*head) = (*head)->prox;
    free(aux);
    return x;
}

void stackprint(no **head){
    if((*head) == NULL) return;
    no *aux = *head;
    while(aux != NULL){
        printf("    %d", aux->info);
        aux = aux->prox;
    }
}

int binary(int x){
    if (x == 0) return 0;
    no *p = NULL;

    while(x>0){
        insert(&p, x%2);
        x /= 2;
    }

    int num = 0;

    printf("\n");
    while(p != NULL){
        num = num*10;
        num = num + pop(&p);
    }
    printf("\n%d", num);
    return num;
}