
def somaDigitos(x):
    if(x < 10):
        soma = x
        return soma
    else:
        soma = x%10 + somaDigitos((x-x%10)/10)
        return soma

numero = int(input("Numero: "))

print(somaDigitos(numero))