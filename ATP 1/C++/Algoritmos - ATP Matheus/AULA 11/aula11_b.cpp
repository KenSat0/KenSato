#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f; 

    f = fopen("log.txt", "w"); //abre ou cria o arquivo com nome log e tipo .txt, a letra w indica que vamos escrever nesse arquivo (write)
    
    if(f) //verificação se o arquivo f foi acessado
    {
        fprintf(f, "Ola Mundo!");
        fclose(f);
    }
    else return 1; //se não foi acessado, return 1

    getchar();
    return 0;
}