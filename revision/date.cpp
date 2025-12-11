#include "date.hpp"


SimpleDate::SimpleDate()
    :jour(0),mois(0),annee(0)
{
}

SimpleDate::SimpleDate(int n1,int n2,int n3)
    :jour(n1),mois(n2),annee(n3)
{
}

void SimpleDate::setjour(int n1){
    jour = n1;
}

void SimpleDate::setmois(int n1){
    mois = n1;
}

void SimpleDate::setannee(int n1){
    annee = n1;
}

int SimpleDate::getjour(void) const{
    return jour;
}

int SimpleDate::getmois(void) const{
    return mois;
}

int SimpleDate::getannee(void) const{
    return annee;
}

bool SimpleDate::estnull(void) const{
    if(jour == 0 && mois == 0 && annee == 0){
        return true;
    }
    else{
        return false;
    }
}

bool Date::operator<(Date d1) const{
    if(annee < d1.getannee()){
        return true;
    }
    else if(annee == d1.getannee()){
        if(mois < d1.getmois()){
            return true;
        }
        else if(mois == d1.getmois()){
            if(jour<d1.getjour()){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
    return false;
}
Date::Date()
    :SimpleDate()
{
};

Date::Date(int n1, int n2, int n3)
    :SimpleDate(n1, n2, n3)
{
};

ostream& operator<<(ostream &flux, Date d1){
    flux<< "Jour: " << d1.getjour() << "\n" << "Mois: " << d1.getmois() << "\n" << "Annee :" << d1.getannee();
    return flux;
}

istream& operator>>(istream &flux, Date d1){
    flux>> d1.jour >> d1.mois >> d1.annee;
    return flux;
}

bool Date::operator==(Date d1){
    if(jour == d1.jour && mois== d1.mois && annee == d1.annee) return true;
    else return false;
}

ListeDates::ListeDates()
{
}

void ListeDates::add(Date d1){
    dates.push_back(d1);
}

void ListeDates::add(const char *nameF) const{
    ofstream fic(nameF);
    int taille = dates.size();
    for(int i=0;i<taille; i++){
        fic<< dates[i].getjour() << " " << dates[i].getmois() << " " << dates[i].getannee() << endl;
    }
}

void ListeDates::afficher(void) const{
    vector<Date>::const_iterator it;
    for(it = dates.begin(); it != dates.end(); it++){
        cout << *it << endl;
    }
}

EnsembleDates::EnsembleDates()
{
}

void EnsembleDates::add(Date d1){
    pair<Date,Date> nouvelElem(d1,d1);
    dates.insert(nouvelElem);
}


