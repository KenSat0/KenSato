#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prox;
};

bool checkVoid(struct node **head){
    if(*head == NULL){
        printf("\nFila vazia");
        return (1);
    }
    return (0);
}

void checkNext(struct node **head){
    if(checkVoid(head)) return;
    struct node *aux = *head;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    printf("\n%d e o proximo na fila", aux->data);
    return;
}

void queuePrint(struct node **head){
    if(checkVoid(head)) return;
    printf("\n");
    struct node *aux = *head;
    while (aux != NULL){
        printf("%d  ", aux->data);
        aux = aux->prox;
    }
}

void insert(struct node **head, int valor){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = valor;
    temp->prox = *head;
    *head = temp;
    return;
}

void remove(struct node **head){
    if(checkVoid(head)) return;
    struct node *aux = *head;
    struct node *ante;
    while(aux->prox != NULL){
        ante = aux;
        aux = aux->prox;
    }
    free(aux);
    ante->prox = NULL;
    return;
}

void impar_par(struct node **head, struct node **head_par, struct node **head_imp){
    if (checkVoid(head)) return;

    struct node *aux = *head;
    while (aux != NULL){
        if((aux->data)%2 == 0){
            insert(head_par, aux->data);
        }else{
            insert(head_imp, aux->data);
        }
        aux = aux->prox;
    }
}

int main(){
    struct node *fila = NULL;
    struct node *fila_par = NULL;
    struct node *fila_imp = NULL;

    checkNext(&fila);

    insert(&fila, 2);
    insert(&fila, 67);
    insert(&fila, 16);
    
    queuePrint(&fila);

    checkNext(&fila);

    remove(&fila);

    queuePrint(&fila);
    
    checkNext(&fila);

    return 0;
}