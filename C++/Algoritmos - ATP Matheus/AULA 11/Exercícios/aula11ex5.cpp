/*

5. Faça um menu interativo que leia o menu no menu.txt e imprima o boleto de um
pedido de lanchonete num boleto.txt .
Dica:
● Coloque a quantidade de itens do menu na primeira linha de menu.txt).
● rewind(f) permite recomeçar

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100
#define MAX_NOME  50

void limpar_buffer() //serve para ler e descartar tudo até a quebra de linha
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int ler_menu(FILE *f, char nomes[][MAX_NOME], float precos[]) //funçao le o arquivo e guarda o nome dos produtos em matriz e os preços em vetores
{
    int n;
    if (fscanf(f, "%d\n", &n) != 1 || n <= 0 || n > MAX_ITENS) return -1;
    //verifica se o numero de itens n é valido dado os MAX definidos

    for (int i = 0; i < n; i++) 
    {
        char linha[200];
        if (!fgets(linha, sizeof(linha), f)) return -2; //le linha
        linha[strcspn(linha, "\r\n")] = '\0'; //strcspn remove chars indesejados

        char *precoPtr = strchr(linha, ';'); //procura o ; da formatação
        if (!precoPtr) return -3;

        //retorna erro se não achar (formataçao errada)

        *precoPtr = '\0';
        strncpy(nomes[i], linha, MAX_NOME - 1);
        nomes[i][MAX_NOME - 1] = '\0';
        precos[i] = atof(precoPtr + 1);

        //separa o menu em nome e preço, "cortando" o ;
    }

    return n;
}

void mostrar_cardapio(char nomes[][MAX_NOME], float precos[], int n) 
{
    printf("--- Menu ---\n");
    printf(" 0) Finalizar pedido\n");
    for (int i = 0; i < n; i++)
        printf("%2d) %-30s R$ %.2f\n", i + 1, nomes[i], precos[i]);

    //mostra o numero e o nome dos itens com o seu preço, alinhados à esquerda co ate 30 char
}

void fazer_pedidos(int n, char nomes[][MAX_NOME], int quant[]) 
{
    int escolha;
    do {
        printf("Selecione o item (0 para finalizar): ");
        if (scanf("%d", &escolha) != 1) //se não deu pra fazer scan
        {
            printf("Entrada invalida.\n"); //erro
            limpar_buffer(); //limpa entrada
            escolha = -1; //escolha = -1, faz a condicional seguinte falhar
            continue;
        }

        if (escolha > 0 && escolha <= n) //se a escolha é valida
        {
            int qtd;
            printf("Quantidade de '%s': ", nomes[escolha - 1]); //pergunta quantidade
            if (scanf("%d", &qtd) != 1 || qtd < 0) //se for invaldia
            {
                printf("Quantidade invalida.\n"); //erro
                limpar_buffer();
            } 
            else 
            {
                quant[escolha - 1] += qtd; //a quantidade do item de indice [escolha-1] recebe += qtd
            }
        } 
        else if (escolha != 0) 
        {
            printf("Erro: Essa nao e uma opcao do menu.\n");
        }

    } 
    while (escolha != 0);
} //loop para registrar o pedido do cliente, loop com parada em 0

void gerar_boleto(char nomes[][MAX_NOME], float precos[], int quant[], int n) 
{ //gera o boleto 
FILE *fb = fopen("boleto.txt", "w"); //abre (ou cria) o arquivo boleto
if (!fb) 
{
    printf("Erro ao criar boleto"); //erro se não der
    return;
}

//imprime elementos de formatação do boleto
fprintf(fb, "Boleto de pedido:\n");
fprintf(fb, "%-30s %10s %12s %12s\n", "Item", "Qtd", "Preço", "Subtotal");
fprintf(fb, "----------------------------------------------------------------------------\n");

float total = 0.0f;
for (int i = 0; i < n; i++) //para cada item oedido
{
    if (quant[i] > 0) 
    {
        float sub = quant[i] * precos[i];
        fprintf(fb, "%-30s %10d   R$ %7.2f   R$ %9.2f\n", nomes[i], quant[i], precos[i], sub);
        //escreve nome, quantidade, preço e subtotal
        total += sub; //soma o subtotal no total
    }
}

fprintf(fb, "\nTotal a pagar: R$ %.2f\n", total);
fclose(fb);
printf("Boleto salvo em 'boleto.txt'.\n");
//escreve o total e fecha o arquivo
}

int main() 
{
    FILE *menu = fopen("menu.txt", "r");
    if (!menu) 
    {
        printf("Erro ao abrir menu.txt");
        return 1;
    } //abre o arquivo e apura se der erro

    char nomes[MAX_ITENS][MAX_NOME];
    float precos[MAX_ITENS];
    int quantidades[MAX_ITENS] = {0};

    int n = ler_menu(menu, nomes, precos);
    fclose(menu);
    if (n < 0) //função de leitura do menu
    {
        fprintf(stderr, "Erro ao ler menu (código %d)\n", n); //retorna um erro no canal de erro
        return 1;
    }

    mostrar_cardapio(nomes, precos, n);
    fazer_pedidos(n, nomes, quantidades);
    gerar_boleto(nomes, precos, quantidades, n);
    //executa cada função do programa

    return 0;
}