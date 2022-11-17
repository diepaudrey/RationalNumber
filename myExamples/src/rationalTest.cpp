//haaaaa
#include "Rational.hpp" 
#include <iostream>

int main(){
    
    //initialize tests
    Rational<int> fraction(1,5);
    //std::cout << "numerateur : " << fraction.m_numerator << std::endl;
    //std::cout << "deno : " << fraction.m_denominator << std::endl;

    //copy constructor
    Rational<int> fraction2(1,2);

    Rational<int> fraction3 = fraction/fraction2;
    //std::cout << "numerateur3 : " << fraction3.m_numerator << std::endl;
    //std::cout << "deno3 : " << fraction3.m_denominator << std::endl;

    std::cout << fraction3 << std::endl;

    return 0;
}