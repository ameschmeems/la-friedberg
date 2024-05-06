#include "Z_p.hpp"

const char *Z_p::PNotEqualException::what() const throw()
{
	return "P values are not equal";
}

Z_p::Z_p(const Z_p &rhs) : _p { rhs._p }, _val { rhs._val }
{
}

Z_p::Z_p(const int p, const int val) : _p { p }, _val { val }
{
}

Z_p &Z_p::operator=(const Z_p &rhs)
{
	if (_p != rhs._p)
		throw new PNotEqualException();
	_val = rhs._val;
	return *this;
}

Z_p Z_p::operator+(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw new PNotEqualException();
	return Z_p { _p, (_val + rhs._val) % _p };
}

Z_p Z_p::operator-(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw new PNotEqualException();
	return *this + (-rhs);
}

Z_p Z_p::operator-() const
{
	return Z_p { _p, (-_val) % _p };
}

Z_p Z_p::operator*(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw new PNotEqualException();
	return Z_p { _p, (_val * rhs._val) % _p };
}

Z_p Z_p::operator/(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw new PNotEqualException();
	return Z_p { _p, (_val / rhs._val) % _p };
}

bool Z_p::operator==(const Z_p &rhs) const
{
	return (_p == rhs._p) && (_val == rhs._val);
}

bool Z_p::operator!=(const Z_p &rhs) const
{
	return !(*this == rhs);
}