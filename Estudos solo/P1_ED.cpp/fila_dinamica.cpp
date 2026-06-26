#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *prox;
}No;

typedef struct{
    No *frente;
    no *fim;
}fifo;

No *criaNo(int x);
void enqueue(fifo *f, int x);
int dequeue(fifo *f);
void print(fifo *f);

int main(){
    fifo f;
    f.frente = NULL;
    f.fim = NULL;

    enqueue(&f, 2);
    enqueue(&f, 3);
    enqueue(&f, 67);
    enqueue(&f, 11);
    print(&f);

    return 0;
}

No *criaNo(int x){
    No* novo = (No*)malloc(sizeof(No));
    novo->info = x;
    novo->prox = NULL;
    return novo;
}

void enqueue(fifo *f, int x){
    No* no = criaNo(x);
    if(f->fim==NULL){
        f->frente = f->fim = no;
    }else{
        f->fim->prox = no;
        f->fim = no;
    }
}

int dequeue(fifo *f){
    if(f->frente==f->fim) return -1;
    No* temp = f->frente;
    int valor = temp->info;
    f->frente = f->frente->prox;
    if(f->frente == NULL) f->fim = NULL;
    free (temp);
    return valor;
}

void print(fifo *f){
    No *aux =  f->frente;
    printf("\n");
    while(aux!=NULL){
        printf("%d  ", aux->info);
        aux = aux->prox;
    }
}