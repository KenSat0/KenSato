#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* maior_substring(char*str1, char*str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_lenght = 0;
    int start_index = 0;
    char* substr_final;

    for(int i = 0; i<len1; i++)
    {
        for(int j = 0; j<len2; j++)
        {
            int current_lenght = 0;
            while(str1[i + current_lenght] == str2[j+current_lenght] && str1[i+current_lenght] != '\0' && str2[j+current_lenght] != '\0')
            {
                current_lenght++;
            }

            if (max_lenght < current_lenght)
            {
                max_lenght = current_lenght;
                start_index = i;
            }
        }
    }

    substr_final = (char*)malloc((max_lenght+1)*sizeof(char));
    strncpy(substr_final, str1+start_index, max_lenght);
    substr_final[max_lenght] = '\0';

    return(substr_final);
}

int main()
{
    char str1[100];
    char str2[100];

    printf("\nobs.: codigo nao funciona se houverem duas substrings comuns de mesmo tamanho, somente a primeira sera mostrada");

    printf("\nstr1: ");
    scanf("%s", str1);

    printf("\nstr2: ");
    scanf("%s", str2);

    printf("\na maior substring comum e %s", maior_substring(str1, str2));

    getchar();
    return 0;
}