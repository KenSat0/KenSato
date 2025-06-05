#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[6] = {1, 2, 3, 4, 5, 6};

    int *ponteiro = vetor;

    int matriz [2][3] = 
    {
        {1, 2, 3},
        {4, 5, 6}
    }; 

    int *p = &matriz[0][0]; //aponta para o ENDEREÇO do primeiro elemento, por isso que funciona

    for (int i = 0; i<6; i++)
    {  
        printf("%d ", *p);
        p++;
    }

    /*
    for (int i = 0; i<6; i++)
    {  
        printf("%d ", *ponteiro);
        ponteiro++;
    }
    */

    getchar();
    return 0;
}