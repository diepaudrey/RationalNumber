//haaaaa
#include "Rational.hpp" 
#include <iostream>

int main(){
    
    //initialize tests
    Rational<int> fraction(1,-5);

    //copy constructor
    Rational<int> fraction2(1,-2);

    int i = pgcd(12,4);
    //std::cout << i << std::endl;

    Rational<int> fraction3 = fraction/fraction2;
    //std::cout << fraction3 << std::endl;

    Rational<int> fraction4(1,-3);
    std::cout << fraction4.vabs() << std::endl;
    std::cout << fraction4 << std::endl;
    std::cout << -fraction4 << std::endl;
    



    return 0;
}