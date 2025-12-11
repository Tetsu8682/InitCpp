#include "ensemble.hpp"
#include "exception.hpp"
#include "rationnel.hpp"

int main(void){
    Ensemble<int> test;
    Ensemble<string> test2;
    try{
        for(int i = 0; i<5; i++){
            test.add(i);
            test2.add("LOL" + i);
        }
        test.afficher();
        test2.afficher();
        Rationnel R1(5,2);
        cout << R1 << endl;
    }
    catch(MyException depassement){
        cout << depassement << endl;
    }
    return 1;
}