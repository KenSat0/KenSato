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

    char str[100];
    
    for(int i = 0; i<5; i++)
    {
        if (fgets(str, 100, f) != NULL)
        {
            printf("%s", str);
        }
    }

    fclose(f);

    getchar();
    return 0;
}