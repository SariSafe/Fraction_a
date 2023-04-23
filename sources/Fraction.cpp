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
        // simplify the fraction
        simplify();
    }
    Fraction Float_to_Fraction(float value)
    {
        int denominator = 1000;
        value *= 1000;
        // here we use the ctor , and there validation of if deminator == 0
        Fraction f(value, denominator);
        // f.simplify(); - there no need because this opreation done in c'tor by default
        return f;
    }
    // getters
    const int Fraction::numerator()
    {
        return this->_numerator;
    };
    const int Fraction::denominator()
    {
        return this->_denominator;
    };

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

    void Fraction::simplify()
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
        result.simplify();
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

        return Float_to_Fraction(-num) + other;
    }

    Fraction Fraction::operator*(const Fraction &other)
    {
        // default state and dont need of default constructor :)
        Fraction result(0, 1);
        result._numerator = (this->_numerator * other._numerator);
        result._denominator = (this->_denominator * other._denominator);
        result.simplify();
        return result;
    }

    float operator*(float num, const Fraction &frac)
    {
        // 1. here we can be confidence that there no divided  with 0
        return (num * frac._numerator) / frac._denominator;
    }

    float operator*(const Fraction &frac, float num)
    {
        return num * frac;
    }

    Fraction Fraction::operator/(const Fraction &other)
    {
        if (other._numerator == 0)
        {
            throw " the by 0 is not defined !";
        }

        // use something already done.
        // 1. here too.
        // We turned the fraction (from the denominator in the numerator) then the multiplied
        return this->operator*(Fraction(other._denominator, other._numerator));
    }

    float operator/(float num, const Fraction &frac)
    {
        if (frac._numerator == 0)
        {
            throw " the by 0 is not defined !";
        }
        // 1. here too.
        return frac._numerator / (frac._denominator * num);
    }

    float operator/(const Fraction &frac, float num)
    {
        if (num == 0)
        {
            throw " there no result to divide in zero ";
        }
        return (frac / num);
    }

    bool Fraction::operator==(const Fraction &other) const
    {
        return (this->_numerator == other._numerator) && (this->_denominator == other._denominator);
    }

    bool operator==(float num, const Fraction &frac)
    {
        float num_0 = frac._denominator / frac._numerator;
        return (num == num_0);
    }

    bool operator==(const Fraction &frac, float num)
    {
        return (frac == num);
    }

    bool Fraction::operator<(const Fraction &other)
    {
        return (this->_numerator / this->_denominator) < (other._numerator / other._denominator);
    }

    bool operator<(const Fraction &frac, float num)
    {

        return (float)(frac._numerator / frac._denominator) < num;
    }

    // prepare for check.
    bool operator<(float num, const Fraction &frac)
    {

        return num < (float)(frac._numerator / frac._denominator);
    }

    bool Fraction::operator<=(const Fraction &other)
    {

        return (this->_numerator / this->_denominator) <= (other._numerator / other._denominator);
    }

    bool operator<=(const Fraction &frac, float num)
    {

        return num <= frac;
    }

    bool operator<=(float num, const Fraction &frac)
    {

        return frac._numerator <= num * frac._denominator;
    }

    bool Fraction::operator>(const Fraction &other)
    {
        bool b = (this->_numerator / this->_denominator) > (other._numerator / other._denominator);
        return b;
    }

    bool operator>(const Fraction &frac, float num)
    {

        return num > frac;
    }

    bool operator>(float num, const Fraction &frac)
    {

        return num > frac._numerator / frac._denominator;
    }

    bool Fraction::operator>=(const Fraction &other)
    {

        return (this->_numerator / this->_denominator) >= (other._numerator / other._denominator);
    }

    bool operator>=(const Fraction &frac, float num)
    {

        return num >= frac;
    }

    bool operator>=(float num, const Fraction &frac)
    {

        return frac._numerator >= num * frac._denominator;
    }
    // prepare for check.
    Fraction &Fraction::operator--()
    {
        Fraction old(*this); // here we save a copy for object(old Fraction)
        (*this)--;           //--(*this) need check the problem with that . but its the same
        return *this;
    }
    Fraction Fraction::operator--(int)
    {
        _numerator -= _denominator;
        simplify();
        return *this;
    }
    Fraction Fraction ::operator++(int)
    {
        _numerator += _denominator;
        simplify();
        return *this;
    }

    Fraction &Fraction::operator++()
    {

        Fraction old(*this);
        ++(*this);
        return *this;
    }
};