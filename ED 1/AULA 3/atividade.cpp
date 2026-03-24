#include <stdio.h>
#include <stdlib.h>

#define STACKMAX 9

struct Pilha{
    int top;
    char *vetor;
};

int C_index;

void push(struct Pilha *p, char x){
    if(p->top < STACKMAX){
            printf("A");
        p->top++;
        p->vetor[p->top] = x;
    }
    return;
}

void instaPush(struct Pilha *p, char *string){
    int i = 0;
    while(string[i] != 'C'){
            printf("B");
        push(p, string[i]);
        i++;
    }
    C_index = i;
}

void popCompare(struct Pilha *p, char *string){
    C_index++;
    int i = 0;
    while(string[C_index+1]!='\0'){
            printf("c");
        if(p->vetor[p->top] != string[C_index+i]){
            printf("\nNao e igual");
            return;
        }
        i++;
        p->top--;
    }
    printf("\nE igual");
}

int main(){
    struct Pilha stack;
    stack.top = -1;

    char *str = "babCbab";

    instaPush(&stack, str);
    popCompare(&stack, str);

    return 0;
}