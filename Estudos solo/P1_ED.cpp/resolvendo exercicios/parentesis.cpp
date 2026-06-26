#include <stdio.h>
#include <stdlib.h>

#define maxsize 100

struct a{
    int top;
    int vetor[maxsize]; //desnecessário
};

typedef struct a stack;

bool empty(stack *p);

bool full(stack *p);

bool insert(stack *p);

bool pop(stack *p);

int checkStr(stack *p, char *str);

int checkStrNOP();

int main(){
    /*stack pilha;
    pilha.top = -1;

    char *str1 = "4x(2-6y(y-5x)-3)";
    char *str2 = "4x)2-6y(y-5x(-3)";
    char *str3 = "4x(2-6y(y-5x)-3";
    
    if(checkStr(&pilha, str1)){
        printf("\nExpressao Valida");
    }
    pilha.top = -1;

    if(checkStr(&pilha, str2)){
        printf("\nExpressao Valida");
    }
    pilha.top = -1;

    if(checkStr(&pilha, str3)){
        printf("\nExpressao Valida");
    }else{
        printf("\nformatacao invalida");
    }*/

    if(checkStrNOP()){
        printf("\ncorreto");
    }else{
        printf("\nerrado");
    }

    return 0;
}

int checkStr(stack *p, char *str){
    for(int i = 0; str[i]!='\0'; i++){
        if(str[i]=='('){
            insert(p);
        }else if (str[i]==')'){
            if(pop(p)==false){
                printf("\nformatacao invalida");
                return (0);
            }
        }
    }
    if(p->top != -1) return (0);
    return 1;
}

int checkStrNOP(){
    stack p;
    p.top = -1;

    char c;

    printf("digite a expressão:\n");
    while(scanf("%c", &c) == 1 && c != '\n'){
        if(c=='('){
            insert(&p);
        }else if (c==')'){
            if(pop(&p)==false){
                printf("\nformatacao invalida");
                return (0);
            }
        }
    }
    if(p.top != -1) return (0);
    return 1;
}

bool empty(stack *p){
    if(p->top == -1) return true;
    return false;
}

bool full(stack *p){
    return(p->top == maxsize - 1);
}

bool insert(stack *p){
    if(full(p)) return false;
    p->top++;
    p->vetor[p->top] = 1;
    return true;
}

bool pop(stack *p){
    if (empty(p)) return false;
    p->vetor[p->top] = 0;
    p->top--;
    return true;
}