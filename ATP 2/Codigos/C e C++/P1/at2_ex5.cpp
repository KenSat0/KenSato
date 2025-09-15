#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char*substring(char*str1, char*str2)
{
    //len1 e len2 simplificam as condições dos laços
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    //max_lenght guarda o tamanho da mair substring
    int max_lenght = 0;

    //start_index guarda o indice de str1 em que a maior substring começa
    int start_index = 0;

    //variavel que sera retornada
    char *substr_final;

    //percorre toda str1
    for(int i = 0; i<len1; i++)
    {
        //percorre toda str2
        for(int j =0; j<len2; j++)
        {
            //guarda o tamanho da substring analisada no momento
            int current_lenght = 0;

            //condições do loop
                //str1 e str2 são iguais, indices se movem conforme current_lenght aumenta
                //str1 ou str 2 não chega ao fim
            while(str1[i+current_lenght]==str2[j+current_lenght] && str1[i+current_lenght]!='\0' && str2[j+current_lenght]!='\0')
            {
                current_lenght++;
            }
            //se a substring tem tamanho maior que a maior substring até então
            if(max_lenght<current_lenght)
            {
                //troca o valor max
                max_lenght= current_lenght;
                //start_index marca o indice de str1 em que a maior substring começa
                start_index = i;
            }
        }
    }

    //aloca memoria para string que sera retornada (max_leght+1 para que haja espaço para o caracter de finalização)
    substr_final = (char*)malloc((max_lenght+1)*sizeof(char));

    //copia n=max_lenght letras de str1+start_index (ponteiro de str1 movido para frente até start_index)
    strncpy(substr_final, str1+start_index, max_lenght);

    //adiciona a finalização para ser considerada string
    substr_final[max_lenght]='\0';
    return(substr_final);

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

        char *str_final = substring(str1, str2);
        printf("\nA maior substring e: %s", str_final);
        free(str_final);

    return 0;
}