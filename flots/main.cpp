#include "../s3/figure.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "rectangle.hpp"

void lectureFichier(const char* title, int limite){
    Point origine(0,0);
    std::ifstream fic1(title);
    std::ofstream fic2("retenue.txt"); // Créer le fichier une seule fois
    int compte = 0;
    while(!fic1.eof()){
        float x, y;
        fic1 >> x >> y;
        Point test(x,y);
        float distanceO = test.distance(origine);
        if(distanceO < limite){
            fic2 << compte << ": ( " << test.getX() << " ; " << test.getY() << " ) d=" << distanceO << "\n";
            compte ++;
        }
    }
    fic1.close();
    fic2.close();
}


int main(void){
    Point point1(0,1);
    Point point2(3,7);
    Segment seg(point1,point2);
    Carre car(seg);
    Rectangle test(seg, 30);
    Cercle cer(point1, 15);
    ListeFormes test2;
    test2.Chainer(&car);
    test2.Chainer(&test);
    test2.Chainer(&cer);
    test2.afficherMax();
    return 1;
}