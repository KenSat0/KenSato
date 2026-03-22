class Node:
    def __init__ (self, valor = None):
        self.data = valor
        self.next = None

class FIFO:
    def __init__ (self, head = None):
        self.head = head

    def empty(self):
        if not self.head:
            print("Fila vazia")
            return True
        return False

    def insert(self, valor):
        new_node = Node(valor)
        new_node.next = self.head
        self.head = new_node

    def remove(self):
        if not self.empty():
            aux = self.head
            if aux.next is not None:
                ant = None
                while aux.next is not None:
                    ant = aux
                    aux = aux.next
                ant.next = aux.next
            else:
                aux = None
        
    def print(self):
        if not self.empty():
            aux = self.head
            while aux is not None:
                print(f"{aux.data}")
                aux = aux.next

    def nextcheck(self):
        if not self.empty():
            aux = self.head
            while aux.next is not None:
                aux = aux.next
            print(f"{aux.data} e o proximo da fila")

    def queuesize(self):
        if not self.empty():
            aux = self.head
            size = 0
            while aux is not None:
                size += 1
            return size
        
fila = FIFO()

fila.empty()

fila.insert(2)
fila.insert(5)
fila.insert(67)
fila.insert(4)
fila.insert(10)

fila.nextcheck()
fila.print()

fila.remove()
fila.remove()

fila.nextcheck()
fila.print()