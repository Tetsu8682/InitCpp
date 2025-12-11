#pragma once
#include <string>
using namespace std;

class MyException{
    public:
        MyException(string mess);
        friend std::ostream& operator<<(std::ostream &flux, const MyException& R);
    private:
        string message;
};