#include "date.hpp"

int main(void){
    Date d3(2,3,4);
    Date d6(1,4,5);
    if(d3 == d6){
        cout << "let'sgo" << endl;
    }
    else{
        cout << "nooonnn" << endl;
    }
    ListeDates test;
    test.add(d3);
    test.add(d6);
    test.add("test.txt");
    test.afficher();
    return 1;
}