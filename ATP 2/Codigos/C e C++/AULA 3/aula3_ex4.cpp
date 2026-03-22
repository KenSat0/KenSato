#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *f;

    f = fopen("nomes.txt", "r");
    if (f == NULL)
    {
        perror("Erro ao abrir");
        return 1;
    }

    FILE *fcopy;

    fcopy = fopen("copia_nomes.txt", "w");

    while(feof(f)==0)
    {
        char str[100];
        fgets(str, 100, f);
        fputs(str, fcopy);
    }

    if(fcopy == NULL)
    {
        perror("Erro ao copiar conteudo");
        return 1;
    }

    fclose(f);
    fclose(fcopy);

    printf("Conteudo copiado");

    getchar();
    return 0;
}