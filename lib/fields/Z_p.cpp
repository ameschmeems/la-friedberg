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

/**
 * Initializes object with val mod p value
*/
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

/**
 * Integers mod p addition
 * Throws PNotEqualException if the two numbers have different p values (and are therefore not the same field)
*/
Z_p Z_p::operator+(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw PNotEqualException();
	return Z_p { _p, (_val + rhs._val) % _p };
}

/**
 * Integers mod p subtraction
 * Throws PNotEqualException if the two numbers have different p values (and are therefore not the same field)
*/
Z_p Z_p::operator-(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw PNotEqualException();
	return *this + (-rhs);
}

/**
 * Integers mod p negation
*/
Z_p Z_p::operator-() const
{
	return Z_p { _p, (-_val) % _p };
}

/**
 * Integers mod p multiplication
 * Throws PNotEqualException if the two numbers have different p values (and are therefore not the same field)
*/
Z_p Z_p::operator*(const Z_p &rhs) const
{
	if (_p != rhs._p)
		throw PNotEqualException();
	return Z_p { _p, (_val * rhs._val) % _p };
}

/**
 * Integers mod p division
 * Throws PNotEqualException if the two numbers have different p values (and are therefore not the same field)
 * Throws DivisionByZeroException if denominator is 0
 * a / b results in the solution to bx = a (mod p)
*/
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

/**
 * Returns true if p and values are the same, otherwise false
*/
bool Z_p::operator==(const Z_p &rhs) const
{
	return (_p == rhs._p) && (_val == rhs._val);
}

/**
 * Returns true if p and values are different, otherwise false
*/
bool Z_p::operator!=(const Z_p &rhs) const
{
	return !(*this == rhs);
}

/**
 * True if value is 0, otherwise false
*/
bool Z_p::is_zero() const
{
	return _val == 0;
}

std::ostream &operator<<(std::ostream &os, const Z_p &rhs)
{
	os << rhs._val % rhs._p;
	return os;
}