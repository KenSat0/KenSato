#include <iostream>
#include <string>
#include <vector>

class episodio;
class temporada;
class serie;

class episodio{
    private:
        int ep_index;
        temporada *ref;
    public:
        int nota1;
        int nota2;

        episodio(int x, int y, int z, temporada *t){
            nota1 = x;
            nota2 = y;
            ep_index = z;
            ref = t;
        }

        int notaMedia(){
            return ((nota1+nota2)/2);
        }
};

class temporada{
    private:
        int temp_index;
        std::vector<episodio*> episodios;
        serie *ref;

    public:
        void addep(episodio *e){
            episodios.push_back(e);
        }

        int getIndex(){
            return temp_index;
        }

    temporada(int temp_index, serie *s){
        this->temp_index = temp_index;
        ref = s;
    }

    int qualityCheck(){
        int counter = 0;
        for (episodio *e_aux : episodios){
            if(e_aux->notaMedia() < 5){
                counter++;
            }
        }
        return counter;
    }
};

class serie{
    private:
        std::string nome;
        std::vector<temporada*> temporadas;

    public:
        void addtemp(temporada* t){
            temporadas.push_back(t);
        }

    serie(std::string name){
        setName(name);
    }

    void setName(std::string name){
        nome = name;
    }

    void qualityCheck(){
        for (temporada *t_aux : temporadas){
                if(t_aux->qualityCheck()==0){
                    std::cout << "temporada " << t_aux->getIndex() << " e perfeita\n";
                }
                else if(t_aux->qualityCheck()==1){
                    std::cout << "temporada " << t_aux->getIndex() << " tem 1 episodio ruim\n";
                }
                else{
                    std::cout << "temporada " << t_aux->getIndex() << " tem " << t_aux->qualityCheck() << " episodios ruins\n";
                }
        }
    }
};

int main(){
    serie teste("amarelo");

    temporada t1(1, &teste);
    temporada t2(2, &teste);
    temporada t3(3, &teste);

    teste.addtemp(&t1);
    teste.addtemp(&t2);
    teste.addtemp(&t3);

    episodio e1(6, 6, 0, &t1);
    episodio e2(6, 6, 1, &t1);
    episodio e3(6, 6, 2, &t1);
    episodio e4(6, 6, 3, &t2);
    episodio e5(6, 6, 4, &t2);
    episodio e6(1, 1, 5, &t2);
    episodio e7(6, 6, 6, &t3);
    episodio e8(1, 1, 7, &t3);
    episodio e9(1, 1, 8, &t3);

    t1.addep(&e1);
    t1.addep(&e2);
    t1.addep(&e3);
    t2.addep(&e4);
    t2.addep(&e5);
    t2.addep(&e6);
    t3.addep(&e7);
    t3.addep(&e8);
    t3.addep(&e9);

    teste.qualityCheck();

    return 0;
}