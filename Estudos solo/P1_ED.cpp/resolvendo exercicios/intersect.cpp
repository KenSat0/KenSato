#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct FilaOrdenada {
    int vetor[MAXSIZE];
    int total; // Usaremos 'total' para simplificar o controle em filas ordenadas estáticas
};

void init(struct FilaOrdenada *f);

bool empty(struct FilaOrdenada *f);

bool full(struct FilaOrdenada *f);

void queue(struct FilaOrdenada *f, int x);

void unqueue(struct FilaOrdenada *f);

void print(struct FilaOrdenada *f);

struct FilaOrdenada *intersect(struct FilaOrdenada *a, struct FilaOrdenada *b);

int main() {
    struct FilaOrdenada a;
    init(&a);

    struct FilaOrdenada b;
    init(&b);

    queue(&a, 30);
    queue(&a, 10);
    queue(&a, 20);
    queue(&a, 6);

    queue(&b, 35);
    queue(&b, 10);
    queue(&b, 25);
    queue(&b, 20); // Teste de repetição
    queue(&b, 5);

    print(&a); // Deve mostrar: 5, 10, 20, 30
    print(&b); // Deve mostrar: 10, 20, 30

    struct FilaOrdenada *c = intersect(&a, &b);
    print(c);
    free(c);

    return 0;
}

// Inicializa a fila
void init(struct FilaOrdenada *f) {
    f->total = 0;
}
// Verifica se está vazia
bool empty(struct FilaOrdenada *f) {
    return (f->total == 0);
}
// Verifica se está cheia
bool full(struct FilaOrdenada *f) {
    return (f->total == MAXSIZE);
}
// Inserção Ordenada e Sem Repetição
void queue(struct FilaOrdenada *f, int x) {
    if (full(f)) {
        printf("Erro: Fila Cheia!\n");
        return;
    }

    // 1. Verificar se já existe (Sem repetição)
    for (int i = 0; i < f->total; i++) {
        if (f->vetor[i] == x) {
            printf("Erro: Valor %d ja existe na fila!\n", x);
            return;
        }
    }

    // 2. Encontrar a posição correta e deslocar elementos
    int i = f->total - 1;
    while (i >= 0 && f->vetor[i] > x) {
        f->vetor[i + 1] = f->vetor[i]; // Desloca para a direita
        i--;
    }

    f->vetor[i + 1] = x;
    f->total++;
    printf("Inserido: %d\n", x);
}
// Remoção (Sempre do início - o menor valor na fila crescente)
void unqueue(struct FilaOrdenada *f) {
    if (empty(f)) {
        printf("Erro: Fila Vazia!\n");
        return;
    }

    printf("Removido: %d\n", f->vetor[0]);

    // Desloca todos os elementos para a esquerda para manter o início no índice 0
    for (int i = 0; i < f->total - 1; i++) {
        f->vetor[i] = f->vetor[i + 1];
    }
    
    f->total--;
}

void print(struct FilaOrdenada *f) {
    if (empty(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila: ");
    for (int i = 0; i < f->total; i++) {
        printf("[%d] ", f->vetor[i]);
    }
    printf("\n");
}

struct FilaOrdenada *intersect(struct FilaOrdenada *a, struct FilaOrdenada *b){
    struct FilaOrdenada *c = (struct FilaOrdenada*)malloc(sizeof(struct FilaOrdenada));
    init(c);
    if(a==NULL || b==NULL) return c;

    for (int i = 0; i < a->total; i++) {
        for (int j = 0; j < b->total; j++) {
            if(a->vetor[i] == b->vetor[j]){
            int inter = a->vetor[i];
                queue(c, inter);
            }
        }
    }
    return c;
}