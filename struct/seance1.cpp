#include "seance1.hpp"

//PARTIE I

Date* initialise_date(void){
    Date* current = new Date;
    current->annee = ANNEE_DE_BASE;
    current->mois = 5;
    current->jour = 4;
    return current;
}

bool compare(Date* date1, Date* date2){
    if(date1->annee == date2->annee && date1->mois == date2->mois && date1->jour == date2->jour){
        return true;
    }
    else{
        return false;
    }
}

void surcharge(Date* current, int annee, int mois, int jour){
    current->annee = annee;
    current->mois = mois;
    current->jour = jour;
}
void affiche_date(Date* current){
    std::cout <<"annee : " << current->annee << std::endl;
    std::cout <<"mois : " << current->mois << std::endl;
    std::cout <<"jour : " << current->jour << std::endl;
}

//Partie II

ListeDates* initialise_ListeDates(int nb_jours){
    ListeDates* current = new ListeDates;
    current->nbjours = nb_jours;
    current->dat = new Date[nb_jours];
    for(int i = 0;i<nb_jours; i++){
        current->dat[i].annee = ANNEE_DE_BASE + i;
        current->dat[i].mois = 1;
        current->dat[i].jour = 1;
    }
    return current;
}

void affiche_ListeDates(ListeDates* current){
    int nb_jours = current->nbjours;
    std::cout << "nombre de jours" << nb_jours <<std::endl;
    for(int i = 0; i<nb_jours; i++){
        std::cout << "jour : " << i << std::endl;
        affiche_date(&current->dat[i]);
    }
}

void modifie_listeDates(ListeDates* current, int position, int annee, int mois, int jour){
    surcharge(&current->dat[position],annee,mois,jour);
}

void libere_listeDates(ListeDates* current){
    delete [] current->dat;
    delete current;
}

int main(void){
    ListeDates* test = initialise_ListeDates(5);
    affiche_ListeDates(test);
    modifie_listeDates(test, 3, 1969, 2, 9);
    affiche_ListeDates(test);
    libere_listeDates(test);
    return 0;
}