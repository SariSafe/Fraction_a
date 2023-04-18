/**
 *declare about  the structure of program
 *@author Sari Safe
 *@since 16.04.23
 */

// to dont include the header alot, once at most
#pragma once

#include <iostream>

namespace ariel
{

    class Fraction
    {
    private:
        const int _numerator;
        const int _denominator;
        /*greatest common divisor of the original values of two integeres.*/
        int GCD(int, int);

    public:
        /*ctor*/
        Fraction(int, int);
    };

};