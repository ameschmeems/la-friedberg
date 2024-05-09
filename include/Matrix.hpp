#ifndef MATRIX_HPP
# define MATRIX_HPP

#include <array>
#include <iostream>

template<typename T, std::size_t m, std::size_t n>
class Matrix
{
public:

	Matrix() = default;

	Matrix(const Matrix &rhs) : _mat { rhs._mat }
	{
	}

	Matrix(Matrix &&rhs) noexcept : _mat { std::move(rhs._mat) }
	{
	}
	
	Matrix(const std::array<std::array<T, m>, n> &rhs) : _mat { rhs }
	{
	}
	
	Matrix(std::array<std::array<T, m>, n> &&rhs) noexcept : _mat { std::move(rhs) }
	{
	}

	Matrix &operator=(const Matrix &rhs)
	{
		_mat = rhs._mat;
	}
	
	Matrix &operator=(Matrix &&rhs) noexcept
	{
		_mat = std::move(rhs._mat);
	}

	Matrix operator+(const Matrix &rhs) const
	{
		std::array<std::array<T, m>, n> temp {};
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				temp[j][i] = _mat[j][i] + rhs._mat[j][i];
		}
		return Matrix { temp };
	}
	
	Matrix operator-(const Matrix &rhs) const
	{
		std::array<std::array<T, m>, n> temp {};
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				temp[j][i] = _mat[j][i] - rhs._mat[j][i];
		}
		return Matrix { temp };
	}

	Matrix operator-() const
	{
		std::array<std::array<T, m>, n> temp {};
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				temp[j][i] = -_mat[j][i];
		}
		return Matrix { temp };
	}

	Matrix operator*(const T &rhs) const
	{
		std::array<std::array<T, m>, n> temp {};
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				temp[j][i] = _mat[j][i] * rhs;
		}
		return Matrix { temp };
	}

	Matrix operator/(const T &rhs) const
	{
		std::array<std::array<T, m>, n> temp {};
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				temp[j][i] = _mat[j][i] / rhs;
		}
		return Matrix { temp };
	}

	std::array<T, m> &operator[](std::size_t i)
	{
		return _mat[i];
	}

	bool operator==(const Matrix &rhs) const
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (_mat[j][i] != rhs._mat[j][i])
					return false;
		return true;
	}

	bool operator!=(const Matrix &rhs) const
	{
		return !(*this == rhs);
	}

	void print(std::ostream &os) const
	{
		for (int i = 0; i < m; i++)
		{
			os << "{ ";
			for (int j = 0; j < n; j++)
				os << _mat[j][i] << " ";
			os << "}" << std::endl;
		}
	}

private:

	std::array<std::array<T, m>, n> _mat {};
};

template<typename T, std::size_t m, std::size_t n>
Matrix<T, m, n> operator*(T i, const Matrix<T, m, n> &rhs)
{
	return rhs * i;
}

#endif