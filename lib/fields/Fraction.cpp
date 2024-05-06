#include "Fraction.hpp"

const char *Fraction::ZeroDenominatorException::what() const throw()
{
	return "Denominator is 0";
}

Fraction::Fraction(const Fraction &rhs) : _num { rhs._num }, _denom { rhs._denom }
{
}

Fraction::Fraction(const int numerator, const int denominator) : _num { numerator }, _denom { denominator }
{
	if (_denom == 0)
		throw new ZeroDenominatorException();
}

Fraction &Fraction::operator=(const Fraction &rhs)
{
	_num = rhs._num;
	_denom = rhs._denom;
	return *this;
}

Fraction Fraction::operator+(const Fraction &rhs) const
{
	int num { (_num * rhs._denom) + (rhs._num * _denom) };
	int denom { _denom * rhs._denom };
	return Fraction { num, denom };
}

Fraction Fraction::operator-(const Fraction &rhs) const
{
	return *this + (-rhs);
}

Fraction Fraction::operator-() const
{
	return Fraction { -_num, _denom };
}

Fraction Fraction::operator*(const Fraction &rhs) const
{
	return Fraction { _num * rhs._num, _denom * rhs._denom };
}

Fraction Fraction::operator/(const Fraction &rhs) const
{
	return Fraction { _num * rhs._denom, _denom * rhs._num };
}

bool Fraction::operator==(const Fraction &rhs) const
{
	float left { static_cast<float>(_num) / _denom };
	float right { static_cast<float>(rhs._num) / rhs._denom };
	return left == right;
}

bool Fraction::operator!=(const Fraction &rhs) const
{
	return !(*this == rhs);
}
