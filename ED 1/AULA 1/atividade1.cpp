#include <stdio.h>
#include <Stdlib.h>

#define MAX 10

struct listaEE{
    int info;
    int prox;
};

struct listaEE L[MAX];
int dispo = 0;
int L = -1;

void inicializar()
{
    int i;
    for(i = 0; i<MAX-1; i++)
    {
        L[i].prox = i+1;
    }
    L[i].prox = -1;
}

void insert(int x){
    if (dispo == -1){
        printf("overflow");
        return;
    }
    int novo = dispo;
    dispo = L[dispo].prox;
    L[novo].info = x;
    L[novo].prox = dispo;
}

void delintervalo(int li, int ls){
    int i = 0;
    while(L[i].info > ls){
        if(L[i].info >= li && L[i].info <= ls){
            dispo = i;
        }

    }
}

int main(){
    int data;

    insert(333);
    insert(222);
    insert(67);

}