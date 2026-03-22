#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f1;
    FILE *f_final;
    char str[100];

    f1 = fopen("nomes.txt", "r");
    if (f1 == NULL)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    f_final = fopen("arquivos_juntos.txt", "w");
    if (f_final == NULL)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    while(fgets(str, sizeof(str), f1) != NULL)
    {
        fputs(str, f_final);
    }

    fclose(f1);
    fclose(f_final);

    f1 = fopen("copia_nomes.txt", "r");
    if (f1 == NULL)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    f_final = fopen("arquivos_juntos.txt", "a");
    if (f_final == NULL)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    fputs("\n", f_final);

    while(fgets(str, sizeof(str), f1) != NULL)
    {
        fputs(str, f_final);
    }

    printf("Concatenacao finalizada");

    getchar();
    return 0;
}