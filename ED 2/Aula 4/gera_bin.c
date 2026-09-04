#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura idêntica à do programa principal
typedef struct {
    char codigo[4];        // 3 caracteres + '\0'
    char nome[51];        // até 50 caracteres
    char seguradora[51];  // até 50 caracteres
    char tipo[31];        // até 30 caracteres
} Segurado;

int main() {
    // 1. Criando insere.bin com registros de exemplo
    FILE *f_insere = fopen("insere.bin", "wb");
    if (f_insere == NULL) {
        printf("Erro ao criar insere.bin\n");
        return 1;
    }

    Segurado dados[] = {
        {"001", "Samuel", "seguro 1", "Residencial"},
        {"002", "Vitoria", "seguro 2", "Automovel"},
        {"003", "Brunello", "seguro 3", "Vida"},
        {"004", "Eduardo", "seguro 4", "Empresarial"},
        {"005", "LEonardo", "seguro 5", "Automovel"}
    };

    int total_insercoes = sizeof(dados) / sizeof(Segurado);
    fwrite(dados, sizeof(Segurado), total_insercoes, f_insere);
    fclose(f_insere);
    printf("Arquivo 'insere.bin' gerado com %d registros.\n", total_insercoes);

    // 2. Criando remove.bin com códigos de teste para remoção
    FILE *f_remove = fopen("remove.bin", "wb");
    if (f_remove == NULL) {
        printf("Erro ao criar remove.bin\n");
        return 1;
    }

    // Códigos de 3 caracteres que serão buscados para remoção
    char codigos_remove[][3] = {
        {'0', '0', '2'}, // Remove Carlos
        {'0', '0', '1'}, // Remove Veronica
        {'0', '0', '4'}  // Remove Fernando
    };

    int total_remocoes = sizeof(codigos_remove) / (3 * sizeof(char));
    fwrite(codigos_remove, sizeof(char), total_remocoes * 3, f_remove);
    fclose(f_remove);
    printf("Arquivo 'remove.bin' gerado com %d codigos de remocao.\n", total_remocoes);

    return 0;
}