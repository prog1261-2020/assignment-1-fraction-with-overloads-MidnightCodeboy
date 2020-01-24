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
*	Returns a new fraction which is the sum of this one and the provided one.
*
*	@param rhs fraction to be added to this one.
*	@return the sum of this fraction and the provided one as a new Fraction
*/
Fraction Fraction::operator+(const Fraction& rhs) const {
	return Fraction(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
}

/**
*	Returns a new fraction which is the sum of two provided values.
*
*	@param lhs first fraction to be added to the second
*	@param rhs second fraction to be added to the first
*	@return the sum of the provided values as a new Fraction
*/
Fraction operator+(const Fraction lhs, const int rhs) {
	int num = lhs.numerator + lhs.denominator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns a new fraction which is the sum of two provided values.
*
*	@param lhs first fraction to be added to the second
*	@param rhs second fraction to be added to the first
*	@return the sum of the provided values as a new Fraction
*/
Fraction operator+(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator + rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}

/**
*	Replaces this fraction with a new fraction which is the sum of this one and the provided fraction.
*
*	@param rhs fraction to be added to this one
*/
void Fraction::operator+=(const Fraction& rhs) {
	*this = *this + rhs;
	reduce();
}

/**
*	Replaces provided fraction with a new one which is the sum of the provided fraction and the provided integer value (interpreted as a fraction).
*
*	@param lhs fraction to be added to
*	@param rhs integer to be added (as a fraction) to lhs fraction
*/
void operator+=(Fraction &lhs, const int rhs) {
	lhs = lhs + rhs;
	lhs.reduce();
}

/**
*	Returns a new fraction which is the difference between this one and the provided one.
*
*	@param rhs fraction to be subtracted from this one.
*	@return the difference between this fraction and the provided one as a new Fraction
*/
Fraction Fraction::operator-(const Fraction& rhs) const {
	return Fraction(numerator * rhs.denominator - rhs.numerator * denominator, denominator * rhs.denominator);
}

/**
*	Returns a new fraction which is the differencebetween two provided values.
*
*	@param lhs first fraction to be subtracted from
*	@param rhs second fraction to be subtracted from the first
*	@return the difference between the provided values as a new Fraction
*/
Fraction operator-(const Fraction lhs, const int rhs) {
	int num = lhs.numerator - lhs.denominator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

/**
*	Returns a new fraction which is the difference between the two provided values.
*
*	@param lhs integer representing the first fraction to be subtracted from
*	@param rhs second fraction to be subtracted from the first
*	@return the difference between the provided values as a new Fraction
*/
Fraction operator-(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator - rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}

/**
*	Replaces this fraction with a new fraction which is the difference this one and the provided fraction.
*
*	@param rhs fraction to be subtracted from this one
*/
void Fraction::operator-=(const Fraction& rhs) {
	*this = *this - rhs;

	reduce();
}

/**
*	Replaces provided fraction with a new one which is the difference between the provided fraction and the provided integer value (interpreted as a fraction).
*
*	@param lhs fraction to be subtracted from
*	@param rhs integer (interpreted as a fraction) to be subtracted from lhs fraction
*/
void operator-=(Fraction& lhs, const int rhs) {
	lhs = lhs - rhs;

	lhs.reduce();
}

/**
*	Multiplies this fraction by the provided fraction and returns result as a new Fraction.
*
*	@param rhs fraction to be multiplied by this one
*	@return a new fraction which is the product of this fraction and the one provided
*/
Fraction Fraction::operator*(const Fraction& rhs) const {
	int num = numerator * rhs.numerator;
	int den = denominator * rhs.denominator;
	return Fraction(num, den);
}

/**
*	Multiplies first provided fraction by the provided int (interpreted as a fraction) and returns result as a new Fraction.
*
*	@param lhs first fraction to be multiplied
*	@param rhs integer (interpreted as a fraction) to be multiplied by the first fraction
*	@return a new fraction which is the product of the two provided values
*/
Fraction operator*(const Fraction lhs, const int rhs) {
	int num = lhs.numerator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

/**
*	Multiplies first provided int (interpreted as a fraction) by the provided fraction and returns result as a new Fraction.
*
*	@param lhs first integer (interpreted as a fraction) to be multiplied
*	@param rhs fraction to be multiplied by the first value
*	@return a new fraction which is the product of the two provided values
*/
Fraction operator*(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}

/**
*	Replaces this fraction with a new fraction which is the sum of this one and the provided one.
*
*	@param rhs fraction to be multiplied by this one
*/
void Fraction::operator*=(const Fraction& rhs) {
	*this = *this * rhs;
	reduce();
}

/**
*	Replaces this fraction with a new fraction which is the sum of this one and the provided int (interpreted as a fraction).
*
*	@param rhs int (interpreted as a fraction) to be multiplied by this one
*/
void Fraction::operator*=(const int rhs) {
	*this = *this * rhs;
	reduce();
}

/**
*	Divides this fraction by the provided fraction and returns result as a new Fraction.
*
*	@param rhs fraction to be divided into this one
*	@return a new fraction which is this fraction divided by the one provided
*/
Fraction Fraction::operator/(const Fraction& rhs) const {
	int num = numerator * rhs.denominator;
	int den = denominator * rhs.numerator;
	return Fraction(num, den);
}

/**
*	Divides first provided fraction by the provided int (interpreted as a fraction) and returns result as a new Fraction.
*
*	@param lhs first fraction to be divided into
*	@param rhs integer (interpreted as a fraction) to be divided into the first fraction
*	@return a new fraction which is the result of dividing the two provided values
*/
Fraction operator/(const Fraction lhs, const int rhs) {
	int num = lhs.numerator;
	int den = lhs.denominator * rhs;
	return Fraction(num, den);
}

/**
*	Divides first provided int (interpreted as a fraction) by the provided fraction and returns result as a new Fraction.
*
*	@param lhs first integer (interpreted as a fraction) to be divided into
*	@param rhs fraction to be divided into the first value
*	@return a new fraction which is the result of dividing the two provided values
*/
Fraction operator/(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator;
	int den = rhs.numerator;
	return Fraction(num, den);
}

/**
*	Replaces this fraction with a new fraction which is this one divided by the provided one.
*
*	@param rhs fraction to be divided into this one
*/
void Fraction::operator/=(const Fraction& rhs) {
	*this = *this / rhs;
	reduce();
}

/**
*	Replaces this fraction with a new fraction which is one divided by the provided int (interpreted as a fraction).
*
*	@param rhs int (interpreted as a fraction) to be divided into this one
*/
void Fraction::operator/=(const int rhs) {
	*this = *this / rhs;
	reduce();
}

/**
*	Overrides the stream insertion operator by inserting a string representation of the fraction and returning the stream.
*
*	@param os outputstream that the fraction string is written to
*	@param rhs fraction whos string representation is inserted into the outputstream
*	@return the provided outputstream after inserting into it
*/
std::ostream& operator <<(std::ostream& os, const Fraction& rhs) {
	os << rhs.numerator << "/" << rhs.denominator;
	return os;
}

/**
*	Overrides the stream extraction operator by extracting a string representation of the fraction from it, assigning these values to a fraction and returning the stream.
*
*	@param is inputstream that the fraction string is extracted from
*	@param rhs fraction whos values are set from the contents of the provided fraction
*	@return the provided inputstream after extracting from it
*/
std::istream& operator >>(std::istream& is, Fraction& rhs) {
	char L;
	is >> rhs.numerator >> L >> rhs.denominator >> L;
	rhs.reduce();
	return is;
}

/**
*	Puts this fraction into its simplest form.
*	uses euclidean algorithm to find largst common divisor (gcd) of the numerator and denominator of this fraction.
*	Divides numerator and denominator by the gcd to put this fraction into its simplest form.
*	Makes sure the -ve character is attached to the numerator (not the denominator) in negative fractions.
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
*	Finds the greatest common divisor of thw provided numbers using the Euclidean algorithm.
*
*	@param num numerator of a fraction
*	@param den denominator of a fraction
*	@return the greatest common divisor of the two provided numbers
*/
int Fraction::euclid(int num, int den) {
	if (den == 0)
		return num;
	return euclid(den, num % den);
}