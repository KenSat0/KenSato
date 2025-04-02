COMO USAR O GITHUB

1) Abrir GitBash na pasta desejada

2) git init

3) git add "arquivo dsejado"
3.1) git add .
        puxa todos os arquivos disponíveis na pasta

4) git commit -m "titulo do commit"
    cria novo comiit

5) git status

6) git branch -M "main"

7) git remote add origin https://github.com/KenSat0/KenSato.git

8) git push -u origin main

9) Log-in do GitHub

COMANDOS 

git checkout -b "nome" (cria nova branch)

git checkout (branch existente)  >  altera a branch em que os arquivos serão enviados

git push origin (branch existente) > envia arquivos para uma branch especifica

git merge (branch secundária) > funde a branch especifica à branch atual (normalmente, usa pra adicionar branchs para a MAIN. Após isso, use git push origin main)

COMO PUXAR O REPOSITORIO EM OUTRA MAQUINA???

1) abra o repositorio no site do github

2) clique no botão verde "Code" e copie o link do repositório

3) crie uma pasta na maquina atual e abra o GitBash nela

4) git clone (link do repositorio)

COMO PUXAR UMA ALTERAÇÃO DO REPOSITORIO

1) entre na pasta do arquivo com o GitBash

2) git pull 