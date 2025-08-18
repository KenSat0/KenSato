#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *f;

    f = fopen("nomes.txt", "r");
    if (f == NULL)
    {
        perror("Erro ao abrir");
    }

    int qtd_linhas = 0;

    while(feof(f)==0)
    {
        char str[100];
        fgets(str, 100, f);
        qtd_linhas++;
    }

    if(feof(f))
    {
        printf("Fim do arquivo alcancado\n");
    }

    printf("O arquivo tem %d linhas\n", qtd_linhas);

    fclose(f);

    getchar();
    return 0;
}