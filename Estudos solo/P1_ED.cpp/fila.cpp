#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct filas{
    int inicio;
    int fim;
    int vetor[MAXSIZE];
};

bool empty(struct filas *f);

void queue(struct filas *f, int x);

void unqueue(struct filas *f);

void checkqueue(struct filas *f);

int main(){
    struct filas fila;
    fila.inicio = -1;
    fila.fim = 0;

    queue(&fila, 2);
    queue(&fila, 4);
    queue(&fila, 67);

    unqueue(&fila);

    checkqueue(&fila);

    return 0;
}

bool empty(struct filas *f){
    if (f->inicio == -1) return 1;
    return 0;
}

void queue(struct filas *f, int x){
    if((f->fim)-(f->inicio)<MAXSIZE-1){
        if(f->inicio == -1){
            f->inicio++;
            f->vetor[f->fim] = x;
            printf("\n%d adicionado", f->vetor[f->fim]);
            return;
        }
        f->fim++;
        f->vetor[f->fim] = x;
        printf("\n%d adicionado", f->vetor[f->fim]);
        return;
    }
    printf("\nErro: Fila Cheia");
    return;
}

void unqueue(struct filas *f){
    if(empty(f)){
        printf("\nErro: Fila Vazia");    
        return;
    }
    printf("\n%d removido", f->vetor[f->inicio]);
    f->vetor[f->inicio] = 0;
    f->inicio++;
    return;
}

void checkqueue(struct filas *f){
    if(empty(f)){
        printf("\nErro: Fila Vazia");
        return;
    }
    for(int i = f->inicio; i <= f->fim; i++){
        printf("\n%d", f->vetor[i]);
    }
    return;
}