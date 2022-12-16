#include <random>
#include <cmath>

#include <gtest/gtest.h>

#include "Rational.hpp"


/////////////////////////////////////////////////////
// constructors

TEST (RationalConstructor, defaultConstructor) { 
	Rational<int> r;
	ASSERT_EQ (r.getNumerator(), 0);
}




/////////////////////////////////////////////////////
// arithmetic

TEST (RationalArithmetic, plus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		double a = gen();
		double b = gen();
		Rational<int> frac1 = Rational<int>::convertFloatRatio (a,4);
		Rational<int> frac2 = Rational<int>::convertFloatRatio (b,4);
		Rational<int> expectedResult = Rational<int>::convertFloatRatio(a+b,4);
		Rational<int> actualResult = frac1+frac2;
		double epsilon = 0.1;
		Rational<int> difference = (actualResult-expectedResult).vabs();
		double differenceFloat= Rational<int>::convertRatioFloat(difference); //(double)difference.getNumerator()/difference.getDenominator();
		std::cout<< "a = " << a << " frac1 = " << frac1 << std::endl;
		std::cout<< "b = " << b << " frac2 = " << frac2 << std::endl;
		std::cout<< "expected = " << Rational<int>::convertRatioFloat(expectedResult)<< " actual = " << Rational<int>::convertRatioFloat(actualResult)<< std::endl;
		std::cout<< "difference = " << differenceFloat << " epsilon = " << epsilon << std::endl;
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
		double a = gen();
		double b = gen();
		Rational<int> frac1 = Rational<int>::convertFloatRatio (a,4);
		Rational<int> frac2 = Rational<int>::convertFloatRatio (b,4);
		Rational<int> expectedResult = Rational<int>::convertFloatRatio(a-b,4);
		Rational<int> actualResult = frac1-frac2;
		double epsilon = 0.1;
		Rational<int> difference = (actualResult-expectedResult).vabs();
		double differenceFloat= Rational<int>::convertRatioFloat(difference); //(double)difference.getNumerator()/difference.getDenominator();
		std::cout<< "a- = " << a << " frac1 = " << frac1 << std::endl;
		std::cout<< "b- = " << b << " frac2 = " << frac2 << std::endl;
		std::cout<< "expected = " << Rational<int>::convertRatioFloat(expectedResult)<< " actual = " << Rational<int>::convertRatioFloat(actualResult)<< std::endl;
		std::cout<< "difference = " << differenceFloat << " epsilon = " << epsilon << std::endl;
		ASSERT_LT(differenceFloat, epsilon);
	}
}

TEST (RationalArithmetic, unaryMinus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);
	
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    int numerator = gen();
    int denominator = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	// here it uses the traditional unary minus
		Rational<int> r3(-numerator, denominator);
    
	
	  ASSERT_EQ (r3,-r1);   
	}
}

TEST (RationalArithmetic, divide) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		double a = gen();
		double b = gen();
		Rational<int> frac1 = Rational<int>::convertFloatRatio (a,4);
		Rational<int> frac2 = Rational<int>::convertFloatRatio (b,4);
		Rational<int> expectedResult = Rational<int>::convertFloatRatio(a/b,4);
		Rational<int> actualResult = frac1/frac2;
		double epsilon = 0.1;
		Rational<int> difference = (actualResult-expectedResult).vabs();
		double differenceFloat= Rational<int>::convertRatioFloat(difference); //(double)difference.getNumerator()/difference.getDenominator();
		std::cout<< "a/ = " << a << " frac1 = " << frac1 << std::endl;
		std::cout<< "b/ = " << b << " frac2 = " << frac2 << std::endl;
		std::cout<< "expected = " << Rational<int>::convertRatioFloat(expectedResult)<< " actual = " << Rational<int>::convertRatioFloat(actualResult)<< std::endl;
		std::cout<< "difference = " << differenceFloat << " epsilon = " << epsilon << std::endl;
		ASSERT_LT(differenceFloat, epsilon); 
	}
}

TEST (RationalArithmetic, multiply) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){
		double a = gen();
		double b = gen();
		Rational<int> frac1 = Rational<int>::convertFloatRatio (a,3);
		Rational<int> frac2 = Rational<int>::convertFloatRatio (b,3);
		Rational<int> expectedResult = Rational<int>::convertFloatRatio(a*b,3);
		Rational<int> actualResult = frac1*frac2;
		double epsilon = 50;
		Rational<int> difference = (actualResult-expectedResult).vabs();
		double differenceFloat= Rational<int>::convertRatioFloat(difference); //(double)difference.getNumerator()/difference.getDenominator();
		std::cout<< "a* = " << a << " frac1 = " << frac1 << std::endl;
		std::cout<< "b* = " << b << " frac2 = " << frac2 << std::endl;
		std::cout<< "expected = " << Rational<int>::convertRatioFloat(expectedResult)<< " actual = " << Rational<int>::convertRatioFloat(actualResult)<< std::endl;
		std::cout<< "difference = " << differenceFloat << " epsilon = " << epsilon << std::endl;
		ASSERT_LT(differenceFloat, epsilon); 
	}
}

TEST (RationalArithmetic, inverse) {

	const size_t maxSize = 2000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformDistributionValue(-int(maxSize),maxSize); //should start at 1 to avoid having a 0 ?
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    int numerator = gen();
    int denominator = gen();
		
		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	// swap numerator and denominator
		Rational<int> r3(denominator,numerator);
    
	
	  ASSERT_EQ (r3,r1.inverse());   
	}
}

TEST (RationalArithmetic, irreducibleFraction) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);
	
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    int numerator = gen();
    int denominator = gen();
	int pgcd = std::__gcd(numerator,denominator);

		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	//divide the numerator & denominator by the pgcd
		Rational<int> r3(numerator/pgcd,denominator/pgcd);
    
	
	  ASSERT_EQ (r3,r1);   
	}
}

TEST (RationalArithmetic, absoluteValue) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    int numerator = gen();
    int denominator = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	//build r3 with the absolute values of r1 numerator and denominator
		Rational<int> r3(abs(numerator),abs(denominator));
    
	
	  ASSERT_EQ (r3,r1.vabs());   
	}
}

TEST (RationalArithmetic, integerPart) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = std::bind(uniformDistributionValue, generator);
	
	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    	double number = gen();
	
		int expectedRes = (int)number;
		int libRes = Rational<int>::intPart(number);
    
	
	  ASSERT_EQ (expectedRes,libRes);
	}
}





// /////////////////////////////////////////////////////
// // exception

// TEST (VectorDException, loadExceptionMessage) {
// 	const std::string filename = "filename.txt";
// 	const std::string expectedException = "VectorD::load: error: can not open file: " + filename;

// 	// check the exception message
//     try{
// 		VectorD vec;
//         vec.load(filename);
//     }
//     catch( const std::exception &e){
//         EXPECT_TRUE( std::string(e.what()).find(expectedException) == 0);
//     }
// }


// TEST (VectorDException, loadExceptionType) {

// 	// check exception type
// 	Rational<int> r;
// 	EXPECT_THROW(r.load("filename.txt"), std::ios_base::failure);
// }


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


