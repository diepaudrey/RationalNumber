#include <random>
#include <cmath>

#include <gtest/gtest.h>

#include "Rational.hpp"

//precision of our calculation
constexpr double epsilon = 0.0001;

/////////////////////////////////////////////////////
// constructors

TEST (RationalConstructor, defaultConstructor) { 
	const Rational<int> r;
	ASSERT_EQ (r.getNumerator(), 0);
}

/////////////////////////////////////////////////////
// arithmetic

TEST (RationalArithmetic, plus) {

	const size_t maxSize = 1000;  // max size of the tested rationals
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		const double a = gen();
		const double b = gen();

		//convert float to ratio
		const Rational<long int> frac1 = Rational<long int>::convertFloatRatio (a,maxIter);
		const Rational<long int> frac2 = Rational<long int>::convertFloatRatio (b,maxIter);

		//comparison between (frac1+frac2) convert in double and a+b
		const double actualFloatResult = Rational<long int>::convertRatioFloat(frac1+frac2);
		const double expectedFloatResult = a+b;
		const double differenceFloat= std::abs(actualFloatResult - expectedFloatResult) ;

		//if you want to see the result, decomment this part
		// std::cout<< "a = " << a << " frac1 = " << frac1 << std::endl;
		// std::cout<< "b = " << b << " frac2 = " << frac2 << std::endl;
		// std::cout<< "expected = " << expectedFloatResult << " actual = " << actualFloatResult<< std::endl;
		// std::cout<< "difference = " << differenceFloat << " epsilon = " << epsilon  << '\n' << std::endl;

		ASSERT_LT(differenceFloat, epsilon);
		
	}
}

TEST (RationalArithmetic, minus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		const double a = gen();
		const double b = gen();

		const Rational<long int> frac1 = Rational<long int>::convertFloatRatio (a,maxIter);
		const Rational<long int> frac2 = Rational<long int>::convertFloatRatio (b,maxIter);
 
		//comparison between (frac1-frac2) convert in double and a-b
		const double actualFloatResult = Rational<long int>::convertRatioFloat(frac1-frac2);
		const double expectedFloatResult = a-b;
		const double differenceFloat= std::abs(actualFloatResult - expectedFloatResult) ;

		//if you want to see the result, decomment this part
		// std::cout<< "a- = " << a << " frac1 = " << frac1 << std::endl;
		// std::cout<< "b- = " << b << " frac2 = " << frac2 << std::endl;
		// std::cout<< "expected = " << expectedFloatResult << " actual = " << actualFloatResult << std::endl;
		// std::cout<< "difference = " << differenceFloat << " epsilon = " << epsilon  << '\n' << std::endl;
		ASSERT_LT(differenceFloat, epsilon);
	}
}

TEST (RationalArithmetic, unaryMinus) {

	const size_t maxSize = 1000;  //max value
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);
	
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		const int numerator = gen();
		const int denominator = gen();

		// build the corresponding Rational
		const Rational<int> r1(numerator,denominator);
		
    	// here it uses the traditional unary minus
		const Rational<int> r3(-numerator, denominator);
    
	
	  ASSERT_EQ (r3,-r1);   
	}
}

TEST (RationalArithmetic, divide) {

	const size_t maxSize = 1000; 
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		const double a = gen();
		const double b = gen();

		const Rational<long int> frac1 = Rational<long int>::convertFloatRatio (a,maxIter);
		const Rational<long int> frac2 = Rational<long int>::convertFloatRatio (b,maxIter);

		//comparison between (frac1/frac2) convert in double and a/b
		const double actualFloatResult = Rational<long int>::convertRatioFloat(frac1/frac2);
		const double expectedFloatResult = a/b;
		const double differenceFloat= std::abs(actualFloatResult - expectedFloatResult) ;


		// if you want to see the result, decomment this part
		// std::cout<< "a/ = " << a << " frac1 = " << frac1 << std::endl;
		// std::cout<< "b/ = " << b << " frac2 = " << frac2 << std::endl;
		// std::cout<< "expected = " << expectedFloatResult << " actual = " <<actualFloatResult<< std::endl;
		// std::cout<< "difference = " << differenceFloat << " epsilon = " << epsilon  << '\n' << std::endl;
		
		ASSERT_LT(differenceFloat, epsilon); 
	}
}

TEST (RationalArithmetic, multiply) {

	const size_t maxSize = 1000;  
	std::mt19937 generator(0);
	std::uniform_real_distribution<long double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		const double a = gen();
		const double b = gen();
		
		const Rational<long int> frac1 = Rational<long int>::convertFloatRatio (a,maxIter);
		const Rational<long int> frac2 = Rational<long int>::convertFloatRatio (b,maxIter);

		//comparison between (frac1*frac2) convert in double and a*b
		const double actualFloatResult = Rational<long int>::convertRatioFloat(frac1*frac2);
		const double expectedFloatResult = a*b;
		const double differenceFloat= std::abs(actualFloatResult - expectedFloatResult) ;

		// if you want to see the result, decomment this part
		// std::cout<< "a* = " << a << " frac1 = " << frac1 << std::endl;
		// std::cout<< "b* = " << b << " frac2 = " << frac2 << std::endl;
		// std::cout<< "expected = " << expectedFloatResult << " actual = " << actualFloatResult<< std::endl;
		// std::cout<< "difference = " << differenceFloat << " epsilon = " << epsilon  << '\n' << std::endl;

		ASSERT_LT(differenceFloat, 0.1); 
	}
}

TEST (RationalOperation, squareRoot) {

	const size_t maxSize = 1000;  
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(0,maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		const double a = gen();

		const Rational<long int> frac1 = Rational<long int>::convertFloatRatio(a,maxIter);
		const double expectedResult = std::sqrt(a);
		const double actualResult = Rational<long int>::sqrt(frac1);

		const double differenceFloat = std::abs(actualResult - expectedResult);
		
		//if you want to see the result, decomment this part
		// std::cout << "a = " << a << std::endl;
		// std::cout << "a_ratio = " << frac1 << std::endl; 
		// std::cout << "expected = " << expectedResult << std::endl;
		// std::cout << "actual = " << actualResult << std::endl;
		// std::cout << "diff = " << differenceFloat << '\n' << std::endl;

		ASSERT_LT(differenceFloat, epsilon); 
	}
}

TEST (RationalOperation, power) {

	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformDistributionIntValueExponent(0,10);
	std::uniform_int_distribution<int> uniformDistributionIntValue(1,100);
	auto expGen = std::bind(uniformDistributionIntValueExponent, generator);
	auto intGen = std::bind(uniformDistributionIntValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		//generating an exponent
		const unsigned int exp = expGen();
		//creating a rational
		const int num = intGen();
		const int deno = intGen();
		Rational<long int> ratio(num,deno);

		//comparing std::pow and our power function
		Rational<long int> expectedResult(std::pow(num, exp), std::pow(deno,exp));
		Rational<long int> actualResult = Rational<long int>::power(ratio, exp);

		//transform in double to be able to compare
		double expectedDoubleResult = Rational<long int>::convertRatioFloat(expectedResult);
		double actualDoubleResult = Rational<long int>::convertRatioFloat(actualResult);
		double difference = std::abs(expectedDoubleResult - actualDoubleResult);

		//if you want to see the result, decomment this part
		// std::cout << "ratio = " << ratio << std::endl;
		// std::cout << "exponent = " << exp << std::endl;
		// std::cout << "expected = " << expectedResult << " actual = " << actualResult << std::endl;
		// std::cout << "diff = " << difference << '\n' << std::endl;

		EXPECT_LT(difference, epsilon ); 
	}
}

TEST (RationalOperation, exponential) {

	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformDistributionValue(-(int)maxSize,maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		const int num = gen();
		const int deno = gen();

		const Rational<long int> ratio(num,deno);
		const double expectedResult = std::exp(((double)num)/deno);
		const double actualResult = Rational<long int>::exp(ratio);

		const double differenceFloat = std::abs(actualResult - expectedResult);
		
		//if you want to see the result, decomment this part
		// std::cout << "ratio = " << ratio << std::endl; 
		// std::cout << "expected = " << expectedResult << std::endl;
		// std::cout << "actual = " << actualResult << std::endl;
		// std::cout << "diff = " << differenceFloat << '\n' << std::endl;

		ASSERT_LT(differenceFloat, epsilon); 
	}
}

TEST (RationalOperation, logarithm) {

	const size_t maxSize = 100;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformDistributionValue(1,maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		const int num = gen();
		const int deno = gen();

		const Rational<long int> ratio(num,deno);
		const double expectedResult = std::log2(((double)num)/deno);
		const double actualResult = Rational<long int>::log2(ratio);

		const double differenceFloat = std::abs(actualResult - expectedResult);
		
		//if you want to see the result, decomment this part
		// std::cout << "ratio = " << ratio << std::endl; 
		// std::cout << "expected = " << expectedResult << std::endl;
		// std::cout << "actual = " << actualResult << std::endl;
		// std::cout << "diff = " << differenceFloat << '\n' << std::endl;

		ASSERT_LT(differenceFloat, epsilon); 
	}
}

TEST (RationalOperation, irreducibleFraction) {

	const size_t maxSize = 1000; 
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);
	
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		const int numerator = gen();
		const int denominator = gen();
		const int pgcd = std::__gcd(numerator,denominator);

		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	//divide the numerator & denominator by the pgcd
		Rational<int> r3(numerator/pgcd,denominator/pgcd);
    
	
	  ASSERT_EQ (r3,r1);   
	}
}

TEST (RationalOperation, absoluteValue) {

	const size_t maxSize = 1000;  
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		const int numerator = gen();
		const int denominator = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	//build r3 with the absolute values of r1 numerator and denominator
		Rational<int> r3(abs(numerator),abs(denominator));
    
	
	  ASSERT_EQ (r3,r1.vabs());   
	}
}

TEST (RationalOperation, integerPart) {

	const size_t maxSize = 1000; 
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);
	
	
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    	const double number = gen();
		const int expectedRes = (int)number;
		const int libRes = Rational<int>::intPart(number);
    
	
	  ASSERT_EQ (expectedRes,libRes);
	}
}


TEST (RationalConversion, FloatToRatio) {

	const size_t maxSize = 1000;
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);
	
	
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    	const double number = gen();
		const Rational<long int> numberRatio = Rational<long int>::convertFloatRatio(number, maxIter);
		const double actualResult = ((double)numberRatio.getNumerator()/numberRatio.getDenominator());
		const double difference = std::abs(number - actualResult);

		//if you want to see the result, decomment this part
		// std::cout << "numberRatio = " << numberRatio << std::endl;
		// std::cout << "expected = " << number << " actual = " << actualResult << std::endl;
		// std::cout << "diff = " << difference << '\n' << std::endl;


	  ASSERT_LT(difference,epsilon);
	}
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


