#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verifica_pal(char *str, int tam)
{
    char str1[tam];
    char str2[tam];
    strcpy(str1, str);
    strrev(str);
    strcpy(str2, str);
    strrev(str);

    for (int i = 0; i<tam; i++)
    {
        if (str1[i]!=str2[i]) return 0;
    }
    return 1;
}

int main()
{

    char *str;

    printf("\nDigite sua palavra: ");
    gets(str);

    int tam = strlen(str);

    if (verifica_pal(str, tam))
    {
        printf("%s e um palindromo", str);
    }
    else
    {
        printf("%s nao e um palindromo", str);
    }

    getchar();
    return 0;
}