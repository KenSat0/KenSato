#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ_DADOS "seguradoras.dat"
#define ARQ_INSERE "insere.bin"
#define ARQ_REMOVE "remove.bin"
#define ARQ_STATUS "status.dat"

// Estrutura para os dados do registro em memoria
typedef struct {
    char codigo[4];        // 3 chars + '\0'
    char nome[51];        // max 50 chars + '\0'
    char seguradora[51];  // max 50 chars + '\0'
    char tipo[31];        // max 30 chars + '\0'
} Segurado;

// Estrutura para controle de carregamento dos arquivos auxiliares
typedef struct {
    int idx_insere;
    int idx_remove;
} StatusCarga;

// Prototipos das funcoes
void inicializa_arquivo();
void inserir_registro();
void remover_registro();
void compactar_arquivo();
void dump_arquivo();
void carregar_arquivos();
int buscar_registro(FILE *fp, const char *codigo, int *tam_reg, long *pos_reg);

int main() {
    int opcao = 0;

    // Garante que o arquivo de dados exista com seu cabecalho
    inicializa_arquivo();

    do {
        printf("\n================ MENU ================\n");
        printf("1. Insercao\n");
        printf("2. Remocao\n");
        printf("3. Compactacao\n");
        printf("4. Dump Arquivo\n");
        printf("5. Carrega Arquivos (Status de Carga)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o \n do buffer de entrada

        switch (opcao) {
            case 1:
                inserir_registro();
                break;
            case 2:
                remover_registro();
                break;
            case 3:
                compactar_arquivo();
                break;
            case 4:
                dump_arquivo();
                break;
            case 5:
                carregar_arquivos();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Verifica se o arquivo de dados existe. Se nao existir, cria e grava
// o cabecalho com o offset do topo da lista de excluidos (inicia com -1)
void inicializa_arquivo() {
    FILE *fp = fopen(ARQ_DADOS, "rb");
    if (fp == NULL) {
        // Arquivo nao existe, vamos criar um novo
        fp = fopen(ARQ_DADOS, "wb");
        if (fp == NULL) {
            printf("Erro fatal ao criar o arquivo de dados.\n");
            exit(1);
        }
        int topo = -1; // -1 indica lista de removidos vazia
        fwrite(&topo, sizeof(int), 1, fp);
        fclose(fp);
    } else {
        fclose(fp);
    }

    // Inicializa arquivo de controle de indices caso nao exista
    FILE *fps = fopen(ARQ_STATUS, "rb");
    if (fps == NULL) {
        fps = fopen(ARQ_STATUS, "wb");
        if (fps != NULL) {
            StatusCarga st = {0, 0};
            fwrite(&st, sizeof(StatusCarga), 1, fps);
            fclose(fps);
        }
    } else {
        fclose(fps);
    }
}

// Funcao para inserir um registro utilizando First-Fit na lista de removidos
void inserir_registro() {
    FILE *fp = fopen(ARQ_INSERE, "rb");
    if (fp == NULL) {
        printf("Erro: Arquivo '%s' nao encontrado.\n", ARQ_INSERE);
        return;
    }

    // Ler indice atual de insercao
    FILE *fps = fopen(ARQ_STATUS, "rb+");
    StatusCarga st = {0, 0};
    if (fps != NULL) {
        fread(&st, sizeof(StatusCarga), 1, fps);
    }

    // Posiciona no registro a ser lido no lote
    fseek(fp, st.idx_insere * sizeof(Segurado), SEEK_SET);
    Segurado reg;
    if (fread(&reg, sizeof(Segurado), 1, fp) != 1) {
        printf("Nao ha mais registros para inserir em '%s'.\n", ARQ_INSERE);
        fclose(fp);
        if (fps) fclose(fps);
        return;
    }
    fclose(fp);

    // Monta o buffer do registro formatado: cod#nome#seguradora#tipo
    char buffer[200];
    sprintf(buffer, "%s#%s#%s#%s", reg.codigo, reg.nome, reg.seguradora, reg.tipo);
    int tam_novo = (int)strlen(buffer);

    FILE *fd = fopen(ARQ_DADOS, "rb+");
    if (fd == NULL) {
        printf("Erro ao abrir arquivo de dados.\n");
        if (fps) fclose(fps);
        return;
    }

    // Le o topo da lista ligada de removidos do cabecalho
    int topo = -1;
    fread(&topo, sizeof(int), 1, fd);

    int pos_ant = -1;
    int pos_atual = topo;
    int encaixou = 0;

    // Busca pelo primeiro espaco disponivel que sirva (First-Fit)
    while (pos_atual != -1) {
        fseek(fd, pos_atual, SEEK_SET);
        int tam_no = 0;
        fread(&tam_no, sizeof(int), 1, fd);

        char marcador;
        fread(&marcador, sizeof(char), 1, fd);

        int prox_offset;
        fread(&prox_offset, sizeof(int), 1, fd);

        // Verifica se o espaco comporta o novo registro
        if (tam_no >= tam_novo) {
            encaixou = 1;

            // Escreve os novos dados no espaco reaproveitado
            fseek(fd, pos_atual, SEEK_SET);
            fwrite(&tam_no, sizeof(int), 1, fd); // Mantem o tamanho original do bloco (frag. interna)
            fwrite(buffer, sizeof(char), tam_novo, fd);

            // Atualiza a lista ligada removendo este no da cadeia
            if (pos_ant == -1) {
                // Era o primeiro nó da lista
                fseek(fd, 0, SEEK_SET);
                fwrite(&prox_offset, sizeof(int), 1, fd);
            } else {
                // Atualiza o ponteiro do nó anterior
                fseek(fd, pos_ant + sizeof(int) + sizeof(char), SEEK_SET);
                fwrite(&prox_offset, sizeof(int), 1, fd);
            }
            printf("Registro inserido com sucesso em espaco reutilizado (offset: %d).\n", pos_atual);
            break;
        }

        pos_ant = pos_atual;
        pos_atual = prox_offset;
    }

    // Se nao encontrou espaco na lista de removidos, grava no final do arquivo
    if (!encaixou) {
        fseek(fd, 0, SEEK_END);
        long offset_fim = ftell(fd);
        fwrite(&tam_novo, sizeof(int), 1, fd);
        fwrite(buffer, sizeof(char), tam_novo, fd);
        printf("Registro inserido no final do arquivo (offset: %ld).\n", offset_fim);
    }

    fclose(fd);

    // Atualiza status do indice de leitura
    st.idx_insere++;
    if (fps != NULL) {
        fseek(fps, 0, SEEK_SET);
        fwrite(&st, sizeof(StatusCarga), 1, fps);
        fclose(fps);
    }
}

// Funcao auxilia para buscar registro por codigo e retornar offset e tamanho
int buscar_registro(FILE *fp, const char *codigo, int *tam_reg, long *pos_reg) {
    fseek(fp, sizeof(int), SEEK_SET); // Pula o cabecalho

    long offset_atual = ftell(fp);
    int tam = 0;

    while (fread(&tam, sizeof(int), 1, fp) == 1) {
        *pos_reg = offset_atual;
        *tam_reg = tam;

        char *temp = (char *)malloc(tam + 1);
        fread(temp, sizeof(char), tam, fp);
        temp[tam] = '\0';

        // Verifica se nao eh um registro marcado como removido
        if (temp[0] != '*') {
            // Extrai o codigo (primeiro campo ate o '#')
            char cod_lido[10] = {0};
            int i = 0;
            while (i < tam && temp[i] != '#' && i < 9) {
                cod_lido[i] = temp[i];
                i++;
            }
            cod_lido[i] = '\0';

            if (strcmp(cod_lido, codigo) == 0) {
                free(temp);
                return 1; // Encontrado
            }
        }

        free(temp);
        offset_atual = ftell(fp);
    }

    return 0; // Nao encontrado
}

// Funcao para remover registro do arquivo e encadear na lista de excluidos
void remover_registro() {
    FILE *fpr = fopen(ARQ_REMOVE, "rb");
    if (fpr == NULL) {
        printf("Erro: Arquivo '%s' nao encontrado.\n", ARQ_REMOVE);
        return;
    }

    // Ler indice atual de remocao
    FILE *fps = fopen(ARQ_STATUS, "rb+");
    StatusCarga st = {0, 0};
    if (fps != NULL) {
        fread(&st, sizeof(StatusCarga), 1, fps);
    }

    fseek(fpr, st.idx_remove * 4, SEEK_SET); // Considerando codigos de 3 chars + buffer
    char cod_busca[10] = {0};
    
    if (fread(cod_busca, sizeof(char), 3, fpr) < 3) {
        printf("Nao ha mais codigos para remover em '%s'.\n", ARQ_REMOVE);
        fclose(fpr);
        if (fps) fclose(fps);
        return;
    }
    cod_busca[3] = '\0';
    fclose(fpr);

    FILE *fd = fopen(ARQ_DADOS, "rb+");
    if (fd == NULL) {
        printf("Erro ao abrir arquivo de dados.\n");
        if (fps) fclose(fps);
        return;
    }

    int tam_reg = 0;
    long pos_reg = 0;

    if (buscar_registro(fd, cod_busca, &tam_reg, &pos_reg)) {
        // Le o topo atual do cabecalho
        int topo_antigo = -1;
        fseek(fd, 0, SEEK_SET);
        fread(&topo_antigo, sizeof(int), 1, fd);

        // Insere o novo espaco no inicio da lista ligada
        int novo_topo = (int)pos_reg;
        fseek(fd, 0, SEEK_SET);
        fwrite(&novo_topo, sizeof(int), 1, fd);

        // Escreve a marcacao no registro removido: <tam>*<offset_prox>
        fseek(fd, pos_reg + sizeof(int), SEEK_SET);
        char mar = '*';
        fwrite(&mar, sizeof(char), 1, fd);
        fwrite(&topo_antigo, sizeof(int), 1, fd);

        printf("Registro com codigo '%s' removido com sucesso.\n", cod_busca);
    } else {
        printf("Registro com codigo '%s' nao foi encontrado para remocao.\n", cod_busca);
    }

    fclose(fd);

    // Atualiza indice de remocao no arquivo de status
    st.idx_remove++;
    if (fps != NULL) {
        fseek(fps, 0, SEEK_SET);
        fwrite(&st, sizeof(StatusCarga), 1, fps);
        fclose(fps);
    }
}

// Reescreve o arquivo removendo os espacos nao utilizados e limpando a lista
void compactar_arquivo() {
    FILE *fd = fopen(ARQ_DADOS, "rb");
    if (fd == NULL) {
        printf("Erro ao abrir arquivo de dados para compactacao.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(fd);
        return;
    }

    // Cabecalho zerado no novo arquivo (sem removidos)
    int topo = -1;
    fwrite(&topo, sizeof(int), 1, temp);

    fseek(fd, sizeof(int), SEEK_SET); // Ignora cabecalho original

    int tam = 0;
    int mantidos = 0;
    while (fread(&tam, sizeof(int), 1, fd) == 1) {
        char *buffer = (char *)malloc(tam);
        fread(buffer, sizeof(char), tam, fd);

        // Se nao for registro removido, escreve no novo arquivo
        if (buffer[0] != '*') {
            fwrite(&tam, sizeof(int), 1, temp);
            fwrite(buffer, sizeof(char), tam, temp);
            mantidos++;
        }
        free(buffer);
    }

    fclose(fd);
    fclose(temp);

    // Substitui o arquivo antigo pelo compactado
    remove(ARQ_DADOS);
    rename("temp.dat", ARQ_DADOS);

    printf("Compactacao concluida! %d registros validos mantidos no arquivo.\n", mantidos);
}

// Imprime a estrutura inteira do arquivo para inspecao
void dump_arquivo() {
    FILE *fd = fopen(ARQ_DADOS, "rb");
    if (fd == NULL) {
        printf("Erro ao abrir arquivo de dados.\n");
        return;
    }

    int topo = -1;
    fread(&topo, sizeof(int), 1, fd);

    printf("\n=== DUMP DO ARQUIVO ===\n");
    printf("Cabecalho (Topo da lista de excluidos): %d\n", topo);
    printf("----------------------------------------\n");

    int tam = 0;
    long offset = ftell(fd);

    while (fread(&tam, sizeof(int), 1, fd) == 1) {
        printf("Offset: %-5ld | Tamanho: %-3d | Conteudo: ", offset, tam);

        char *buffer = (char *)malloc(tam + 1);
        fread(buffer, sizeof(char), tam, fd);
        buffer[tam] = '\0';

        if (buffer[0] == '*') {
            // Registro de espaco livre
            int prox = -1;
            memcpy(&prox, buffer + 1, sizeof(int));
            printf("[ESPACO LIVRE] Prox Offset: %d\n", prox);
        } else {
            printf("%s\n", buffer);
        }

        free(buffer);
        offset = ftell(fd);
    }

    printf("========================\n\n");
    fclose(fd);
}

// Exibe a situacao atual de carregamento dos arquivos externos
void carregar_arquivos() {
    FILE *fps = fopen(ARQ_STATUS, "rb");
    if (fps == NULL) {
        printf("Status de carga nao encontrado.\n");
        return;
    }

    StatusCarga st;
    fread(&st, sizeof(StatusCarga), 1, fps);
    fclose(fps);

    printf("\n=== STATUS DE CARGA DOS ARQUIVOS ===\n");
    printf("Insercoes ja realizadas: %d\n", st.idx_insere);
    printf("Remocoes ja realizadas:  %d\n", st.idx_remove);
    printf("====================================\n\n");
}