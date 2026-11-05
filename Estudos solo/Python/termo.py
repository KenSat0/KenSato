chave = "MANTO"

chute = input("chute: ")

for letra in chute:
    i = 0
    if chute[i] == chave[i]: print("green")
    elif letra in chave: print("yellow")
    else: print("grey")
    i = i + 1
