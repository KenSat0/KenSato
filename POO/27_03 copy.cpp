#include <iostream>

class Camara{
    public:
        int id;
        bool nao_furada;
        Camara(int i, bool st);
};

class bike{
    int id;
    Camara frente;
    Camara tras;
    bike(int i, Camara f, Camara t);
};
