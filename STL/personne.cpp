#include "personne.hpp"

personne::personne(int new_age, std::string name)
    :nom(name), age(new_age)
{
}

void personne::affichage(void) const{
    std::cout << "Nom : " << nom << std::endl;
    std::cout << "Age : " << age << std::endl;
}

int personne::getAge(void) const{
    return age;
}

bool ComparatePersonne::operator()(const personne& p1, const personne&p2){
    if(p1.getAge() >= p2.getAge()){
        return true;
    }
    else{
        return false;
    }
}