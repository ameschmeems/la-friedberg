#include "Complex.hpp"

/**
 * Initialize object with a complex number value
 * @param real		real part of the complex number
 * @param imaginary	imaginary part of the complex number
*/
Complex::Complex(const float real, const float imaginary) : _real { real }, _i { imaginary }
{
}

Complex::Complex(const Complex &rhs) : _real { rhs._real }, _i { rhs._i }
{
}

Complex &Complex::operator=(const Complex &rhs)
{
	_real = rhs._real;
	_i = rhs._i;
	return *this;
}

/**
 * Complex number addition
*/
Complex Complex::operator+(const Complex &rhs) const
{
	return Complex { _real + rhs._real, _i + rhs._i };
}

/**
 * Complex number subtraction
*/
Complex Complex::operator-(const Complex &rhs) const
{
	return Complex { _real -rhs._real, _i - rhs._i };
}

/**
 * Complex number negation
*/
Complex Complex::operator-() const
{
	return Complex { -_real, -_i };
}

/**
 * Complex number multiplication ((a + bi)(c + di) = (ac - bd) + (ad + bc)i)
*/
Complex Complex::operator*(const Complex &rhs) const
{
	float real { (_real * rhs._real) - (_i * rhs._i) };
	float i { (_real * rhs._i) + (_i * rhs._real) };
	return Complex { real, i };
}

/**
 * Complex number division ((a + bi)/(c + di) = ((ac + bd) + (bc - ad)i)/(c^2 + d^2))
*/
Complex Complex::operator/(const Complex &rhs) const
{
	float denum { (rhs._real * rhs._real) + (rhs._i * rhs._i) };
	float real { ((_real * rhs._real) + (_i  * rhs._i)) / denum };
	float i { ((_i * rhs._real) - (_real * rhs._i))/denum };
	return Complex { real, i };
}

/**
 * True if real and imaginary parts are equal, otherwise false
*/
bool Complex::operator==(const Complex &rhs) const
{
	return (_real == rhs._real) && (_i == rhs._i);
}

/**
 * True if either real or imaginary parts are different, otherwise false
*/
bool Complex::operator!=(const Complex &rhs) const
{
	return !(*this == rhs);
}

/**
 * True if both real and imaginary parts are 0, otherwise false
*/
bool Complex::is_zero() const
{
	return (_real == 0) && (_i == 0); 
}

std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
	os << rhs._real << " + " << rhs._i << "i";
	return os;
}