#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *maior_substring(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_lenght;
    int start_index;

    for(int i = 0; i<len1; i++)
    {
        for(int j = 0; j<len2; j++)
        {
            int current_lenght = 0;
            while(str1[i+current_lenght]==str2[j+current_lenght] && str1[i+current_lenght]!='\0' && str2[j+current_lenght] != '\0')
            {
                current_lenght++;
            }
            if(max_lenght<current_lenght)
            {
                max_lenght = current_lenght;
                start_index = i;
            }
        }
    }

    char *substring = (char*)malloc((max_lenght+1) * sizeof(char));
    strncpy(substring, str1+start_index, max_lenght);
    substring[max_lenght] = '\0';

    return(substring);
}

int main()
{
    char str1[100];
    char str2[100];
    
    printf("\nString 1: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("\nString 2: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    printf("A maior substring e: %s", maior_substring(str1, str2));
}