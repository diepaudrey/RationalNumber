#include "Rational.hpp" 
#include <iostream>


//You can change value of num and deno to test
const long int num1= 14;
const long int deno1 = 5;
const long int num2= 2;
const long int deno2 = 5;
const double lambda = 6.8;
const int exponent = 2;

//for conversion from a float to ratio
const double test = 0.3333333333333333;


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
    //use for comparison
    const double ratioInFloat = Rational<long int>::convertRatioFloat(ratio1);

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
    std::cout << "ratio1 / ratio2 = " << ratio1 << " / " << ratio2 << " = " << ratio1/ratio2 <<"\n" << std::endl;

    std::cout << "Division between rational and double : " << std::endl;
    Rational<long int> actualResult = lambda/ratio1;
    double actualFloatResult = Rational<long int>::convertRatioFloat(actualResult);
    std::cout << "lambda / ratio1 = " << lambda << " / " << ratio1 << " = " << actualResult << std::endl;
    std::cout << "actualFloatResult = " << actualFloatResult << std::endl;
    std::cout << "expectedResult = " << lambda/Rational<long int>::convertRatioFloat(ratio1) << "\n" << std::endl;
    std::cout << "ratio1 / lambda = " << ratio1 << " / " << lambda << " = " << ratio1/lambda<< std::endl;
    std::cout << "The result is the inverse of the previous one !" << "\n" << std::endl;

    //Operator square root
    std::cout << "Test square root : " << std::endl;
    std::cout <<"ratio1 = " << ratio1 << std::endl;
    std::cout << "sqrt(ratio1) = " <<   Rational<long int>::sqrt(ratio1) << std::endl;
    std::cout << "expectedSqrt = " <<   std::sqrt(Rational<long int>::convertRatioFloat(ratio1)) << "\n"<< std::endl;

    std::cout <<"ratio2 = " << ratio2 << std::endl;
    std::cout << "sqrt(ratio2) = " <<   Rational<long int>::sqrt(ratio2) << std::endl;
    std::cout << "expectedSqrt = " <<   std::sqrt(Rational<long int>::convertRatioFloat(ratio2)) << "\n"<< std::endl;


    //Operator power
    std::cout << "Rational to the power of an exponent : " << std::endl;
    
    std::cout <<"Rational = " << ratio1 << std::endl;
    Rational<long int> powerRatio = Rational<long int>::power(ratio1, exponent);
    double expectedPowerResult = std::pow(Rational<long int>::convertRatioFloat(ratio1),exponent);

    std::cout << "actualResult = " <<   powerRatio << std::endl;
    std::cout << "expectedResult = " <<   Rational<long int>::convertFloatRatio(std::pow(Rational<long int>::convertRatioFloat(ratio1),exponent),maxIter) << std::endl;
    std::cout << "actualFloatResult = " << Rational<long int>::convertRatioFloat(powerRatio)<< std::endl;
    std::cout << "expectedFloatResult = " << expectedPowerResult << "\n" << std::endl;

    //Operator exponential
    std::cout << "Exponential test : " <<std::endl;
    
    std::cout <<"Rational = " << ratio1 << std::endl;
    std::cout << "expectedResult = " << std::exp(ratioInFloat) << std::endl;
    std::cout << "actualResult = " << Rational<long int>::exp(ratio1) << "\n" << std::endl;

    //Operator log_2
    std::cout << "Binary logarithm test : " <<std::endl;
    std::cout <<"Rational = " << ratio1 << std::endl;
    std::cout << "expectedResult = " << std::log2(ratioInFloat) << std::endl;
    std::cout << "actualResult = " << Rational<long int>::log2(ratio1) << "\n" << std::endl;
}   

void exampleConversion(){

    std::cout << "Convert Float to Rational test : " << std::endl;
    Rational<long int> result = Rational<long int>::convertFloatRatio(test,10); //modifier le nombre d'iteration
    std::cout << "expectedValue : " << test << std::endl;
    std::cout << "convert result :  " << result << std::endl;
    std::cout << "actualValue : " << Rational<long int>::convertRatioFloat(result) << "\n" << std::endl;

    Rational<long int> ratio(num1, deno1);
    std::cout << "Convert Rational to Float test : " << std::endl;
    std::cout << "Rational = " << ratio << std::endl;
    std::cout << "inFloat = " << Rational<long int>::convertRatioFloat(ratio) << std::endl;
}

int main(){
    
    //Show the use of constructors
    exampleConstructors();

    //Use every computed operations 
    exampleArithmetic();

    //Use the conversion from Float to Ratio and vice versa
    exampleConversion();
    
    return 0;
}