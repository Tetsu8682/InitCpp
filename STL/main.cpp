#include "personne.hpp"
#include "figure.hpp"
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <list>

void ReadFile_Vector(std::vector<personne> *current){
    std::ifstream fic("info.txt");
    int age;
    std::string name;
    while(!fic.eof()){
        fic >> name >> age;
        personne newP(age,name);
        current->push_back(newP);
    }
    fic.close();
}

void PrintVect(std::vector<personne> *current){
    std::vector<personne>::iterator it;
    for(it = current->begin(); it < current->end() ; it ++){
        it->affichage();
    }
}

std::map<std::string,personne> ReadFile_Map(void){
    std::map<std::string,personne> map1;
    std::ifstream fic("info.txt");
    int age;
    std::string name;
    while(!fic.eof()){
        fic >> name >> age;
        personne newP(age,name);
        std::pair<std::string, personne> nouvelElement(name, newP);
        map1.insert(nouvelElement);
    }
    fic.close();
    return map1;
}

void PrintMap(std::map<std::string, personne> map1){
    std::map<std::string, personne>::iterator it;
    for(it = map1.begin(); it != map1.end() ; it ++){
        it->second.affichage();
    }
}

std::list<Point> ReadFile_List(void){
    std::list<Point> l1;
    std::ifstream fic("point.txt");
    float x;
    float y;
    while(!fic.eof()){
        fic >> x >> y;
        Point newP(x,y);
        l1.push_back(newP);
    }
    fic.close();
    return l1;
}

void PrintList(std::list<Point> l1){
    std::list<Point>::iterator it;
    for(it = l1.begin(); it != l1.end() ; it ++){
        it->affichage();
    }
}

void DeleteMostFarPoint(std::list<Point>& l1){
    Point origine(0,0);
    std::list<Point>::iterator Max = l1.begin();
    std::list<Point>::iterator it = l1.begin();
    float distance = 0;
    float distanceMax = it->distance(origine);
    for(it = l1.begin(); it != l1.end() ; it ++){
        distance = it->distance(origine);
        if(distance > distanceMax){
            distanceMax = distance;
            Max = it;
        }
    }
    l1.erase(Max);
}

void AddBeforeP1(std::list<Point>& l1, Point p1, Point p2){
    std::list<Point>::iterator it = l1.begin();
    for(it = l1.begin(); it !=l1.end() ; it++){
        if(it->getX() == p1.getX() && it->getY() == p1.getY()){
            l1.insert(it, p2);
            break;
        }
    }
    std::cout << "Le point p1 n'existe pas" << std::endl;
}
int  main(void){
    int choix;
    std::cout << "Que souhaitez vous faire? \n 1:Création d'un vecteur et trie par l'âge. \n 2 : Créez une map et l'afficher. \n 3:créer une liste et l'afficher.";
    std::cin >> choix;
    if(choix == 1){
        std::vector<personne> vect;
        ReadFile_Vector(&vect);
        PrintVect(&vect);
        std::sort(vect.begin(),vect.end(),ComparatePersonne());
        PrintVect(&vect);
    }
    else if(choix == 2){
        std::map<std::string, personne> map1 = ReadFile_Map();
        PrintMap(map1);
    }
    else{
        std::list<Point> l1 = ReadFile_List();
        PrintList(l1);
        DeleteMostFarPoint(l1);
        PrintList(l1);
        Point p1(8, 19.45);
        Point p2(3, 4);
        AddBeforeP1(l1, p1 , p2);
        PrintList(l1);
    }
    return 1;
}