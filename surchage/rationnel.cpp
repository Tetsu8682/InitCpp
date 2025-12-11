#include "rationnel.hpp"
#include <iostream>


int PGCD(int num, int den){
    int reste = num%den;
    if(reste == 0){
        return den;
    }
    else{
        return PGCD(den, reste);
    }
}

Rationnel::Rationnel(long new_num, long new_den = 1)
{
    int pgcd = PGCD(new_num, new_den);
    num = new_num/pgcd;
    den = new_den/pgcd;
};

Rationnel::Rationnel(long new_num)
    :num(new_num)
{
};

void Rationnel::afficher(void) const{
    std::cout << num << "/" << den << std::endl;
};

Rationnel Rationnel::operator+(const Rationnel& r2) const{
    Rationnel r3(num*r2.den + r2.num*den, den*r2.den);
    return r3;
};

Rationnel Rationnel::operator-(const Rationnel& r2) const{
    Rationnel r3(num*r2.den - r2.num*den, den*r2.den);
    return r3;
};

Rationnel Rationnel::operator*(const Rationnel& r2) const{
    Rationnel r3(num*r2.num, den*r2.den);
    return r3;
};

Rationnel Rationnel::operator/(const Rationnel& r2) const{
    Rationnel r3(num*r2.den, den*r2.num);
    return r3;
};

void Rationnel::operator+=(const Rationnel& r2){
    num = num*r2.den + r2.num*den;
    den = den*r2.den;
};

void Rationnel::operator-=(const Rationnel& r2){
    num = num*r2.den - r2.num*den;
    den = den*r2.den;
};

void Rationnel::operator*=(const Rationnel& r2){
    num = num*r2.num;
    den = den*r2.den;
};

void Rationnel::operator/=(const Rationnel& r2){
    num = num*r2.den;
    den = den*r2.num;
};

bool Rationnel::operator>(const Rationnel& r2){
    long num1 = num*r2.den;
    long num2 = r2.num*den;
    if(num1 > num2){
        return true;
    }
    else{
        return false;
    }
}

bool Rationnel::operator>=(const Rationnel& r2){
    long num1 = num*r2.den;
    long num2 = r2.num*den;
    if(num1 >= num2){
        return true;
    }
    else{
        return false;
    }
}

bool Rationnel::operator<(const Rationnel& r2){
    long num1 = num*r2.den;
    long num2 = r2.num*den;
    if(num1 < num2){
        return true;
    }
    else{
        return false;
    }
}

bool Rationnel::operator<=(const Rationnel& r2){
    long num1 = num*r2.den;
    long num2 = r2.num*den;
    if(num1 <= num2){
        return true;
    }
    else{
        return false;
    }
}

bool Rationnel::operator!=(const Rationnel& r2){
    long num1 = num*r2.den;
    long num2 = r2.num*den;
    if(num1 != num2){
        return true;
    }
    else{
        return false;
    }
}

bool Rationnel::operator==(const Rationnel& r2){
    long num1 = num*r2.den;
    long num2 = r2.num*den;
    if(num1 == num2){
        return true;
    }
    else{
        return false;
    }
}

float Rationnel::conversion(void) const{
    return (num/den);
}

std::ostream& operator<<(std::ostream &flux, const Rationnel& R){
    flux<<R.num << "/" << R.den;
    return flux;
}

