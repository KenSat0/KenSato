#include <stdio.h>
#include <stdlib.h>

#define MAX 200

struct stack{
    int top;
    char vetor[MAX];
};

typedef struct stack stack;

void push(stack *p, char c);
char pop(stack *p);
void palindromo();

int main(){
    palindromo();
    return 0;
}

void push(stack *p, char c){
    if (p->top < MAX - 1){
        p->top++;
        p->vetor[p->top] = c;
    }
}

char pop(stack *p){
    if (p->top == -1) return ('\0');
    char c = p->vetor[p->top];
    p->top--;
    return c;
}

void palindromo(){
    stack p;
    p.top = -1;
    char c;
    char s[MAX];
    int i = 0;
    printf("Escreva uma frase (cap.: 180): ");
    while((scanf("%c", &c)==1) && c != '\n'){
        if(c!=' '){
            push(&p, c);
            s[i] = c;
            i++;
        }
    }
    char str[p.top+1];
    i = 0;
    for(i; p.top >= 0; i++){
        str[i]=pop(&p);
    }
    str[i] = '\0';
    

    printf("%s\n", s);
    printf("%s\n", str);

    int j = 0;

    while(s[j]!='\0' && str[j]!='\0'){
        if(s[j]!=str[j]){
            printf("\nNao e palindromo");
            return;
        }
        j++;
    }
    printf("\nE palindromo");
    return;
}
