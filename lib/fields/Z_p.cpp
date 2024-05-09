#include "Z_p.hpp"
#include "utils.hpp"

const char *Z_p::PNotEqualException::what() const throw()
{
	return "P values are not equal";
}

const char *Z_p::PNotPrimeException::what() const throw()
{
	return "P is not prime";
}

const char *Z_p::DivisionByZeroException::what() const throw()
{
	return "Division by zero";
}

Z_p::Z_p(const Z_p &rhs) : _p { rhs._p }, _val { rhs._val }
{
}

Z_p::Z_p(const int p, const int val) : _p { p }, _val { val }
{
	if (p <= 1)
		throw PNotPrimeException();
	for (int i = 2; i <= p / 2; i++)
	{
		if (p % i == 0)
			throw PNotPrimeException();
	}
}

Z_p &Z_p::operator=(const Z_p &rhs)
{
	if (_p != rhs._p)
		throw PNotEqualException();
	_val = rhs._val;
	return *this;
}

Z_p Z_p::operator+(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw PNotEqualException();
	return Z_p { _p, (_val + rhs._val) % _p };
}

Z_p Z_p::operator-(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw PNotEqualException();
	return *this + (-rhs);
}

Z_p Z_p::operator-() const
{
	return Z_p { _p, (-_val) % _p };
}

Z_p Z_p::operator*(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw PNotEqualException();
	return Z_p { _p, (_val * rhs._val) % _p };
}

Z_p Z_p::operator/(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw PNotEqualException();
	if (rhs._val == 0)
		throw DivisionByZeroException();
	int u {};
	int v {};
	int g = bezout_algorithm(rhs._val, _p, u, v);
	if (rhs._val > _p)
		return Z_p { _p, (_val * u) % _p };
	return Z_p { _p, (_val * v) % _p };
}

bool Z_p::operator==(const Z_p &rhs) const
{
	return (_p == rhs._p) && (_val == rhs._val);
}

bool Z_p::operator!=(const Z_p &rhs) const
{
	return !(*this == rhs);
}

std::ostream &operator<<(std::ostream &os, const Z_p &rhs)
{
	os << rhs._val % rhs._p;
	return os;
}