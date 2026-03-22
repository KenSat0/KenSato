#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char linha[100];
    char palavra[100];

    arquivo = fopen("nomes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Palavra desejada: ");
    scanf("%s", palavra);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, palavra) != NULL) { 
            printf("Palavra '%s' encontrada na linha: %s", palavra, linha);
        }
    }


    fclose(arquivo);

    getchar();
    return 0;
}