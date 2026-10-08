
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CAB 12
#define MAX 138

typedef struct {
    char codigo[5], nome[61], artista[51], genero[21];
} Faixa;

int32_t ler_int(FILE *f, long pos) { //le um inteiro na coordenada POS do arquivo
    int32_t n;
    fseek(f, pos, SEEK_SET);
    fread(&n, 4, 1, f);
    return n;
}

void gravar_int(FILE *f, long pos, int32_t n) { //grava um inteiro N na coordenada POS do arquivo
    fseek(f, pos, SEEK_SET);
    fwrite(&n, 4, 1, f);
}

/* Busca fisica: pula cada registro usando sua capacidade. */
int32_t buscar(FILE *f, const char *codigo) {
    int32_t capacidade, pos = CAB;
    char chave[5];
    fseek(f, pos, SEEK_SET); //do inicio do arquivo, apos o cabeçalho
    while (fread(&capacidade, 4, 1, f) == 1) { //le uma capacidade, se possivel
        fread(chave, 1, 5, f); //le a chave
        if (chave[0] != '@' && memcmp(chave, codigo, 4) == 0 && chave[4] == '|') //se existir registro, bater com o codigo e terminar em |
            return pos; //bingo, achei bloco
        pos += 4 + capacidade; //caso contrario, POS avança para o proximo bloco
        fseek(f, pos, SEEK_SET); //coloca o cursor na coordenada POS
    }
    return -1; //busca deu errado
}

void inserir(FILE *f, const Faixa *x) {
    char texto[MAX] = {0};
    if (buscar(f, x->codigo) != -1) { puts("Codigo duplicado."); return; } //verifica chave duplicada
    snprintf(texto, sizeof texto, "%s|%s|%s|%s", x->codigo, x->nome, x->artista, x->genero);//formata os dados
    int32_t usado = (int32_t)strlen(texto) + 1; //ve o espaço necessario pros dados
    int32_t atual = ler_int(f, 0), anterior = -1;
    int32_t melhor = -1, antes_melhor = -1, capacidade = MAX + 1;

    /* Best-fit: menor espaco que comporta o registro. */
    while (atual != -1) {
        int32_t tam = ler_int(f, atual);
        if (tam >= usado && tam < capacidade) {//se cabe e entre os que cabe, o menor
            melhor = atual;
            antes_melhor = anterior;
            capacidade = tam;
        }
        anterior = atual;
        atual = ler_int(f, atual + 5); //avança a coordenada para verificar os proximos
    }

    if (melhor == -1) { //se nao achou um espaço otimo
        fseek(f, 0, SEEK_END); //cursor no fim do arquivo
        melhor = (int32_t)ftell(f); //indica a coordenada do fim do arquivo (OFFSET)
        capacidade = usado; //precisa de um espaço proprio (nao fragmentado)
    } else {
        int32_t proximo = ler_int(f, melhor + 5); //recebe o "indice" (OFFSET) do proximo do melhor
        if (antes_melhor == -1) gravar_int(f, 0, proximo);
        else gravar_int(f, antes_melhor + 5, proximo);
    }
    /* Preserva a capacidade; o restante do vetor texto ja contem zeros. */
    gravar_int(f, melhor, capacidade);
    fwrite(texto, 1, capacidade, f);
    printf("Inserido em %d; sobra interna: %d bytes.\n", (int)melhor, (int)(capacidade - usado));
}

void remover(FILE *f, const char *codigo) {
    int32_t pos = buscar(f, codigo);
    if (pos == -1) { puts("Codigo nao encontrado."); return; }
    fseek(f, pos + 4, SEEK_SET);
    fputc('@', f);
    gravar_int(f, pos + 5, -1);

    /* Acrescenta o espaco NO FINAL da lista de livres. */
    int32_t ultimo = ler_int(f, 0);
    if (ultimo == -1) gravar_int(f, 0, pos);
    else {
        int32_t proximo;
        while ((proximo = ler_int(f, ultimo + 5)) != -1)
            ultimo = proximo;
        gravar_int(f, ultimo + 5, pos);
    }
    puts("Removido.");
}

FILE *compactar(FILE *f) {
    FILE *novo = fopen("dados.tmp", "w+b"); //cria novo arquivo (escrever binario)
    if (!novo) { puts("Nao foi possivel criar o temporario."); return f; }
    gravar_int(novo, 0, -1); //grava na pos=0, -1
    gravar_int(novo, 4, ler_int(f, 4)); //le o INS do cabeçalho
    gravar_int(novo, 8, ler_int(f, 8)); //le o REM do cabeçalho
    int32_t capacidade;
    char texto[MAX];
    fseek(f, CAB, SEEK_SET);
    while (fread(&capacidade, 4, 1, f) == 1) { //se der pra ler capacidade
        fread(texto, 1, capacidade, f);//coloca em texto o que foi lido
        if (texto[0] != '@') { //se o texto existe
            int32_t real = (int32_t)strlen(texto) + 1; //real = tamanho total do texto
            fwrite(&real, 4, 1, novo); 
            fwrite(texto, 1, real, novo); 
        }
    }
    fclose(f);
    fclose(novo);
    remove("dados.bin");
    rename("dados.tmp", "dados.bin");
    puts("Compactado.");
    return fopen("dados.bin", "r+b");
}

void dump(FILE *f) {
    printf("Topo: %d | Insercoes consumidas: %d | Remocoes consumidas: %d\n",
           (int)ler_int(f, 0), (int)ler_int(f, 4), (int)ler_int(f, 8));
    int32_t capacidade, pos = CAB;
    char texto[MAX];
    fseek(f, CAB, SEEK_SET);
    while (fread(&capacidade, 4, 1, f) == 1) {
        fread(texto, 1, capacidade, f);
        printf("Offset %d | Capacidade %d | ", (int)pos, (int)capacidade);
        if (texto[0] == '@') {
            int32_t proximo;
            memcpy(&proximo, texto + 1, 4);
            printf("LIVRE: proximo %d\n", (int)proximo);
        } else printf("%s | Sobra %d\n", texto, (int)(capacidade - strlen(texto) - 1));
        pos += 4 + capacidade;
    }
}

void consumir(FILE *f, FILE *entrada, int opcao) {
    if (!entrada) { puts("Carregue as entradas com a opcao 5."); return; } //pede pra carregar entrada
    int32_t contador = ler_int(f, opcao == 1 ? 4 : 8); //cont 4 para insert e 8 para remove
    fseek(entrada, (long)contador * (opcao == 1 ? 138 : 5), SEEK_SET); //avança para proxima entrada (inx * 138 ou idx * 5)
    Faixa x;
    if (fread(x.codigo, 1, 5, entrada) != 5) { puts("Fim das entradas."); return; }
    if (opcao == 1) { //se escolher insert, atualiza Faixa X
        fread(x.nome, 1, 61, entrada);
        fread(x.artista, 1, 51, entrada);
        fread(x.genero, 1, 21, entrada);
        inserir(f, &x); //insere x em F
    } else remover(f, x.codigo); 
    gravar_int(f, opcao == 1 ? 4 : 8, contador + 1);//grava CONTADOR + 1 no arquivo, na posição 4 se inserir e 8 se remover
    fflush(f);
}

int main(int argc, char **argv) {
    const char *a = argc == 3 ? argv[1] : "insere.bin";
    const char *b = argc == 3 ? argv[2] : "remove.bin";
    FILE *f = fopen("dados.bin", "r+b"), *ins = NULL, *rem = NULL;
    if (!f) {
        f = fopen("dados.bin", "w+b");
        if (!f) return 1;
        gravar_int(f, 0, -1);
        gravar_int(f, 4, 0);
        gravar_int(f, 8, 0);
    }
    carregar(&ins, &rem, a, b);
    int opcao;
    do {
        puts("1 Inserir | 2 Remover | 3 Compactar | 4 Dump | 0 Sair");
        if (scanf("%d", &opcao) != 1) break;
        switch (opcao) {
            case 1: consumir(f, ins, 1); break;
            case 2: consumir(f, rem, 2); break;
            case 3: f = compactar(f); if (!f) return 1; break;
            case 4: dump(f); break;
        }
    } while (opcao != 0);
    if (ins) fclose(ins);
    if (rem) fclose(rem);
    fclose(f);
    return 0;
}