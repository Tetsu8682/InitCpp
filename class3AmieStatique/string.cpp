#include "string.hpp"
#include <cstring>
#include <cctype>
#include <iostream>

String::String(const char* chaine){
    taille = strlen(chaine);
    ch = new char[taille+1];
    strcpy(ch, chaine);
}

String::String(const String& s1){
    taille = s1.taille;
    ch = new char[taille];
    strcpy(ch, s1.ch);
}

String::~String(){
    delete[] ch;
}

void String::affichage() const{
    std::cout<<this->ch << std::endl;
}

void String::upper(void){
    for(int i = 0; i < taille; i++){
        ch[i] = toupper(ch[i]);
    }
}

bool String::estEgal(const String& str2){
    if(taille == str2.taille){
        for(int i = 0; i < taille; i++){
            if(ch[i] != str2.ch[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

