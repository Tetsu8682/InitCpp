#include "ensemble.hpp"


int main(void){
    Ensemble test;
    test.add(4);
    test.add(7);
    test.add(8);
    Ensemble test2 = test.premier();
    test2.afficher();
}