#include <stdio.h>
#include <stdlib.h>

//obs.: o algoritmo usa 0 valor -67 para delimitar os grupos de cada rodada e -1 para o fim do vetor

int menor_entre(int a, int b){
    if(a < b) return a;
    return b;
}

int *formatar_rodada(int rodada, int *vetor_origem){
    int index_o = 0;
    int index_f = 0;
    int *vetor_formatado = (int*)malloc(32*sizeof(int));

    while(vetor_origem[index_o] != -1){
        for(int i = 0; i < rodada; i++){
            vetor_formatado[index_f] = vetor_origem[index_o];
            printf("\norigem: %d -> destino %d", vetor_origem[index_o], vetor_formatado[index_f]);
            index_f++;
            index_o++;
        }
        vetor_formatado[index_f] = -67;
        index_f++;
    }

    vetor_formatado[index_f] = -1;

    printf("\n");
    index_f = 0;
    while(vetor_formatado[index_f] != -1){
        printf("%d  ", vetor_formatado[index_f]);
        index_f++;
    }

    return vetor_formatado;
}

int *intercalar(int *f1, int *f2, int *saida, int rodada, int num_rodada){
    int i = 0, j = 0, index_s = rodada*num_rodada;

    while(f1[i] != -67 && f2[j] != -67){
        if(f1[i] < f2[j]){
            saida[index_s] = f1[i];
            index_s++;
            i++;
        } else {
            saida[index_s] = f2[j];
            index_s++;
            j++;
        }
    }
    while(f1[i] != -67){
        saida[index_s] = f1[i];
        index_s++;
        i++;
    }
    while(f2[j] != -67){
        saida[index_s] = f2[j];
        index_s++;
        j++;
    }
    return saida;
}

int *merge(int *f1, int *f2, int *g1, int *g2, int rodada){
    f1 = formatar_rodada(rodada, f1);
    f2 = formatar_rodada(rodada, f2);
    int i = 0, j = 0;

    while(f1){

    }
}

int main(){
    int f1[17] = {14, 3, 27, 9, 55, 41, 22, 18, -1}; 
    int f2[17] = {7, 33, 12, 29, 5, 48, 20, 11, -1};
    int g1[17];
    int g2[17];

    int *t1 = formatar_rodada(2, f1);
    int *t2 = formatar_rodada(2, f2);

    

    return 0;
}

/*
merge: intercala até chegar no delimitador -67, se encontrar um delimitador -1, joga o resto do outro vetor
*/