#include <iostream>
using namespace std;

struct VW {     //agregação, composição, tipo produto
    int peso;
    int idade;
    char sexo;
};

double imc(VW &x, int ano){
    int resultado = x.peso/x.idade;
    return resultado;
}

VW ex = {78.0, 36, 'F'};
double i = imc(&ex, 2026);

class ZY {      
public:
    double peso;
    int idade;
    char sexo;
    double imc(int ano){
        double res = peso/idade;
        return res;
    }
};

ZY ex2 = {95.0, 29, 'M'};
double j = ex2.imc(2026);