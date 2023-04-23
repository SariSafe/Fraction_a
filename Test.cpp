#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>
#include <stdexcept>

using std::endl, std::cout;
using namespace ariel;

TEST_CASE(" edge cases and  safe c'tors  ")
{

    // CHECK_THROWS(Fraction(0, 0));
    Fraction r(0, 10);
    CHECK_THROWS(r / 0);
    Fraction a1(5, 9);
    Fraction a2(0, 6);
    CHECK_THROWS(a1 / a2); // we can't divide by 0
    Fraction a3(0, 7);
    CHECK_THROWS(a3 / a2); // (0/0) is not defined !

    CHECK_NOTHROW(Fraction d(0, 10));
    CHECK_NOTHROW(a2 / a1); // we can divide 0 by every number is not zero
    CHECK_NOTHROW(Fraction(0, 10) / 10);
}
TEST_CASE(" simple operation ")
{
    // case 0 :Simplification of fraction
    Fraction f(4, 12);
    cout << "other way to write the fraction  " << endl;
    CHECK(f.numerator() == 1);
    CHECK(f.denominator() == 3);

    Fraction f1(1, 2);
    Fraction f2(1, 4);
    Fraction f3 = f1 + f2;
    CHECK(f3.numerator() == 3);
    CHECK(f3.denominator() == 4);

    // case 2
    Fraction f4(3, 4);
    Fraction f5(1, 4);
    Fraction f6 = f4 - f5;
    CHECK(f6.numerator() == 1);
    CHECK(f6.denominator() == 2);

    // case 3
    Fraction f7(1, 2);
    Fraction f8(3, 4);
    Fraction f9 = f7 * f8;
    CHECK(f9.numerator() == 3);
    CHECK(f9.denominator() == 8);

    // case 4
    Fraction f10(3, 4);
    Fraction f11(1, 2);
    Fraction f12 = f10 / f11;
    CHECK(f12.numerator() == 3);
    CHECK(f12.denominator() == 2);

    Fraction mul(2, 1);
    float simple_check;
    for (int i = 0; i < 3; i++)
    {
        simple_check = 2 * mul;
    }
    CHECK(simple_check == 8.00);
}
TEST_CASE(" sequence of operations")
{
    Fraction fract(1, 2);
    Fraction fract0(1, 9);
    Fraction fract1(1, 7);
    Fraction fract2(13, 5);
    Fraction fract3 = fract + fract0 - fract1 * fract2 / fract;
    CHECK(fract3.numerator() == -83);
    CHECK(fract3.denominator() == 630);

    Fraction compare(1, 3);
    Fraction compare1(6, 9);
    bool b1 = compare < compare1;
    bool b2 = compare > compare1;
    bool b3 = (compare == compare1);
    CHECK(b1 == true);
    CHECK_FALSE(b2 == false);
    CHECK_FALSE(b3 == false);

    Fraction c0(4, 1);  // 4
    Fraction c1(6, 3);  // 2
    Fraction c2(27, 9); // 3

    CHECK((c0 * c1 * c2) == 24);
    CHECK((c0 * c1 + c2) == 11);
    CHECK(c0 - (c1 * c2) == -2);
    CHECK((c0 - c1) * c2 == 6);
    CHECK(-1 * c0 + c1 - c2 == -5);
}
