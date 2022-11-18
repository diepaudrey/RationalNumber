//rational laugh
#include "Rational.hpp"
#include <iostream>

int pgcd(int a, int b){
    int rest;
    if (b==0){
        return a;
    }
    rest = a%b;
    while (rest!=0){
        a=b;
        b=rest;
        rest=a%b;
    }
    return b;
}



