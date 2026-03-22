#include <stdio.h>
#include <stdlib.h>

 /*
 Tipos de Arquivos

    Arquivos de Texto
        caracteres 
        relação de byte X caracter
        formatação: .txt, .csv, .c

    Arquivos Binários
        Dados brutos
        Armazenam qualquer tipo de dado
        Compactos mas não legíveis

    Acesso de Arquivos
        Sequancial: dados lidos ou escritos em ordem do inicio ao fim
        Aleatório: permite acessar diretamente qualquer posição no arquivo (modificar sessões especificas do arquivo)
 
 Portabilidade
    Texto são mais portáveis entre sistemas
    Binarios podem sofrer problemas de portabilidade devido a diferenças de estrutura de baixo nivel

Tamanho de Registro
    Binario: registro de tamanhos fixos facilitam o acesso aleatorio
    Texto: tamnhos de linhas variaveis podem complicar o acesso aleatório com precisão

Uso de Buffer
    O acesso sequencial geralmente beneficia o buffreing do sistema operacional
    Acesso aleatorio frequente pode reduzir a eficacia do buffering

Integridade de Dados
    Corrupção em aquivos binarios pode ser mais problematica do que em arquivos de texto
    Arquivos de texto podem ser analisados e restaurados manualmente

Operações com Arquivos em C
    Abertura e Fechamento

|| = = - - - - - = = ||

    FILE *arquivo;
    arquivo = fopen("nome_do_arquivo.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    //operações no codigo

    fclose(arquivo);

|| = = - - - - - = = ||

    Modos de Abertura
        "r": Leitura
        "w": Escrita
        "a": Anexar (append)
        "r+": Leitura e escrita
        "b": Modo binario (usado com outros modos "rb", "wb")

|| = = - Leitura de Arquivo em C - = = ||

int c = fgetc(arquivo); // leitura de caracter

char str[100];
if (fgets(str, 100, arquivo) != NULL)
{
    printf("%s", str);
}

|| = = - Escrita em Arquivo - = = ||

fputc('A', arquivo);

fputs("Hello World", arquivo);

|| = = - - Posicionamento em Arquivo - - = = ||

//move o cursor para o inicio 

rewind(arquivo);

//move o cursor para uma posição específica

fseek(arquivo, 10, SEEK_SET) //10 bytes do inicio

fseek(arquivo, 5, SEEK_END) // 5 bytes antes do fim
    

|| = = - - Manipulação de Dados em Arquivos - - = = ||

//Leitura e Escrita de Estruturas

struct Pessoa 
{
    char nome[50];
    int idade
}

struct Pessoa p = {"Nome", x_idade}

//Escrita
fwrite(&p, sizeof(struct Pessoa), 1, arquivo);

//Leitura
freed(&p_lida, sizeof(struct Pessoa), 1, arquivo);

|| = = - - Tratamento de Erro - - = = ||

if (ferror(arquivo))
{
    perror("Erro na operação com arquivo");
    clearerr(arquivo);
}

if (feof(arquivo))
{
    printf("fim do arquivo alcançado");
}

Bons Habitos

    -Verificar abertura correta do arquivo
    -Feche arquivos apos o uso
    -Use fflush() para forçar a escrita de dados em buffer para o arquivo
    -Em binario, use fread() e fwrite() para ler/escrever em blocos de dados

*/