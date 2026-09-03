#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 512
#define MAX_CAMPO 100

typedef struct {
    char cpf[15];
    char nome[50];
    char sobrenome[50];
    char telefone[20];
    char cidade[50];
} Cliente;

typedef struct {
    long offset;
    char cpf[15];
} IndiceEntry;

typedef struct {
    IndiceEntry *entries;
    int total;
} Indice;

int pega_campo(FILE *fp, char *buffer, int max_len) {
    int c, i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '|' || c == '\n') {
            buffer[i] = '\0';
            return 1;
        }
        if (i < max_len - 1) {
            buffer[i++] = c;
        }
    }
    buffer[i] = '\0';
    return (i > 0) ? 1 : 0;
}

int pega_registro(FILE *fp, Cliente *c) {
    char buffer[MAX_BUFFER];
    if (!pega_campo(fp, buffer, sizeof(buffer))) {
        return 0;
    }
    
    int lidos = sscanf(buffer, "%s %s %s %s %s", 
                       c->cpf, c->nome, c->sobrenome, c->telefone, c->cidade);
    
    return (lidos >= 1);
}

void grava_registro(FILE *fp, const Cliente *c) {
    fprintf(fp, "%s %s %s %s %s|", c->cpf, c->nome, c->sobrenome, c->telefone, c->cidade);
}

void inserir_cliente(const char *arq_nome, Cliente novo) {
    FILE *in = fopen(arq_nome, "rb");
    FILE *out = fopen("temp.bin", "wb");
    
    if (!out) {
        if (in) fclose(in);
        return;
    }

    Cliente atual;
    int inserido = 0;

    if (in) {
        while (pega_registro(in, &atual)) {
            int cmp = strcmp(atual.cpf, novo.cpf);
            if (cmp == 0) {
                
                printf("Erro: CPF %s ja cadastrado.\n", novo.cpf);
                inserido = -1;
                grava_registro(out, &atual);
            } else if (cmp > 0 && !inserido) {
                grava_registro(out, &novo);
                grava_registro(out, &atual);
                inserido = 1;
            } else {
                grava_registro(out, &atual);
            }
        }
        fclose(in);
    }

    if (!inserido) {
        grava_registro(out, &novo);
    }

    fclose(out);
    remove(arq_nome);
    rename("temp.bin", arq_nome);
}

void remover_cliente(const char *arq_nome, const char *cpf_busca) {
    FILE *in = fopen(arq_nome, "rb");
    if (!in) return;

    FILE *out = fopen("temp.bin", "wb");
    if (!out) {
        fclose(in);
        return;
    }

    Cliente atual;
    int removido = 0;

    while (pega_registro(in, &atual)) {
        if (strcmp(atual.cpf, cpf_busca) == 0) {
            removido = 1; 
            continue;
        }
        grava_registro(out, &atual);
    }

    fclose(in);
    fclose(out);

    if (removido) {
        remove(arq_nome);
        rename("temp.bin", arq_nome);
        printf("Cliente %s removido com sucesso.\n", cpf_busca);
    } else {
        remove("temp.bin");
        printf("CPF %s nao encontrado para remocao.\n", cpf_busca);
    }
}

void atualizar_cliente(const char *arq_nome, Cliente novo_dado) {
    FILE *in = fopen(arq_nome, "rb");
    if (!in) return;

    FILE *out = fopen("temp.bin", "wb");
    if (!out) {
        fclose(in);
        return;
    }

    Cliente atual;
    int atualizado = 0;

    while (pega_registro(in, &atual)) {
        if (strcmp(atual.cpf, novo_dado.cpf) == 0) {

            grava_registro(out, &novo_dado);
            atualizado = 1;
        } else {
            grava_registro(out, &atual);
        }
    }

    fclose(in);
    fclose(out);

    if (atualizado) {
        remove(arq_nome);
        rename("temp.bin", arq_nome);
        printf("Cliente %s atualizado com sucesso.\n", novo_dado.cpf);
    } else {
        remove("temp.bin");
        printf("CPF %s nao encontrado para atualizacao.\n", novo_dado.cpf);
    }
}

Indice* construir_indice(FILE *fp) {
    Indice *idx = malloc(sizeof(Indice));
    idx->entries = NULL;
    idx->total = 0;

    fseek(fp, 0, SEEK_SET);
    long offset_atual = ftell(fp);
    Cliente c;

    while (1) {
        offset_atual = ftell(fp);
        if (!pega_registro(fp, &c)) break;

        idx->entries = realloc(idx->entries, sizeof(IndiceEntry) * (idx->total + 1));
        idx->entries[idx->total].offset = offset_atual;
        strcpy(idx->entries[idx->total].cpf, c.cpf);
        idx->total++;
    }

    return idx;
}

void liberar_indice(Indice *idx) {
    if (idx) {
        free(idx->entries);
        free(idx);
    }
}

int busca_binaria_cliente(const char *arq_nome, const char *cpf_busca, Cliente *resultado) {
    FILE *fp = fopen(arq_nome, "rb");
    if (!fp) return 0;

    Indice *idx = construir_indice(fp);

    int inicio = 0;
    int fim = idx->total - 1;
    int encontrado = 0;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        int cmp = strcmp(idx->entries[meio].cpf, cpf_busca);

        if (cmp == 0) {
            fseek(fp, idx->entries[meio].offset, SEEK_SET);[cite: 1]
            pega_registro(fp, resultado);
            encontrado = 1;
            break;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    liberar_indice(idx);
    fclose(fp);
    return encontrado;
}

void merge_arquivos(const char *arq1, const char *arq2, const char *arq_out) {
    FILE *f1 = fopen(arq1, "rb");
    FILE *f2 = fopen(arq2, "rb");
    FILE *out = fopen(arq_out, "wb");

    if (!out) {
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return;
    }

    Cliente c1, c2;
    int tem_c1 = f1 ? pega_registro(f1, &c1) : 0;
    int tem_c2 = f2 ? pega_registro(f2, &c2) : 0;

    while (tem_c1 && tem_c2) {
        int cmp = strcmp(c1.cpf, c2.cpf);
        if (cmp < 0) {
            grava_registro(out, &c1);
            tem_c1 = pega_registro(f1, &c1);
        } else if (cmp > 0) {
            grava_registro(out, &c2);
            tem_c2 = pega_registro(f2, &c2);
        } else {
            grava_registro(out, &c1);
            tem_c1 = pega_registro(f1, &c1);
            tem_c2 = pega_registro(f2, &c2);
        }
    }

    while (tem_c1) {
        grava_registro(out, &c1);
        tem_c1 = pega_registro(f1, &c1);
    }

    while (tem_c2) {
        grava_registro(out, &c2);
        tem_c2 = pega_registro(f2, &c2);
    }

    if (f1) fclose(f1);
    if (f2) fclose(f2);
    fclose(out);
}