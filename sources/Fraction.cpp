/**
 *declare about implemention and logic of the structure  program
 *@author Sari Safe
 *@since 16.04.23
 */

#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;

namespace ariel
{

    Fraction::Fraction(const int numerator,
                       const int denominator) : _numerator(numerator), _denominator(denominator)
    {
        // possibility div by 0 !
        if (denominator == 0)
        {
            throw " cannot be 0 .";
        }
    }
    ariel::Fraction fractionFromFloat(float value)
    {
        int denominator = 100;
        value *= 100;

        Fraction f(value, denominator);
        f.reduce();
        return f;
    }

    /**
     * @param input two integeres(num_0, num_1)
     * @param return gcd(num_0,num_1)
     */
    int Fraction::GCD(int num_0, int num_1)
    {

        if (num_0 == 0)
        {
            return num_1;
        }
        if (num_1 == 0)
        {
            return num_0;
        }
        while (num_1 != 0)
        {
            int temp = num_1;
            num_1 = num_0 % num_1;
            num_0 = temp;
        }
        return num_0;
    }

    void Fraction::reduce()
    {
        int gcd = GCD(_numerator, _denominator);
        _numerator /= gcd;
        _denominator /= gcd;
    }

    // must pass the stream by reference, not by value. streams are not copyable
    ostream &operator<<(ostream &out, const Fraction &other)
    {
        out << other._numerator << "/" << other._denominator << endl;
        return out;
    }

    istream &operator>>(istream &into, Fraction &other)
    {
        into >> other._numerator >> other._denominator;
        return into;
    }

    Fraction Fraction::operator+(const Fraction &other)
    {
        // default state and dont need of default constructor :)
        Fraction result(0, 1);
        result._numerator = (this->_numerator * other._denominator) + (this->_denominator * other._numerator);
        result._denominator = (this->_denominator * other._denominator);
        result.reduce();
        return result;
    }

    float operator+(float j, const Fraction &frac)
    {
        return ((frac._numerator) + (j * frac._denominator)) / (frac._denominator);
    }

    float operator+(const Fraction &frac, float j)
    {
        return (j + frac);
    }

    // here we use the + operator to subscracts
    Fraction Fraction::operator-(const Fraction &frac)
    {
        return this->operator+(Fraction(-1 * (frac._numerator), frac._denominator));
    }

    float operator-(float num, const Fraction &frac)
    {
        return num + Fraction(-1 * (frac._numerator), frac._denominator);
    }

    Fraction operator-(const Fraction &other, float num)
    {

        return fractionFromFloat(-num) + other;
    }

    Fraction Fraction::operator*(const Fraction &other)
    {
        // default state and dont need of default constructor :)
        Fraction result(0, 1);
        result._numerator = (this->_numerator * other._numerator);
        result._denominator = (this->_denominator * other._denominator);
        result.reduce();
        return result;
    }

    float operator*(float num, const Fraction &frac)
    {
        return (num * frac._numerator) / frac._denominator;
    }

    float operator*(const Fraction &frac, float num)
    {
        return num * frac;
    }

    Fraction Fraction::operator/(const Fraction &other)
    {
        // use something already done.
        return this->operator*(Fraction(other._denominator, other._numerator));
    }

    float operator/(float num, const Fraction &frac)
    {
        return frac._numerator / (frac._numerator * num);
    }

    float operator/(const Fraction &frac, float num)
    {
        return 1 / (num * (1 / frac));
    }

    bool Fraction::operator==(const Fraction &other)
    {
        // need to check
        bool b = (this->_numerator + other._denominator == other._numerator + this->_denominator);
        return b;
    }
    // prepare for check.
    float operator==(float num, const Fraction &frac)
    {
        return (num * frac._denominator == frac._numerator);
    }

    float operator==(const Fraction &frac, float num)
    {
        return frac == num;
    }
    // prepare for check.
    bool Fraction::operator<(const Fraction &other)
    {
        bool b = (this->_numerator + other._denominator < other._numerator + this->_denominator);
        return b;
    }

    // prepare for check.
    float operator<(const Fraction &frac, float num)
    {
        bool b = num < frac;
        return b;
    }

    // prepare for check.
    float operator<(float num, const Fraction &frac)
    {
        bool b = frac._numerator < num * frac._denominator;
        return b;
    }
    // prepare for check.
    bool Fraction::operator<=(const Fraction &other)
    {
        bool b = (this->_numerator + other._denominator <= other._numerator + this->_denominator);
        return b;
    }
    // prepare for check.
    float operator<=(const Fraction &frac, float num)
    {
        bool b = num <= frac;
        return b;
    }
    // prepare for check.
    float operator<=(float num, const Fraction &frac)
    {
        bool b = frac._numerator <= num * frac._denominator;
        return b;
    }
    // prepare for check.
    bool Fraction::operator>(const Fraction &other)
    {
        bool b = (this->_numerator + other._denominator > other._numerator + this->_denominator);
        return b;
    }

    // prepare for check.
    float operator>(const Fraction &frac, float num)
    {
        bool b = num > frac;
        return b;
    }

    // prepare for check.
    float operator>(float num, const Fraction &frac)
    {
        bool b = frac._numerator > num * frac._denominator;
        return b;
    }
    // prepare for check.
    bool Fraction::operator>=(const Fraction &other)
    {
        bool b = (this->_numerator + other._denominator >= other._numerator + this->_denominator);
        return b;
    }
    // need to check isn't final implement there problem with final output
    float operator>=(const Fraction &frac, float num)
    {
        bool b = num >= frac;
        return b;
    }
    // need to check isn't final implement there problem with final output
    float operator>=(float num, const Fraction &frac)
    {
        bool b = frac._numerator >= num * frac._denominator;
        return b;
    }
    // prepare for check.
    Fraction &Fraction::operator--()
    {
        Fraction temp(*this);
        --(*this);
        return *this;
    }
    Fraction Fraction::operator--(int)
    {
        _numerator -= _denominator;
        reduce();
        return *this;
    }
    Fraction Fraction ::operator++(int)
    {
        _numerator += _denominator;
        reduce();
        return *this;
    }

    Fraction &Fraction::operator++()
    {

        Fraction old(*this);
        ++(*this);
        return *this;
    }
};