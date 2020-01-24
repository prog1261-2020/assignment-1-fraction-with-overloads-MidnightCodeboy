#pragma once
/**
* @file		Fraction.h
* @author	Joseph Roy-Plommer
* @date		2020-01-24
* @version	<1.0>
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
* @section DESCRIPTION
*  Implements a mathematical fraction. Supports all the expected functionality of fractions.
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

#include <iostream>

class Fraction
{

public:
	explicit Fraction();
	Fraction(int numerator);
	Fraction(int numerator, int denominator);

	// Equality Operator Overloads
	bool operator==(const Fraction& rhs) const;
	bool operator!=(const Fraction& rhs) const;

	// Comparison Operator Overloads
	bool operator<(const Fraction& rhs) const;
	friend bool operator<(const Fraction lhs, const int rhs);
	friend bool operator<(const int lhs, const Fraction rhs);

	bool operator<=(const Fraction& rhs) const;
	friend bool operator<=(const Fraction lhs, const int rhs);
	friend bool operator<=(const int lhs, const Fraction rhs);

	bool operator>(const Fraction& rhs) const;
	friend bool operator>(const Fraction lhs, const int rhs);
	friend bool operator>(const int lhs, const Fraction rhs);

	bool operator>=(const Fraction& rhs) const;
	friend bool operator>=(const Fraction lhs, const int rhs);
	friend bool operator>=(const int lhs, const Fraction rhs);

	Fraction operator+(const Fraction& rhs) const;
	friend Fraction operator+(const Fraction lhs, const int rhs);
	friend Fraction operator+(const int lhs, const Fraction rhs);

	void operator+=(const Fraction& rhs);
	friend void operator+=(Fraction &lhs, const int rhs);

	Fraction operator-(const Fraction& rhs) const;
	friend Fraction operator-(const Fraction lhs, const int rhs);
	friend Fraction operator-(const int lhs, const Fraction rhs);

	void operator-=(const Fraction& rhs);
	friend void operator-=(Fraction& lhs, const int rhs);

	Fraction operator*(const Fraction& rhs) const;
	friend Fraction operator*(const Fraction lhs, const int rhs);
	friend Fraction operator*(const int lhs, const Fraction rhs);
	void operator*=(const Fraction& rhs);
	void operator*=(const int rhs);
	
	Fraction operator/(const Fraction& rhs) const;
	friend Fraction operator/(const Fraction lhs, const int rhs);
	friend Fraction operator/(const int lhs, const Fraction rhs);
	void operator/=(const Fraction& rhs);
	void operator/=(const int rhs);

	// Stream Manipulation Operator Overloads
	friend std::ostream& operator <<(std::ostream&, const Fraction&);
	friend std::istream& operator >>(std::istream&, Fraction&);
	
private:
	int numerator;
	int denominator;
	void reduce();
	int euclid(int num, int den);
	
};

