#pragma once

#include <iostream>

/**
 * Field of complex numbers C
*/
class Complex
{
public:

	Complex() = default;
	Complex(const Complex &rhs);
	Complex(const float real, const float imaginary);

	Complex &operator=(const Complex &rhs);
	Complex operator+(const Complex &rhs) const;
	Complex operator-(const Complex &rhs) const;
	Complex operator-() const;
	Complex operator*(const Complex &rhs) const;
	Complex operator/(const Complex &rhs) const;
	bool operator==(const Complex &rhs) const;
	bool operator!=(const Complex &rhs) const;

	bool is_zero() const;

	friend std::ostream &operator<<(std::ostream &os, const Complex &rhs);

private:

	float _real {};
	float _i {};
};
