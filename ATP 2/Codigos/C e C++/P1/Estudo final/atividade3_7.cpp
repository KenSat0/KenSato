#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char nome[100];
    int idade;
    float nota;
} alunos;

int cadastro()
{
    FILE *p = fopen("boletim.txt", "ab");
    if(p==NULL) return 1;

    alunos *aux = (alunos*)malloc(sizeof(alunos));

    char nome[100];
    printf("\nNome: ");
    scanf("%s", nome);
    strcpy(aux->nome, nome);

    printf("\nIdade: ");
    scanf("%d", &aux->idade);

    printf("\nNota: ");
    scanf("%f", &aux->nota);

    fwrite(aux, sizeof(alunos), 1, p);

    free(aux);
    fclose(p);

    return 0;
}

int listar()
{
    FILE *p = fopen("boletim.txt", "rb");
    if(p==NULL) return 1;

    alunos *aux = (alunos*)malloc(sizeof(alunos));

    while(fread(aux, sizeof(alunos), 1, p)==1)
    {
        printf("\nNome: %s", aux->nome);
        printf("\nIdade: %d", aux->idade);
        printf("\nNota: %f", aux->nota);
    }

    free(aux);
    fclose(p);
    
    return 0;
}

int buscar()
{
    FILE *p = fopen("boletim.txt", "rb");
    if(p==NULL) return 1;

    alunos *aux = (alunos*)malloc(sizeof(alunos));

    char nome[100];
    printf("\nBuscar por nome: ");
    scanf("%s", nome);

    while(fread(aux, sizeof(alunos), 1, p)==1)
    {
        if(strcmp(nome, aux->nome)==0)
        {
            printf("\nNome: %s", aux->nome);
            printf("\nIdade: %d", aux->idade);
            printf("\nNota: %f", aux->nota);
        }
    }

    free(aux);
    fclose(p);
    
    return 0;
}

int main()
{
    int menu;
    while(true)
    {
        printf("\n1 - Cadastrar\n2 - Listar\n3 - Buscar\n4 - Sair\nO que fazer: ");
        scanf("%d", &menu);
        if(menu==1) cadastro();
        if(menu==2) listar();
        if(menu==3) buscar();
        if(menu==4) break;
    }

    getchar();
    return 0;
}