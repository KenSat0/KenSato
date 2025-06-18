#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f; 
    char linha [100];

    if(argc != 2)
    {
        return 1; //se o usuario não mandar argumentos 
    }
    
    f = fopen(argv[1], "r"); //abre o arquivo log.txt, a letra r indica que vamos ler algo nesse arquivo (read)
    
    if(f) //verificação se o arquivo f foi acessado
    {
        while (fgets(linha, sizeof(linha), f)) //enquanto houver linhas para serem lidas
        {
            printf("%s", linha);
        }

        //isso lê o arquivo todo, até que a leitura fracasse (não existem mais linhas para serem lidas)

        fclose(f);
    }
    else return 1; 

    //no terminal, escrevendo " & .\'aula11_e.exe' abc.txt " ele abre o arquivo abc.txt como um argumento para o codigo, lendo-o

    /*
    Funções para manipular arquivos:argc

    fopen: abre os arquivos em modo de leitura (r), escrita (w) e append (a)
    fclose: fecha o arquivo (SEMPRE PRECISA SER CHAMADO APOS O USO)
    fprintf: printa dentro do arquivo
    fscanf: scaneia tudo dentro do arquivo
    fgets: le uma linha do arquivo
    fputs: escreve uma linha no arquivo (sem formatação)
    fread: lê dados binarios (util para estrutura e acessos aleatorios)
    fwrite: escreve dados binarios
    fseek: move o ponteiro para uma posição especifica (util em acesso aleatorio)
    rewind: reposiciona o ponteiro no inicio do arquivo (equivalente a fseek(fp, 0, SEEK_SET))
    feof: verifica se o fim do arquivo (eof = end of file) foi alcançado

    */

    getchar();
    return 0;
}