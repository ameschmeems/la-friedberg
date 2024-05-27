#include "Real.hpp"

Real::Real(const Real &rhs) : _num { rhs._num }
{
}

/**
 * Initializes object with real number value
 * @param num	the value of underlying real number
*/
Real::Real(const float num) : _num { num }
{
}

Real &Real::operator=(const Real &rhs)
{
	_num = rhs._num;
	return *this;
}

/**
 * Real number addition
*/
Real Real::operator+(const Real &rhs) const
{
	return Real { _num + rhs._num };
}

Real &Real::operator+=(const Real &rhs)
{
	*this = *this + rhs;
	return *this;
}

/**
 * Real number subtraction
*/
Real Real::operator-(const Real &rhs) const
{
	return Real { _num - rhs._num };
}

Real &Real::operator-=(const Real &rhs)
{
	*this = *this - rhs;
	return *this;
}

/**
 * Real number negation
*/
Real Real::operator-() const
{
	return Real { -_num };
}

/**
 * Real number multiplication
*/
Real Real::operator*(const Real &rhs) const
{
	return Real { _num * rhs._num };
}

Real &Real::operator*=(const Real &rhs)
{
	*this = *this * rhs;
	return *this;
}

/**
 * Real number division
*/
Real Real::operator/(const Real &rhs) const
{
	return Real { _num / rhs._num };
}

Real &Real::operator/=(const Real &rhs)
{
	*this = *this / rhs;
	return *this;
}

bool Real::operator<(const Real &rhs) const
{
	return _num < rhs._num;
}

bool Real::operator<=(const Real &rhs) const
{
	return _num <= rhs._num;
}

bool Real::operator>(const Real &rhs) const
{
	return _num > rhs._num;
}

bool Real::operator>=(const Real &rhs) const
{
	return _num >= rhs._num;
}

/**
 * True if numbers are equal, otherwise false
*/
bool Real::operator==(const Real &rhs) const
{
	return _num == rhs._num;
}

/**
 * True if numbers are not equal, otherwise false
*/
bool Real::operator!=(const Real &rhs) const
{
	return !(*this == rhs);
}

/**
 * True if the number is equal to 0
*/
bool Real::is_zero() const
{
	return _num == 0;
}

std::ostream &operator<<(std::ostream &os, const Real &rhs)
{
	os << rhs._num;
	return os;
}