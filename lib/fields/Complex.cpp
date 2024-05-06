#include "Complex.hpp"

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

Complex Complex::operator+(const Complex &rhs) const
{
	return Complex { _real + rhs._real, _i + rhs._i };
}

Complex Complex::operator-(const Complex &rhs) const
{
	return Complex { _real -rhs._real, _i - rhs._i };
}

Complex Complex::operator-() const
{
	return Complex { -_real, -_i };
}

#include <iostream>

Complex Complex::operator*(const Complex &rhs) const
{
	float real { (_real * rhs._real) - (_i * rhs._i) };
	float i { (_real * rhs._i) + (_i * rhs._real) };
	return Complex { real, i };
}

Complex Complex::operator/(const Complex &rhs) const
{
	float denum { (rhs._real * rhs._real) + (rhs._i * rhs._i) };
	float real { ((_real * rhs._real) + (_i  * rhs._i)) / denum };
	float i { ((_i * rhs._real) - (_real * rhs._i))/denum };
	return Complex { real, i };
}

bool Complex::operator==(const Complex &rhs) const
{
	return (_real == rhs._real) && (_i == rhs._i);
}

bool Complex::operator!=(const Complex &rhs) const
{
	return !(*this == rhs);
}

std::ostream &operator<<(std::ostream &os, const Complex &rhs)
{
	os << rhs._real << " + " << rhs._i << "i";
	return os;
}