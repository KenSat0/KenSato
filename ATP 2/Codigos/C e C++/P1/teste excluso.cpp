#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *normalize(char *str)
{
    int index = 0;
    char *new_str = (char*)malloc(strlen(str)*sizeof(str));
    for(int i = 0; str[i]!='\0';i++)
    {
        char current_char = str[i];
        if(isspace(current_char)==0)
        {
            if(isalpha(current_char))
            {
                new_str[index] = tolower(current_char);
                index++;
            }
        }
    }
    return(new_str);
}

int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    char str1[100];

    strcpy(str1, normalize(str));

    printf("\n%s\n", str1);

    getchar();
    return 0;
}