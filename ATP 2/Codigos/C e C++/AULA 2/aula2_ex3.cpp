#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conta_vogais (char *str, int tam)
{
    int cont = 0;
    for (int i = 0; i<tam; i++)
    {
        if (str[i]=='a'||str[i]=='A')
        {
            cont++;
        }
        if (str[i]=='e'||str[i]=='E')
        {
            cont++;
        }
        if (str[i]=='i'||str[i]=='I')
        {
            cont++;
        }
        if (str[i]=='o'||str[i]=='O')
        {
            cont++;
        }
        if (str[i]=='u'||str[i]=='U')
        {
            cont++;
        }
    }
    return (cont);
}

int main()
{

    char *str1;

    printf("\nDigite sua palavra: ");
    scanf("%s", str1);

    int tam = strlen(str1);

    printf("A palavra tem %d vogais", conta_vogais(str1, tam));


    getchar();
    return 0;
}