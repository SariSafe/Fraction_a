/**
 *declare about implemention and logic of the structure of program
 *@author Sari Safe
 *@since 16.04.23
 */

#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;
// using std::ostream, std::istream;
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
        result._numerator = (this->_numerator * other._numerator) + (this->_denominator * other._numerator);
        result._denominator = (this->_denominator * other._denominator);
        result.reduce();
        return result;
    }
    float operator+(const Fraction &frac, float j)
    {
        return (j + frac);
    }
    float operator+(float j, const Fraction &frac)
    {
        return (j + frac);
    }
    Fraction Fraction::operator-(const Fraction &other)
    {
        return this->operator+(Fraction((other._numerator), -1 * other._denominator));
    }

    float operator-(float _add, const Fraction &other)
    {
        return _add + Fraction((other._numerator), -1 * other._denominator);
    }

};