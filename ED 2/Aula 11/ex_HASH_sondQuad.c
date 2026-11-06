#include <stdlib.h>
#include <stdbool.h>

//inserção, busca, sondagem quadratica

#define size 10

typedef struct elemento{
    int chave; 
    int dado;
    bool ocupado;
} elemento;

typedef struct{
    elemento *tabela;
    int tamanho; //quantidade de buckets
    int quantidade;
} HASH;

HASH *inicializarHash(HASH *h, int tam){
    h->tamanho = tam; 
    h->quantidade = 0;

    h->tabela = (elemento*)malloc(tam * sizeof(elemento));

    for(int i = 0; i<tam; i++){
        h->tabela[i].ocupado = false; 
    }
    return h;
}

elemento criarElemento(int x){
    elemento *novo = (elemento*)malloc(sizeof(elemento));
    novo->chave = x;
    novo->dado = NULL;
    novo->ocupado = false;

    return novo;
}

int insert(HASH *h, elemento atual){
    if(h->quantidade >= h->tamanho) {
        printf("\nTabela HASH esta cheia");
        return 1;
    }

    int hash_inicial = atual.chave % h->tamanho;
    int hash = hash_inicial;
    int i = 0;

    while(h->tabela[hash].ocupado){
        i++;
        hash = (hash_inicial + (i*i)) % h->tamanho;
    }
    
    h->tabela[hash] = atual;
    h->tabela[hash].ocupado = true;
    h->quantidade++;

    return 0;
}

int busca(HASH *h, int x){
    int hash_inicial = x % h->tamanho;
    int hash;
    int i = 0;

    while(i < h->tamanho && h->tabela[hash].ocupado){
        if(h->tabela[hash].chave == x){
            printf("\nElemento %d encontrado", x);
            return hash;
        }
        i++;
        hash = (hash_inicial + (i*i)) % h->tamanho;
    }

    printf("\nElemento nao encontrado");

    return -1;
}

int main(){
    int vec[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    HASH *h = inicializarHash(h, size);
    for(int i = 0; i<10; i++){
        elemento aux = criarElemento(vec[i]);
        insert(h, aux);
    }
}