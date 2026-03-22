#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v;
    int quanto;
    quanto = 100;

    scanf("%d", &quanto);

    v = (int*) malloc(quanto * sizeof(int)); //bits a serem alocados + "int*" converte para vetor inteiro

    realloc(v, quanto*sizeof(int));

    v = (int*) calloc(quanto, sizeof(int)); // aloca espaço de memoria e setta todo o vetor pra 0

    for(int i = 0; i<quanto; i++)
        printf("%d ", v[i]);

    //verificação se  deu certo 

    if (v==NULL)
    {
        printf("Erro na alocação de memoria\n");
        return 1;
    }

    free(v);  // libera a memoria alocada (igual limpar a bancada depois de cozinhar), esquecer isso vai tirar nota
    getchar();
    return 0;
}