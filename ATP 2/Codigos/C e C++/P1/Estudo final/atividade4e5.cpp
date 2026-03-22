#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct no
{
    char nome[50];
    int matricula;
    no *prox;
} regFunc;

regFunc *listaRFunc;

//**atual é igual a &regFunc e *atual (que é muito usado no exercicio) é o HEAD da lista, vulgo endereço para o primeiro nó, onde a lista começa
int cadastro_ordenado(regFunc**atual)
{
    //aloca ponteiro temp e verifica se alocou certo
    regFunc *temp = (regFunc*)malloc(sizeof(regFunc));
    if(temp==NULL)
    {
        perror("\nTemp nao alocado");
        return 1;
    }

    //os ponteiros atual e anteior servem para marcar o lugar desejado e o anterior dele
    regFunc *p_atual = *atual;
    regFunc *p_anterior = NULL;

    //pede o numero de matricula e verifica validade dele
    printf("\nMatricula: ");
    scanf("%d", &temp->matricula);
    if(temp->matricula < 1 || temp->matricula > 10)
    {
        perror("\nNumero de cadastro invalido");
        //se for um numero errado, libera temp
        free(temp);
        return 1;
    }

    //pede nome e guarda no temp->nome
    char nome[50];
    printf("\nNome: ");
    scanf("%s", nome);
    strcpy(temp->nome, nome);

    //isso verifica se a lista ta vazia
    if((*atual)==NULL)
    {
        //prox recebe NULL, ja que temp é o primeiro elemento
        temp->prox = NULL;
        //atual recebe temp (pense em *atual como "head" da lista, ou seja, endereço do inicio da lista)
        *atual = temp;
    }
    else
    {
        //enquanto
            //ponteiro atual não é nulo (ou seja, até o fim da lista)
            //o numero da matricula de ponteiro atual for menor que o temp que desejo adicionar (ou seja, para o laço quando chegar no ponteiro que é maior q o ponteiro a ser adicionado)
            //os ponsteiros atual matricula e temp matricula são diferentes (para o ponteiro se houver duplicidade de matricula)
        while(p_atual!=NULL && p_atual->matricula<temp->matricula && p_atual->matricula!=temp->matricula)
        {
            //se seguir as 3 condições, ponteiro anterior avança um nó
            p_anterior = p_atual;
            //após isso, ponteiro atual avança um nó
            p_atual = p_atual->prox;

            //isso mantem sempre os dois ponteiros um após o outro (anterior e depois atual)
        }
        //se
            //ponteiro atual não é nulo (ou seja, não acabou a lista)
            //as matriculas são iguais (atual e a que vai adicionar)
        if(p_atual!=NULL && temp->matricula == p_atual->matricula)
        {
            //erro de matricula duplicada
            perror("\nNumero de matricula repetido");
            free(temp);
            return 1;
        }
        //se 
            //ponteiro anterior == NULL (significa que o laço while nunca rodou, ou seja, o novo nó precisa entrar na primeira posição)
            //(sabemos disso pois anterior é iniciado como NULL, se ele se mantem assim é pq a posição não foi alterada pelo while)
        if(p_anterior==NULL)
        {
            //temp->prox recebe atual (endereço inicial), se tornando o novo primeiro nó
            temp->prox = *atual;
            //o endereço de inicio da lista é atualizado para temp
            *atual = temp;
        }
        //se nenhum caso aconteecr, é pq o novo nó vai entrar ou no meio, ou no fim da lista, em ambos os casos, o algoritmo é o mesmo
        else
        {
            //o anterior continua sendo menor que o novo, portanto anterior->prox = temp
            p_anterior->prox = temp;
            //atual é maior que temp (ou nulo, se for o fim da lista), portanto temp->prox = p_atual
            temp->prox = p_atual;

            //esse caso não lida com o caso de lista vazia pois p_anterior->prox não existe se p_anterior == NULL (valor que ele é iniciado)
        }
    }
    return 0;
}

int listar(regFunc**atual)
{
    regFunc *p_atual = *atual;
    
    if((*atual)==NULL)
    {
        perror("\nLista vazia");
        return 1;
    }
    else
    {
        while(p_atual!=NULL)
        {
            printf("\n\n");
            printf("\nNome: %s", p_atual->nome);
            printf("\nMatricula: %d", p_atual->matricula);
            p_atual = p_atual->prox;  
        }
    }
    return 0;
}

int excluir(regFunc**atual)
{
    regFunc *p_atual = *atual;
    regFunc *p_anterior = NULL;

    int numero;
    printf("\nMatricula a ser removida: ");
    scanf("%d", &numero);

    if((*atual)==NULL)
    {
        perror("\nLista vazia");
        return 1;
    }
    if (p_atual->matricula == numero)
    {
        regFunc *aux = *atual;
        (*atual) = (*atual)->prox;
        free(aux);

        return 0;
    }
    else
    {
        while(p_atual!=NULL && numero!=p_atual->matricula)
        {
            p_anterior = p_atual;
            p_atual = p_atual->prox;
        }
        if(p_atual==NULL)
        {
            perror("\nCadastro nao existe na lista");
            return 1;
        }
        else
        {
            p_anterior->prox = p_atual->prox;
            free(p_atual);
        }
    }

    return 0;
}

int main()
{
    int menu;
    while(true)
    {
        printf("\n1 - Cadastro\n2 - Listar\n3 - Excluir\n4 - Sair\no que fazer: ");
        scanf("%d", &menu);
        if(menu==1) cadastro_ordenado(&listaRFunc);
        if(menu==2) listar(&listaRFunc);
        if(menu==3) excluir(&listaRFunc);
        if(menu==4) break;
    }

    getchar();
    return 0;
}