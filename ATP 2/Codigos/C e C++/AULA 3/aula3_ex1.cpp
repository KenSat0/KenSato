#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *f;

    f = fopen("nomes.txt", "w");
    if (f == NULL)
    {
        perror("Erro ao abrir");
    }

    for(int i = 0; i < 5; i++)
    {
        char str[100];

        printf("\nNome: ");
        scanf("%s", str);

        fputs(str, f);
        fputs("\n", f);
    }

    fclose(f);

    getchar();
    return 0;
}