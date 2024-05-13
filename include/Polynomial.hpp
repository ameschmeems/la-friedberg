#pragma once

#include <vector>
#include <iostream>

template<
	typename T,
	bool arithmetic = std::is_arithmetic<T>::value
>
class Polynomial;

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

	Polynomial(const std::vector<T> &rhs) : _coeffs { rhs }
	{
		while (_coeffs[_coeffs.size()-1] == 0)
			_coeffs.pop_back();
	}

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

	Polynomial operator-() const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(-_coeffs[i]);
		return Polynomial { std::move(temp) };
	}

	Polynomial operator*(const T &rhs) const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(rhs * _coeffs[i]);
		return Polynomial { std::move(temp) };
	}

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

	Polynomial operator/(const T &rhs) const
	{
		std::vector<T> temp {};
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

	// ordered list of coefficients
	// when ax_0 + bx_1, _coeffs[0] == a and _coeffs[1] == b
	std::vector<T> _coeffs {};
};

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

	Polynomial(const std::vector<T> &rhs) : _coeffs { rhs }
	{
		while (_coeffs[_coeffs.size()-1].is_zero())
			_coeffs.pop_back();
	}

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

	Polynomial operator-() const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(-_coeffs[i]);
		return Polynomial { std::move(temp) };
	}

	Polynomial operator*(const T &rhs) const
	{
		std::vector<T> temp {};
		for (int i = 0; i < _coeffs.size(); i++)
			temp.push_back(rhs * _coeffs[i]);
		return Polynomial { std::move(temp) };
	}

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

	Polynomial operator/(const T &rhs) const
	{
		std::vector<T> temp {};
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

	// ordered list of coefficients
	// when ax_0 + bx_1, _coeffs[0] == a and _coeffs[1] == b
	std::vector<T> _coeffs {};
};

template<typename T>
Polynomial<T> operator*(T i, const Polynomial<T> &rhs)
{
	return rhs * i;
}
