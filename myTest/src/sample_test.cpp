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
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	


    float number1 = 5.555555;
    float number2 = 8.6545;
    
	Rational<int> fraction1 = Rational<int>::convertFloatRatio(number1,1000);
	Rational<int> fraction2 = Rational<int>::convertFloatRatio(number2,1000);
		
    	
		Rational<int> expectedResult = Rational<int>::convertFloatRatio((number1+number2),100);
		Rational<int> actualResult = fraction1+fraction2;
		Rational<int>  epsilon(1,10000000);
		
		Rational<int> difference = (actualResult-expectedResult);

		std::cout<< "f1: "<< fraction1 <<std::endl;
		std::cout<< "f2: "<< fraction2 <<std::endl;
		std::cout<< "n1+n2: "<< number1 + number2 <<std::endl;
		std::cout<< "f1+f2: "<< expectedResult <<std::endl;
		std::cout<< "actual: "<< actualResult <<std::endl;
		std::cout<< "difference: "<< difference <<std::endl;

	  ASSERT_LT (difference.vabs(), epsilon);    // EXPECT_DOUBLE_EQ would be fine too


}



/*
TEST (RationalArithmetic, plus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){


    int numerator1 = gen();
    int denominator1 = gen();
    int numerator2 = gen();
    int denominator2 = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator1,denominator1),r2(numerator2,denominator2);
		
    	// here it uses the traditional +
		Rational<int> r3(r1+r2);
    
	
	  ASSERT_EQ (r3,r1+r2);   
	}
}

TEST (RationalArithmetic, minus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){


    int numerator1 = gen();
    int denominator1 = gen();
    int numerator2 = gen();
    int denominator2 = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator1,denominator1),r2(numerator2,denominator2);
		
    	// here it uses the traditional -
		Rational<int> r3(r1-r2);
    
	
	  ASSERT_EQ (r3,r1-r2);   
	}
}
*/

TEST (RationalArithmetic, multiply) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){


    int numerator1 = gen();
    int denominator1 = gen();
    int numerator2 = gen();
    int denominator2 = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator1,denominator1),r2(numerator2,denominator2);
		
    	// here it uses the traditional *
		Rational<int> r3(r1*r2);
    
	
	  ASSERT_EQ (r3,r1*r2);   
	}
}

TEST (RationalArithmetic, unaryMinus) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){


    int numerator = gen();
    int denominator = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	// here it uses the traditional unary minus
		Rational<int> r3(-r1);
    
	
	  ASSERT_EQ (r3,-r1);   
	}
}

TEST (RationalArithmetic, divide) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){


    int numerator1 = gen();
    int denominator1 = gen();
    int numerator2 = gen();
    int denominator2 = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator1,denominator1),r2(numerator2,denominator2);
		
    	// here it uses the traditional /
		Rational<int> r3(r1/r2);
    
	
	  ASSERT_EQ (r3,r1/r2);   
	}
}

TEST (RationalArithmetic, inverse) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(1,maxSize); //start at 1 to avoid having a 0 
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

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
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize); //start at 1 to avoid having a 0 
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    int numerator = gen();
    int denominator = gen();
	int pgcd = std::__gcd(numerator,denominator);

		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	//divide the numerator & denominatorby the pgcd
		Rational<int> r3(numerator/pgcd,denominator/pgcd);
    
	
	  ASSERT_EQ (r3,r1);   
	}
}

TEST (RationalArithmetic, absoluteValue) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize); //start at 1 to avoid having a 0 
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

    int numerator = gen();
    int denominator = gen();

		// build the corresponding Rational
		Rational<int> r1(numerator,denominator);
		
    	//divide the numerator & denominatorby the pgcd
		Rational<int> r3(abs(numerator),abs(denominator));
    
	
	  ASSERT_EQ (r3,r1.vabs());   
	}
}

TEST (RationalArithmetic, integerPart) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize); //start at 1 to avoid having a 0 
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

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


