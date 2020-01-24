// Fraction.cpp : Defines the functions for the static library.
//

#include "Fraction.h"
#include <algorithm>
#include <vector>

Fraction::Fraction() {
	Fraction(1);
}

Fraction::Fraction(int numerator) {
	Fraction(numerator, 1);
}

Fraction::Fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
	
	reduce();
}



// TODO:: Fix this for almost equal floats
bool Fraction::operator==(const Fraction& rhs) const {
	return (numerator / (1.0 * denominator)) == (rhs.numerator / (1.0 * rhs.denominator));
}

bool Fraction::operator!=(const Fraction& rhs) const {
	return !((*this) == rhs);
}

bool Fraction::operator<(const Fraction& rhs) const {
	return (numerator / (1.0 * denominator)) < (rhs.numerator / (1.0 * rhs.denominator));
}


bool operator<(const Fraction lhs, const int rhs) {
	return (lhs.numerator / (1.0 * lhs.denominator)) < (rhs * 1.0);
}

bool operator<(const int lhs, const Fraction rhs) {
	return (lhs * 1.0) < (rhs.numerator / (1.0 * rhs.denominator));
}

bool Fraction::operator<=(const Fraction& rhs) const {
	return (*this) < rhs || (*this) == rhs;
}

bool operator<=(const Fraction lhs, const int rhs){
	return lhs.numerator / (1.0 * lhs.denominator) < (rhs * 1.0) || lhs.numerator / (1.0 * lhs.denominator) == (rhs * 1.0);
}

bool operator<=(const int lhs, const Fraction rhs) {
	return (lhs * 1.0) < rhs.numerator / (1.0 * rhs.denominator) || (lhs * 1.0) == rhs.numerator / (1.0 * rhs.denominator);
}

bool Fraction::operator>(const Fraction& rhs) const {
	return (numerator / (1.0 * denominator)) > (rhs.numerator / (1.0 * rhs.denominator));
}

bool operator>(const Fraction lhs, const int rhs) {
	return (lhs.numerator / (1.0 * lhs.denominator)) > (rhs * 1.0);
}

bool operator>(const int lhs, const Fraction rhs) {
	return (lhs * 1.0) > (rhs.numerator / (1.0 * rhs.denominator));
}

bool Fraction::operator>=(const Fraction& rhs) const {
	return (*this) > rhs || (*this) == rhs;
}

bool operator>=(const Fraction lhs, const int rhs) {
	return lhs.numerator / (1.0 * lhs.denominator) > (rhs * 1.0) || lhs.numerator / (1.0 * lhs.denominator) == (rhs * 1.0);
}

bool operator>=(const int lhs, const Fraction rhs) {
	return (lhs * 1.0) > rhs.numerator / (1.0 * rhs.denominator) || (lhs * 1.0) == rhs.numerator / (1.0 * rhs.denominator);
}

Fraction Fraction::operator+(const Fraction& rhs) const {
	return Fraction(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
}

Fraction operator+(const Fraction lhs, const int rhs) {
	int num = lhs.numerator + lhs.denominator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

Fraction operator+(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator + rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}

void Fraction::operator+=(const Fraction& rhs) {
	*this = *this + rhs;

	reduce();
}

void operator+=(Fraction &lhs, const int rhs) {
	lhs = lhs + rhs;

	lhs.reduce();
}

Fraction Fraction::operator-(const Fraction& rhs) const {
	return Fraction(numerator * rhs.denominator - rhs.numerator * denominator, denominator * rhs.denominator);
}

Fraction operator-(const Fraction lhs, const int rhs) {
	int num = lhs.numerator - lhs.denominator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

Fraction operator-(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator - rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}

void Fraction::operator-=(const Fraction& rhs) {
	*this = *this - rhs;

	reduce();
}

void operator-=(Fraction& lhs, const int rhs) {
	lhs = lhs - rhs;

	lhs.reduce();
}



Fraction Fraction::operator*(const Fraction& rhs) const {
	int num = numerator * rhs.numerator;
	int den = denominator * rhs.denominator;
	return Fraction(num, den);
}

Fraction operator*(const Fraction lhs, const int rhs) {
	int num = lhs.numerator * rhs;
	int den = lhs.denominator;
	return Fraction(num, den);
}

Fraction operator*(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.numerator;
	int den = rhs.denominator;
	return Fraction(num, den);
}


void Fraction::operator*=(const Fraction& rhs) {
	*this = *this * rhs;

	reduce();
}

void Fraction::operator*=(const int rhs) {
	*this = *this * rhs;

	reduce();
}


Fraction Fraction::operator/(const Fraction& rhs) const {
	int num = numerator * rhs.denominator;
	int den = denominator * rhs.numerator;
	return Fraction(num, den);
}

Fraction operator/(const Fraction lhs, const int rhs) {
	int num = lhs.numerator;
	int den = lhs.denominator * rhs;
	return Fraction(num, den);
}

Fraction operator/(const int lhs, const Fraction rhs) {
	int num = lhs * rhs.denominator;
	int den = rhs.numerator;
	return Fraction(num, den);
}


void Fraction::operator/=(const Fraction& rhs) {
	*this = *this / rhs;

	reduce();
}

void Fraction::operator/=(const int rhs) {
	*this = *this / rhs;

	reduce();
}

std::ostream& operator <<(std::ostream& os, const Fraction& rhs) {
	os << rhs.numerator << "/" << rhs.denominator;
	return os;
}

std::istream& operator >>(std::istream& is, Fraction& rhs) {
	
	char L;

	is >> rhs.numerator >> L >> rhs.denominator >> L;	
	
	return is;
}

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


/*
*	Returns greatest common divisor
*/
int Fraction::euclid(int num, int den) {
	if (den == 0)
		return num;
	return euclid(den, num % den);
}