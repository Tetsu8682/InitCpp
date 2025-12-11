#pragma once
#include <iostream>
#include <string>


class personne{
    public:
        personne(int new_age, std::string name);
        void affichage(void) const;
        int getAge(void) const;
    private:
        std::string nom;
        int age;
};

class ComparatePersonne{
    public:
        bool operator()(const personne& p1, const personne&p2);
    private:
};