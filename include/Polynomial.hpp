#ifndef POLYNOMIAL_HPP
# define POLYNOMIAL_HPP

#include <vector>
#include <iostream>

template<typename T>
class Polynomial
{
public:

	Polynomial() = default;
	
	Polynomial(const Polynomial &rhs) : _coeffs { rhs._coeffs }
	{
	}

	Polynomial(Polynomial &&) noexcept : _coeffs { std::move(rhs._coeffs) }
	{
	}

	Polynomial(const std::vector<T> &rhs) : _coeffs { rhs }
	{
	}

	Polynomial(std::vector<T> &&rhs) noexcept : _coeffs { std::move(rhs) }
	{
	}

	Polynomial &operator=(const Polynomial &rhs)
	{
		_coeffs = rhs._coeffs;
	}

	Polynomial &operator=(Polynomial &&rhs) noexcept
	{
		_coeffs = std::move(rhs._coeffs);
	}

	Polynomial &operator+(const Polynomial &rhs) const
	{
		std::vector temp {};
		int degree = _coeffs.size() <= rhs._coeffs.size() ? _coeffs.size() : rhs._coeffs.size();
		for (int i = 0; i < degree; i++)
		{
			if (_coeffs.size() < i && rhs._coeffs.size() < i)
				temp.push_back(_coeffs[i] + rhs._coeffs[i]);
			else if (_coeffs.size() < i)
				temp.push_back(_coeffs[i]);
			else
				temp.push_back(rhs._coeffs[i]);
		}
		return Polynomial { std::move(temp) };
	}

	Polynomial &operator-(const Polynomial &rhs) const
	{
		std::vector temp {};
		int degree = _coeffs.size() <= rhs._coeffs.size() ? _coeffs.size() : rhs._coeffs.size();
		for (int i = 0; i < degree; i++)
		{
			if (_coeffs.size() < i && rhs._coeffs.size() < i)
				temp.push_back(_coeffs[i] - rhs._coeffs[i]);
			else if (_coeffs.size() < i)
				temp.push_back(_coeffs[i]);
			else
				temp.push_back(-rhs._coeffs[i]);
		}
		return Polynomial { std::move(temp) };
	}

	Polynomial &operator-() const
	{
		std::vector temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(-_coeffs[i]);
		return Polynomial { std::move(temp) };
	}

	Polynomial &operator*(const T &rhs) const
	{
		std::vector temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(rhs * _coeffs[i]);
		return Polynomial { std::move(temp) };
	}

	Polynomial &operator*(const Polynomial &rhs) const
	{
		// TODO
	}

	Polynomial &operator/(const T &rhs) const
	{
		std::vector temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(_coeffs[i] / rhs);
		return Polynomial { std::move(temp) };
	}

	T &operator[](std::size_t i)
	{
		return _coeffs[i];
	}

	bool operator==(const Polynomial &rhs) const
	{
		return _coeffs == rhs._coeffs;
	}

	bool operator!=(const Polynomial &rhs) const
	{
		return !(*this == rhs);
	}

	friend std::ostream &operator<<(std::ostream &os, const Polynomial &rhs);

private:

	// ordered list of coefficients
	// when ax_0 + bx_1, _coeffs[0] == a and _coeffs[1] == b
	std::vector<T> _coeffs;
};

template<typename T>
Polynomial<T> operator*(T i, const Polynomial<T> &rhs)
{
	return rhs * i;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Polynomial<T> &rhs)
{
	int i {};
	for (i = 0; i < rhs._coeffs.size() - 1; i++)
	{
		os << rhs._coeffs[i] << "*x^" << i << " + ";
	}
	os << rhs._coeffs[i] << "*x^" << i;
}

#endif