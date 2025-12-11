#include "vehicule.hpp"



int main(void){
    Moto test2("LOL", 14, ROUGE, 133);
    Voiture test3("MDR" , 23, VERT,5);
    Vehicule *test4 = &test2;
    Vehicule *test5 = &test3;
    listePtrVehicules liste;
    liste.ajout(test4);
    liste.ajout(test5);
    liste.afficher();
    return 1;
}
