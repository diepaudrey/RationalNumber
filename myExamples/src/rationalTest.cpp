//haaaaa
#include "Rational.hpp" 
#include <iostream>


int main(){
    
    //initialize tests
    Rational<int> fraction(8,2);
    std::cout << "fraction : " << fraction << std::endl;

    std::cout << "irreducible fraction : " << fraction.irreducibleFraction() << std::endl;

    //copy constructor
    Rational<int> fraction2(4,2);
    
    Rational<int> fraction3 = fraction - fraction2;
    //std::cout << "numerateur3 : " << fraction3.m_numerator << std::endl;
    //std::cout << "deno3 : " << fraction3.m_denominator << std::endl;

    std::cout << fraction << " - " << fraction2 << " = " << fraction3 << std::endl;


    //testing comparative operators
    bool result = fraction!=fraction2;
    std::cout << result << std::endl; 

    bool result2 = fraction<fraction2;
    std::cout << result2 << std::endl; 

    Rational<int> fraction4(-2,-1);

    std::cout << fraction4 << std::endl;
    std::cout << -fraction4 << std::endl;
    std::cout << fraction4 << std::endl;
    std::cout << fraction4.vabs() << std::endl;
    std::cout << fraction4 << std::endl;

    if (fraction4 == fraction2)
    {
        std::cout << "wouw" << std::endl;
    }
    else{
        std::cout << ":(" << std::endl;
    } 
    

    return 0;
}