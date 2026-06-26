#include <iostream>

class personagem{
    public:
        std::string nome;
        int pv;
        int pm;
        int pa;
        std::string condicao = "N/A";

    personagem(std::string nome, int pv, int pm, int pa){
        this->nome = nome;
        this->pv = pv;
        this->pm = pm;
        this->pa = pa;
    }

    personagem(std::string nome, int pv, int pm, int pa, std::string condicao){
        this->nome = nome;
        this->pv = pv;
        this->pm = pm;
        this->pa = pa;
        this->condicao = condicao;
    }

    void showStats(){
        std::cout << nome << '\n';
        std::cout << pv << '\n';
        std::cout << pm << '\n';
        std::cout << pa << '\n';
        std::cout << condicao << '\n';
    }

    void atualizarVida(int newPV){
        pv = newPV;
    }

    void sofrerDano(int dano){
        pv = pv - dano;
    }

    void atualizarMana(int newPM){
        pm = newPM;
    }

    void gastarMana(int custo){
        pm = pm - custo;
    }

    void atualizarAcao(int newPA){
        pa = newPA;
    }

    void gastarAcao(int custo){
        pa = pa - custo;
    }
};

int main(){
    personagem perso1("Angelo", 10, 10, 2);

    perso1.showStats();


    return 0;
}