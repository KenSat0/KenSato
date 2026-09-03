#include <stdio.h>
#include <stdlib.h>

void ler_ultimas_linhas(const char *nome_arquivo, int n) {
    FILE *f = fopen(nome_arquivo, "rb");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    long pos = ftell(f) - 1;

    if (pos < 0) {
        printf("O arquivo está vazio.\n");
        fclose(f);
        return;
    }

    fseek(f, pos, SEEK_SET);
    if (fgetc(f) == '\n') {
        pos--;
    }

    int count = 0;
    while (pos >= 0) {
        fseek(f, pos, SEEK_SET);
        int ch = fgetc(f);

        if (ch == '\n') {
            count++;
            if (count == n) {
                break; 
            }
        }
        pos--;
    }


    if (pos < 0) {
        fseek(f, 0, SEEK_SET);
    } else {
        fseek(f, pos + 1, SEEK_SET);
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        printf("%s", buffer);
    }

    fclose(f);
}

int main() {
    int n = 3;
    ler_ultimas_linhas("ex3.txt", n);
    return 0;
}