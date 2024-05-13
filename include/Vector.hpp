#pragma once

#include <array>
#include <iostream>

/**
 * An n-tuple vector space over field T
*/
template<typename T, std::size_t n>
class Vector
{
public:

	Vector() = default;

	Vector(const Vector &rhs) : _vec { rhs._vec }
	{
	}

	Vector(Vector &&rhs) noexcept : _vec { std::move(rhs._vec) }
	{
	}

	/**
	 * Initialize object to the contents of given array
	*/
	Vector(const std::array<T, n> &rhs) : _vec { rhs }
	{
	}

	/**
	 * Initialize object to the contents of given array
	*/
	Vector(std::array<T, n> &&rhs) noexcept : _vec { std::move(rhs) }
	{
	}

	Vector &operator=(const Vector &rhs)
	{
		_vec = rhs._vec;
		return *this;
	}

	Vector &operator=(Vector &&rhs) noexcept
	{
		_vec = std::move(rhs._vec);
		return *this;
	}

	/**
	 * Componentwise addition
	*/
	Vector operator+(const Vector &rhs) const
	{
		std::array<T, n> temp {};
		for (int i = 0; i < n; i++)
			temp[i] = _vec[i] + rhs._vec[i];
		return Vector { std::move(temp) };
	}

	/**
	 * Componentwise subtraction
	*/
	Vector operator-(const Vector &rhs) const
	{
		std::array<T, n> temp {};
		for (int i = 0; i < n; i++)
			temp[i] = _vec[i] - rhs._vec[i];
		return Vector { std::move(temp) };
	}

	/**
	 * Componentwise negation
	*/
	Vector operator-() const
	{
		std::array<T, n> temp {};
		for (int i = 0; i < n; i++)
			temp[i] = -_vec[i];
		return Vector { std::move(temp) };
	}

	/**
	 * Componentwise scalar multiplication
	*/
	Vector operator*(const T &rhs) const
	{
		std::array<T, n> temp {};
		for (int i = 0; i < n; i++)
			temp[i] = _vec[i] * rhs;
		return Vector { std::move(temp) };
	}

	/**
	 * Componentwise scalar division
	*/
	Vector operator/(const T &rhs) const
	{
		std::array<T, n> temp {};
		for (int i = 0; i < n; i++)
			temp[i] = _vec[i] / rhs;
		return Vector { std::move(temp) };
	}

	/**
	 * Access to i-th element in tuple (i < n)
	*/
	T &operator[](std::size_t i)
	{
		return _vec[i];
	}

	/**
	 * True if all elements are equal, otherwise false
	*/
	bool operator==(const Vector &rhs) const
	{
		for (int i = 0; i < n; i++)
			if (_vec[i] != rhs._vec[i])
				return false;
		return true;
	}

	/**
	 * True if any elements are not equal, otherwise false
	*/
	bool operator!=(const Vector &rhs) const
	{
		return !(*this == rhs);
	}

	friend std::ostream &operator<<(std::ostream &os, const Vector &rhs)
	{
		os << "{ ";
		for (int i = 0; i < n - 1; i++)
			os << rhs._vec[i] << ", ";
		os << rhs._vec[n - 1] << " }";
		return os;
	}

private:

	std::array<T, n> _vec {};
};

/**
 * Componentwise scalar multiplication, with scalar on the left
*/
template<typename T, std::size_t n>
Vector<T, n> operator*(T i, const Vector<T, n> &rhs)
{
	return rhs * i;
}
