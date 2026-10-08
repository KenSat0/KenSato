#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    char endereco[50];
    int idx;
}registro;

int adicionar(char *arquivo, registro *r){
    FILE *f = fopen(arquivo, "ab");
    if (!f){printf("\n erro"); return 0;}

    fwrite(r, sizeof(registro), 1, f);
    fclose(f);
}

int cadastros(char *arquivo){
    FILE *f = fopen(arquivo, "rb");
    if (!f){printf("\n erro"); return 0;}

    registro aux;
    while(fread(&aux, sizeof(registro), 1, f) == 1){
        printf("\n %d", aux.idx);
        printf("\n %s", aux.nome);
        printf("\n %s", aux.endereco);
    }

    fclose(f);
    return 0;
}

int main(){
    registro A = {"ALICE", "RUA 1", 1};
    registro B = {"BRUNO", "RUA 3", 2};
    registro C = {"CARLOS", "RUA 5", 3};

    adicionar("data.bin", &A);
    adicionar("data.bin", &B);
    adicionar("data.bin", &C);

    cadastros("data.bin");

    return 0;
}