#pragma once
#include <iostream>
#include "exception.hpp"

class Rationnel
{
    public:
        Rationnel(long new_num, long now_den);
        Rationnel(long new_num);
        void afficher(void) const;
        Rationnel operator+(const Rationnel& r2) const;
        Rationnel operator-(const Rationnel& r2) const;
        Rationnel operator*(const Rationnel& r2) const;
        Rationnel operator/(const Rationnel& r2) const;
        void operator+=(const Rationnel& r2);
        void operator-=(const Rationnel& r2);
        void operator*=(const Rationnel& r2);
        void operator/=(const Rationnel& r2);
        bool operator>(const Rationnel& r2);
        bool operator>=(const Rationnel& r2);
        bool operator<(const Rationnel& r2);
        bool operator<=(const Rationnel& r2);
        bool operator==(const Rationnel& r2);
        bool operator!=(const Rationnel& r2);
        float conversion(void) const;
        friend std::ostream& operator<<(std::ostream &flux, const Rationnel& R);
    private:
        long num;
        long den;
};