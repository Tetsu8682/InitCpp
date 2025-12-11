#include "ensemble.hpp"

Ensemble::Ensemble(){
    for(int i = 0; i<50; i++){
        tab[i] = 0;
    }
    remplie = 0;
}

bool Ensemble::appartenance(int number) const{
    if(remplie == 0){
        std::cout << "Il n'y a encore aucun nombre dans l'ensemble." << std::endl;
        return false;
    }
    else{
        for(int i = 0; i<remplie; i++){
            if(tab[i] == number){
                return true;
            }
        }
        return false;
    }
}

void Ensemble::add(int number){
    if(remplie < 50){
        if(!(this->appartenance(number))){
            tab[remplie] = number;
            remplie ++;
        }
        else{
            std::cout << "Le nombre est déjà dans l'ensemble" << std::endl;
        }
    }
    else{
        std::cout << "L'ensemble a atteint sa taille maximale" << std::endl;
    }
}

void Ensemble::suppr(int number){
    if(this->appartenance(number)){
        int verif = 0;
        for(int i = 0; i<remplie ; i++){
            if(tab[i] == number){
                tab[i] = 0;
                verif = 1;
            }
            else if(verif == 1){
                tab[i-1] = tab[i];
            }
        }
        tab[remplie] = 0;
        remplie --;
    }
    else{
        std::cout << "Le nombre demandé n'est pas dans l'ensemble" << std::endl;
    }
}

void Ensemble::afficher(void) const{
    for(int i=0; i<remplie;i++){
        std::cout << "place " << i << ":" << tab[i] << std::endl;
    }
}

bool Ensemble::egalite(Ensemble e1) const{
    if(remplie == e1.remplie){
        for(int i = 0; i < remplie; i++){
            if(!(this->appartenance(e1.tab[i]))){
                std::cout<< "Les 2 ensembles sont différents" << std::endl;
                return false;
            }
        }
        std::cout<< "Les 2 ensembles sont égaux" << std::endl;
        return true;
    }
    else{
        std::cout << "Les 2 ensembles ne sont pas de la même taille" << std::endl;
        return false;
    }
}

/*
Je suis pas convaincu de ma fonction.
Je ne sais pas comment créer un tableau de taille exacte sans paroucrir deux fois la liste.
*/
void Ensemble::intersection(Ensemble e1) const{
    Ensemble intersection;
    for(int i=0; i<remplie; i++){
        if(this->appartenance(e1.tab[i])){
            intersection.add(e1.tab[i]);
        }
    }
    intersection.afficher();
}

bool est_premier(int number){
    for(int i=2; i<=sqrt(number); i++){
        if(number%i == 0){
            return false;
        }
    }
    return true;
}

Ensemble Ensemble::premier() const{
    Ensemble premier;
    for(int i=0; i<remplie; i++){
        if(est_premier(tab[i])){
            premier.add(tab[i]);
        }
    }
    return premier;
}