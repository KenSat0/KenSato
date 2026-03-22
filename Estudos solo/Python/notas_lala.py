media_sem = float(input("media sem: "))

diss = float(input("diss: "))

obj = float(input("obj: "))

pontos = (media_sem * 2) + (diss*0.5) + (obj*0.3) + 1

if pontos < 24:
    print("Não passou")
    print(f"faltam {24-pontos}")
else:
    print("passou")
    print(f"folga {pontos - 24}")
