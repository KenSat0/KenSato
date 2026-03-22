#include <iostream>

struct MK{
    int a, b, c;
};

void f(MK x){
    cout << x.a << x.b << x.c;
}

void g(MK *y){
    cout << (*y).a << (*y).b << (*y).c;
}

void h(MK &z){
    cout << z.a << z.b << z.c;
}

int main(){
    MK s = {10, 100, 1000};
    f(s);
    g(&s);
    h(s);
}