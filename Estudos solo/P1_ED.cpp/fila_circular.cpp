#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 5

// Função para inserir (Enfileirar)
void inserir(int vetor[], int *fim, int *inicio, int valor);

// Função para remover (Desenfileirar)
void remover(int vetor[], int *inicio, int *fim);

// Função para mostrar os elementos
void mostrar(int vetor[], int inicio, int fim);

int somatorio(int fila[], int inicio, int fim);

int main() {
    int fila[MAXSIZE];
    int ini = 0;
    int f = 0;

    inserir(fila, &f, &ini, 10);
    inserir(fila, &f, &ini, 20);
    inserir(fila, &f, &ini, 30);
    
    mostrar(fila, ini, f);
    printf("Somatorio: %d\n", somatorio(fila, ini, f));

    remover(fila, &ini, &f);
    mostrar(fila, ini, f);
    printf("Somatorio: %d\n", somatorio(fila, ini, f));

    return 0;
}

// Função para inserir (Enfileirar)
void inserir(int vetor[], int *fim, int *inicio, int valor) {
    // Verifica se o próximo passo do fim alcança o início
    if ((*fim + 1) % MAXSIZE == *inicio) {
        printf("Erro: Fila Cheia! Nao foi possivel inserir %d\n", valor);
    } else {
        *fim = (*fim + 1) % MAXSIZE;
        vetor[*fim] = valor;
        printf("Inserido: %d\n", valor);
    }
}

// Função para remover (Desenfileirar)
void remover(int vetor[], int *inicio, int *fim) {
    if (*inicio == *fim) {
        printf("Erro: Fila Vazia!\n");
    } else {
        *inicio = (*inicio + 1) % MAXSIZE;
        printf("Removido: %d\n", vetor[*inicio]);
    }
}

// Função para mostrar os elementos
void mostrar(int vetor[], int inicio, int fim) {
    if (inicio == fim) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila atual: ");
    int i = (inicio + 1) % MAXSIZE;
    while (true) {
        printf("[%d] ", vetor[i]);
        if (i == fim) break;
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int somatorio(int fila[], int inicio, int fim){
    if (inicio == fim) return 0;
    
    int i = (inicio + 1) % MAXSIZE;

    int soma = 0;
    while (true) {
        soma = soma + fila[i];
        if (i == fim) break;
        i = (i + 1) % MAXSIZE;
    }
    return soma;
}