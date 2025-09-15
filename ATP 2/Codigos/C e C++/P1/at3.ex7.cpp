#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//bloco de dados para alunos

typedef struct
{

    char nome[50];
    int idade;
    float nota;

} Alunos;

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int adicionar()
{
    //abre arquivo para escrever em binario
    FILE *p = fopen("alunos.txt", "ab");
    if(p==NULL) return 1;

    //cria ponteiro aluno auxiliar
    Alunos *aux;
    aux = (Alunos*)malloc(sizeof(Alunos));

    printf("\nNome: ");
    char nome[50];
    scanf("%s", nome);
    strcpy(aux->nome, nome);

    printf("\nIdade: ");
    scanf("%d", &aux->idade);

    printf("\nNota: ");
    scanf("%f", &aux->nota);

    //escreve o auxiliar, de tamanho aluno, 1 por vez, no arquivo
    fwrite(aux, sizeof(Alunos), 1, p);

    //libera e fecha
    free(aux);
    fclose(p);
}

int listar()
{
    //abre arquivo para ler em binario
    FILE *p = fopen("alunos.txt", "rb");
    if(p==NULL) return 1;

    //volta o ponteiro para o inicio do arquivo
    rewind(p);  

    Alunos *aux;
    aux = (Alunos*)malloc(sizeof(Alunos));

    //enquanto der para ler um aluno (se acabar, retorna 0 e fica falso)
    while(fread(aux, sizeof(Alunos), 1, p)==1)
    {
        //imprime informações
        printf("\nNome: %s", aux->nome);
        printf("\nIdade: %d", aux->idade);
        printf("\nNota: %.2f", aux->nota);
    }

    //libera e fecha
    free(aux);
    fclose(p);
    return 0;
}

int buscar()
{
    FILE *p = fopen("alunos.txt", "rb");
    if(p==NULL) return 1;

    rewind(p);  

    Alunos *aux;
    aux = (Alunos*)malloc(sizeof(Alunos));

    char nome[50];
    printf("\nBusca por nome: ");
    scanf("%s", nome);

    //enquanto não terminar o arquivo
    while(fread(aux, sizeof(Alunos), 1, p)==1)
    {
        //compara duas strings: nome X busca (0 significa nenhuma diferença)
        if(strcmp(nome, aux->nome)==0)
        {
            //imprime o aluno que achou
            printf("\nNome: %s", aux->nome);
            printf("\nIdade: %d", aux->idade);
            printf("\nNota: %.2f", aux->nota);
        }
    }

    //libera e fecha
    free(aux);
    fclose(p);
    return 0;
}

int main()
{
    int menu;
    while(true)
    {
        printf("\n1 - Cadastrar alunos\n2 - Listar alunos\n3 - Buscar\n4 - Sair\nO que deseja fazer: ");
        scanf("%d", &menu);

        limpar_buffer();

        if(menu==1) adicionar();
        if(menu==2) listar();
        if(menu==3) buscar();
        if(menu==4) break;
    }

    getchar();
    return 0;
}