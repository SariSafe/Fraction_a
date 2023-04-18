/**
 *declare about  the structure of program
 *@author Sari Safe
 *@since 16.04.23
 */

// to dont include the header alot, once at most
#pragma once

#include <iostream>

using namespace std;
namespace ariel
{

    class Fraction
    {
    private:
        int _numerator;
        int _denominator;
        /*greatest common divisor of the original values of two integeres.*/
        int GCD(int, int);

    public:
        // help function
        void reduce();

        /*ctor*/
        Fraction(int, int);
        /* istream and ostream */
        friend ostream &operator<<(ostream &, const Fraction &);
        friend istream &operator>>(istream &, Fraction &);
        /*
        1.addition of tow objacts (Fractions)
        2.additon Fraction and flaot(Fractoin+float)
        3.additon Fraction and flaot(float+Fractoin)
        */
        Fraction operator+(const Fraction &);
        friend float operator+(const Fraction &, float);
        friend float operator+(float, const Fraction &);
        /*
        1.subtraction two Fractions
        2.subtraction float and Fractions(Fractoin-float) there no need but in progress we drop it
        3.subtraction float and Fractions(float-Fractoin) there no need but in progress we drop it
         */
        Fraction operator-(const Fraction &);
        friend float operator-(float, const Fraction &);
        friend float operator-(const Fraction &, float);
        /*
        1.multiply two Fractions
        2.multiply float and Fractions(Fractoin*float) there no need but in progress we drop it
        3.multiply float and Fractions(float*Fractoin) there no need but in progress we drop it
         */
        Fraction operator*(const Fraction &);
        friend float operator*(float, const Fraction &);
        friend float operator*(const Fraction &, float);
    };

};