#pragma once

#include <vector>
#include <iostream>

/**
 * Class for polynomials
*/
template<
	typename T,
	bool arithmetic = std::is_arithmetic<T>::value
>
class Polynomial;

/**
 * Polynomial over arithmetic types (int, float, etc)
*/
template<typename T>
class Polynomial<T, true>
{
public:

	Polynomial() = default;
	
	Polynomial(const Polynomial &rhs) : _coeffs { rhs._coeffs }
	{
	}

	Polynomial(Polynomial &&rhs) noexcept : _coeffs { std::move(rhs._coeffs) }
	{
	}

	/**
	 * Initializes object with polynomial coefficients
	 * Removes any trailing 0
	 * @param rhs	ordered list of polynomial coefficients, from lowest to highest degree
	*/
	Polynomial(const std::vector<T> &rhs) : _coeffs { rhs }
	{
		while (_coeffs[_coeffs.size()-1] == 0)
			_coeffs.pop_back();
	}

	/**
	 * Initializes object with polynomial coefficients
	 * Removes any trailing 0
	 * @param rhs	ordered list of polynomial coefficients, from lowest to highest degree
	*/
	Polynomial(std::vector<T> &&rhs) noexcept : _coeffs { std::move(rhs) }
	{
		while (_coeffs[_coeffs.size()-1] == 0)
			_coeffs.pop_back();
	}

	Polynomial &operator=(const Polynomial &rhs)
	{
		_coeffs = rhs._coeffs;
		return *this;
	}

	Polynomial &operator=(Polynomial &&rhs) noexcept
	{
		_coeffs = std::move(rhs._coeffs);
		return *this;
	}

	/**
	 * Polynomial addition
	*/
	Polynomial operator+(const Polynomial &rhs) const
	{
		std::vector<T> temp {};
		int degree = static_cast<int>(_coeffs.size() >= rhs._coeffs.size() ? _coeffs.size() : rhs._coeffs.size());
		for (int i = 0; i < degree; i++)
		{
			if (i < _coeffs.size() && i < rhs._coeffs.size())
				temp.push_back(_coeffs[i] + rhs._coeffs[i]);
			else if (i < _coeffs.size())
				temp.push_back(_coeffs[i]);
			else
				temp.push_back(rhs._coeffs[i]);
		}
		return Polynomial { std::move(temp) };
	}

	/**
	 * Polynomial subtraction
	*/
	Polynomial operator-(const Polynomial &rhs) const
	{
		std::vector<T> temp {};
		int degree = static_cast<int>(_coeffs.size() >= rhs._coeffs.size() ? _coeffs.size() : rhs._coeffs.size());
		for (int i = 0; i < degree; i++)
		{
			if (i < _coeffs.size() && i < rhs._coeffs.size())
				temp.push_back(_coeffs[i] - rhs._coeffs[i]);
			else if (i < _coeffs.size())
				temp.push_back(_coeffs[i]);
			else
				temp.push_back(-rhs._coeffs[i]);
		}
		return Polynomial { std::move(temp) };
	}

	/**
	 * Polynomial negation
	*/
	Polynomial operator-() const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(-_coeffs[i]);
		return Polynomial { std::move(temp) };
	}

	/**
	 * Scalar multiplication
	*/
	Polynomial operator*(const T &rhs) const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(rhs * _coeffs[i]);
		return Polynomial { std::move(temp) };
	}

	/**
	 * Polynomial multiplication
	*/
	Polynomial operator*(const Polynomial &rhs) const
	{
		int degree { static_cast<int>(_coeffs.size() + rhs._coeffs.size() - 1) };
		std::vector<T> temp {};
		for (int i = 0; i < degree; i++)
			temp.push_back(T());
		for (int i = 0; i < _coeffs.size(); i++)
		{
			for (int j = 0; j < rhs._coeffs.size(); j++)
				temp[i + j] += _coeffs[i] * rhs._coeffs[j];
		}
		return Polynomial { std::move(temp) };
	}

	/**
	 * Scalar division
	*/
	Polynomial operator/(const T &rhs) const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(_coeffs[i] / rhs);
		return Polynomial { std::move(temp) };
	}

	/**
	 * Returns the i-th coefficient
	*/
	T &operator[](std::size_t i)
	{
		return _coeffs[i];
	}

	/**
	 * True if all coefficients are equal, otherwise false
	*/
	bool operator==(const Polynomial &rhs) const
	{
		return _coeffs == rhs._coeffs;
	}

	/**
	 * True if any coefficients are different, otherwise false
	*/
	bool operator!=(const Polynomial &rhs) const
	{
		return !(*this == rhs);
	}

	/**
	 * Prints polynomial to os, any elements with a coefficient 0 are skipped
	*/
	friend std::ostream &operator<<(std::ostream &os, const Polynomial<T> &rhs)
	{
		int i {};
		os << "(";
		for (i = 0; i < rhs._coeffs.size() - 1; i++)
		{
			if (rhs._coeffs[i] != 0)
				os << rhs._coeffs[i] << "*x^" << i << " + ";
		}
		os << rhs._coeffs[i] << "*x^" << i << ")";
		return os;
	}

private:

	std::vector<T> _coeffs {};
};

/**
 * Polynomial over non-arithmetic types
 * Underlying types need to provide overloads for +, -, *, / operators and a is_zero() method
*/
template<typename T>
class Polynomial<T, false>
{
public:

	Polynomial() = default;
	
	Polynomial(const Polynomial &rhs) : _coeffs { rhs._coeffs }
	{
	}

	Polynomial(Polynomial &&rhs) noexcept : _coeffs { std::move(rhs._coeffs) }
	{
	}

	/**
	 * Initializes object with polynomial coefficients
	 * Removes any trailing 0
	 * @param rhs	ordered list of polynomial coefficients, from lowest to highest degree
	*/
	Polynomial(const std::vector<T> &rhs) : _coeffs { rhs }
	{
		while (_coeffs[_coeffs.size()-1].is_zero())
			_coeffs.pop_back();
	}

	/**
	 * Initializes object with polynomial coefficients
	 * Removes any trailing 0
	 * @param rhs	ordered list of polynomial coefficients, from lowest to highest degree
	*/
	Polynomial(std::vector<T> &&rhs) noexcept : _coeffs { std::move(rhs) }
	{
		while (_coeffs[_coeffs.size()-1].is_zero())
			_coeffs.pop_back();
	}

	Polynomial &operator=(const Polynomial &rhs)
	{
		_coeffs = rhs._coeffs;
		return *this;
	}

	Polynomial &operator=(Polynomial &&rhs) noexcept
	{
		_coeffs = std::move(rhs._coeffs);
		return *this;
	}

	/**
	 * Polynomial addition
	*/
	Polynomial operator+(const Polynomial &rhs) const
	{
		std::vector<T> temp {};
		int degree = static_cast<int>(_coeffs.size() >= rhs._coeffs.size() ? _coeffs.size() : rhs._coeffs.size());
		for (int i = 0; i < degree; i++)
		{
			if (i < _coeffs.size() && i < rhs._coeffs.size())
				temp.push_back(_coeffs[i] + rhs._coeffs[i]);
			else if (i < _coeffs.size())
				temp.push_back(_coeffs[i]);
			else
				temp.push_back(rhs._coeffs[i]);
		}
		return Polynomial { std::move(temp) };
	}

	/**
	 * Polynomial subtraction
	*/
	Polynomial operator-(const Polynomial &rhs) const
	{
		std::vector<T> temp {};
		int degree = static_cast<int>(_coeffs.size() >= rhs._coeffs.size() ? _coeffs.size() : rhs._coeffs.size());
		for (int i = 0; i < degree; i++)
		{
			if (i < _coeffs.size() && i < rhs._coeffs.size())
				temp.push_back(_coeffs[i] - rhs._coeffs[i]);
			else if (i < _coeffs.size())
				temp.push_back(_coeffs[i]);
			else
				temp.push_back(-rhs._coeffs[i]);
		}
		return Polynomial { std::move(temp) };
	}

	/**
	 * Polynomial negation
	*/
	Polynomial operator-() const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(-_coeffs[i]);
		return Polynomial { std::move(temp) };
	}

	/**
	 * Scalar multiplication
	*/
	Polynomial operator*(const T &rhs) const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(rhs * _coeffs[i]);
		return Polynomial { std::move(temp) };
	}

	/**
	 * Polynomial multiplication
	*/
	Polynomial operator*(const Polynomial &rhs) const
	{
		int degree { static_cast<int>(_coeffs.size() + rhs._coeffs.size() - 1) };
		std::vector<T> temp {};
		for (int i = 0; i < degree; i++)
			temp.push_back(T());
		for (int i = 0; i < _coeffs.size(); i++)
		{
			for (int j = 0; j < rhs._coeffs.size(); j++)
				temp[i + j] += _coeffs[i] * rhs._coeffs[j];
		}
		return Polynomial { std::move(temp) };
	}

	/**
	 * Scalar division
	*/
	Polynomial operator/(const T &rhs) const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(_coeffs[i] / rhs);
		return Polynomial { std::move(temp) };
	}

	/**
	 * Returns the i-th coefficient
	*/
	T &operator[](std::size_t i)
	{
		return _coeffs[i];
	}

	/**
	 * True if all coefficients are equal, otherwise false
	*/
	bool operator==(const Polynomial &rhs) const
	{
		return _coeffs == rhs._coeffs;
	}

	/**
	 * True if any coefficients are different, otherwise false
	*/
	bool operator!=(const Polynomial &rhs) const
	{
		return !(*this == rhs);
	}

	/**
	 * Prints polynomial to os, any elements with a coefficient 0 are skipped
	*/
	friend std::ostream &operator<<(std::ostream &os, const Polynomial<T> &rhs)
	{
		int i {};
		os << "(";
		for (i = 0; i < rhs._coeffs.size() - 1; i++)
		{
			if (!rhs._coeffs[i].is_zero())
				os << rhs._coeffs[i] << "*x^" << i << " + ";
		}
		os << rhs._coeffs[i] << "*x^" << i << ")";
		return os;
	}

private:

	std::vector<T> _coeffs {};
};

/**
 * Scalar multiplication, when scalar is on the left
*/
template<typename T>
Polynomial<T> operator*(T i, const Polynomial<T> &rhs)
{
	return rhs * i;
}
