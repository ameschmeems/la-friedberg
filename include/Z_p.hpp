#ifndef Z_P_HPP
# define Z_P_HPP

#include <iostream>
#include <stdexcept>

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

	friend std::ostream &operator<<(std::ostream &os, const Z_p &rhs);

	class PNotEqualException : public std::exception
	{
		const char *what() const throw();
	};

private:

	int _p { 1 };
	int _val {};
};

#endif