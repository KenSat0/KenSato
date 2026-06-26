#include <stdio.h>
#include <stdlib.h>

#define MAX 200

struct stack{
    int top;
    int vetor[MAX];
};

typedef struct stack stack;

void push(stack *p, int c);
int pop(stack *p);
void invert(stack *a, stack *b);
void check(stack *p);

int main(){
    stack p;
    stack p2;
    p.top = -1;
    p2.top = -1;

    push(&p, 5);
    push(&p, 4);
    push(&p, 3);
    push(&p, 2);
    push(&p, 1);
    check(&p);

    invert(&p, &p2);
    check(&p2);

    return 0;
}

void push(stack *p, int c){
    if (p->top < MAX - 1){
        p->top++;
        p->vetor[p->top] = c;
    }
}

int pop(stack *p){
    if (p->top == -1) return ('\0');
    int c = p->vetor[p->top];
    p->top--;
    return c;
}

void invert(stack *a, stack *b){
    if(a->top == -1) return;
    while(a->top >= 0){
        push(b, pop(a));
    }
}

void check(stack *p){
    if(p->top == -1) return;
    int i = p->top;
    while(i >= 0){
        printf("    %d", p->vetor[i]);
        i--;
    }
}