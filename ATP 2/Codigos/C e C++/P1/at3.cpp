#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//previre conflitos entre scanf e fgets
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//escrever nomes
int escrever_nomes()
{
    //abre arquivo em forma de escrita e verifica se deu certo
    FILE *p = fopen("nomes.txt", "w");
    if(p==NULL)
    {
        perror("\nerro ao abrir arquivo");
        return 1;
    }

    //escreve 5 nomes
    for(int i = 0; i<5; i++)
    {
        char nome[50];
        printf("\nNome %d: ", i+1);
        fgets(nome, sizeof(nome), stdin);
        //remove a quebra natural de fgets
        nome[strcspn(nome, "\n")] = 0;

        //adiciona uma quebra
        strcat(nome, "\n");

        //escreve no arquivo
        fputs(nome, p);
    }

    //fecha o arquivo
    fclose(p);
    return 0;
}

int imprimir_nomes()
{
    //abre o arquivo em leitura e verifica
    FILE *p = fopen("nomes.txt", "r");
    if(p==NULL)
    {
        perror("\nerro ao abrir");
        return 1;
    }

    //enquanto der para ler
    char nome[50];
    while(fgets(nome, sizeof(nome), p)!=NULL)
    {
        //imprime o que leu
        printf("%s", nome);
    }

    //fecha o arquivo
    fclose(p);
    return 0;
}

int numero_linhas()
{
    //abre o arquivo em leitura e verifica
    FILE *p = fopen("nomes.txt", "r");
    if(p==NULL)
    {
        perror("\nerro ao abrir");
        return 1;
    }
    
    int cont = 0;
    char nome[50];
    //enquanto tiver linhas para ler, aumenta o cont
    while(fgets(nome, sizeof(nome), p)!=NULL) cont++;

    //fecha o arquivo
    fclose(p);

    return(cont);
}

int copia()
{
    //recebe o nome do arquivo origem
    char origem[100];
    printf("\nNome do arquivo origem: ");
    scanf("%s", origem);

    //recebe o nome do arquivo destino
    char destino[100];
    printf("\nNome do arquivo destino: ");
    scanf("%s", destino);

    //usei scanf pois desconsiderei nomes com espaços em branco

    //abre o arquivo origem em leitura e verifica
    FILE *p = fopen(origem, "r");
    if(p==NULL)
    {
        perror("\nerro ao abrir origem");
        return 1;
    }

    //abre o arquivo destino em escrita e verifica
    FILE *p1 = fopen(destino, "w");
    if(p1 == NULL)
    {
        perror("\nerro ao abrir destino");
        return 1;
    }

    //enquanto der para ler
    char nome[50];
    while(fgets(nome, sizeof(nome), p)!=NULL)
    {
        //escreve o que leu da origem no destino
        fputs(nome, p1);
    }

    //fecha ambos os arquivos
    fclose(p);
    fclose(p1);

    return 0;
}

int busca()
{
    //abre o arquivo em leitura e verifica
    FILE *p = fopen("nomes.txt", "r");
    if(p==NULL) return 1;

    char str[50];
    printf("\nBusca: ");
    //só pra ter certeza, limpa o buffer antes do fgets ler stdin
    limpar_buffer();
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    //enquanto der para ler linhas
    char busca[50];
    while(fgets(busca, sizeof(busca), p)!=NULL)
    {
        //ve se a palavra é substring da linha
        if(strstr(busca, str)!=NULL)
        {
            //se é, imprime a linha
            printf("\nPalavra encontrada em %s", busca);
        }
    }

    //fecha o arquivo
    fclose(p);
    return 0;
}

int concat()
{
    //abre arquivo para ler
    FILE *p = fopen("nomes.txt", "r");
    if (p==NULL) return 1;

    //abre o arquivo 2 para ler
    FILE *p1 = fopen("nomes_copia.txt", "r");
    if (p1==NULL) return 1;
    
    //abre o arquivo 3 para apendiciar
    FILE *p2 = fopen("concat.txt", "a");
    if(p2==NULL) return 1;

    //enquanto tiver o que ler em arquivo 1
    char str[50];
    while(fgets(str, sizeof(str), p)!=NULL)
    {
        //escreve em arquivo 3
        fputs(str, p2);
    }

    //fecha arquivo 1
    fclose(p);

    //enquanto tiver o que ler em arquivo 2
    while(fgets(str, sizeof(str), p1)!=NULL)
    {
        //escreve em arquivo 3 (depois do conteudo do 1)
        fputs(str, p2);
    }

    //fecha tudo
    fclose(p1);
    fclose(p2);

    return 0;
}

int main()
{
    escrever_nomes();
    imprimir_nomes();
    numero_linhas();
    copia();
    busca();
    concat();

    getchar();
    return 0;
}