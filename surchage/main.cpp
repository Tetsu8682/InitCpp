#include "rationnel.hpp"
#include <iostream>
#include <cmath>

//je sais pas
void suite_u(int q, int n){
    Rationnel u(1);
    for(int i=1; i<n; i++){
        u += Rationnel(1,pow(q,i));
        std::cout << u << std::endl;
        std::cout << u.conversion() << std::endl;
    }
}

void suite_double(int n){
    if(n>0){
        Rationnel u(2);
        Rationnel v(2,2);
        for(int i=0; i<n; i++){
            Rationnel verif = u - v;
            std::cout << verif << std::endl;
            if(verif < Rationnel(1, pow(4,i))){
                std::cout << "La condition est vérifié" << std::endl;
            }
            else{
                std::cout << "La condition n'est pas vérifié";
            }
            u = (u + v)/2;
            v =  Rationnel(2)/u;
        }
    }
    else{
        std::cout << "n doit être sup à 0" << std::endl;
    }
}

int main(void){
    suite_u(10,5);
    Rationnel R(3,7);
    std::cout << R << std::endl;
    return 1;
}