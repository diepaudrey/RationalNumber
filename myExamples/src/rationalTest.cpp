//haaaaa
#include "Rational.hpp" 
#include <iostream>


//You can change value of num and deno to test
const long int num1= 20;
const long int deno1 = 5;
const long int num2= 2;
const long int deno2 = 5;
const double lambda = 6.8;

//for conversion from a float to ratio
double test = 0.33333333333333333333333333;


void exampleConstructors(){
    
    Rational<int> ratioDefault;
    Rational<int> ratio(num1,deno1);
    Rational<int> ratioCopy = ratio;

    std::cout << "Constructors example : " << std::endl;
    std::cout << "Numerator = " << num1 << " Denominator = " << deno1 << std::endl; 
    std::cout << " - Default constructor : " << ratioDefault << std::endl;
    std::cout << " - Constructor by value : " << ratio << std::endl;
    std::cout << " - Copy constructor : " << ratioCopy << "\n" << std::endl;

}

void exampleArithmetic(){
    Rational<long int> ratio1(num1, deno1);
    Rational<long int> ratio2(num2, deno2);
    std::cout << "Operators example : " << std::endl;

    //Operator + 
    std::cout << "ratio1 + ratio2 = " << ratio1 << " + " << ratio2 << " = " << ratio1+ratio2 << std::endl;

    //Opeator - 
    std::cout << "ratio1 - ratio2 = " << ratio1 << " - " << ratio2 << " = " << ratio1-ratio2 << std::endl;
    std::cout << "-ratio1 = " << -ratio1 << std::endl;

    //Operator * 
    std::cout << "ratio1 * ratio2 = " << ratio1 << " * " << ratio2 << " = " << ratio1*ratio2 << std::endl;
    std::cout << "lambda * ratio1 = " << lambda << " * " << ratio1<< " = " << lambda*ratio1 << std::endl;
    std::cout << "ratio1 * lambda = " << ratio1 << " * " << lambda << " = " << ratio1*lambda << "\n" <<  std::endl;

    //Operator / 
    std::cout << "Division between 2 rationals : " << std::endl;
    std::cout << "ratio1 / ratio2 = " << ratio1 << " / " << ratio2 << " = " << ratio1/ratio2 << std::endl;

    std::cout << "Division between rational and double : \n " << std::endl;
    std::cout << "lambda / ratio2 = " << lambda << " / " << ratio1 << " = " << lambda/ratio1<< std::endl;
    std::cout << "ratio1 / lambda = " << ratio1 << " / " << lambda << " = " << ratio1/lambda<< "\n" << std::endl;

    //Operator square root
    std::cout << "Test square root : " << std::endl;
    std::cout <<"ratio1 = " << ratio1 << std::endl;
    std::cout << "sqrt(ratio1) = " <<   Rational<long int>::sqrt(ratio1) << std::endl;
    std::cout << "expectedSqrt = " <<   std::sqrt(Rational<long int>::convertRatioFloat(ratio1)) << "\n"<< std::endl;

    std::cout <<"ratio2 = " << ratio2 << std::endl;
    std::cout << "sqrt(ratio2) = " <<   Rational<long int>::sqrt(ratio2) << std::endl;
    std::cout << "expectedSqrt = " <<   std::sqrt(Rational<long int>::convertRatioFloat(ratio2)) << "\n"<< std::endl;

}

void exampleConversion(){

    std::cout << "Convert Float to Rational test : " << std::endl;
    Rational<int> result = Rational<int>::convertFloatRatio(test,3); //modifier le nombre d'iteration
    std::cout << "expectedValue : " << test << std::endl;
    std::cout << "convert result :  " << result << std::endl;
    std::cout << "actualValue : " << Rational<int>::convertRatioFloat(result) << "\n" << std::endl;
}

int main(){
    exampleConstructors();
    exampleArithmetic();
    exampleConversion();
#if 0

    std::cout << "Division between rational and double : \n " << std::endl;
    Rational<int> res_division = test/fraction;
    double inFloat = (double)fraction.getNumerator()/fraction.getDenominator();
    std::cout << test << " / " << fraction << " = " << res_division << std::endl;
    std::cout << "Product in float = " << (double)res_division.getNumerator()/res_division.getDenominator()<< std::endl;
    std::cout << test << " / " << inFloat  << " = " << test/inFloat << std::endl;

    std::cout << "Convert Float to Rational test : " << std::endl;
    double test = 0.333333333333333333333;
    Rational<int> result = Rational<int>::convertFloatRatio(test,10);
    std::cout << "expectedValue : " << test << std::endl;
    std::cout << "convert result :  " << result << std::endl;
    std::cout << "actualValue : " << (double)result.getNumerator()/result.getDenominator() << "\n" << std::endl;

    std::cout << "Test square root : " << std::endl;
    Rational<int> ratioSqrt(5,4);
    std::cout <<"Rational = " << ratioSqrt << std::endl;
    //std::cout << std::sqrt(5)/std::sqrt(4) << std::endl;
    std::cout << "sqrt = " <<   Rational<int>::sqrt(ratioSqrt) << std::endl;
    std::cout << "expectedSqrt = " <<   std::sqrt(Rational<int>::convertRatioFloat(ratioSqrt)) << "\n"<< std::endl;


    std::cout << "Rational to the power of an exponent : " << std::endl;
    Rational<int> ratioPow(5,2);
    const int exp = 2;
    std::cout <<"Rational = " << ratioPow << std::endl;
    std::cout << "power = " <<   Rational<int>::power(ratioPow, exp) << std::endl;
    std::cout << "expectedSqrt = " <<   Rational<int>::convertFloatRatio(std::pow(Rational<int>::convertRatioFloat(ratioPow),exp),maxIter) << "\n" << std::endl;

    std::cout << "Exponential test : " <<std::endl;
    Rational<int> ratioExp(4,3);
    std::cout << "expectedResult = " << std::exp(4.0/3) << std::endl;
    std::cout << "actualResult = " << Rational<int>::exp(ratioExp) << "\n" << std::endl;

    std::cout << "Binary logarithm test : " <<std::endl;
    Rational<int> ratioLog(4,3);
    std::cout << "expectedResult = " << std::log2(4.0/3) << std::endl;
    std::cout << "actualResult = " << Rational<int>::log2(ratioLog) << "\n" << std::endl;
#endif 

    
    
    return 0;
}