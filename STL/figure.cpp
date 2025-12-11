#include "figure.hpp"
#include <iostream>
#include <cmath>

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(float coo_x, float coo_y){
    x = coo_x;
    y = coo_y;
}

float Point::getX() const{
    return x;
}

float Point::getY() const{
    return y;
}

void Point::setX(float nouveauX){
    x = nouveauX;
}

void Point::setY(float nouveauY){
    y = nouveauY;
}

void Point::affichage(void) const{
    std::cout << "x:" << this->getX() << std::endl;
    std::cout << "y:" << this->getY() << std::endl;
}

bool Point::egalite(Point p2) const{
    if(x == p2.x && y==p2.y){
        return true;
    }
    else{
        return false;
    }
}

float Point::distance(Point p2) const{
    return sqrt((x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y));
}

Segment::Segment(Point p1, Point p2):origine(p1),extremite(p2){
};

void Segment::affichage(void) const{
    std::cout << "origine" << std::endl;
    std::cout << "x:" << origine.getX() << "y:" << origine.getY() << std::endl;
    std::cout << "extremite" << std::endl;
    std::cout << "x:" << extremite.getX() << "y:" << extremite.getY() << std::endl;
}

void Segment::translation(Point new_origine){
    float tailleX = extremite.getX() - origine.getX();
    float tailleY = extremite.getY() - origine.getY();
    origine.setX(new_origine.getX());
    origine.setY(new_origine.getY());
    extremite.setX(origine.getX() + tailleX);
    extremite.setY(origine.getY() + tailleY);
}

float Segment::longueur(void) const{
    return origine.distance(extremite);
}

Polygone::Polygone(int nbPoint, Point tab_point[]){
    nbPointExtreme = nbPoint;
    tab = new Point[nbPoint];
    for(int i=0; i<nbPoint; i++){
        tab[i] = tab_point[i];
    }
}

Polygone::Polygone(int nbPoint){
    nbPointExtreme = nbPoint;
    tab = new Point[nbPoint];
}

Polygone::~Polygone(){
    delete [] tab;
}

void Polygone::affichage(void) const{
    for(int i=0; i<nbPointExtreme; i++){
        std::cout << "Point " << i << std::endl;
        std::cout << "x: " << tab[i].getX() << " y: " << tab[i].getY() << std::endl;
    }
}

float Polygone::perimetre(void) const{
    float perimetre = 0;
    for(int i=0; i<nbPointExtreme-1;i++){
        perimetre += tab[i].distance(tab[i+1]);
    }
    std::cout << "perimetre :" << perimetre << std::endl;
    return perimetre;
}

Point extreme(Point tableau[], int nbPoint){
    Point p = tableau[0];
    for(int i=0; i<nbPoint; i++){
        if(p.getX() > tableau[i].getX()){
            p = tableau[i];
        }
        else if(p.getX() == tableau[i].getX()){
            if(tableau[i].getY() > p.getY()){
                p = tableau[i];
            }
        }
    }
    return p;
}

Point choix(Point tableau[], int nbPoint, Point p){
    for(int i=0; i<nbPoint; i++){
        if(tableau[i].egalite(p) == 0){
            return tableau[i];
        }
    }
    return p;
}

Polygone Polygone::enveloppeConvexe(void) const{
    Polygone convexe(nbPointExtreme);
    int indice = 0;
    Point p0 = extreme(tab, nbPointExtreme); //permet de renvoyer le bon point
    Point p = p0;
    do{
        convexe.tab[indice] = p;
        Point q = choix(tab, nbPointExtreme, p);
        for(int i=0; i<nbPointExtreme; i++){
            if(((q.getX()-p.getX())*(tab[i].getY()-p.getY()) - (tab[i].getX() - p.getX())*(q.getY() -p.getY())) < 0){
                q = tab[i];
            }
        }
        p = q;
        indice ++;
    }while(p.egalite(p0) == 0);
    return convexe;
}


