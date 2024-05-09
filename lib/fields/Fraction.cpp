#include "Fraction.hpp"
#include "utils.hpp"

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
	int left { _num * rhs._denom };
	int right { _denom * rhs._num };
	return left == right;
}

bool Fraction::operator!=(const Fraction &rhs) const
{
	return !(*this == rhs);
}

bool Fraction::is_zero() const
{
	return _num == 0;
}

std::ostream &operator<<(std::ostream& os, const Fraction &rhs)
{
	os << rhs._num << "/" << rhs._denom;
	return os;
}
