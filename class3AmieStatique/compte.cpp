#include "compte.hpp"
#include <iostream>

int Compte::nb_compte = 0;
float Compte::rate = 0.1;
Compte* Compte::tete = nullptr;


Compte::Compte(const char* pers_name, int montant)
    :name(pers_name), suiv(nullptr)
    {
    balance = montant;
    if(tete == nullptr){
        tete = this;
    }
    else{
        this->suiv = tete;
        tete = this; 
    }
    nb_compte ++;
}
/*
Compte::~Compte(void){
    if(this == tete){
        if(tete->suiv == nullptr){
            tete = nullptr;
        }
        else{
            tete = tete->suiv;
        }
    }
    else{
        Compte* current = tete;
        while(current->suiv != this){
            current = current->suiv;
        }
        current->suiv = this->suiv;
    }
    nb_compte --;
}
*/

Compte::~Compte ()
{
    Compte* prec = 0;
    Compte* compte = tete;

    /* parcours de la liste a la recherche du compte, tout en gardant trace de
     * son precedent
     */
    while (compte != this) // la recherche est faite en comparant les adresses
    {
        prec = compte; 
        compte = compte->suiv;
    }

    // on sort necessairement de la boucle en ayant trouve le compte

    /* on supprime le compte de la liste en chainant son precedent sur son
     * suivant, ou en chainant la tete de liste sur son suivant s'il n'a pas de
     * precedent
     */
    if (prec != 0)
        prec->suiv = compte->suiv;
    else
        tete = compte->suiv;
}

void Compte::versement(int addition){
    balance += addition;
}

void Compte::update(void){
    if(nb_compte == 0){
        std::cout << "Il n'y a aucun compte enregistré" << std::endl;
    }
    else{
        Compte* current = tete;
        while(current != nullptr){
            current->balance += (current->balance*rate);
            current = current->suiv;
        }
    }
}

void Compte::affichage(void){
    if(nb_compte == 0){
        std::cout << "Il n'y a aucun compte enregistré" << std::endl;
    }
    else{
        Compte* current = tete; 
        while(current != nullptr){
            std::cout << "Propriétaire : " << std::endl;
            current->name.affichage();
            std::cout << "Solde : " << std::endl;
            std::cout << current->balance << std::endl;
            current = current->suiv;
        }
    }
}