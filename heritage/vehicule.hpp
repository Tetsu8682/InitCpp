#pragma once

#define TAILLENOM 32
#define TAILLELISTE 50

//Enumération des différentes couleurs possibles
enum Couleur{
    ROUGE,
    BLEU,
    VERT
};

//Définition de la classe mère véhicule
class Vehicule {
    //Empêche la création direct de la classe véhicule, seulement les classes fils nous intéresse
    protected:
        Vehicule(const char* nameCar, int Fisc, int NumWheels, Couleur colorCar);
    public:
        //fonction d'affichage des caractéristiques du véhicules
        void afficher(void) const;
    private:
        //Caractéristique du véhicule
        char name[TAILLENOM];
        int FiscalPower;
        int NbWheels;
        Couleur color;
};

//Définition de la classe fils Moto de véhicule
class Moto:public Vehicule{
    public:
        //Constructeur de l'objet moto
        Moto(const char* nameMoto, int FiscMoto, Couleur colorMoto, int enginemoto);
        //Affichage des caractéristqiues de la moto
        void afficher(void) const;
    private:
        //Caractéristiques spécifique à la moto
        int engine;
};

//Définition de la classe fils Voiture
class Voiture:public Vehicule{
    public:
        //Constructeur de la classe fils Voiture
        Voiture(const char* nameVoiture, int FiscVoiture, Couleur colorVoiture, int nbPlaceVoiture);
        //Affiche les caractéristiques de la voiture
        void afficher(void) const;
    private:
        //Caractéristiques spécifiques à la voiture
        int nbPlace;
};

//Classe listant l'ensemble des véhicules
class listePtrVehicules{
    public:
        //Constructeur de cette classe initalisant seulement le nombre de case remplie (c'est à dire 0)
        listePtrVehicules(void);
        //Ajoute une véhicule à la liste
        void ajout(Vehicule *newVheicule);
        //Affiche l'ensemble de la liste
        void afficher(void) const;
    private:
        //Tableau de pointeur de véhicule
        Vehicule *tab[TAILLELISTE];
        int remplie;
};

const char* couleurToString(Couleur c);