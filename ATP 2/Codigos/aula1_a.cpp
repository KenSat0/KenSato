#include <stdio.h>
#include <stdlib.h>

//definição de tipo Resgistro com as váriaveis necessárias

typedef struct
{
    char nome[50];
    int numero_de_ficha;
    int dias;
    int *calorias;
    float peso_inicial;
    float peso_final;
    int alta;

} Registro;

//criação de vetor tipo Registro com tamanho 20, pois o Spa recebe no maximo 20 hospedes

Registro *hospedes[20];

//cria uma variavel para acompanhar a quantiade de hospedes

int qnt_hospedes = 0;

//função cadastro

int cadastro()
{

    //laço que repete infinitamente, parando apenas quando algum Return é chamado

    while (true)
    {
        int ficha = 0; 
        int dias, cal; 
        float peso_ini;

        //scan na entrada de numero da ficha, -1 fecha a função

        printf("\nNumero da ficha (-1 para terminar): ");
        scanf("%d", &ficha);

        //fecha a função se ficha == -1 (precisa estar antes da verificação de validade do numero)

        if (ficha == -1) return 1;

        //verifica se o numero é valido para uma ficha -> influencia o indice do vetor

        if(ficha<1 || ficha>=20)
        {
            printf("\nNumero inválido de ficha");
            return 2;
        }

        //verifica se há espaço vago no spa

        if (qnt_hospedes >= 20)
        {
            printf("\nO Spa esta lotado");
            return 1;
        }

        //se a ficha ja existe (se é diferente de nula)

        if(hospedes[ficha-1] != NULL)
        {
            printf("Ficha ja existe");
            return 2;
        }

        //aloca memoria no vetor

        hospedes[ficha-1] = (Registro*)malloc(sizeof(Registro));
        if (hospedes[ficha-1] == NULL)
        {
            printf("\nErro ao alocar memoria\n");
        }

        //da entrada na ficha como sem alta

        hospedes[ficha-1]->alta = 0;

        //registra o numero da ficha

        hospedes[ficha-1]->numero_de_ficha = ficha;

        //registra nome (direto na variavel do vetor hospedes)

        printf("\nNome: ");
        scanf("%s", hospedes[ficha-1]->nome);

        //registra peso inicial

        printf("\nPeso ao entrar: ");
        scanf("%f", &peso_ini);
        hospedes[ficha-1]->peso_inicial = peso_ini;

        //registra dias

        printf("\nDias: ");
        scanf("%d", &dias);
        if (dias > 30) //verifica se a quantiade de dias é válida
        {
            printf("\nQuantidade de dias maxima excedida");
            return 0;
        }
        hospedes[ficha-1]->dias = dias;

        //aloca memoria no vetor calorias para cada dia

        hospedes[ficha-1]->calorias = (int*)malloc(dias * sizeof(int));

        //registra calorias por dia

        for (int i = 0; i<dias; i++)
        {
            printf("\nCalorias no dia %d: ", i+1);
            scanf("%d",  &cal);
            hospedes[ficha-1]->calorias[i] = cal;
        }

        //imprime os valores registrados (sem peso final ou alta)
    
        printf("\n============");
        printf("\nFicha n: %d", hospedes[ficha-1]->numero_de_ficha);
        printf("\n======");
        printf("\nNome: %s", hospedes[ficha-1]->nome);
        printf("\nPeso ao entrar: %.2f kg", hospedes[ficha-1]->peso_inicial);
        printf("\n======");
        printf("\nDias de Tratamento: %d", hospedes[ficha-1]->dias);
        printf("\n");
        printf("\nQtd de calorias permitidas em cada dia: ");
        for (int i = 0; i<dias; i++)
        {
            printf("\nDia %d: %d", i+1, hospedes[ficha-1]->calorias[i]);
        }
        printf("\n============\n");

        //adiciona 1 na quantidade de hospedes

        qnt_hospedes++;

        //da opção de cadastrar nova ficha

        int opcao = 0;
        printf("\nCadastrar nova ficha?\n1- Sim\n2- Fechar\n");
        scanf("%d", &opcao);
        if(opcao==2) return 1;
    }
    return 0;
}

//funcção de dar baixa nas fichas

int dar_baixa()
{

    //laço sempre verdadeiro, mesmo caso do anterior

    while(true)
    {

        int ficha;
        float peso_fim;
        printf("\nNumero da ficha: "); 
        scanf("%d", &ficha); //recebe um numero de ficha para ser acessada


        if(hospedes[ficha-1] == NULL || ficha<1 || ficha>=20) //verifica existencia e validade da ficha desejada
        {
                printf("\nA ficha não existeou seu numero é inválido");
                return 2;
        }

        if(hospedes[ficha-1]->alta==1) //verifica se a ficha ja recebeu alta
        {
            printf("\nEssa ficha ja recebeu alta");
                return 2;
        }

        printf("Peso ao sair: ");
        scanf("%f", &peso_fim);
        hospedes[ficha-1]->peso_final = peso_fim; //registra peso final

        float perda = hospedes[ficha-1]->peso_inicial - hospedes[ficha-1]->peso_final;
        printf("Peso perdido: %.2f kg\n", perda); //retorna a perda de peso

        qnt_hospedes--; //diminui em 1 a ocupação do spa
        hospedes[ficha-1]->alta = 1; //da alta na ficha

        //imprime a ficha completa

        printf("\n============");
        printf("\nFicha n: %d", hospedes[ficha-1]->numero_de_ficha);
        printf("\nAlta (X)");
        printf("\n======");
        printf("\nNome: %s", hospedes[ficha-1]->nome);
        printf("\nPeso ao entrar: %.2f kg", hospedes[ficha-1]->peso_inicial);
        printf("\nPeso ao sair: %.2f kg", hospedes[ficha-1]->peso_final);
        printf("\n======");
        printf("\nDias de Tratamento: %d", hospedes[ficha-1]->dias);
        printf("\n");
        printf("\nQtd de calorias permitidas em cada dia: ");
        for (int i = 0; i<hospedes[ficha-1]->dias; i++)
        {
            printf("\nDia %d: %d", i+1, hospedes[ficha-1]->calorias[i]);
        }
        printf("\n============\n");

        //da opção de dar baixa em mais uma ficha

        int opcao = 0;
        printf("\nDar nova baixa?\n1- Sim\n2- Fechar\n");
        scanf("%d", &opcao);
        if(opcao==2) return 1;
    }
    return 0;
}

int main()
{
    while(true)
    {
        int menu=0;
        printf("\nO que deseja fazer:\n1- Cadastrar Ficha\n2- Dar Baixa\n3- Fechar\n");
        scanf("%d", &menu);
        if (menu==1) cadastro();
        if (menu==2) dar_baixa();
        if (menu==3) return 1;
    }
    
    getchar();
    return 0;
}