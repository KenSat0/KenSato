#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

struct stack{
    int pilha[MAXSIZE];
    int top;
};

void insert(struct stack *s, int x);

void pop(struct stack *s);

int stacktop(struct stack *s);

void print(struct stack *s){
    if(s->top != -1){
        printf("\n");
        for(int i = 0; i<=s->top; i++){
            printf("%d  ", s->pilha[i]);
        }
    }
}

int main(){
    struct stack s;
    s.top = -1;

    insert(&s, 2);
    insert(&s, 4);
    insert(&s, 8);
    insert(&s, 67);
    print(&s);
    if(stacktop(&s)!=-1){
        printf("\n%d", stacktop(&s));
    };
    pop(&s);
    pop(&s);
    if(stacktop(&s)!=-1){
        printf("\n%d", stacktop(&s));
    };

}

void insert(struct stack *s, int x){
    if(s->top<MAXSIZE-1){
        s->top++;
        s->pilha[s->top] = x;
        printf("\nValor %d inserido", x);
        return;
    }
    printf("\nErro: Pilha Cheia");
    return;
}

void pop(struct stack *s){
    if(s->top==-1){
        printf("\nErro: Pilha Vazia");
        return;
    }
    printf("\nValor %d removido", s->pilha[s->top]);
    s->pilha[s->top] = 0;
    s->top--;
    return;
}

int stacktop(struct stack *s){
    if(s->top == -1){
        printf("\nErro: Pilha Vazia");
        return -1;
    }
    return (s->pilha[s->top]);
}