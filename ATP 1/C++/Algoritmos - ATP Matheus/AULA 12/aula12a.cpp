#include <stdio.h>
#include <stdlib.h>

struct Ponto
{
    float x, y;
};

/*

typedef struct
{
    float x, y;
} Ponto;

também funciona igual

*/

void imprime_ponto(Ponto p)
{
    printf("(%.2f),(%.2f)\n", p.x, p.y);
}

void escala_ponto(Ponto *p, float escala)
{  
    //p->x endereço do X na estrutura P
    p->x = p->x * escala;
    p->y = p->y * escala;
}

int main()
{
    Ponto p1, p2; // ponto se torna um tipo de dado, assim como int e float

    p1 = {2.5, 3.7};
    p2.y = 4.2;
    p2.x = 1.8;

    escala_ponto(&p1, 3); //multiplica ponto por um escalar 

    //printf("p1: (%.2f),(%.2f)", p1.x, p1.y);
    imprime_ponto(p1);
    imprime_ponto(p2);

    getchar();
    return 0;
}