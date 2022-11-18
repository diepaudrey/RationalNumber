//hihi

#include <cmath>
#include<cassert>
#include <iostream>

#ifndef __RATIONAL__HPP
#define __RATIONAL__HPP

template <class T>
class Rational{
    public:
    //private : 
        T m_numerator;
        T m_denominator;

    public : 
        //constructor 
        Rational(const T num, const T deno)
            : m_numerator(num), m_denominator(deno)
            {};

        //copy constructor
        Rational(const Rational &ratio)
            : m_numerator(ratio.m_numerator), m_denominator(ratio.m_denominator)
            {};

        //default construtor
        Rational()
            :m_numerator(0), m_denominator(1)
            {};

        //destructor
        ~Rational() = default;

        //------------operator----------
        Rational<T> operator+(const Rational<T> &r) const; 
        Rational<T> operator-() const; 
        Rational<T> operator-(const Rational<T> &r) const; 
        Rational<T> operator*(const Rational<T> &r) const; 
        Rational<T> operator/(const Rational<T> &r) const; 


        //------------function----------
        Rational<T> inverse() const;
        Rational<T> vabs();
};

template<typename T>
Rational<T> Rational<T>::operator+(const Rational<T> &r) const{
    Rational<T> result;
    result.m_numerator=(m_numerator*r.m_denominator)+(m_denominator*r.m_numerator);
    result.m_denominator=(m_denominator*r.m_denominator);
    return result;
}

template<typename T>
Rational<T> Rational<T>::operator-() const{
    Rational<T> result;
    result.m_numerator = -m_numerator;
    result.m_denominator=m_denominator;
    return result;
}

template<typename T>
Rational<T> Rational<T>::operator-(const Rational<T> &r) const{
    Rational<T> result;
    result.m_numerator=(m_numerator*r.m_denominator)-(m_denominator*r.m_numerator);
    result.m_denominator=(m_denominator*r.m_denominator);
    return result;
}

template<typename T>
Rational<T> Rational<T>::operator*(const Rational<T> &r) const{
    Rational<T> result;
    result.m_numerator=(m_numerator*r.m_numerator);
    result.m_denominator=(m_denominator*r.m_denominator);
    return result;
}

template<typename T>
Rational<T> Rational<T>::operator/(const Rational<T> &r) const{
    Rational<T> result;
    result.m_denominator = m_denominator*r.inverse().m_denominator;
    result.m_numerator = m_numerator*r.inverse().m_numerator;
    return result;
}
//-------------function-----------------
template<typename T>
Rational<T> Rational<T>::inverse()const{
    Rational<T> result;
    assert(m_numerator!=0 && "error: 0 irreversible");
    result.m_numerator=m_denominator;
    result.m_denominator=m_numerator;
    return result;
}


int pgcd(int a, int b);

template<typename T>
Rational<T> Rational<T>::vabs()
{
    //---condition 0 à revoir---
    if(m_numerator==0){
        m_numerator=0;
        m_denominator=1;
    }
    //check si ça ne change pas sinon mettre une variable result 
    //comme dans l'inverse (update: ça a l'air good)
    if (m_numerator*m_denominator<0){
        return -*this;
    }
    return *this;
}


//------------cout--------------------
template<typename T>
std::ostream& operator<< (std::ostream& stream, const Rational<T>& r){
    if (r.m_denominator == 0){
        stream<< "error : division by 0";
    }
    /*
    //risque de redite
    else if (r.m_numerator == 0){
        stream<< "0/1";
    }*/
    else if (r.m_numerator<0 && r.m_denominator<0)
       stream<< -r.m_numerator << "/" << -r.m_denominator;
    else
        stream<< r.m_numerator << "/" << r.m_denominator;
    return stream;
}

#endif