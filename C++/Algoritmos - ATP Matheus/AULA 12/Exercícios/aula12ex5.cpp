#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pegar o menu interativo da lista anterior e fazer uma estrutura "menu" e estrutura "produto" para a mesma finalidade

#define MAX_ITENS 100
#define MAX_NOME  50

typedef struct
{
    char nome[MAX_NOME];
    float preco;
} Produto;

typedef struct 
{
    Produto itens[MAX_ITENS];
    int total;
} Menu;

int ler_menu(FILE *f, Menu *menu)//mesma função do outro menu, mas com struct
{
    if (fscanf(f, "%d\n", &menu->total) != 1 || menu->total <= 0 || menu->total > MAX_ITENS) return -1;
    //verifica se o numero de itens n é valido dado os MAX definidos

    for (int i = 0; i < menu->total; i++) 
    {
        char linha[200];
        if (!fgets(linha, sizeof(linha), f)) return -2; 
        linha[strcspn(linha, "\r\n")] = '\0'; 

        char *separar = strchr(linha, ';'); //procura o ; da formatação
        if (!separar) return -3;

        //retorna erro se não achar (formataçao errada)

        *separar = '\0';
        strncpy(menu->itens[i].nome, linha, MAX_NOME - 1);
        menu->itens[i].nome[MAX_NOME - 1] = '\0';

        menu->itens[i].preco = atof(separar + 1);
    }

    return 1;
}

void mostrar_menu(Menu *menu) 
{
    printf("\n--- menu ---\n");
    printf(" 0) Finalizar pedido\n");
    
    for (int i = 0; i < menu->total; i++) 
    {
        printf("%2d) %-30s R$ %.2f\n", i + 1, menu->itens[i].nome, menu->itens[i].preco);
    }
    printf("\n");
}

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void fazer_pedidos(Menu *menu, int quantidades[]) 
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

        if (escolha > 0 && escolha <= menu->total) //se a escolha é valida
        {
            int qtd;
            printf("Quantidade de '%s': ", menu->itens[escolha - 1].nome); //pergunta quantidade
            if (scanf("%d", &qtd) != 1 || qtd < 0) //se for invaldia
            {
                printf("Quantidade invalida.\n"); //erro
                limpar_buffer();
            } 
            else 
            {
                quantidades[escolha - 1] += qtd; //a quantidade do item de indice [escolha-1] recebe += qtd
            }
        } 
        else if (escolha != 0) 
        {
            printf("Erro: Essa nao e uma opcao do menu.\n");
        }

    } 
    while (escolha != 0);
}

void gerar_boleto(Menu *menu, int quantidades[]) 
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
for (int i = 0; i < menu->total; i++) //para cada item oedido
{
    if (quantidades[i] > 0) 
    {
        float sub = quantidades[i] * menu->itens[i].preco;
        fprintf(fb, "%-30s %10d   R$ %7.2f   R$ %9.2f\n", menu->itens[i].nome, quantidades[i], menu->itens[i].preco, sub);

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
    FILE *m = fopen("menu.txt", "r");
    if (!m) 
    {
        printf("Erro ao abrir menu.txt");
        return 1;
    } //abre o arquivo e apura se der erro

    Menu menu;

    if (!ler_menu(m, &menu)) //função de leitura do menu
    {
        fprintf(stderr, "Erro ao ler menu\n"); //retorna um erro no canal de erro
        return 1;
    }

    fclose(m);

    int quantidades[MAX_ITENS] = {0};

    mostrar_menu(&menu);
    fazer_pedidos(&menu, quantidades);
    gerar_boleto(&menu, quantidades);
    //executa cada função do programa

    return 0;
}