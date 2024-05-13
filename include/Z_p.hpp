#pragma once

#include <iostream>
#include <stdexcept>

/**
 * The field of integers mod p
*/
class Z_p
{
public:

	Z_p() = default;
	Z_p(const Z_p &rhs);
	Z_p(const int p, const int val);

	Z_p &operator=(const Z_p &rhs);
	Z_p operator+(const Z_p &rhs) const;
	Z_p operator-(const Z_p &rhs) const;
	Z_p operator-() const;
	Z_p operator*(const Z_p &rhs) const;
	Z_p operator/(const Z_p &rhs) const;
	bool operator==(const Z_p &rhs) const;
	bool operator!=(const Z_p &rhs) const;

	bool is_zero() const;

	friend std::ostream &operator<<(std::ostream &os, const Z_p &rhs);

	class PNotEqualException : public std::exception
	{
		const char *what() const throw();
	};

	class PNotPrimeException : public std::exception
	{
		const char *what() const throw();
	};

	class DivisionByZeroException : public std::exception
	{
		const char *what() const throw();
	};

private:

	int _p { 2 };
	int _val {};
};
