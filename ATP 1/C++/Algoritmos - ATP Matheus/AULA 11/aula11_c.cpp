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
        if (fgets(linha, sizeof(linha), f)) //verifica se a leitura deu certo
        {
            printf("%s", linha);
        }
        
        //obs.: isso lê apenas a primeira linha

        // isso imprime o que estiver escrito no arquivo (se você abrir manualmente e escrever, aparece aqui quando executar)

        fclose(f);
    }
    else return 1; //se não foi acessado, return 1

    getchar();
    return 0;
}