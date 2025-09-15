#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int comprimento(char *str)
{
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        cont++;
    }
    return(cont);
}

char *normalize(char *str)
{
    int index = 0;
    char *new_str = (char*)malloc((comprimento(str)+1)*sizeof(char));
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

void inversa(char *str)
{
    for(int i = (comprimento(str)-1); i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

int vogais(char *str)
{
    int cont = 0;
    char *str1 = normalize(str);

    for(int i = 0; str1[i]!='\0'; i++) 
    {
        if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u')
        {
            cont++;
        }
    }
    free(str1);
    return(cont);
}

void palindromo(char *str)
{
    int verifica = 1;
    char *str1 = normalize(str);

    for(int i = 0; str1[i]!='\0'; i++)
    {
        if(str1[i]!=str1[comprimento(str1)-1-i])
        {
            verifica = 0;
            break;
        }
    }

    free(str1);
    if(verifica) printf("\nE um palindromo");
    else printf("\nNao e um palindromo");
}

int main()
{
    int menu;
    while(true)
    {
        char str[100];
        printf("\nString: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0;
        printf("\n1 - Comprimento\n2 - Inversa\n3 - Vogais\n4 - Palindromo\n5 - Sair\nO que deseja fazer: ");
        scanf("%d", &menu);
        if(menu==1)
        {
            printf("%d", comprimento(str));
        }
        if(menu==2) inversa(str);
        if(menu==3)
        {
            printf("%d", vogais(str));
        }     
        if(menu==4) palindromo(str);
        if(menu==5) break;
        limpar_buffer();
    }
    return 0;
}