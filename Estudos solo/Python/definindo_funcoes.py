def cumprimento(first, last):
    print(f"Ola {first} {last}")
    print("Bem vindo ao Python")


cumprimento("Leo", "Ken")
cumprimento("Larissa", "Ken")


def return_greet(nome):
    return f"Ola {nome}"


msg = return_greet("Leo")
print(msg)
file = open("teste.txt", "w")
file.write(msg)


def increment(number, by = 3): #default value = se não for passado BY, assume valor 1
    return number + by


print(increment(2, by = 1)) #keyword argument = clarifica o significado de cada argumento da função

print(increment(2)) 


def produto(*numeros):
    total = 1
    for x in numeros:
        total *= x
    return total


print(produto(1, 2, 3, 4))
