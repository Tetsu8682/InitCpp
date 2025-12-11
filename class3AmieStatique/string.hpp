#pragma once


class String
{
    public:
        String(const char* chaine);
        String(const String& s2);
        ~String();
        void affichage(void) const;
        void upper(void);
        bool estEgal(const String& str2);
    private:
        char* ch;
        int taille;
};