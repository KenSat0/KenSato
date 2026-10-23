#include <stdio.h>
#include <stdlib.h>

#define ORDEM 4

typedef struct Page{
    int count;
    int keys[ORDEM - 1];
    struct Page *filhos[ORDEM];
    bool isLeaf;
} Page;

Page *alocarNo(){
    Page *novaPag = (Page*)malloc(sizeof(Page));

    if(novaPag != NULL){
        novaPag->count = 0;
        novaPag->isLeaf = true;

        for(int i = 0; i<ORDEM; i++){
            novaPag->filhos[i] = NULL;
        }
    }

    return novaPag;
}

int main(){
    //qlqr coisa :)
}