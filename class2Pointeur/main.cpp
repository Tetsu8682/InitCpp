#include "figure.hpp"
#include <iostream>

int main(void){
    Point p1(0,0);
    Point p2(0,4);
    float d = p1.distance(p2);
    std::cout << d << std::endl;
    return 1;
}