#include <iostream>

int main(){
    std::cout << "hello" << std::endl;
    int vezes;
    std::cout << "digite: ";
    std::cin >> vezes;
    for(int i = 0; i < vezes; i++){
        std::cout << "caguei";
    }
    std::cout << std::endl;
}