//haaaaa
#include "Rational.hpp" 
#include <iostream>


int main(){
#if 0
    //initialize tests
    Rational<int> fraction(21,5);
    std::cout << "fraction : " << fraction << std::endl;

    std::cout << "irreducible fraction : " << fraction.irreducibleFraction() << std::endl;

    //copy constructor
    Rational<int> fraction2(4,2);
    
    Rational<int> fraction3 = fraction - fraction2;
    //std::cout << "numerateur3 : " << fraction3.m_numerator << std::endl;
    //std::cout << "deno3 : " << fraction3.m_denominator << std::endl;

    std::cout << fraction << " - " << fraction2 << " = " << fraction3 << std::endl;


    //testing comparative operators
    //bool result = fraction!=fraction2;
    //std::cout << result << std::endl; 

    bool result2 = fraction<fraction2;
    std::cout << result2 << std::endl; 

    Rational<int> fraction4(-2,-1);

    std::cout << fraction4 << std::endl;
    std::cout << -fraction4 << std::endl;
    std::cout << fraction4 << std::endl;
    std::cout << fraction4.inverse() << std::endl;
    std::cout << fraction4.vabs() << std::endl;
    std::cout << fraction4 << std::endl;

    if (fraction4 == fraction2)
    {
        std::cout << "wouw" << std::endl;
    }
    else{
        std::cout << ":(" << std::endl;
    } 

    //Test integerPart 
    // double x = 1252.765;
    // double fracPart, intPart;
    // fracPart = modf(x,&intPart);
    // std::cout << "fraction4 = " << fraction2 << std::endl;
    // std::cout << "int part of fraction4 : " << Rational<int>::intPart(x) << " vs " << intPart << std::endl;

    
    double test = -899.26;
    Rational<int> result = Rational<int>::convertFloatRatio(test,10);
    std::cout << result << std::endl;
    std::cout << (double)result.getNumerator()/result.getDenominator() << std::endl;

    // //troncature test 
    // double x = 0.1256389975;
    // std::cout <<"x = "<<  x << std::endl;
    // std::cout <<"troncature de x = " << troncature(x) << std::endl;


    //product between Ratio and double 
    // std::cout << "Product between rational and double : \n " << std::endl;
    // Rational<int> res_prod = fraction*test;
    // double inFloat = (double)fraction.getNumerator()/fraction.getDenominator();
    // std::cout << test << " * " << fraction << " = " << res_prod << std::endl;
    // std::cout << "Product in float = " << (double)res_prod.getNumerator()/res_prod.getDenominator()<< std::endl;
    // std::cout << test << " * " << inFloat  << " = " << test*inFloat << std::endl;

    // std::cout << "Product between rational and double : \n " << std::endl;
    // Rational<int> res_prod = test*fraction;
    // double inFloat = (double)fraction.getNumerator()/fraction.getDenominator();
    // std::cout << test << " * " << fraction << " = " << res_prod << std::endl;
    // std::cout << "Product in float = " << (double)res_prod.getNumerator()/res_prod.getDenominator()<< std::endl;
    // std::cout << test << " * " << inFloat  << " = " << test*inFloat << std::endl;
    

    std::cout << "Division between rational and double : \n " << std::endl;
    Rational<int> res_division = test/fraction;
    double inFloat = (double)fraction.getNumerator()/fraction.getDenominator();
    std::cout << test << " / " << fraction << " = " << res_division << std::endl;
    std::cout << "Product in float = " << (double)res_division.getNumerator()/res_division.getDenominator()<< std::endl;
    std::cout << test << " / " << inFloat  << " = " << test/inFloat << std::endl;
#endif 
    
    double a = 14.21;
    Rational<int> a_ratio = Rational<int>::convertFloatRatio(a,maxIter);
    std::cout << a_ratio << std::endl;

    return 0;
}