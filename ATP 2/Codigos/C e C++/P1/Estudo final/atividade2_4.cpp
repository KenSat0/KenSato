#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *normalizar(char *str)
{
    char *new_str = (char*)malloc((strlen(str)+1)*sizeof(char));
    int index = 0;
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

    new_str[index] = '\0';
    return(new_str);
}

int palindromo(char* str)
{   
    int flag = 1;
    char *str1 = normalizar(str);

    for(int i = 0; str1[i]!='\0'; i++)
    {
        if(str1[i]!=str1[strlen(str1)-1-i])
        {
            flag = 0;
            break;
        }
    }

    if(flag) printf("\nE palindromo");
    else printf("\nNao e palindromo");

    return 0;
}

int main()
{
    char str[100];
    printf("\nString: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    palindromo(str);

    getchar();
    return 0;
}