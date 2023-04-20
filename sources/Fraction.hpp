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
          addition of tow objacts (Fractions)
        */
        Fraction operator+(const Fraction &);
        /*
          additon Fraction and flaot(Fractoin+float)
        */
        friend float operator+(const Fraction &, float);
        /*
          additon Fraction and flaot(float+Fractoin)
        */
        friend float operator+(float, const Fraction &);
        /*
          subtraction two Fractions
        */
        Fraction operator-(const Fraction &);
        /*
         subtraction float and Fractions(Fractoin-float) - there no exist in demo examples
        */
        friend float operator-(float, const Fraction &);
        /*
         subtraction float and Fractions(float-Fractoin) 
        */
        friend float operator-(const Fraction &, float);
        /*
         multiply two Fractions
        */
        Fraction operator*(const Fraction &);
        /*
          multiply float and Fractions(Fractoin*float) - there no exist in demo examples
        */
        friend float operator*(float, const Fraction &);
        /*
         multiply float and Fractions(float*Fractoin) - there no exist in demo examples
        */
        friend float operator*(const Fraction &, float);
        /*
          divison two Fractions
         */
        Fraction operator/(const Fraction &);
        /*
          divison float and Fractions(Fractoin/float)
         */
        friend float operator/(float, const Fraction &);
        /*
          divison float and Fractions(float/Fractoin)
        */
        friend float operator/(const Fraction &, float);
        /*
         equallity two Fractions
        */
        bool operator==(const Fraction &);
        /*
          equallity float and Fractions(Fractoin == float)
        */
        friend float operator==(float, const Fraction &);
        /*
          equallity float and Fractions(float == Fractoin)
        */
        friend float operator==(const Fraction &, float);
    };

};