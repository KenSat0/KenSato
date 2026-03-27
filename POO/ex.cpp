#include <stdio.h>
#include <stdlib.h>

#define MAXLENGHT 5

struct ep{
    int notaA, notaB;
    int num;
    bool e_existe;
};

struct temporada{
    int num;
    bool t_existe;
    struct ep array[MAXLENGHT];
};

struct serie{
    char nome[50];
    struct temporada array[MAXLENGHT];
};

int notaMedia(struct ep e){
    int media = (e.notaA + e.notaB)/2;
    return media;
}

void consulta(struct serie s){
    int x = 0;
    while(s.array[x].t_existe){
        struct temporada t = s.array[x];
        int y = 0;
        while(t.array[y].e_existe){
            struct ep e = t.array[y];
            if (notaMedia(e) < 5){
                printf("\nSerie merda");
                return;
            }
            y++;
        }
        x++;
    }
    printf("\nPeak");
}

int main(){
    struct ep i;
        i.notaA = 6;
        i.notaB = 6;
        i.num = 1;
    struct ep ii;
        ii.notaA = 6;
        ii.notaB = 6;
        ii.num = 2;
    struct ep iii;
        iii.notaA = 6;
        iii.notaB = 6;
        iii.num = 3;
    struct ep iv;
        iv.notaA = 6;
        iv.notaB = 6;
        iv.num = 4;
    struct ep v;
        v.notaA = 3;
        v.notaB = 6;
        v.num = 5;
    struct ep vi;
        vi.notaA = 6;
        vi.notaB = 6;
        vi.num = 6;
    
    struct temporada um;
        for(int i = 0; i<MAXLENGHT; i++){
            um.array[i].e_existe = 0;
        }

        um.array[0] = i;
        um.array[0].e_existe = 1;
        um.array[1] = ii;
        um.array[1].e_existe = 1;
        um.array[2] = iii;
        um.array[2].e_existe = 1;
        um.array[3] = iv;
        um.array[3].e_existe = 1;
        um.array[4] = v;
        um.array[4].e_existe = 1;
    struct temporada dois;
        for(int i = 0; i<MAXLENGHT; i++){
            dois.array[i].e_existe = 0;
        }

        dois.array[0] = vi;
        dois.array[0].e_existe = 1;

    um.num = 1;
    dois.num = 2;

    struct serie *pinto;
    for(int i = 0; i<MAXLENGHT; i++){
        pinto->array[i].t_existe = 0;
    }

    pinto->array[0] = um;
    pinto->array[0].t_existe = 1;
    pinto->array[1] = dois;
    pinto->array[1].t_existe = 1;

    consulta(*pinto);

    return 0;
}