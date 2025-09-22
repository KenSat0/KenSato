class Node:
    def __init__ (self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def add_first(self, data):
        novo_no = Node(data)
        novo_no.next = self.head
        self.head = novo_no

    def add_last(self, data):
        novo_no = Node(data)
        current_node = self.head

        if current_node is None:
            self.head = novo_no
        else:
            while current_node.next is not None:
                current_node = current_node.next

            current_node.next = novo_no

    def remove(self, data):
        current_node = self.head
        node_past = None

        if current_node is None:
            print("lista vazia")
            return
        else:
            while current_node is not None and current_node.data is not data:
                node_past = current_node
                current_node = current_node.next

            if node_past is None:
                self.head = self.head.next
            elif current_node is None:
                print("valor não encontrado na lista")
            else:
                node_past.next = current_node.next

        

    def print_list(self):
        current_node = self.head

        while current_node is not None:
            print(current_node.data)
            current_node = current_node.next

lista = LinkedList()

while True:
    temp_data = int(input("Numero do no(-1 para terminar): "))
    if temp_data == -1:
        break
    else:
        lista.add_last(temp_data)

lista.remove(3)

lista.print_list()