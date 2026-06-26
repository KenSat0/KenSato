import sqlite3

conexao = sqlite3.connect("banco.db")
#cria a ligação entre o codigo e o banco de dados

cursor = conexao.cursor()
#objeto responsavel por ler e interpretar dados

#como criar a tabela de dados (usadom linguagem SQL)
    #executa um comando passado na string, cria tabela com um nome
cursor.execute("""CREATE TABLE IF NOT EXISTS contas_bancarias (
               id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
               titular TEXT NOT NULL,
               saldo FLOAT NOT NULL,
               cpf TEXT NOT NULL UNIQUE
               )""") 
#usa triple-string pra poder quebrar a linha sem problemas
                #id é o numero unico de cada registro criado
                    #tipo inteiro nao nulo
                    #primary key diz que esse é o parametro de identificação
                    #autoincrement = cresce automaticamente conforme adicionamos registros

# cursor.execute("""INSERT INTO contas_bancarias 
#                (titular, saldo, cpf) VALUES
#                ('larissa', -6700, '1234512365478900')""")

# cursor.execute("""UPDATE contas_bancarias
#                SET saldo = -100000
#                WHERE id = 2""")

# o * seleciona todos os campos de dados criados de todos os registros
cursor.execute("""SELECT * FROM contas_bancarias""") #pode trocar * pelo nome das colunas (titular, saldo...), lembre de mudar as variaveis no desempacotamento
#cursor.execute("""SELECT * FROM contas_bancarias WHERE id = 1""") -> filtra os dados para a codição passada ex.: WHERE saldo > 0
contas = cursor.fetchall()

# cursor.execute("""DELETE FROM contas_bancarias WHERE id = 2""") -> comando para remover registros da tabela


for conta in contas:
    id, titular, saldo, cpf = conta
    print(f"""
    ID: {id}
    Titular: {titular}
    Saldo: {saldo}
    CPF: {cpf}""")
    print("\n")

conexao.commit()

