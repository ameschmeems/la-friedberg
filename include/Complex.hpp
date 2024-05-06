#ifndef COMPLEX_HPP
# define COMPLEX_HPP

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

private:

	float _real {};
	float _i {};
};

#endif