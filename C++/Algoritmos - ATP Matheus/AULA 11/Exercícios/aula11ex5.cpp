/*

5. Faça um menu interativo que leia o menu no menu.txt e imprima o boleto de um
pedido de lanchonete num boleto.txt .
Dica:
● Coloque a quantidade de itens do menu na primeira linha de menu.txt).
● rewind(f) permite recomeçar

*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *menutxt = fopen("menu.txt", "r"); //abre o menu para ler
    if(!menutxt) return 1; //se não abriu, retorna 1

    int n;
    fscanf(menutxt, "%d", &n); 

    getchar();
    return 0;
}