#include <stdio.h>
#include <stdlib.h>

#define max_size 10

bool empty(int **front, int **rear);
bool full(int *lastElement);
void queue(int **front, int **rear, int *lastElement, int val);
int unqueue(int **front, int **rear, int *lastElement);

int main(){
    int fila[max_size] = {0};
    
    int *lastElement = &fila[max_size];
    int *head = &fila[0];
    int **headCpy = &head;
    int *tail = &fila[0];
    int **tailCpy = &tail;

    queue(headCpy, tailCpy, lastElement, 67);
    queue(headCpy, tailCpy, lastElement, 69);
    unqueue(headCpy, tailCpy, lastElement);
    printf("%d", fila[0]);

    return 0;
}

bool empty(int **front, int **rear){
    if((*front)==(*rear)){
        return true;
    }
    return false;
}

bool full(int *lastElement){
    if(*lastElement == 0){
        return false;
    }
    return true;
}

void queue(int **front, int **rear, int *lastElement, int val){
    if(empty(front, rear)){
        *rear = *rear + 1;
        *(*front) = val;
        return;
    }
    if(full(lastElement)){
        puts("\ncheio pai");
        return;
    }
    *(*rear) = val;
    *rear = *rear + 1;
}

int unqueue(int **front, int **rear, int *lastElement){
    if(empty(front, rear)){
        puts("\nvazio pai");
        return -1;   
    }
    if(full(lastElement)){
        int i = *(*front);
        int j = 0;
        while(j < max_size - 1){
            (*front)[j] = (*front)[j + 1];
            j++;
        }
        return i;
    }

    int i = *(*front);
    int j = 0;
    while((*front)[j] != 0){
        (*front)[j] = (*front)[j + 1];
        j++;
    }

    *rear = *rear + 1;
    return i;
}