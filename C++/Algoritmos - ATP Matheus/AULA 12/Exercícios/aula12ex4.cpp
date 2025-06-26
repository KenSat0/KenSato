#include <stdio.h>
#include <stdlib.h>

//fazer estrutura

typedef struct 
{
    int inteiro, decimal;
} Quebrado;

Quebrado somar(Quebrado *a, Quebrado *b)
{
    Quebrado soma;
    int parte_inteira = a->inteiro + b->inteiro;
    int parte_decimal = a->decimal + b->decimal;
    if (parte_decimal >= 10000)
    {
        parte_inteira++;
        parte_decimal-=10000;
    }
    soma.inteiro = parte_inteira;
    soma.decimal = parte_decimal;

    //diferença entre "." e "->"
    //"->" ponteiros do valor
    //"." valor 

    /*
    
    O ponteiro Quebrado *A consiste de 3 ponteiros:
        -1° para o tipo Quebrado
        -2° para a parte_inteira do Quebrado *A
        -3° para a parte_decimal do Quebrado *A

    */

    return(soma);
}
