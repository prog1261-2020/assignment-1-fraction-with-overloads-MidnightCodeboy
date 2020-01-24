/**
* @file		Fraction.cpp
* @author	Joseph Roy-Plommer
* @date		2020-01-24
* @version	<1.0>
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
* @section DESCRIPTION
*  Implements a mathematical fraction. Supports all the expected functionality of fractions
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2019
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

#include "Fraction.h"
#include <algorithm>
#include <vector>

/**
*	Constructs an object representing a mathematical fraction, with value 1/1.
*/
Fraction::Fraction() {
	Fraction(1);
}

/**
*	Constructs an object representing a mathematical fraction, from the specified numerator.
*
*	@param numerator The numerator of the fraction
*/
Fraction::Fraction(int numerator) {
	Fraction(numerator, 1);
}

/**
*	Constructs an object representing a mathematical fraction, from the specified numerator and denominator.
*
*	@param numerator The numerator of the fraction
*	@param denominator The denoinator of the fraction
*/
Fraction::Fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	reduce();
}

/**
*	Overrides equality operator, verifying that both the numerators and the denominators of the two fractions match.
*
*	@param rhs other fraction to be compaired with this one
*	@return boolean true if fractions are equal, false if not
*/
bool Fraction::operator==(const Fraction& rhs) const {
	return numerator == rhs.numerator && denominator == rhs.denominator;
}

/**
*	Overrides inequality operator, verifying that not both the numerators and the denominators of the two fractions match.
*
*	@param rhs other fraction to be compaired with this one
*	@return boolean false if fractions are equal, true if not
*/
bool Fraction::operator!=(const Fraction& rhs) const {
	return !((*this) == rhs);
}

/**
*	Overrides less than operator, checking that the value of num/den is larger for the other fraction than for this one.
*
*	@param rhs other fraction to be compaired with this one
*	@return boolean true if other fraction is greater than or equal to this one, false otherwise
*/
bool Fraction::operator<(const Fraction& rhs) const {
	return (numerator / (1.0 * denominator)) < (rhs.numerator / (1.0 * rhs.denominator));
}

/**
*	Overrides less than operator, checking that the value of num/den is larger for the first fraction than for the second.
*
*	@param lhs left hand fraction for the comparison
*	@param rhs right hand value to be compaired with the first
*	@return boolean true if right hand value is greater than or equal to the left hand fraction, false otherwise
*/
bool operator<(const Fraction lhs, const int rhs) {
	return (lhs.numerator / (1.0 * lhs.denominator)) < (rhs * 1.0);
}

/**
*	Overrides less than operator, checking that the value of num/den is larger for the second fraction than for the first.
*
*	@param lhs left hand value for the comparison
*	@param rhs right hand fraction to be compaired with the first
*	@return boolean true if right hand fraction is greater than or equal to the left hand value, false otherwise
*/
bool operator<(const int lhs, const Fraction rhs) {
	return (lhs * 1.0) < (rhs.numerator / (1.0 * rhs.denominator));
}

/**
*	Overrides less than or equal to operator, checking that the value of num/den is larger (or equal) for the other fraction than for this one.
*
*	@param rhs other fraction to be compaired with this one
*	@return boolean true if other fraction is greater than or equal to this one, false otherwise
*/
bool Fraction::operator<=(const Fraction& rhs) const {
	return (*this) < rhs || (*this) == rhs;
}

/**
*	Overrides less than or equal to operator, checking that the value of num/den is larger (or equal) for the other fraction than for this one.
*
*	@param lhs left hand fraction for the comparison
*	@param rhs right hand value to be compaired with the first
*	@return boolean true if right hand value is greater than the left hand value, false otherwise
*/
bool operator<=(const Fraction lhs, const int rhs){
	return lhs.numerator / (1.0 * lhs.denominator) < (rhs * 1.0) || lhs.numerator / (1.0 * lhs.denominator) == (rhs * 1.0);
}

/**
*	Overrides less than or equal to operator, checking that the value of num/den is larger (or equal) for the other fraction than for this one.
*
*	@param lhs left hand value for the comparison
*	@param rhs right hand fraction to be compaired with the first
*	@return boolean true if right hand value is greater than the left hand value, false otherwise
*/
bool operator<=(const int lhs, const Fraction rhs) {
	return (lhs * 1.0) < rhs.numerator / (1.0 * rhs.denominator) || (lhs * 1.0) == rhs.numerator / (1.0 * rhs.denominator);
}

/**
*	Overrides greater than operator, checking that the value of num/den is larger for the this fraction than for the other one.
*
*	@param rhs other fraction to be compaired with this one
*	@return boolean true if this fraction is greater than the other one, false otherwise
*/
bool Fraction::operator>(const Fraction& rhs) const {
	return (numerator / (1.0 * denominator)) > (rhs.numerator / (1.0 * rhs.denominator));
}
/**
*	Overrides greater than operator, checking that the value of num/den is larger for the first fraction than for the second.
*
*	@param lhs left hand fraction for the comparison
*	@param rhs right hand value to be compaired with the first
*	@return boolean true if left hand value is greater than the right hand fraction, false otherwise
*/
bool operator>(const Fraction lhs, const int rhs) {
	return (lhs.numerator / (1.0 * lhs.denominator)) > (rhs * 1.0);
}

/**
*	Overrides greater than operator, checking that the value of num/den is larger for the first fraction than for the second.
*
*	@param lhs left hand value for the comparison
*	@param rhs right hand fraction to be compaired with the first
*	@return boolean true if left hand fraction is greater than the right hand value, false otherwise
*/
bool operator>(const int lhs, const Fraction rhs) {
	return (lhs * 1.0) > (rhs.numerator / (1.0 * rhs.denominator));
}

/**
*	Overrides greater than or equal to operator, checking that the value of num/den is larger (or equal) for the this fraction than for this other one.
*
*	@param rhs other fraction to be compaired with this one
*	@return boolean true if this fraction is greater than or equal to the other one, false otherwise
*/
bool Fraction::operator>=(const Fraction& rhs) const {
	return (*this) > rhs || (*this) == rhs;
}

/**
*	Overrides greater than or equal to operator, checking that the value of num/den is larger (or equal) for the lhs fraction than for thie rhs.
*
*	@param lhs left hand fraction for the comparison
*	@param rhs right hand value to be compaired with the first
*	@return boolean true if left hand value is greater than or equal to the right hand value, false otherwise
*/
bool operator>=(const Fraction lhs, const int rhs) {
	return lhs.numerator / (1.0 * lhs.denominator) > (rhs * 1.0) || lhs.numerator / (1.0 * lhs.denominator) == (rhs * 1.0);
}

/**
*	Overrides greater than or equal to operator, checking that the value of num/den is larger (or equal) for the lhs fraction than for thie rhs.
*
*	@param lhs left hand fraction for the comparison
*	@param rhs right hand value to be compaired with the first
*	@return boolean true if left hand value is greater than or equal to the right hand value, false otherwise
*/
bool operator>=(const int lhs, const Fraction rhs) {
	return (lhs * 1.0) > rhs.numerator / (1.0 * rhs.denominator) || (lhs * 1.0) == rhs.numerator / (1.0 * rhs.denominator);
}

/**
*	Returns greatest common divisor
*/
Fraction Fraction::operator+(const Fraction& rhs) const {
	return Fraction(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
}

/**
*	Returns greatest common divisor
*/
Fraction operator+(const Fraction lhs, const int rhs) {
	int num = lhs.numerator + lhs.denominator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
Fraction operator+(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator + rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
void Fraction::operator+=(const Fraction& rhs) {
	*this = *this + rhs;
	reduce();
}

/**
*	Returns greatest common divisor
*/
void operator+=(Fraction &lhs, const int rhs) {
	lhs = lhs + rhs;
	lhs.reduce();
}

/**
*	Returns greatest common divisor
*/
Fraction Fraction::operator-(const Fraction& rhs) const {
	return Fraction(numerator * rhs.denominator - rhs.numerator * denominator, denominator * rhs.denominator);
}

/**
*	Returns greatest common divisor
*/
Fraction operator-(const Fraction lhs, const int rhs) {
	int num = lhs.numerator - lhs.denominator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
Fraction operator-(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator - rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
void Fraction::operator-=(const Fraction& rhs) {
	*this = *this - rhs;

	reduce();
}

/**
*	Returns greatest common divisor
*/
void operator-=(Fraction& lhs, const int rhs) {
	lhs = lhs - rhs;

	lhs.reduce();
}

/**
*	Returns greatest common divisor
*/
Fraction Fraction::operator*(const Fraction& rhs) const {
	int num = numerator * rhs.numerator;
	int den = denominator * rhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
Fraction operator*(const Fraction lhs, const int rhs) {
	int num = lhs.numerator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
Fraction operator*(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
void Fraction::operator*=(const Fraction& rhs) {
	*this = *this * rhs;
	reduce();
}

/**
*	Returns greatest common divisor
*/
void Fraction::operator*=(const int rhs) {
	*this = *this * rhs;
	reduce();
}

/**
*	Returns greatest common divisor
*/
Fraction Fraction::operator/(const Fraction& rhs) const {
	int num = numerator * rhs.denominator;
	int den = denominator * rhs.numerator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
Fraction operator/(const Fraction lhs, const int rhs) {
	int num = lhs.numerator;
	int den = lhs.denominator * rhs;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
Fraction operator/(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator;
	int den = rhs.numerator;
	return Fraction(num, den);
}

/**
*	Returns greatest common divisor
*/
void Fraction::operator/=(const Fraction& rhs) {
	*this = *this / rhs;
	reduce();
}

/**
*	Returns greatest common divisor
*/
void Fraction::operator/=(const int rhs) {
	*this = *this / rhs;
	reduce();
}

/**
*	Returns greatest common divisor
*/
std::ostream& operator <<(std::ostream& os, const Fraction& rhs) {
	os << rhs.numerator << "/" << rhs.denominator;
	return os;
}

/**
*	Returns greatest common divisor
*/
std::istream& operator >>(std::istream& is, Fraction& rhs) {
	char L;
	is >> rhs.numerator >> L >> rhs.denominator >> L;
	rhs.reduce();
	return is;
}

/**
*	Returns greatest common divisor
*/
void Fraction::reduce() {
	// Reduced Form
	int gcd = euclid(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}
}

/**
*	Returns greatest common divisor
*/
int Fraction::euclid(int num, int den) {
	if (den == 0)
		return num;
	return euclid(den, num % den);
}