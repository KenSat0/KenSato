def soma(a, b):
    return a + b

def subtração(a, b):
    return a - b

def divisão(a, b):
    return a / b

def produto(a, b):
    return a * b

menu = 0
while(menu != 5):
    print("\n1 - soma\n2 - subtração\n3 - divisão\n4 - produto\n5 - sair")
    menu = int(input("O que fazer: "))
    if menu == 1:
        print("soma")
        a = int(input("a: "))
        b = int(input("b: "))
        print(f"{soma(a, b)}")
    elif menu == 2:
        print("subtração")
        a = int(input("a: "))
        b = int(input("b: "))
        subtração(a, b)
    elif menu == 3:
        print("divisão")
        a = int(input("a: "))
        b = int(input("b: "))
        divisão(a, b)
    elif menu == 4:
        print("produto")
        a = int(input("a: "))
        b = int(input("b: "))
        produto(a, b)
