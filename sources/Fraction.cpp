/**
 *declare about implemention and logic of the structure of program
 *@author Sari Safe
 *@since 16.04.23
 */

#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"

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

};