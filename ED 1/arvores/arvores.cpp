#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no *esq, *dir;
};

void preorder(struct no *p){
    if(!p) return;
    printf("%d" ,p->info);
    preorder(p->esq);
    preorder(p->dir);
}

void inorder(struct no *p){

}

void posorder(struct no *p){

}

int main(){
    struct no *p = NULL;
    return 0;
}