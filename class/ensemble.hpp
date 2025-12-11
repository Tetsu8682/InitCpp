#include <iostream>
#include <cmath>
#define TAILLE 50


class Ensemble
{
    public:
        Ensemble();
        void afficher() const;
        bool appartenance(int number) const;
        void add(int number);
        void suppr(int number);
        bool egalite(Ensemble e1) const;
        void intersection(Ensemble e1) const;
        Ensemble premier() const;
    private:
        int remplie;
        int tab[TAILLE];
};

bool est_premier(int number);
