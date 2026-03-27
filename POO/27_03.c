#include <stdio.h>

struct camara{
    int id;
    int nao_furada;
};

struct bike{
    int id;
    struct camara *frente;
    struct camara *tras;
};

int isOK(struct bike *b){
    return (b->frente->nao_furada && b->tras->nao_furada);
};

int main(){
    //fodase
}