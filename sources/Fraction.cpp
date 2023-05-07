//
// Created by super on 4/15/23.
//

#include "Fraction.hpp"
#include <iostream>
#include <math.h>
#include <limits.h>
#include <stdexcept>
#include <ostream>
using namespace std;
namespace ariel{

  Fraction::Fraction(int numerator, int denominator){
    if (denominator == 0){
      throw invalid_argument("denominator can't be 0");
    }

    if (denominator < 0){
      numerator *= -1;
      denominator *= -1;
    }
    num = numerator;
    den = denominator;
    reduce();
  }

  Fraction::Fraction(float num1) : Fraction((int)(num1 * 1000), 1000){}

  int Fraction::getNumerator() const{
    return num;
  }

  int Fraction::getDenominator() const{
    return den;
  }

  bool are_you_valid(long long num1, long long num2){
    if (num1 > INT_MAX || num1 < INT_MIN || num2 > INT_MAX || num2 < INT_MIN){
      return false;
    }
    return true;
  }

  const Fraction Fraction::operator+(const Fraction &frc) const{
    long long this_num = num;
    long long this_den = den;
    long long frc_num = frc.getNumerator();
    long long frc_den = frc.getDenominator();
    long long num1 = this_num * frc_den + frc_num * this_den;
    long long num2 = this_den * frc_den;
    if (!are_you_valid(num1, num2)){
      throw std::overflow_error("invalid input");
    }
    return Fraction(num1, num2);
  }

  const Fraction Fraction::operator-(const Fraction &frc) const{
    long long this_num = num;
    long long this_den = den;
    long long frc_num = frc.getNumerator();
    long long frc_den = frc.getDenominator();
    long long num1 = this_num * frc_den - frc_num * this_den;
    long long num2 = this_den * frc_den;
    if (!are_you_valid(num1, num2)){
      throw std::overflow_error("invalid input");
    }
    return Fraction(num1, num2);
  }

  const Fraction Fraction::operator*(const Fraction &frc) const{
    long long this_num = num;
    long long this_den = den;
    long long frc_num = frc.getNumerator();
    long long frc_den = frc.getDenominator();
    long long num1 = this_num * frc_num;
    long long num2 = this_den * frc_den;
    if (!are_you_valid(num1, num2)){
      throw std::overflow_error("invalid input");
    }
    return Fraction(num1, num2);
  }

  const Fraction Fraction::operator/(const Fraction &frc) const{
    if (frc.getNumerator() == 0){
      throw runtime_error("can't divide by 0");
    }
    long long this_num = num;
    long long this_den = den;
    long long frc_num = frc.getNumerator();
    long long frc_den = frc.getDenominator();
    long long num1 = this_num * frc_den;
    long long num2 = this_den * frc_num;
    if (!are_you_valid(num1, num2)){
      throw std::overflow_error("invalid input");
    }
    return Fraction(num1, num2);
  }

  Fraction &Fraction::operator+=(const Fraction &frc){
    *this = *this + frc;
    this->reduce();
    return *this;
  }

  Fraction &Fraction::operator-=(const Fraction &frc){
    *this = *this - frc;
    this->reduce();
    return *this;
  }

  Fraction &Fraction::operator+=(float num1){
    Fraction f = Fraction(num1);
    *this = *this + f;
    this->reduce();
    return *this;
  }

  Fraction &Fraction::operator-=(float num1){
    Fraction f = Fraction(num1);
    *this = *this - f;
    this->reduce();
    return *this;
  }

  // prefix
  Fraction &Fraction::operator++(){
    *this += Fraction(1, 1);
    return *this;
  }

  // postfix
  const Fraction Fraction::operator++(int){
    Fraction frc(this->getNumerator(), this->getDenominator());
    *this += Fraction(1, 1);
    return frc;
  }

  // prefix
  Fraction &Fraction::operator--(){
    *this -= Fraction(1, 1);
    return *this;
  }

  // postfix
  const Fraction Fraction::operator--(int){
    Fraction frc(this->getNumerator(), this->getDenominator());
    *this -= Fraction(1, 1);
    return frc;
  }

  bool Fraction::operator>(const Fraction &frc) const{
    float this_frc = ((float)this->getNumerator()) / ((float)this->getDenominator());
    float other_frc = ((float)frc.getNumerator()) / ((float)frc.getDenominator());
    if (this_frc > other_frc)
      return true;
    return false;
  }

  bool Fraction::operator<(const Fraction &frc) const{
    float this_frc = ((float)this->getNumerator()) / ((float)this->getDenominator());
    float other_frc = ((float)frc.getNumerator()) / ((float)frc.getDenominator());
    if (this_frc < other_frc)
      return true;
    return false;
  }

  bool Fraction::operator>=(const Fraction &frc) const{
    float this_frc = ((float)this->getNumerator()) / ((float)this->getDenominator());
    float other_frc = ((float)frc.getNumerator()) / ((float)frc.getDenominator());
    if (this_frc >= other_frc)
      return true;
    return false;
  }

  bool Fraction::operator<=(const Fraction &frc) const{
    float this_frc = ((float)this->getNumerator()) / ((float)this->getDenominator());
    float other_frc = ((float)frc.getNumerator()) / ((float)frc.getDenominator());
    if (this_frc <= other_frc)
      return true;
    return false;
  }

  bool Fraction::operator==(Fraction frc) const{
    return (this->getNumerator() == frc.getNumerator() && this->getDenominator() == frc.getDenominator());
  }

  bool Fraction::operator!=(const Fraction &frc) const{
    return (this->getNumerator() != frc.getNumerator() || this->getDenominator() != frc.getDenominator());
  }

  ostream &operator<<(ostream &ost, const Fraction &fraction){
    ost << fraction.getNumerator() << "/" << fraction.getDenominator();
    return ost;
  }

  std::istream &operator>>(istream &ist, Fraction &fraction){
    int num, den;
    ist >> num >> den;
    if (ist.fail()){
      throw std::runtime_error("Error: Input failed");
    }
    if (den == 0){
      throw std::runtime_error("Error: cant divide by zero");
    }
    fraction = Fraction(num, den);
    return ist;
  }

  void Fraction::reduce(){
    int gcd_val = gcd(abs(num), abs(den));
    num = ((int)(num)) / gcd_val;
    den = ((int)(den)) / gcd_val;
  }

  int Fraction::gcd(int anum, int bnum) const{
    if (anum == 0)
      return bnum;
    return gcd(bnum % anum, anum);
  }

  const Fraction operator+(float num1, const Fraction &frc){
    return Fraction(num1) + frc;
  }

  const Fraction operator-(float num1, const Fraction &frc){
    return Fraction(num1) - frc;
  }

  const Fraction operator*(float num1, const Fraction &frc){
    return Fraction(num1) * frc;
  }

  const Fraction operator/(float num1, const Fraction &frc){
    return Fraction(num1) / frc;
  }

  const Fraction Fraction::operator+(float num1) const{
    return *this + Fraction(num1);
  }

  const Fraction Fraction::operator-(float num1) const{
    return *this - Fraction(num1);
  }

  const Fraction Fraction::operator*(float num1) const{
    return *this * Fraction(num1);
  }

  const Fraction Fraction::operator/(float num1) const{
    return *this / Fraction(num1);
  }

  bool Fraction::operator>(float num1) const{
    Fraction f = Fraction(num1);
    return (*this > f);
  }

  bool Fraction::operator<(float num1) const{
    Fraction f = Fraction(num1);
    return (*this < f);
  }

  bool Fraction::operator>=(float num1) const{
    Fraction f = Fraction(num1);
    return (*this >= f);
  }

  bool Fraction::operator<=(float num1) const{
    Fraction f = Fraction(num1);
    return (*this <= f);
  }

  bool Fraction::operator==(float num1) const{
    float this_frc = (float)(this->getNumerator()) / (this->getDenominator());
    this_frc = round(this_frc * 1000) / 1000;
    return (this_frc == num1);
  }

  bool operator>(float num1, const Fraction &frc){
    Fraction f = Fraction(num1);
    return (f > frc);
  }

  bool operator<(float num1, const Fraction &frc){
    Fraction f = Fraction(num1);
    return (f < frc);
  }

  bool operator>=(float num1, const Fraction &frc){
    Fraction f = Fraction(num1);
    return (f >= frc);
  }

  bool operator<=(float num1, const Fraction &frc){
    Fraction f = Fraction(num1);
    return (f <= frc);
  }

  bool operator==(float num1, const Fraction &frc){
    Fraction f = Fraction(num1);
    return (f == frc);
  }
}
