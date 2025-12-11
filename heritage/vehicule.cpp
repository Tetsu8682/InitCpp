#include "vehicule.hpp"
#include <iostream>
#include <cstring>

//Constructeur de ma classe Vehicule
Vehicule::Vehicule(const char* no, int Fisc, int NumWheels, Couleur c)
    :FiscalPower(Fisc),NbWheels(NumWheels),color(c)
    {
        strcpy(name, no);
    }

//Affiche les caractéristiques de mon véhicule
void Vehicule::afficher(void) const{
    std::cout << "Nom : " << name << std::endl;
    std::cout << "Puissance fiscale : " << FiscalPower << std::endl;
    std::cout << "Nombre de roues : " << NbWheels << std::endl;
    std::cout << "Couleur : " << couleurToString(color) << std::endl;
}

Moto::Moto(const char* nameMoto, int FiscMoto, Couleur colorMoto, int enginemoto)
    :Vehicule(nameMoto, FiscMoto, 2, colorMoto),engine(enginemoto)
    {
    };

void Moto::afficher(void) const{
    Vehicule::afficher();
    std::cout << "Cylindrée : " << engine << std::endl;
}

Voiture::Voiture(const char* nameVoiture, int FiscVoiture, Couleur colorVoiture, int nbPlaceVoiture)
    :Vehicule(nameVoiture,FiscVoiture,4,colorVoiture),nbPlace(nbPlaceVoiture)
{
}

void Voiture::afficher(void) const{
    Vehicule::afficher();
    std::cout << "Nombre de place dans la voiture : " << nbPlace << std::endl;
}

const char* couleurToString(Couleur c) {
    switch(c) {
        case ROUGE: return "ROUGE";
        case VERT:  return "VERT";
        case BLEU:  return "BLEU";
        default:    return "INCONNU";
    }
}

listePtrVehicules::listePtrVehicules(void){
    remplie = 0;
}

void listePtrVehicules::ajout(Vehicule *newVehicule){
    tab[remplie] = newVehicule;
    remplie ++;
}

void listePtrVehicules::afficher(void) const{
    for(int i=0; i<remplie; i++){
        tab[i]->afficher();
    }
}