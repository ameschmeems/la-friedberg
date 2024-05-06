#include "Real.hpp"

Real::Real(const Real &rhs) : _num { rhs._num }
{
}

Real::Real(const float num) : _num { num }
{
}

Real &Real::operator=(const Real &rhs)
{
	_num = rhs._num;
	return *this;
}

Real Real::operator+(const Real &rhs) const
{
	return Real { _num + rhs._num };
}

Real Real::operator-(const Real &rhs) const
{
	return Real { _num - rhs._num };
}

Real Real::operator-() const
{
	return Real { -_num };
}

Real Real::operator*(const Real &rhs) const
{
	return Real { _num * rhs._num };
}

Real Real::operator/(const Real &rhs) const
{
	return Real { _num / rhs._num };
}

bool Real::operator==(const Real &rhs) const
{
	return _num == rhs._num;
}

bool Real::operator!=(const Real &rhs) const
{
	return !(*this == rhs);
}

std::ostream &operator<<(std::ostream &os, const Real &rhs)
{
	os << rhs._num;
	return os;
}