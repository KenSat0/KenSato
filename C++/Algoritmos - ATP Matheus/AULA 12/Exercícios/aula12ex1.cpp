#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float p1, p2, ex;

} Aluno;

float calcular_media(Aluno *a)
{
    float media = 0;
    float provas = 0;
    provas = (a->p1*4+a->p2*6)/10;
    media = (a->ex * 2 + provas * 8)/10;

    return (media);
}



int main()
{
    Aluno a;
    a.ex = 10;
    a.p1 = 10;
    a.p2 = 10;

    printf("%.2f", calcular_media(&a));

    getchar();
    return 0;
}