#pragma once

#include <array>
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"

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

	/**
	 * Initializes matrix with an array of columns
	*/
	Matrix(std::array<Vector<T, m>, n> &cols)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				_mat[j][i] = cols[j][i];
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
	bool is_square() const
	{
		return m == n;
	}

	/**
	 * Returns the transposed matrix
	*/
	Matrix<T, n, m> transposed() const
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
	T trace() const
	{
		if (!(this->is_square()))
			throw MatrixNotSquareException();
		T temp {};
		for (int i = 0; i < n; i++)
			temp += _mat[i][i];
		return std::move(temp);
	}

	/**
	 * Solves a system of linear equations using gaussian elimination
	 * @returns reduced row echelon form of the matrix
	*/
	Matrix solve_system() const
	{
		Matrix temp { *this };
		temp._forward_elim();
		temp._back_sub();
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

	/**
	 * Swap i-th and j-th row of matrix
	*/
	void _swap_row(int i, int j)
	{
		for (int k = 0; k < n; k++)
		{
			T temp { _mat[k][i] };
			_mat[k][i] = _mat[k][j];
			_mat[k][j] = temp;
		}
	}

	/**
	 * Divide each element of the i-th row by scalar
	*/
	void _div_row(int i, T scalar)
	{
		for (int j = 0; j < n; j++)
			_mat[j][i] = _mat[j][i] / scalar;
	}

	/**
	 * Scale each element of i-th row by scalar
	*/
	void _scale_row(int i, T scalar)
	{
		for (int j = 0; j < n; j++)
			_mat[j][i] = _mat[j][i] * scalar;
	}

	/**
	 * Forward elimination part of gaussian elimination
	*/
	template<typename U = T, typename std::enable_if_t<std::is_arithmetic_v<U>, int> = 0>
	void _forward_elim()
	{
		int pivot_num { 0 };
		for (int i = 0; i < n; i++)
		{
			int pivot {};
			T highest_num {};
			for (int j = pivot_num; j < m; j++)
			{
				if (std::abs(_mat[i][j]) > highest_num || highest_num == 0)
				{
					pivot = j;
					highest_num = std::abs(_mat[i][j]);
				}
			}
			if (highest_num != 0)
			{
				_div_row(pivot, _mat[i][pivot]);
				_swap_row(pivot, pivot_num);
				for (int k = pivot_num + 1; k < m; k++)
				{
					T scale { _mat[i][k] };
					for (int l = 0; l < n; l++)
					{
						_mat[l][k] -= _mat[l][pivot_num] * scale;
						if (std::abs(_mat[l][k]) < 0.0001)
							_mat[l][k] = 0;
					}
				}
				pivot_num++;
			}
		}
	}

	/**
	 * Forward elimination for non-arithmetic types. Expects T to have a .is_zero() method
	*/
	template<typename U = T, typename std::enable_if_t<!std::is_arithmetic_v<U>, int> = 0>
	void _forward_elim()
	{
		int pivot_num { 0 };
		for (int i = 0; i < n - 1; i++)
		{
			int pivot {};
			T highest_num {};
			for (int j = pivot_num; j < m; j++)
			{
				if (std::abs(_mat[i][j]) > highest_num || highest_num.is_zero())
				{
					pivot = j;
					highest_num = std::abs(_mat[i][j]);
				}
			}
			if (!highest_num.is_zero())
			{
				_div_row(pivot, _mat[i][pivot]);
				_swap_row(pivot, pivot_num);
				for (int k = pivot_num + 1; k < m; k++)
				{
					T scale { _mat[i][k] };
					for (int l = 0; l < n; l++)
						_mat[l][k] -= _mat[l][i] * scale;
				}
				pivot_num++;
			}
		}
	}

	/**
	 * Back substitution part of gaussian elimination
	*/
	template<typename U = T, typename std::enable_if_t<std::is_arithmetic_v<U>, int> = 0>
	void _back_sub()
	{
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (_mat[j][i] != 0)
				{
					for (int k = i - 1; k >= 0; k--)
					{
						T scale { _mat[j][k] };
						for (int l = j; l < n; l++)
							_mat[l][k] -= _mat[l][i] * scale;
					}
					break ;
				}
			}
		}
	}

	/**
	 * Back substitution for non-arithmetic types. Expects T to have a .is_zero() method
	*/
	template<typename U = T, typename std::enable_if_t<!std::is_arithmetic_v<U>, int> = 0>
	void _back_sub()
	{
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (!_mat[j][i].is_zero())
				{
					for (int k = i - 1; k >= 0; k--)
					{
						T scale { _mat[j][k] };
						for (int l = j; l < n; l++)
							_mat[l][k] -= _mat[l][i] * scale;
					}
					break ;
				}
			}
		}
	}

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
