#include <iostream>
#include <vector>
#include "Matrix.hpp"

template<typename T, std::size_t m, std::size_t n>
void transpose_and_trace(Matrix<T, m, n> mat)
{
	std::cout << "The transpose of" << std::endl;
	mat.print(std::cout);
	std::cout << "is" << std::endl;
	mat.transposed().print(std::cout);
	if (mat.is_square())
	{
		std::cout << "The trace is " << mat.trace() << std::endl;
	}
}

int main()
{
	{
		Matrix<float, 2, 2> m {};
		m[0][0] = -4;
		m[1][0] = 2;
		m[0][1] = 5;
		m[1][1] = -1;
		transpose_and_trace(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 2, 3> m {};
		m[0][0] = 0;
		m[1][0] = 8;
		m[2][0] = -6;
		m[0][1] = 3;
		m[1][1] = 4;
		m[2][1] = 7;
		transpose_and_trace(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 3, 2> m {};
		m[0][0] = -3;
		m[1][0] = 9;
		m[0][1] = 0;
		m[1][1] = -2;
		m[0][2] = 6;
		m[1][2] = 1;
		transpose_and_trace(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 3, 3> m {};
		m[0][0] = 10;
		m[1][0] = 0;
		m[2][0] = -8;
		m[0][1] = 2;
		m[1][1] = -4;
		m[2][1] = 3;
		m[0][2] = -5;
		m[1][2] = 7;
		m[2][2] = 6;
		transpose_and_trace(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 1, 4> m {};
		m[0][0] = 1;
		m[1][0] = -1;
		m[2][0] = 3;
		m[3][0] = 5;
		transpose_and_trace(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 2, 4> m {};
		m[0][0] = -2;
		m[1][0] = 5;
		m[2][0] = 1;
		m[3][0] = 4;
		m[0][1] = 7;
		m[1][1] = 0;
		m[2][1] = 1;
		m[3][1] = -6;
		transpose_and_trace(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 3, 1> m {};
		m[0][0] = 5;
		m[0][1] = 6;
		m[0][2] = 7;
		transpose_and_trace(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 3, 3> m {};
		m[0][0] = -4;
		m[1][0] = 0;
		m[2][0] = 6;
		m[0][1] = 0;
		m[1][1] = 1;
		m[2][1] = -3;
		m[0][2] = 6;
		m[1][2] = -3;
		m[2][2] = 5;
		transpose_and_trace(m);
	}
	std::cout << "---------------" << std::endl;
	return 0;
}