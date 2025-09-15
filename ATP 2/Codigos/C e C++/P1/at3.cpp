#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int escrever_nomes()
{
    FILE *p = fopen("nomes.txt", "w");
    if(p==NULL)
    {
        perror("\nerro ao abrir arquivo");
        return 1;
    }

    for(int i = 0; i<5; i++)
    {
        char nome[50];
        printf("\nNome %d: ", i+1);
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;
        strcat(nome, "\n");

        fputs(nome, p);
    }

    fclose(p);
    return 0;
}

int imprimir_nomes()
{
    FILE *p = fopen("nomes.txt", "r");
    if(p==NULL)
    {
        perror("\nerro ao abrir");
        return 1;
    }

    char nome[50];
    while(fgets(nome, sizeof(nome), p)!=NULL)
    {
        printf("%s", nome);
    }

    fclose(p);
    return 0;
}

int numero_linhas()
{
    FILE *p = fopen("nomes.txt", "r");
    if(p==NULL)
    {
        perror("\nerro ao abrir");
        return 1;
    }
    
    int cont = 0;
    char nome[50];
    while(fgets(nome, sizeof(nome), p)!=NULL) cont++;

    fclose(p);

    return(cont);
}

int copia()
{
    char origem[100];
    printf("\nNome do arquivo origem: ");
    scanf("%s", origem);

    char destino[100];
    printf("\nNome do arquivo destino: ");
    scanf("%s", destino);

    FILE *p = fopen(origem, "r");
    if(p==NULL)
    {
        perror("\nerro ao abrir origem");
        return 1;
    }
    FILE *p1 = fopen(destino, "w");
    if(p1 == NULL)
    {
        perror("\nerro ao abrir destino");
        return 1;
    }

    char nome[50];
    while(fgets(nome, sizeof(nome), p)!=NULL)
    {
        fputs(nome, p1);
    }

    fclose(p);
    fclose(p1);

    return 0;
}

int busca()
{
    FILE *p = fopen("nomes.txt", "r");
    if(p==NULL) return 1;

    char str[50];
    printf("\nBusca: ");
    limpar_buffer();
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    char busca[50];
    while(fgets(busca, sizeof(busca), p)!=NULL)
    {
        if(strstr(busca, str)!=NULL)
        {
            printf("\nPalavra encontrada em %s", busca);
        }
    }

    fclose(p);
    return 0;
}

int concat()
{
    FILE *p = fopen("nomes.txt", "r");
    if (p==NULL) return 1;

    FILE *p1 = fopen("nomes_copia.txt", "r");
    if (p1==NULL) return 1;
    
    FILE *p2 = fopen("concat.txt", "a");
    if(p2==NULL) return 1;

    char str[50];
    while(fgets(str, sizeof(str), p)!=NULL)
    {
        fputs(str, p2);
    }

    fclose(p);

    while(fgets(str, sizeof(str), p1)!=NULL)
    {
        fputs(str, p2);
    }

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