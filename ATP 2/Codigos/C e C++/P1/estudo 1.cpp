#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void comprimento_str(char *str)
{
    printf("\nA srting tem %d caarcteres", strlen(str));
}

void reverte_str(char *str)
{
    strrev(str); 
    printf("\nA string invertida e %s", str);
    strrev(str);
}

void vogais_st(char *str)
{
    int i=0;
    int cont = 0;
    while(str[i] != '\0')
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
        {
            cont++;
        }
        i++;
    }
    printf("\nA string tem %d vogais", cont);
}

int verifica_pali(char *str)
{
    char *nova_str = (char*)malloc(strlen(str)*sizeof(char));
    int index = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        char char_atual = str[i];
        if(isspace(char_atual) == 0)
        {
            if(isalpha(char_atual))
            {
                nova_str[index] = tolower(char_atual);
                index++;
            }
        }
    }

    int palindromo = 1;
    for(int i = 0; nova_str[i] != '\0'; i++)
    {
        if(nova_str[i] != nova_str[index-1-i])
        {
            palindromo = 0;
            break;
        }
    }

    if(palindromo)
    {
        printf("E palindromo");
    }
    else
    {
        printf("Nao e palindromo");
    }
}

int main()
{
    int menu;

        while(true)
        {

        char str[100];
        printf("\nstr: ");
        fgets(str, 100, stdin);

        printf("\n1 - strlen");
        printf("\n2 - strrev");
        printf("\n3 - vogais");
        printf("\n4 - palindromo");
        printf("\n5 - Fechar");
        printf("\nO que vai fazer com a str: ");
        scanf("%d", &menu);

        if(menu==1) comprimento_str(str);
        if(menu==2) reverte_str(str);
        if(menu==3) vogais_st(str);
        if(menu==4) verifica_pali(str);
        if(menu==5) return 0; 
        }

    getchar();
    return 0;
}