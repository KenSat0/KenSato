#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

struct filas{
    int inicio;
    int fim;
    int vetor[MAXSIZE];
};

bool empty(struct filas *f);

bool full(struct filas *f);

void queue(struct filas *f, int x);

void unqueue(struct filas *f);

void checkqueue(struct filas *f);

int somatorio(struct filas *f);

int main(){
    struct filas f;
    f.inicio = MAXSIZE-1;
    f.fim = MAXSIZE-1;

    queue(&f, 2);
    queue(&f, 67);
    queue(&f, 11);
    queue(&f, 3);

    checkqueue(&f);

    printf("\nSomatorio: %d", somatorio(&f));

    unqueue(&f);

    checkqueue(&f);

    printf("\nSomatorio: %d", somatorio(&f));

    return 0;
}

bool empty(struct filas *f){
    if(f->fim == f->inicio) return 1;
    return 0;
}

bool full(struct filas *f){
    return ((f->fim + 1) % MAXSIZE == f->inicio);
}

void queue(struct filas *f, int x){
    if(full(f)){
        printf("\nErro: Fila Cheia");
        return;
    }

    f->fim = (f->fim + 1) % MAXSIZE;
    f->vetor[f->fim] = x;
    return;
}

void unqueue(struct filas *f){
    if(empty(f)){
        printf("\nErro: Fila Vazia");
        return;
    }

    f->inicio = (f->inicio + 1) % MAXSIZE;

    printf("\n%d removido", f->vetor[f->inicio]);
    return;
}

void checkqueue(struct filas *f){
    if(empty(f)) return;
    printf("\n");
    int i = (f->inicio + 1) % MAXSIZE;

    while (true){
        printf("    %d", f->vetor[i]);
        if (i == f->fim) break;
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    return;
}

int somatorio(struct filas *f){
    if(empty(f)) return 0;

    int i = (f->inicio + 1) % MAXSIZE;
    int soma = 0;

    while (true){
        soma = soma + f->vetor[i];
        if (i == f->fim) break;
        i = (i + 1) % MAXSIZE;
    }
    return soma;
}