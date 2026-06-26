#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct no{
    char info;
    struct no *esq;
    struct no *dir;
};

void insere(struct no **atual, char elem);
void print_tree(struct no *r, int c);
struct no *busca(struct no *atual, char elem);
void retira(struct no **atual, char elem);
void antecessor(struct no **aux, struct no **atual);

int main(){
    struct no *raiz, *dado;
    char info[10];
    raiz = NULL;
    do{
        printf("Digite uma letra: ");
        gets(info);
        if(*info) insere(&raiz, *info);
    }while(*info);
    print_tree(raiz, NULL);
    printf("Digite o elemento a ser buscado: ");
    gets(info);
    dado = busca(raiz, *info);
    if(dado) printf("Dado  = %c\n", dado->info);
    else printf("Elemento inexistente\n");

    printf("Digite o elemento a ser retirado: ");
    gets(info);
    retira(&raiz, *info);
    print_tree(raiz, NULL);
    
    return 0;
}

void insere(struct no **atual, char elem){
    if (*atual==NULL){
        *atual = (struct no*)malloc(sizeof(struct no));
        if(!(atual)){
            printf("sem memoria \n");
            exit(0);
        }
        else{
            (*atual)->info = elem;
            (*atual)->esq = NULL;
            (*atual)->dir = NULL;
            return;
        }
    }
    else{
        if(elem<(*atual)->info) insere(&(*atual)->esq, elem);
        else insere(&(*atual)->dir, elem);
    }
}

void print_tree(struct no *r, int c){
    int i;
    if (!r) return;
    print_tree(r->dir, c+1);
    for(i = 0; i<c; ++i) printf(" ");
    printf("%c\n", r->info);
    print_tree(r->esq, c+1);
}

struct no *busca(struct no *atual, char elem){
    if(atual==NULL || atual->info == elem) return atual;
    else
        if (elem<atual->info) return busca(atual->esq, elem);
        else return busca(atual->dir, elem);
}

void retira(struct no **atual, char elem){
    struct no *aux;
    if(*atual == NULL) printf("Elemento não está na árvore\n");
    else
        if(elem<(*atual)->info) retira(&(*atual)->esq, elem);
        else
            if(elem>(*atual)->info) retira(&(*atual)->dir, elem);
            else{
                aux = *atual;
                if((*atual)->dir==NULL) *atual = aux->esq;
                else{
                    if((*atual)->esq==NULL) *atual = aux->dir;
                    else antecessor(&aux, &(*atual)->esq);
                    free(aux);
                }
            }
}

void antecessor(struct no **aux, struct no **atual){
    if((*atual)->dir==NULL) antecessor(aux, &(*atual)->dir);
    else{
        (*aux) -> info = (*atual)->info;
        *aux = *atual;
        *atual = (*atual)->esq;
    }
}