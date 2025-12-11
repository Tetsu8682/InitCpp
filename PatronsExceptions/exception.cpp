#include "exception.hpp"

MyException::MyException(string mess)
    :message(mess)
{
}

ostream& operator<<(std::ostream &flux, const MyException& R){
    flux<<R.message;
    return flux;
}