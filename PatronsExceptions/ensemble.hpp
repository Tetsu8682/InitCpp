
#pragma once 
#include <iostream>
#include <cmath>
#define TAILLE 5
#include "exception.hpp"

template <class T>
class Ensemble
{
    public:
        Ensemble();
        void afficher() const;
        bool appartenance(T val) const;
        void add(T val);
    private:
        int remplie;
        T tab[TAILLE];
};

template <class T>
Ensemble<T>::Ensemble()
    :remplie(0)
{
}

template <class T>
void Ensemble<T>::afficher(void) const{
    for(int i=0; i<remplie; i++){
        cout<< tab[i] << endl;
    }
}

template <class T>
bool Ensemble<T>::appartenance(T val) const{
    if(remplie == 0){
        std::cout << "Il n'y a encore aucun nombre dans l'ensemble." << std::endl;
        return false;
    }
    else{
        for(int i = 0; i<remplie; i++){
            if(tab[i] == val){
                return true;
            }
        }
        return false;
    }
}

template <class T>
void Ensemble<T>::add(T val){
    if(remplie < TAILLE){
        if(!(this->appartenance(val))){
            tab[remplie] = val;
            remplie ++;
        }
        else{
            std::cout << "Le nombre est déjà dans l'ensemble" << std::endl;
        }
    }
    else{
        MyException depassement("L'ensemble a atteint sa taille maximale");
        throw depassement;
    }
}

bool est_premier(int number);
