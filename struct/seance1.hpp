#include <iostream>
#define ANNEE_DE_BASE 2020

struct Date
{
    int jour;
    int mois;
    int annee;
};

struct ListeDates
{
    int nbjours;
    Date* dat;
};

Date* initialise_date(void);
bool compare(Date* date1, Date* date2);
void surcharge(Date* current, int annee, int mois, int jour);
void affiche_date(Date* current);
ListeDates* initialise_ListeDates(int nb_jours);
void affiche_ListeDates(ListeDates* current);
void modifie_listeDates(ListeDates* current, int position, int annee, int mois, int jour);
void libere_listeDates(ListeDates* current);