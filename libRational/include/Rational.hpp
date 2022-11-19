//hihi

#include <cmath>
#include<cassert>
#include <iostream>
#include <algorithm>

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



/// \class Rational
/// \brief class defining a rational.
template <class T>
class Rational{
    private : 
        T m_numerator;
        T m_denominator;

    public : 
        //constructor 
        // Rational(const T num, const T deno)
        //     : m_numerator(num), m_denominator(deno)
        //     {};

        /// \brief constructor from given values which tests if 0 is the denominator
        /// \param num : the numerator
        /// \param num : the denominator
        Rational(const T num, const T deno){
            assert(deno!=0 && "error: 0 is not a possible value");
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

        /// \brief divides 2 rational numbers
	    /// \param r : the rational number the calling rational will be divided by (should not have a numerator equal to 0)
	    /// \return the division of the current rational and the argument rational 
        Rational<T> operator/(const Rational<T> &r) const; 

        /// \brief checks if 2 rationals are equals
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the argument rational and the current are equals
        bool operator==(const Rational<T> &r)const;

        /// \brief checks if 2 rationals are equals
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the argument rational and the current are not equals
        bool operator!=(const Rational<T> &r) const;

        /// \brief checks if the current rational is greater than the argument rational
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the current rational is greater than the argument rational
        bool operator>(const Rational<T> &r) const;

        /// \brief checks if the current rational is less than the argument rational
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the current rational is less than the argument rational
        bool operator<(const Rational<T> &r) const;

        /// \brief checks if the current rational is greater than or equal to the argument rational
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the current rational is greater than or equal to the argument rational
        bool operator<=(const Rational<T> &r) const;

        /// \brief checks if the current rational is less than or equal to the argument rational
	    /// \param r : the rational number the calling rational will be compared to
	    /// \return true if the current rational is less than or equal to the argument rational
        bool operator>=(const Rational<T> &r) const;


        //------------setters-getters-----

        //à supprimer si pas utiliser 

        // void setNumerator(const T numerator){
        //     m_numerator = numerator;
        // }

        // void setDenominator(const T denominator){
        //     if(denominator != 0){
        //         m_denominator = denominator;
        //     }
           
        // }

        T getNumerator()const{
            return m_numerator;
        }

        T getDenominator()const{
            return m_denominator;
        }

        //------------function----------
        Rational<T> inverse() const;
        Rational<T> irreducibleFraction() ;
        Rational<T> vabs();
};

template<typename T>
Rational<T> Rational<T>::operator+(const Rational<T> &r) const{
    Rational<T> result;
    result.m_numerator=(m_numerator*r.m_denominator)+(m_denominator*r.m_numerator);
    result.m_denominator=(m_denominator*r.m_denominator);
    return result.irreducibleFraction();
}
//do an affectation operator with = ?

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
    result.m_numerator=(m_numerator*r.m_numerator);
    result.m_denominator=(m_denominator*r.m_denominator);
    return result.irreducibleFraction();
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

//-------------function-----------------

/// \brief inverses the current rational and put it into its irreductible form
/// \return : the inverse of the current rational under its irreductible form
template<typename T>
Rational<T> Rational<T>::inverse()const{
    Rational<T> result;
    assert(m_numerator!=0 && "error: 0 irreversible");
    result.m_numerator=m_denominator;
    result.m_denominator=m_numerator;
    return result.irreducibleFraction();
}

/// \brief put the current rational into its irreductible form
/// \return : the current rational under its irreductible form
template<typename T>
Rational<T> Rational<T>::irreducibleFraction(){
    int pgcd = std::__gcd(m_numerator,m_denominator);

    this->m_numerator=this->m_numerator/pgcd;
    this->m_denominator=this->m_denominator/pgcd;
    
    return *(this);
}

/// \brief computes the absolute value of the current rational
/// \return : the absolute value of the current rational
template<typename T>
Rational<T> Rational<T>::vabs(){
    //-----condition 0 à revoir-----
    if(this->m_numerator==0){
        this->m_numerator=0;
        this->m_denominator=1;
    }
    //check si ça ne change pas sinon mettre une variable result
    //comme dans l'inverse (update: ça a l'air good)
    if(this->m_numerator*this->m_denominator<0){
        return -*this;
    }
    return *this;
}

//------------cout--------------------

/// \brief overload the operator << for Rational
/// \param stream : input stream
/// \param r : the rational number to output
/// \return the output stream containing the rational data      
template<typename T>
std::ostream& operator<< (std::ostream& stream, const Rational<T>& r){
    if (r.getNumerator() == 0){
        stream<< "error : division by 0";
    }
    else if (r.getNumerator() == 0){
        stream<< "0/1";
    }
    else if (r.getNumerator()<0 && r.getDenominator()<0){
        stream<<-r.getNumerator()<<"/"<<-r.getDenominator();
    }
    else
        stream<< r.getNumerator() << "/" << r.getDenominator();
    return stream;
}

#endif
       
    