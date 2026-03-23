#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float nota;
} Aluno;

void cadastrarAluno(int a, char *b, float c){ //variaveis não precisam ser passadas, pode pedir quando declara Aluno temp
    FILE *arq = fopen("aluno_data.dat", "ab"); //não precisa receber arquivo como argumento pois o arquivo é externo e é acessado pelo nome em qualquer lugar do codigo
    if (arq == NULL) return;

    Aluno temp;
    temp.id = a;
    strcpy(temp.nome, b);
    temp.nota = c;

    fwrite(&temp, sizeof(Aluno), 1, arq);

    fclose(arq);
}

void listarAluno(){
    FILE *arq = fopen("aluno_data.dat", "rb");
    if (arq == NULL){
        printf("\nArquivo nao encontrado");
        return;
    }

    Aluno aux;
    printf("\n--- Lista de Alunos ---");
    while (fread(&aux, sizeof(Aluno), 1, arq)){
        printf("\nID: %d | Nome: %-15s | Nota: %.2f", aux.id, aux.nome, aux.nota);
    }

    fclose(arq);
}

void atualizarNota(int procura, int nova_nota){
    FILE *arq = fopen("aluno_data.dat", "rb+");
    if (arq == NULL){
        printf("\nArquivo nao encontrado");
        return;
    }

    Aluno aux;
    printf("\n--- Lista de Alunos ---");
    while (fread(&aux, sizeof(Aluno), 1, arq)){
        if(procura == aux.id){
            aux.nota = nova_nota;

            fseek(arq, -sizeof(Aluno), SEEK_CUR);

            fwrite(&aux, sizeof(Aluno), 1, arq);

            printf("\nNota alterada");
            break;
        }
    }

    fclose(arq);
}

void removerAluno(int procura){
    int found_check = 0;
    FILE *arq = fopen("aluno_data.dat", "rb+");
    if (arq == NULL){
        printf("\nArquivo nao encontrado");
        return;
    }

    FILE *temp = fopen("temp.dat", "w");
    if (temp == NULL){
        printf("\nArquivo nao encontrado");
        return;
    }

    Aluno aux;
    while (fread(&aux, sizeof(Aluno), 1, arq)){
        if(procura != aux.id){
            fwrite(&aux, sizeof(Aluno), 1, arq);

            printf("\nNota alterada");
        }else{
            found_check = 1;
        }
    }

    fclose(arq);
    fclose(temp);

    if (found_check){
        remove("aluno_data.dat");
        rename("temp.dat", "aluno_data.dat");
    }else{
        remove("temp.dat");
        printf("\nAluno nao encontrado");
    }
}

void clear(){
    remove("aluno_data.dat");
}

int main(){
    cadastrarAluno(1, "eduardo", 6.0);
    cadastrarAluno(2, "samuel", 7.0);
    cadastrarAluno(3, "brunello", 6.0);
    cadastrarAluno(4, "vitoria", 7.0);
    cadastrarAluno(5, "leonardo", 10.0);

    listarAluno();

    atualizarNota(5, 9.0);

    listarAluno();

    clear();

    return 0;
}