#include "rectangle.hpp"
#include <iostream>

Forme::Forme(void)
    :suiv(nullptr)
{
}
Cercle::Cercle(const Point& origine, double longueur)
    :Forme(),centre(origine), rayon(longueur), type("cercle")
{
}

double Cercle::perimetre(void) const{
    return 2*PI*rayon;
}

double Cercle::surface(void) const{
    return PI*rayon*rayon;
}

void Cercle::afficher(void) const{
    std::cout << "Type de figure : " << type << std::endl;
    std::cout << "perimetre : " << this->perimetre() << std::endl;
    std::cout << "surface : " << this->surface() << std::endl;
}

Rectangle::Rectangle(const Segment& seg, double high)
    :Forme(),type("Rectangle"), base(seg), hauteur(high) 
{
}
double Rectangle::perimetre(void) const{
    return base.longueur()*2+hauteur*2;
}

double Rectangle::surface(void) const{
    return base.longueur()*hauteur;
}

void Rectangle::afficher(void) const{
    std::cout << "Type de figure : " << type << std::endl;
    std::cout << "perimetre : " << this->perimetre() << std::endl;
    std::cout << "surface : " << this->surface() << std::endl;
}

Carre::Carre(const Segment& seg)
    :Rectangle(seg, seg.longueur()), type("Carré")
{
}

void Carre::afficher(void) const{
    std::cout << "Type de figure : " << type << std::endl;
    std::cout << "perimetre : " << this->perimetre() << std::endl;
    std::cout << "surface : " << this->surface() << std::endl;
}

ListeFormes::ListeFormes()
    :racine(nullptr)
{
}

void ListeFormes::Chainer(Forme *nouveau){
    if(racine == nullptr){
        racine = nouveau;
    }
    else{
        Forme *current = racine;
        while(current->suiv != nullptr){
            current = current->suiv;
        }
        current->suiv = nouveau;
    }
}

void ListeFormes::afficherMax(void) const{
    Forme *current = racine;
    Forme *PerM = racine;
    Forme *SurM = racine;
    double perimetre_m = racine->perimetre();
    double surface_m = racine->surface();
    double perimetre_t;
    double surface_t;
    while(current != nullptr){
        perimetre_t = current->perimetre();
        surface_t = current->surface();
        if(perimetre_t > perimetre_m){
            perimetre_m = perimetre_t;
            PerM = current;
        }
        if(surface_t > surface_m){
            surface_m = surface_t;
            SurM = current;
        }
        current = current->suiv;
    }
    std::cout << "Forme au plus grand perimètre" << std::endl;
    PerM->afficher();
    std::cout << "Forme a la plus grande surface" << std::endl;
    SurM->afficher();
}