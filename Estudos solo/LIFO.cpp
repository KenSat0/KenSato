#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 100

struct stack {
    int top;
    int data[MAXSTACK];
};

bool empty(struct stack *pnt){
    if(pnt->top == -1){
        printf("\nPilha vazia");
        return (1);
    }
    return (0);
}

void stacktop(struct stack *pnt){
    if(empty(pnt)) return;
    printf("\n%d e o topo da pilha", pnt->data[pnt->top]);
    return;
}

void stackPrint(struct stack *pnt){
    if(empty(pnt)) return;
    printf("\n");
    for (int i = 0; i<= pnt->top; i++){
        printf("%d   ", pnt->data[i]);
    }
    return;
}

void push(struct stack *pnt, int valor){
    if(pnt->top < MAXSTACK){
        pnt->top++;
        pnt->data[pnt->top] = valor;
    }
    return;
}

void pop(struct stack *pnt){
    if(empty(pnt)) return;
    pnt->top--;
    return;
}

int main(){
    struct stack s;
    s.top = -1;

    
    stacktop(&s);

    push(&s, 2);
    push(&s, 67);
    push(&s, 16);
    
    stackPrint(&s);

    stacktop(&s);

    pop(&s);

    stackPrint(&s);
    
    stacktop(&s);

    return 0;
}