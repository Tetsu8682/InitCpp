#pragma once
#include "string.hpp"


class Compte
{
    public:
        Compte(const char* personnal_name, int montant);
        ~Compte(void);
        void versement(int addition);
        static void update(void);
        static void affichage(void);
    private:
        String name;
        int balance;
        Compte *suiv;
        static int nb_compte;
        static float rate;
        static Compte* tete;
};