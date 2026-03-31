#include <iostream>

class Animal{
    public:
        bool vivo = true;
    void comer(){
        std::cout << "comeu\n"; 
    }
};

class Cachorro : public Animal{
    public:
        void latir(){
            std::cout << "auau\n";
        }
};

class Gato : public Animal{
    public:
        void miar(){
            std::cout << "miau\n";
        }
};

int main(){
    Cachorro dog1;
    Gato cat1;

    std::cout << dog1.vivo << '\n';
    cat1.miar();

    return 0;
}