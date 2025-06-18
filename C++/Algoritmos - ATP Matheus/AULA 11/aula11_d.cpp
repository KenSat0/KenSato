#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f; 
    char linha [100];
    
    f = fopen("log.txt", "r"); //abre o arquivo log.txt, a letra r indica que vamos ler algo nesse arquivo (read)
    
    if(f) //verificação se o arquivo f foi acessado
    {
        while (fgets(linha, sizeof(linha), f)) //enquanto houver linhas para serem lidas
        {
            printf("%s", linha);
        }

        //isso lê o arquivo todo, até que a leitura fracasse (não existem mais linhas para serem lidas)

        fclose(f);
    }
    else return 1; 

    getchar();
    return 0;
}