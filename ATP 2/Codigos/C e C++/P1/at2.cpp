#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//serev para limpar o buffer entre scanf e fgets
void limpar_buffer()
{
    int c;
    //enquanto c não é quebra de linha ou o fim do arquivo
    while ((c = getchar()) != '\n' && c != EOF);
}

//faz a mesma coisa de strlen
int comprimento(char *str)
{
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        cont++;
    }
    return(cont);
}

//remove espaços e caixa alta
char *normalize(char *str)
{
    int index = 0;
    //aloca uma string nova
    char *new_str = (char*)malloc((comprimento(str)+1)*sizeof(char));

    //percorre a string dada na função
    for(int i = 0; str[i]!='\0';i++)
    {
        char current_char = str[i];
        //se o caracter atual não é espaço
        if(isspace(current_char)==0)
        {
            //se o caracter atual é letra
            if(isalpha(current_char))
            {
                //nova string recebe o minusculo da letra atual
                new_str[index] = tolower(current_char);
                index++;
                //nove o indice de nova string para o proximo
            }
        }
    }

    //adiciona o caracter de finalização para new_str ser considerada uma string
    new_str[index] = '\0';
    return(new_str);
}

//inverte str sem usar strrev
void inversa(char *str)
{
    //percorre a string começando pelo fim
    for(int i = (comprimento(str)-1); i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

//conta as vogais de uma str
int vogais(char *str)
{
    int cont = 0;
    //normaliza a str para facilitar
    char *str1 = normalize(str);

    //percorre a string
    for(int i = 0; str1[i]!='\0'; i++) 
    {  
        //se for uma vogal, cont++
        if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u')
        {
            cont++;
        }
    }
    free(str1);
    return(cont);
}

//ve se é palindromo
void palindromo(char *str)
{
    int verifica = 1;

    //normaliza para tirar espaço e caixa alta
    char *str1 = normalize(str);

    //percorre a string
    for(int i = 0; str1[i]!='\0'; i++)
    {
        //usa a mesma string, uma do inicio ao fim e outra do fim ao inicio
        if(str1[i]!=str1[comprimento(str1)-1-i])
        {
            verifica = 0;
            //se ver que nao é palindromo, ja sai do loop
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