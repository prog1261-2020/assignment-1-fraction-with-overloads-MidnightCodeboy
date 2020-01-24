#pragma once
#include <iostream>

class Fraction
{

public:
	explicit Fraction();

	Fraction(int numerator);

	Fraction(int numerator, int denominator);

	operator double () {
		return numerator / (1.0 * denominator);
	}

	

	bool operator==(const Fraction& rhs) const;

	bool operator!=(const Fraction& rhs) const;

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

	friend std::ostream& operator <<(std::ostream&, const Fraction&);
	friend std::istream& operator >>(std::istream&, Fraction&);
	

protected:
	int numerator;
	int denominator;

	void reduce();

	int euclid(int num, int den);
	

};

