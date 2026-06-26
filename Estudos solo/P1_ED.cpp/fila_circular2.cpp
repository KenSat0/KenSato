#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct fifoc{
    int vetor[MAX];
    int frente;
    int fim;
};

void enqueue(struct fifoc *f, int x);
int dequeue(struct fifoc *f);
void print(struct fifoc *f);

int main(){
    struct fifoc f;
    f.frente = 0;
    f.fim = 0;

    enqueue(&f, 2);
    enqueue(&f, 3);
    enqueue(&f, 67);
    enqueue(&f, 11);
    print(&f);

}

void enqueue(struct fifoc *f, int x){
    if((f->fim+1)%MAX == f->frente) return;
    f->vetor[f->fim] = x;
    f->fim = (f->fim + 1) % MAX;
}

int dequeue(struct fifoc *f){
    if(f->frente == f->fim) return -1;
    int valor = f->vetor[f->frente];
    f->frente = (f->frente + 1) % MAX;
    return valor;
}

void print(struct fifoc *f){
    int i = f->frente;
    printf("\n");
    while(i!=f->fim){
        printf("%d  ", f->vetor[i]);
        i = (i+1)%MAX;
    }
}