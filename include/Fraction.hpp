#ifndef FRACTION_HPP
# define FRACTION_HPP

#include <stdexcept>

class Fraction
{
public:

	Fraction() = default;
	Fraction(const Fraction &rhs);
	Fraction(const int numerator, const int denominator);

	Fraction &operator=(const Fraction &rhs);
	Fraction operator+(const Fraction &rhs) const;
	Fraction operator-(const Fraction &rhs) const;
	Fraction operator-() const;
	Fraction operator*(const Fraction &rhs) const;
	Fraction operator/(const Fraction &rhs) const;
	bool operator==(const Fraction &rhs) const;
	bool operator!=(const Fraction &rhs) const;

	class ZeroDenominatorException : public std::exception
	{
		const char *what() const throw();
	};

private:

	int _num {};
	int _denom { 1 };
};

#endif