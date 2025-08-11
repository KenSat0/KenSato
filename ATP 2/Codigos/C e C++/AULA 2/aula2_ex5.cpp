#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *retorna_maior_comum(char *str1, char *str2 int tam)
{
    char *sub_comum[tam];

}

int main()
{

    char *str1;
    char *str2;

    printf("\nDigite sua primeira palavra: ");
    gets(str1);

    printf("\nDigite sua segunda palavra: ");
    gets(str2);

    int tam = 0;

    if (stricmp(str1, str2)==0)
    {
        tam = strlen(str1);
    }
    else if (stricmp(str1,str2)<0)
    {
        tam = strlen(str1);
    }
    else
    {
        tam = strlen(str2);
    }

    getchar();
    return 0;
}