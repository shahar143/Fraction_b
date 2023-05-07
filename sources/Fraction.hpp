//
// Created by super on 4/15/23.
//

#ifndef CPP_FRACTION_3A_FRACTION_HPP
#define CPP_FRACTION_3A_FRACTION_HPP

#endif // CPP_FRACTION_3A_FRACTION_HPP
#include <ostream>
using namespace std;

namespace ariel{
  class Fraction{
  private:
    int num;
    int den;

  public:
    /**
     * @brief constructor for Fraction object - excepts numerator and denominator
     * @throws invalid_argument if denominator is 0
     * @throws overflow_error if the result of the operation is out of range
     * @param numerator
     * @param denominator
     */
    Fraction(int numerator, int denominator);

    /**
     * @brief constructor for Fraction object - excepts a float number
     * @throws overflow_error if the result of the operation is out of range
     * @param num1
     */
    Fraction(float num1);

    /**
     * @brief default constructor for Fraction object - numerator = 0, denominator = 1
     * represent the number 0 as a fraction
     */
    Fraction(): num(0), den(1){}

    /**
     * @brief getters for numerator and denominator
     * @return
     */
    int getNumerator() const;
    int getDenominator() const;

    /**
     * @brief basic math operators - +, -, *, /
     * @param frc - Fraction object
     * @return the result of the operation as a new Fraction object
     */
    const Fraction operator+(const Fraction &frc) const;
    const Fraction operator-(const Fraction &frc) const;
    const Fraction operator*(const Fraction &frc) const;
    const Fraction operator/(const Fraction &frc) const;

    /**
     * @brief += and -= operators
     * @param frc - Fraction object
     * @return a reference to the current(this) Fraction object after the operation
     */
    Fraction &operator+=(const Fraction &frc);
    Fraction &operator-=(const Fraction &frc);

    /**
     * @brief += and -= operators
     * @param float num1 - a float number
     * @return a reference to the current(this) Fraction object after the operation
     */
    Fraction &operator+=(float num1);
    Fraction &operator-=(float num1);

    /**
     * @brief prefix ++ and -- operators - increase or decrease by 1
     * @return (this) Fraction object after the operation - increase or decrease by 1
     */
    Fraction &operator++();
    Fraction &operator--();

    /**
     * @brief postfix ++ and -- operators - increase or decrease by 1
     * @return (this) Fraction object before the operation - increase or decrease by 1
     */
    const Fraction operator++(int);
    const Fraction operator--(int);

    /**
     * @brief basic comparators - >, <, >=, <=, ==, !=
     * @param frc - Fraction object
     * @return true or false
     */
    bool operator>(const Fraction &frc) const;
    bool operator<(const Fraction &frc) const;
    bool operator>=(const Fraction &frc) const;
    bool operator<=(const Fraction &frc) const;
    bool operator==(Fraction frc) const;
    bool operator!=(const Fraction &frc) const;

    /**
     * @brief cout and cin operators - print or read Fraction object
     * @param ost - ostream object or ist - istream object
     * @param frc - a reference to a Fraction object
     * @return ostream/istream object
     */
    friend ostream &operator<<(ostream &ost, const Fraction &frc);
    friend istream &operator>>(istream &ist, Fraction &frc);

    /**
     * @brief basic math operators - +, -, *, / - when the first parameter is a float number
     * @param num1 - a float number
     * @param frc - Fraction object
     * @return the result of the operation as a new Fraction object
     */
    friend const Fraction operator+(float num1, const Fraction &frc);
    friend const Fraction operator-(float num1, const Fraction &frc);
    friend const Fraction operator*(float num1, const Fraction &frc);
    friend const Fraction operator/(float num1, const Fraction &frc);

    /**
     * @brief basic math operators - +, -, *, / - when the second parameter is a float number
     * @param num1 - a float number
     * @return the result of the operation as a new Fraction object
     */
    const Fraction operator+(float num1) const;
    const Fraction operator-(float num1) const;
    const Fraction operator*(float num1) const;
    const Fraction operator/(float num1) const;

    /**
     * @brief basic comparators - >, <, >=, <=, ==, != - when the second parameter is a float number
     * @param num1 - a float number
     * @return true or false
     */
    bool operator>(float num1) const;
    bool operator<(float num1) const;
    bool operator>=(float num1) const;
    bool operator<=(float num1) const;
    bool operator==(float num1) const;

    /**
     * @brief basic comparators - >, <, >=, <=, ==, != - when the first parameter is a float number
     * @param num1 - a float number
     * @param frc - Fraction object
     * @return true or false
     */
    friend bool operator>(float num1, const Fraction &frc);
    friend bool operator<(float num1, const Fraction &frc);
    friend bool operator>=(float num1, const Fraction &frc);
    friend bool operator<=(float num1, const Fraction &frc);
    friend bool operator==(float num1, const Fraction &frc);

    /**
     * @brief a function that reduces the fraction to its lowest terms
     */
    void reduce();

    /**
     * @brief a function that returns the greatest common divisor of two numbers
     * @param anum - first number
     * @param bnum - second number
     * @return the greatest common divisor of two numbers
     */
    int gcd(int anum, int bnum) const;
  };
}
