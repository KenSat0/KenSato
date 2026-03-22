#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float p1, p2, ex;

} Aluno;

typedef struct no
{
    Aluno *aluno;
    struct no *prox;
} No;

float calcular_media(Aluno *a)
{
    float media = 0;
    float provas = 0;
    provas = (a->p1*4+a->p2*6)/10;
    media = (a->ex * 2 + provas * 8)/10;

    return (media);
}

void imprime_media(No *listaAluno)
{  
    No *atual = listaAluno;
    while(atual != NULL)
    {
        printf("%s: %.2f\n", atual->aluno->nome, (calcular_media(atual->aluno)));
        atual = atual->prox;
    }
}

int main()
{
    Aluno a, b;
    No na, nb;

    na.aluno = &a;
    na.prox = &nb;
    nb.aluno = &b;
    nb.prox = NULL;

    a.ex = 10;
    a.p1 = 10;
    a.p2 = 10;
    b.ex = 0;
    b.p1 = 0;
    b.p2 = 0;

    imprime_media(&na);

    getchar();
    return 0;
}