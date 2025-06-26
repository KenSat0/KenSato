#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

int verifica_rep(int numeros[], int qtd, int num)
{
    for (int i = 0; i < qtd; i++) {
        if (numeros[i] == num)
            return 1; 
    }
    return 0;
}

void gerar_numeros(int numeros[], int qtd, int min, int max) 
{
    int count = 0; 
    while (count < qtd) 
    {
        int num = rand() % (max - min + 1) + min; 
        if (!verifica_rep(numeros, count, num)) 
        {
            numeros[count++] = num;
        }
    }
}

void gerar_cartela(FILE *arquivo)
{
    int B[5], I[5], N[4], G[5], O[5];

    gerar_numeros(B, 5, 1, 15); 
    gerar_numeros(I, 5, 16, 30);
    gerar_numeros(N, 4, 31, 45); 
    gerar_numeros(G, 5, 46, 60);
    gerar_numeros(O, 5, 61, 75);

    for (int linha = 0; linha < 5; linha++) 
    { 
        fprintf(arquivo, "%d,", B[linha]);  
        fprintf(arquivo, "%d,", I[linha]); 

        if (linha == 2)
            fprintf(arquivo, "FREE,");
        else if (linha < 2)
            fprintf(arquivo, "%d,", N[linha]);
        else
            fprintf(arquivo, "%d,", N[linha - 1]); 

        fprintf(arquivo, "%d,", G[linha]);
        fprintf(arquivo, "%d", O[linha]);

        fprintf(arquivo, "\n");
    }

    fprintf(arquivo, "\n");
}

int main() {

    int cartelas;
    printf("Digite a quantidade de cartelas a serem geradas:\n");
    scanf("%d", &cartelas);

    srand(time(NULL));


    FILE *arquivo = fopen("cartelas.csv", "w"); 

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < cartelas; i++) 
    {
        gerar_cartela(arquivo); 
    }

    fclose(arquivo);

    return 0;
}