COMPRESSÃO: reduz a quantidade de bits para representar um dado
COMPACTAÇÃO: união de dados que nao estejam unidos

Eliminação de redundâncias

OMISSÃO DE SEQUÊNCIAS REPETIDAS (RLE)
    substitui valores repetidos sequencialmente por 3 bytes que descrevem como a repetição acontece
    Ex.: 22 23 24 24 24 24 24 24 24 25 26 26 26 26 26 26 25 24
         22 23 ff 24 07 25 ff 26 06 25 24

Alem de eliminar redundâncias, ganha espaço de memória, aumenta o desempenho em transmissões

CLASSIFICAÇÃO
    com perdas X sem perdas
        diz respeito à possivel perda ou nao de dados apos a reconstrução dos dados comprimidos (nem sempre a perda é um problema)
    simetricos X assimetricos
        simetria é repetir a logica de compressão invertida para descompressão
    adaptativo X nao adaptativo
        diz respeito a portabilidade do metodo para o tipo de dados de entrada (regras invariaveis para o tipo de dado de entrada)
    + relativa a operação
        metodos estatisticos
        metodos de dicionario

    CODIGO DE HUFFMAN (dicionario)
        atribui codigos menores para simbolos mais frequentes e codigos maiores para simbolos menos frequentes
        codigo = conjunto de bits

        como evitar ambiguidade de interpretação no HUFFMAN?
            usa-se uma arvore binaria com as frequencias para conseguir codigos para cada simbolo
            como construi-la:
                tabela de frequencia dos simbolos
                faça uma lista ordenada da menor para maior frequencia
                junte os dois menores em um nó, esse nó tem como raiz a soma das frequencias e essa raiz entra na lista anterior
                repita até que nao sobre mais elementos na lista ordenada

    CODIFICAÇÃO DE SHANNON-FANO (estatistica)
        gera codigos variaveis para simbolos baseados na sua probabilidade de ocorrência

        contabilize a probabilidade de ocorrencia de cada simbolo em uma lista ordenada
        a arvore binaria dessa vez tenta separar 50% de prob em cada sub-arvore
        a atribuição de bits aos simbolos acontece da mesma forma que o HUFFMAN

    ALGORITMO LEMPEL-ZIV
        nao trabalha com frequencia ou estatistica
        nao guarda estrutura extra

EXEMPLO LEMPEL-ZIV:

    ABBABABAC

    |A|BBABABAC
    se o entre ponteiros esta no dicionario, avança
    |AB|BABABAC
    tem no dicionario? nao, entao cria
    1|BB|ABABAC > adicionou BB
    122|ABA|BAC > A e AB existem, cria um novo para ABA
    1224|ABAC| > A AB ABA ja existem, cria ABAC

    122473 > utiliza 3 pq C so aparece 1 vez

    chave |  valor
    1     |  a
    2     |  b
    3     |  c
    4     |  ab
    5     |  bb
    6     |  ba
    7     |  aba
    8     |  abac

RECONSTRUINDO: 122473

os 3 primeiros são padrões (singulares)

    chave |  valor
    1     |  a
    2     |  b
    3     |  c
    4     |  ab
    5     |  bb
    6     |  ba
    7     |  aba
    8     |  

||122473      : 1=a
|A|22473      : 2=b
|AB|2473      : ab nao existe no dicionario de descompressão, cria
A|BB|473      : 2 é b, bb ainda n existe na lista
AB|BA|B73     : 4 é traduzido pq ja existe, como B ja existe, verifica que BA n existe ainda
ABB|AB|73     : A e AB ja existem, 7 é descoberto por suposições, e depois o 7 é registrado (suposição = registro entao ta certo)
ABB|AB|ABA3   : supõe o valor de 7 com ABA
ABBA|BA|BA3   : ABA nao existe e é registrado em 7 (suposição = registro)
ABBABA|BA|C   : BA existe, prossegue a traduzir 3 que ja tem
ABBABABAC

ALGORITMO LZ77
    ctrl+c ctrl+v entre janela e buffre

EX. LZ77

A ASA DA CASA

JANELA (8):
BUFFER (4): A_AS > nao existe nenhuma subsequencia na janela

(0,0,A) > escreve A na janela sem usar nenhuma subsequencia

JANELA (8): A
BUFFER (4): _ASA 

(0,0,_)

JANELA (8): A_
BUFFER (4): ASA_

(2,1,S) > volta 2 casas, para a janlena caracter A, copia o A uma vez, e depois um S

JANELA (8): A_AS
BUFFER (4): A_DA

(4,2,D) > anda 4 casas, copia os 2 caracteres A_, depois D

JANELA (8):A_ASA_D
BUFFER (4):A_CA

(3,2,C)

JANELA (8):ASA_DA_C
BUFFER (4):ASA

(8,3,EOF)

SAÍDA: (0,0,A)(0,0,_)(2,1,S)(4,2,D)(3,2,C)(8,3,EOF)

Descompactar: leia as tuplas em ordem 

A | _ | AS | A_D | A_C | ASA = A ASA DA CASA   