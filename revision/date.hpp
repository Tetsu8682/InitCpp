#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;


class SimpleDate{
    public:
        SimpleDate();
        SimpleDate(int ,int ,int );
        void setjour(int);
        void setmois(int);
        void setannee(int);
        int getjour(void) const;
        int getmois(void) const;
        int getannee(void) const;
        bool estnull(void) const;
    protected:
        int jour,mois,annee;
};

class Date:public SimpleDate{
    public:
        Date();
        Date(int ,int ,int );
        bool operator==(Date);
        bool operator<(Date d2) const;
        friend ostream& operator<<(ostream &, Date);
        friend istream& operator>>(istream &, Date);
    private:

};

class ListeDates{
    public:
        ListeDates();
        void add(Date);
        void add(const char *) const;
        void afficher(void) const;
    private:
        vector<Date> dates;
};

class EnsembleDates{
    public:
        EnsembleDates();
        void add(Date);
    private:
        map<Date,Date> dates;
};