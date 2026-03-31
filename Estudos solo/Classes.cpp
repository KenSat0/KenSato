#include <iostream>

//classes = atributos + metodos
    //caracteristicas e funções relacionadas
    //podem mimicar ou representar objetos (por isso Orientação a Objeto)

class Human{
    public:
        //caracteristicas/atributos
        std::string nome;
        std::string ocupacao;
        int idade;
        //se atribuir valores aqui, eles se tornam valores "default", podem ser mudados se atribuidos depois na main

        //metodos
        void comer(){
            std::cout << "ta comendo\n";
        }

        void beber(){
            std::cout << "ta bebendo\n";
        }

        void mandaSalve(){
            std::cout << "ta salvado meu rei\n";
        }
};

class aluno{
    public:
        std::string nome;
        int idade;
        double nota;

    aluno(std::string nome, int idade, double nota){
        //se o nome dos parametros locais da função forem diferentes dos atributos da classe, o prefixo this-> é desnecessário
        this->nome = nome;
        this->idade = idade;
        this->nota = nota;
    }
};

class pokemon{
    public:
        std::string nome;
        std::string tipo;
        std::string subtipo;
        std::string regiao;
        int lvl;

    pokemon(std::string nome, std::string tipo, std::string subtipo, std::string regiao, int lvl){
        this->nome = nome;
        this->tipo = tipo;
        this->subtipo = subtipo;
        this->regiao = regiao;
        this->lvl = lvl;
    }

    void stats(){
        std::cout << "Nome: " << this->nome << '\n';
        std::cout << "Tipo Primario: " << this->tipo << '\n';
        std::cout << "Nivel: " << this->lvl << '\n';
    }
};

int main(){
    //aluno aluno1("bruno", 67, 6.7);

    pokemon poke1("sylveon", "fada", "N/A", "seila krl", 67);
    pokemon poke2("vaporeon", "agua", "N/A", "seila krl", 69);

    poke1.stats();
    poke2.stats();

    /*
    std::cout << aluno1.nome << '\n';
    std::cout << aluno1.idade << '\n';
    std::cout << aluno1.nota << '\n';

    Human ummano;
    Human doismano;

    ummano.nome = "bruno";
    ummano.ocupacao = "melador de cueca";
    ummano.idade = 67;

    doismano.nome = "brunello";
    doismano.ocupacao = "deus inefavel do sofrimento";
    doismano.idade = 6009;

    std::cout << ummano.nome << '\n';
    std::cout << ummano.ocupacao << '\n';
    std::cout << ummano.idade << '\n';

    ummano.mandaSalve();
    ummano.comer();
    */

    return 0;
}