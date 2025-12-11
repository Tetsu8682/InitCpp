#pragma once
#include "../s3/figure.hpp"
#include <iostream>
#define PI 3.14

class Forme{
    public:
        Forme(void);
        virtual void afficher(void) const = 0;
        virtual double perimetre(void) const {return 0;};
        virtual double surface(void) const {return 0;};
        Forme *suiv;
};

class Cercle
    :public Forme
{
    public:
        Cercle(const Point& origine, double longueur);
        double perimetre(void) const override;
        double surface(void) const override;
        void afficher(void) const override;
    private:
        Point centre;
        double rayon;
        const char* type;
};

class Rectangle:public Forme{
    public:
        Rectangle(const Segment& seg, double high);
        double perimetre(void) const override;
        double surface(void) const override;
        void afficher(void) const override;
    private:
        const char* type;
        Segment base;
        double hauteur;
};

class Carre:public Rectangle{
    public:
        Carre (const Segment& seg); 
        void afficher(void) const override;
    private:
        const char* type;
};

class ListeFormes{
    public:
        ListeFormes();
        void Chainer(Forme *);
        void afficherMax() const;
    private:
        Forme *racine;
};