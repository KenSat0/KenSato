STACKMAX = 100

class LIFO:
    def __init__ (self):
        self.top = -1
        self.data = []

    def empty(self):
        if not self.data:
            print("Pilha vazia")
            return True
        return False
    
    def push(self, valor):
        if len(self.data) < STACKMAX:
            self.data.append(valor)
            self.top = len(self.data) - 1
        else:
            return print("Pilha cheia")
        
    def pop(self):
        if self.empty():
            return None
        
        self.data.pop()
        self.top = len(self.data) - 1
        return 1
    
    def stacktop(self):
        if self.empty():
            return None
        print(f"Topo: {self.data[-1]}")

    def stackprint(self):
        if not self.empty():
            for item in reversed(self.data):
                print(f"{item}  ")

pilha = LIFO()
pilha.top = -1

pilha.empty()

pilha.push(2)
pilha.push(99)
pilha.push(67)
pilha.push(66)

pilha.stacktop()
pilha.stackprint()

pilha.pop()

pilha.stacktop()
pilha.stackprint()

#Last in, First Out: primeiro a sair foi o ultimo que entrou (pilha)