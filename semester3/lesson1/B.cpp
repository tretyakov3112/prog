#pragma once
#include<iostream>

class Rational final {
public:
    Rational() {}
    Rational(int numerator = 0, int denominator = 1) :  m_numerator(numerator), m_denominator(denominator) {}
    Rational(const Rational& other) 
    {
        m_numerator = other.m_numerator;
        m_denominator = other.m_denominator;
    };
    int get_numerator() const { return m_numerator; }
    int get_denominator() const { return m_denominator; }
    void set_numerator(int numerator) { m_numerator = numerator; }
    void set_denominator(int denominator) { m_denominator = denominator; }
      explicit operator double() const 
    {
        return static_cast<double>(m_numerator) / m_denominator;
    }

    double toDouble() const 
    {
        return static_cast<double>(m_numerator) / m_denominator;
    }
    Rational& operator=(const Rational & other) 
    {
        m_numerator = other.m_numerator;
        m_denominator = other.m_denominator;
        return *this;
    }
    Rational& operator+=(const Rational& other)
    {
        m_numerator = other.m_denominator * m_numerator + other.m_numerator * m_denominator;
        m_denominator *= other.m_denominator;
        return *this;
    }

    Rational operator+() const
    {
        return Rational(m_numerator, m_denominator);
    }

    Rational operator-() const
    {
        return Rational(-m_numerator, m_denominator);
    }
   
    Rational& operator-=(const Rational& other)
    {
        m_numerator = other.m_denominator * m_numerator - other.m_numerator * m_denominator;
        m_denominator *= other.m_denominator;
        return *this;
    }
    
    Rational& operator*=(const Rational& other)
    {
        m_numerator *= other.m_numerator;
        m_denominator *= other.m_denominator;
        return *this;
    }

    Rational& operator/=(const Rational& other)
    {
        m_numerator *= other.m_denominator;
        m_denominator *= other.m_numerator;
        return *this;
    }
    
private:
    friend bool operator<(const Rational &l, const Rational &r) 
    {
        return l.m_numerator * r.m_denominator < l.m_denominator * r.m_numerator;
    }

    friend bool operator<=(const Rational &l, const Rational &r) 
    {
        return l.m_numerator * r.m_denominator <= l.m_denominator * r.m_numerator;
    }

    friend bool operator>(const Rational &l, const Rational &r) 
    {
        return l.m_numerator * r.m_denominator > l.m_denominator * r.m_numerator;
    }

    friend bool operator>=(const Rational &l, const Rational &r) 
    {
        return l.m_numerator * r.m_denominator >= l.m_denominator * r.m_numerator;
    }

    friend bool operator==(const Rational &l, const Rational &r) 
    {
        return l.m_numerator * r.m_denominator == l.m_denominator * r.m_numerator;
    }

    friend bool operator!=(const Rational &l, const Rational &r) 
    {
        return l.m_numerator * r.m_denominator != l.m_denominator * r.m_numerator;
    }
    
    int m_numerator;
    int m_denominator;
};


Rational operator+(const Rational& lhs, const Rational& rhs)
{
    Rational r = lhs;
    r += rhs;
    return r;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    Rational r = lhs;
    r -= rhs;
    return r;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    Rational r = lhs;
    r *= rhs;
    return r;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    Rational r = lhs;
    r /= rhs;
    return r;
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
    os << r.get_numerator() << " / " << r.get_denominator() << "\n";
    return os;
}

int main()
{
    Rational r = Rational(1, 2);
    Rational l = Rational(1, 3);
    std::cout << r + 10 ;
}