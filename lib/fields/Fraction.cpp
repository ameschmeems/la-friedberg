#include "Fraction.hpp"
#include "utils.hpp"

const char *Fraction::ZeroDenominatorException::what() const throw()
{
	return "Denominator is 0";
}

Fraction::Fraction(const Fraction &rhs) : _num { rhs._num }, _denom { rhs._denom }
{
}

/**
 * Initialize object with a fraction value
 * Uses the bezout algorithm to find the greates common divisor and simplify the fraction
 * Throws a ZeroDenominatorException if denominator is 0
 * @param numerator		numerator of the fraction
 * @param denominator	denominator of the fraction
*/
Fraction::Fraction(const int numerator, const int denominator) : _num { numerator }, _denom { denominator }
{
	if (_denom == 0)
		throw ZeroDenominatorException();
	int u {};
	int v {};
	int g { bezout_algorithm(_num, _denom, u, v) };
	_num /= g;
	_denom /= g;
}

Fraction &Fraction::operator=(const Fraction &rhs)
{
	_num = rhs._num;
	_denom = rhs._denom;
	return *this;
}

/**
 * Fraction addition
*/
Fraction Fraction::operator+(const Fraction &rhs) const
{
	int num { (_num * rhs._denom) + (rhs._num * _denom) };
	int denom { _denom * rhs._denom };
	return Fraction { num, denom };
}

/**
 * Fraction subtraction
*/
Fraction Fraction::operator-(const Fraction &rhs) const
{
	return *this + (-rhs);
}

/**
 * Fraction negation
*/
Fraction Fraction::operator-() const
{
	return Fraction { -_num, _denom };
}

/**
 * Fraction multiplication
*/
Fraction Fraction::operator*(const Fraction &rhs) const
{
	return Fraction { _num * rhs._num, _denom * rhs._denom };
}

/**
 * Fraction division
*/
Fraction Fraction::operator/(const Fraction &rhs) const
{
	return Fraction { _num * rhs._denom, _denom * rhs._num };
}

/**
 * True if the values of the fractions are equal
 * Uses the fact that if a/b = c/d then ad = bc
*/
bool Fraction::operator==(const Fraction &rhs) const
{
	int left { _num * rhs._denom };
	int right { _denom * rhs._num };
	return left == right;
}

/**
 * True if the values of the fractions are different, otherwise false
*/
bool Fraction::operator!=(const Fraction &rhs) const
{
	return !(*this == rhs);
}

/**
 * True if numerator is 0
*/
bool Fraction::is_zero() const
{
	return _num == 0;
}

std::ostream &operator<<(std::ostream& os, const Fraction &rhs)
{
	os << rhs._num << "/" << rhs._denom;
	return os;
}
