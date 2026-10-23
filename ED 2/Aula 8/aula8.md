Processamento Co-Sequencial

    processamento de duas ou mais listas de entrada ordenadas. 
    ex.:
        matching - interseção
        merging - união

    merging:
        inicialização - abrir arquivos e inicializar variaveis para processamento correto
        condições de fim - quando uma lista acabar, continua-se a processar a outra
        possiveis erros: chaves duplicadas ou fora de ordem

    matching: 
        inicialização - abrir arquivos e inicializar variaveis para processamento correto
        condições de fim - quando uma lista acabar, finaliza o processo
        possiveis erros: chaves duplicadas ou fora de ordem

    obs.: avança a chave menor (alfabeticamente menor e tambem de tamanho menor)

Operações Co-Sequenciais
    implementação direta e simples: leitura e escrita de registris um a um pode tornar as operações ineficientes

    Multi-Way Merging:
        Ordenação Externa - ordenação em memoria secundaria, por isso, busca otimização, ja que essa memoria é lenta
            Dificuldade: dependem fortemente da tecnologia
            Solução: baseado em modelo simplificado
                divisão de blocos por rodadas e merging local
                repetição nao exclui o repetido, mantem ele X vezes

            1. carrega toda ram com a parte do arquivo
            2. ordena NA RAM com algoritmo in-place
            3. escreve-se os registros ordenados em um arquivo separado
            4. repete-se até finalizar o arquivo 

