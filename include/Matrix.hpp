#pragma once

#include <array>
#include <iostream>
#include <stdexcept>

/**
 * An m by n matrix over field T
*/
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
	
	/**
	 * Initializes matrix with 2D array
	*/
	Matrix(const std::array<std::array<T, m>, n> &rhs) : _mat { rhs }
	{
	}
	
	/**
	 * Initializes matrix with 2D array
	*/
	Matrix(std::array<std::array<T, m>, n> &&rhs) noexcept : _mat { std::move(rhs) }
	{
	}

	Matrix &operator=(const Matrix &rhs)
	{
		_mat = rhs._mat;
		return *this;
	}
	
	Matrix &operator=(Matrix &&rhs) noexcept
	{
		_mat = std::move(rhs._mat);
		return *this;
	}

	/**
	 * Componentwise addition
	*/
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
	
	/**
	 * Componentwise subtraction
	*/
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

	/**
	 * Componentwise negation
	*/
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

	/**
	 * Componentwise scalar multiplication
	*/
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

	/**
	 * Componentwise scalar division
	*/
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

	/**
	 * Returns underlying i-th column array
	*/
	std::array<T, m> &operator[](std::size_t i)
	{
		return _mat[i];
	}

	/**
	 * True if all entries are equal, otherwise false
	*/
	bool operator==(const Matrix &rhs) const
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (_mat[j][i] != rhs._mat[j][i])
					return false;
		return true;
	}

	/**
	 * True if any entries are different, otherwise false
	*/
	bool operator!=(const Matrix &rhs) const
	{
		return !(*this == rhs);
	}

	/**
	 * Prints the matrix (multiline)
	 * @param os	output stream to which matrix should be printed
	*/
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

	/**
	 * Returns true if the matrix is square, otherwise false
	*/
	bool is_square()
	{
		return m == n;
	}

	/**
	 * Returns the transposed matrix
	*/
	Matrix<T, n, m> transposed()
	{
		Matrix<T, n, m> temp {};
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				temp[i][j] = _mat[j][i];
		}
		return std::move(temp);
	}

	/**
	 * Returns the trace of the matrix.
	 * If matrix is not square, throws a MatrixNotSquareException
	*/
	T trace()
	{
		if (!(this->is_square()))
			throw MatrixNotSquareException();
		T temp {};
		for (int i = 0; i < n; i++)
			temp += _mat[i][i];
		return std::move(temp);
	}

	class MatrixNotSquareException : public std::exception
	{
		const char *what() const throw()
		{
			return "Matrix is not square";
		}
	};

private:

	std::array<std::array<T, m>, n> _mat {};
};

/**
 * Componentwise scalar multiplication, when scalar is on the left
*/
template<typename T, std::size_t m, std::size_t n>
Matrix<T, m, n> operator*(T i, const Matrix<T, m, n> &rhs)
{
	return rhs * i;
}
