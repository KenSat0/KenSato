#include <stdio.h>
#include <stdlib.h>

#define V 1
#define F 0

enum balanco{
    menor = -1, igual, maior
};

struct no{
    char info;
    struct no *esq;
    struct no *dir;
    enum balanco bal;
};

void insere(struct no **atual, char elem, int *h);
void print_tree(struct no *r, int c);
struct no *busca(struct no *atual, char elem);
void retira(struct no **atual, char elem, int *h);
void antecessor(struct no **aux, struct no **atual, int *h);
void balancoE(struct no **p, int *h);
void balancoD(struct no **p, int *h);

int main(){
    struct no *raiz, *dado;
    char info[10];
    int h = V;
    raiz = NULL;
    do{
        printf("Digite uma letra: ");
        gets(info);
        if(*info) insere(&raiz, *info, &h);
    }while(*info);
    print_tree(raiz, NULL);
    printf("Digite o elemento a ser buscado: ");
    gets(info);
    dado = busca(raiz, *info);
    if(dado) printf("Dado  = %c\n", dado->info);
    else printf("Elemento inexistente\n");

    do{
    printf("Digite o elemento a ser retirado: ");
    gets(info);
    h=F;
    if(*info) retira(&raiz, *info, &h);
    }while(*info);
    
    print_tree(raiz, NULL);
    return 0;
}

void insere(struct no **atual, char elem, int *h){
    struct no *p1, *p2;
    if(*atual==NULL){
        *atual = (struct no*)malloc(sizeof(struct no));
        if(!(*atual)){
            printf("sem memoria\n");
            exit(0);
        }else{
            *h = V;
            (*atual)->info = elem;
            (*atual)->esq = NULL;
            (*atual)->dir = NULL;
            (*atual)->bal = igual;
            return
        }
    }
}
void print_tree(struct no *r, int c);
struct no *busca(struct no *atual, char elem);
void retira(struct no **atual, char elem, int *h);
void antecessor(struct no **aux, struct no **atual, int *h);
void balancoE(struct no **p, int *h);
void balancoD(struct no **p, int *h);