//hihi

#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <fstream>

#ifndef __RATIONAL__HPP
#define __RATIONAL__HPP

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html chips.jpeg
/// \tableofcontents
/// \section instroduction_sec What for?
/// Rational is a super tool which grants you the power to use and manipulate rational numbers in a simple way.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li nothing
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li if Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html

// number iteration used for function convertFloatRatio 
constexpr unsigned int maxIter = 10 ;
constexpr double precision = 100000;

template<typename T>
T troncature(T x){
    return round(x*precision)/precision;
}


/// \class Rational
/// \brief class defining a rational.
template <class T>
class Rational{
    private : 
        T m_numerator;
        T m_denominator;

    public : 
        //------------constructors----------

        /// \brief constructor from given values in irreducible form
        /// \param num : the numerator
        /// \param num : the denominator
        Rational(const T num, const T deno){
            m_numerator = num;
            m_denominator = deno;
            this->irreducibleFraction();
        }

        /// \brief copy-constructor
        /// \param ratio : the rational number to be copied
        Rational(const Rational &ratio)
            : m_numerator(ratio.m_numerator), m_denominator(ratio.m_denominator)
            {};

        /// \brief default constructor = 0/1
        Rational()
            :m_numerator(0), m_denominator(1)
            {};

        /// \brief destructor
        ~Rational() = default;

        //------------operator----------
        
        /// \brief adds 2 rational numbers
	    /// \param r : rational number to add to the calling rational number
	    /// \return the sum of the current rational and the argument rational
        Rational<T> operator+(const Rational<T> &r) const; 

        /// \brief substracts 2 rational numbers
	    /// \param r : rational number to substract to the calling rational number
	    /// \return the substraction of the current rational and the argument rational 
        Rational<T> operator-(const Rational<T> &r) const; 

        /// \brief unary minus
	    /// \return the minus of the current rational 
        Rational<T> operator-() const; 

        /// \brief multiplies 2 rational numbers
	    /// \param r : the rational number the calling rational will be multplied by
	    /// \return the multiplication of the current rational and the argument rational 
        Rational<T> operator*(const Rational<T> &r) const; 

        /// \brief multiplies a rational number and a template type
	    /// \param x : a template type number the calling rational will be multplied by
	    /// \return the multiplication of the current rational and the template type argument
        Rational<T> operator*(const T &x) const;

        /// \brief multiplies a double and a rational
	    /// \param x : a double number the calling rational will be multplied by
        /// \param r : a rational the calling double will be multiplied by
	    /// \return the multiplication of the double argument and the rational argument
        inline friend Rational<T> operator*(const double &x,const Rational<T> &r){return Rational<T>::convertFloatRatio(x,maxIter)*r;};

        /// \brief multiplies a rational and a double
	    /// \param x : a double number the calling rational will be multplied by
        /// \param r : a rational the calling double will be multiplied by
	    /// \return the multiplication of the rational argument and the double argument
        inline friend Rational<T> operator*(const Rational<T> &r,const double &x){return Rational<T>::convertFloatRatio(x,maxIter)*r;}

        /// \brief divides 2 rational numbers
	    /// \param r : the rational number the calling rational will be divided by (should not have a numerator equal to 0)
	    /// \return the division of the current rational and the argument rational 
        Rational<T> operator/(const Rational<T> &r) const; 


        /// \brief divides a rational number with a double
	    /// \param x : a double number the calling rational will divide by
	    /// \return the division of the current rational by the argument double 
        Rational<T> operator/(const T &x) const{return Rational<T>::convertFloatRatio(x,maxIter)/(*this);}; 

        /// \brief divides a double by a rational
	    /// \param x : a double number the calling rational will be divided by
        /// \param r : a rational the calling double will divided 
	    /// \return the division of the current double by the argument rational
        inline friend Rational<T> operator/(const double &x,const Rational<T> &r){return Rational<T>::convertFloatRatio(x,maxIter)/r;};

        /// \brief divides a rational by a double
	    /// \param x : a double number the calling rational will be divided by
        /// \param r : a rational the calling double will divided 
	    /// \return the multiplication of the current rational by the double argument
        inline friend Rational<T> operator/(const Rational<T> &r, const double &x){return r/Rational<T>::convertFloatRatio(x,maxIter);};


        /// \brief checks if 2 rationals are equals
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the argument rational and the current are equals
        bool operator==(const Rational<T> &r)const;

        /// \brief checks if 2 rationals are different
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the argument rational and the current are not equals
        bool operator!=(const Rational<T> &r) const;

        /// \brief checks if the current rational is greater than the argument rational
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the current rational is greater than the argument rational
        bool operator>(const Rational<T> &r) const;

        /// \brief checks if the current rational is less than the argument rational
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the current rational is lower than the argument rational
        bool operator<(const Rational<T> &r) const;

        /// \brief checks if the current rational is greater than or equal to the argument rational
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the current rational is greater than or equal to the argument rational
        bool operator<=(const Rational<T> &r) const;

        /// \brief checks if the current rational is less than or equal to the argument rational
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the current rational is lower than or equal to the argument rational
        bool operator>=(const Rational<T> &r) const;


        //------------other operation----------

        /// \brief square root of a rational
        /// \param r : rational number 
	    /// \return a double corresponding at the square root of the rational
        static double sqrt(const Rational<T> &r);

        /// \brief computes the value of the rational raised to the power exp.
        /// \param exp : exponent as a value of integral type
	    /// \return a double corresponding to a rational to the power of the exposant
        static Rational<T> power(const Rational<T> &r, const int exp);

        /// \brief computes the exponential of the rational.
        /// \param r : rational number
	    /// \return a double corresponding to the exponential of the parameter r
        static double exp(const Rational<T> &r);


        /// \brief computes the binary logarithm of the rational.
        /// \param r : rational number
	    /// \return a double corresponding to the binary logarithm of the parameter r
        static double log2(const Rational<T> &r);

        //------------setters-getters-----


        /// \brief setter for the numerator
        void setNumerator(const T numerator){
            m_numerator = numerator;
        };
        /// \brief setter for the denominator
        void setDenominator(const T denominator){
            if(denominator != 0){
                m_denominator = denominator;
            }
           
        };

        /// \brief getter for the numerator
        /// \return the numerator of the rational number
        inline const T getNumerator() const{
            return m_numerator;
        }

        /// \brief getter for the denominator
        /// \return the denominator of the rational number
        inline const T getDenominator()const{
            return m_denominator;
        }

        

        //------------functions----------
        
        /// \brief inverses the current rational and put it into its irreductible form
        /// \return : the inverse of the current rational under its irreductible form
        Rational<T> inverse() const;

        /// \brief put the current rational into its irreductible form
        /// \return : the current rational under its irreductible form
        Rational<T> irreducibleFraction() ;

        /// \brief if the rational is < 0, put the sign on the numerator
        /// \return : the rational with a minus on the numerator
        Rational<T> setMinus() ;

        /// \brief computes the absolute value of the current rational
        /// \return : the absolute value of the current rational
        Rational<T> vabs();


        /// \brief take the integer part of a Rational
        /// \return : integer part of the Rational
        static int intPart(const double &x);
        
        /// \brief convert a float to a rational
        /// \param x : the float to convert
        /// \param nbIter : the number of iteration of the function
        /// \return : a rational
        static Rational<T> convertFloatRatio(double x, const unsigned int nbIter);

        /// \brief convert a ratio to a float
        /// \param ratio : the ratio to convert into a float
        /// \return : a double
        static double convertRatioFloat(Rational<T> ratio);

        
        
        
};

//------------operator----------

template<typename T>
Rational<T> Rational<T>::operator+(const Rational<T> &r) const{
    Rational<T> result;
    result.m_numerator=(m_numerator*r.m_denominator)+(m_denominator*r.m_numerator);
    result.m_denominator=(m_denominator*r.m_denominator);
    return result.irreducibleFraction();
}

template<typename T>
Rational<T> Rational<T>::operator-() const{
    Rational<T> result;
    result.m_numerator=-m_numerator;
    result.m_denominator=m_denominator;
    return result.irreducibleFraction();
}

template<typename T>
Rational<T> Rational<T>::operator-(const Rational<T> &r) const{
    Rational<T> result;
    result.m_numerator=(m_numerator*r.m_denominator)-(m_denominator*r.m_numerator);
    result.m_denominator=(m_denominator*r.m_denominator);
    return result.irreducibleFraction();
}

template<typename T>
Rational<T> Rational<T>::operator*(const Rational<T> &r) const{
    Rational<T> result;
    result.m_numerator=(this->m_numerator*r.m_numerator);
    result.m_denominator=(this->m_denominator*r.m_denominator);
    return result.irreducibleFraction();
}

template<typename T>
Rational<T> Rational<T>::operator*(const T &x) const{
    Rational<T> ratioX = Rational<T>::convertFloatRatio(x,maxIter);

    return ratioX*(*this);
}


template<typename T>
Rational<T> Rational<T>::operator/(const Rational<T> &r) const{
    Rational<T> result;
    result.m_denominator = m_denominator*r.inverse().m_denominator;
    result.m_numerator = m_numerator*r.inverse().m_numerator;
    return result.irreducibleFraction();
}

template<typename T>
bool Rational<T>::operator==(const Rational<T> &r) const{
    if(m_numerator != r.m_numerator || m_denominator != r.m_denominator){
        return false;
    }
    return true;

}

template<typename T>
bool Rational<T>::operator!=(const Rational<T> &r) const{
    if(m_numerator != r.m_numerator || m_denominator != r.m_denominator){
        return true;
    }
    return false;

}

template<typename T>
bool Rational<T>::operator>(const Rational<T> &r) const{
    if(((*this)-r).getNumerator() > 0){
        return true;
    }
    return false;

}

template<typename T>
bool Rational<T>::operator<(const Rational<T> &r) const{
    if(((*this)-r).getNumerator() >= 0){
        return false;
    }
    return true;

}

template<typename T>
bool Rational<T>::operator>=(const Rational<T> &r) const{
    if(((*this)-r).getNumerator() >= 0){
        return true;
    }
    return false;

}

template<typename T>
bool Rational<T>::operator<=(const Rational<T> &r) const{
    if(((*this)-r).getNumerator() > 0){
        return false;
    }
    return true;
}

//------------other operators----------

template<typename T>
double Rational<T>::sqrt(const Rational<T> &r){
    double result = std::sqrt(r.m_numerator)/std::sqrt(r.m_denominator);
    return result;
}

template<typename T>
Rational<T> Rational<T>::power(const Rational<T> &r, const int exp){
    Rational<T> result;
    result.m_numerator = std::pow(r.m_numerator, exp);
    result.m_denominator = std::pow(r.m_denominator, exp);
    return result.irreducibleFraction();
}

template<typename T>
double Rational<T>::exp(const Rational<T> &r){
    return std::pow(std::exp(r.m_numerator), 1.0/(r.m_denominator));
}

template<typename T>
double Rational<T>::log2(const Rational<T> &r){
    return std::log2(r.m_numerator) - std::log2(r.m_denominator);
}

//-------------functions-----------------

template<typename T>
Rational<T> Rational<T>::inverse()const{
    Rational<T> result;
    result.m_numerator=m_denominator;
    result.m_denominator=m_numerator;
    return result.irreducibleFraction();
}

template<typename T>
Rational<T> Rational<T>::irreducibleFraction(){
    int pgcd = std::__gcd(m_numerator,m_denominator);

    this->m_numerator=this->m_numerator/pgcd;
    this->m_denominator=this->m_denominator/pgcd;
    
    return this->setMinus();
}

template<typename T> 
Rational<T> Rational<T>::setMinus(){
    if(this->getNumerator() > 0 && this->getDenominator() < 0){
        this->setNumerator(-this->getNumerator());
        this->setDenominator(-this->getDenominator());
    }
    else if(this->getNumerator() < 0 && this->getDenominator() < 0){
        this->setNumerator(-this->getNumerator());
        this->setDenominator(-this->getDenominator());
    }
    return *(this);
}

template<typename T>
Rational<T> Rational<T>::vabs(){
    if(this->m_numerator==0){
        return Rational<T>(0,1);
    }
    if(this->m_numerator*this->m_denominator<0){
        return -(*this);
    }
    return *this;
}

template<typename T>
int Rational<T>::intPart(const double &x){
    int res = static_cast<int>(x);
    return res;
}

//------------cout--------------------

/// \brief overload the operator << for Rational
/// \param stream : input stream
/// \param r : the rational number to output
/// \return the output stream containing the rational data      
template<typename T>
std::ostream& operator<< (std::ostream& stream, const Rational<T>& r){
    if (r.getDenominator() == 0){
        //stream<< "error : division by 0";
        stream<< "inf";
    }
    else if (r.getNumerator() == 0){
        stream<< "0/1";
    }
    else
        stream<< r.getNumerator() << "/" << r.getDenominator();
    return stream;
}


template<typename T>
Rational<T> Rational<T>::convertFloatRatio(double x, const unsigned int nbIter){
    
<<<<<<< Updated upstream
    //Use troncature when using Rational<int>, you can comment it for Rational<long int>
    //x = troncature(x);
=======
    x = troncature(x);
>>>>>>> Stashed changes
    if (x<0){
        Rational<T> result = -(convertFloatRatio(-x,nbIter));
        return result.setMinus();
    }
    if(x==0){//x<0.0015 && x>-0.0015){
        std::cout<< nbIter << ":)" <<std::endl;
        return Rational<T>(0,1);
        
    }
    if(nbIter == 0){
        return Rational<T>(0,1);
<<<<<<< Updated upstream
        return Rational<T>(0,1);
=======
        
>>>>>>> Stashed changes
    }
    if(x<1){
        return convertFloatRatio(1/x,nbIter).inverse();
    }
    if(x>=1){
        int integerPart = intPart(x);
        Rational<T> q(integerPart,1);
        return q + convertFloatRatio((x-integerPart), nbIter-1);
    }
    return Rational<T>(0,1);
}

template<typename T>
double Rational<T>::convertRatioFloat(Rational<T> ratio){
    return ((double)(ratio.getNumerator())/(ratio.getDenominator()));
}




#endif
       
    