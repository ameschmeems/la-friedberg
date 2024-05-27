#include <iostream>
#include "Matrix.hpp"

template<typename T, std::size_t m, std::size_t n>
void solve_and_print(Matrix<T, m, n> &mat)
{
	std::cout << "The linear system:" << std::endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (mat[j][i] != 0)
				std::cout << mat[j][i] << "x_" << j << " ";
			if (j != n-2 && mat[j][i] != 0)
				std::cout << "+ ";
		}
		std::cout << "= " << mat[n-1][i] << std::endl;
	}
	std::cout << "Has solutions:" << std::endl;
	Matrix<T, m, n> solved { mat.solve_system() };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (solved[j][i] != 0)
				std::cout << solved[j][i] << "x_" << j << " ";
			else
				std::cout << 0 << " ";
			if (j != n-2)
				std::cout << "+ ";
		}
		std::cout << "= " << solved[n-1][i] << std::endl;
	}
}

int main()
{
	{
		Matrix<float, 3, 5> m {};
		m[0][0] = 2;
		m[1][0] = -2;
		m[2][0] = -3;
		m[3][0] = 0;
		m[4][0] = -2;
		m[0][1] = 3;
		m[1][1] = -3;
		m[2][1] = -2;
		m[3][1] = 5;
		m[4][1] = 7;
		m[0][2] = 1;
		m[1][2] = -1;
		m[2][2] = -2;
		m[3][2] = -1;
		m[4][2] = -3;

		solve_and_print(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 3, 4> m {};
		m[0][0] = 3;
		m[1][0] = -7;
		m[2][0] = 4;
		m[3][0] = 10;
		m[0][1] = 1;
		m[1][1] = -2;
		m[2][1] = 1;
		m[3][1] = 3;
		m[0][2] = 2;
		m[1][2] = -1;
		m[2][2] = -2;
		m[3][2] = 6;

		solve_and_print(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 3, 5> m {};
		m[0][0] = 1;
		m[1][0] = 2;
		m[2][0] = -1;
		m[3][0] = 1;
		m[4][0] = 5;
		m[0][1] = 1;
		m[1][1] = 4;
		m[2][1] = -3;
		m[3][1] = -3;
		m[4][1] = 6;
		m[0][2] = 2;
		m[1][2] = 3;
		m[2][2] = -1;
		m[3][2] = -4;
		m[4][2] = 8;

		solve_and_print(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 3, 5> m {};
		m[0][0] = 1;
		m[1][0] = 2;
		m[2][0] = 2;
		m[3][0] = 0;
		m[4][0] = 2;
		m[0][1] = 1;
		m[1][1] = 0;
		m[2][1] = 8;
		m[3][1] = 5;
		m[4][1] = -6;
		m[0][2] = 1;
		m[1][2] = 1;
		m[2][2] = 5;
		m[3][2] = 5;
		m[4][2] = 3;

		solve_and_print(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 4, 6> m {};
		m[0][0] = 1;
		m[1][0] = 2;
		m[2][0] = -4;
		m[3][0] = -1;
		m[4][0] = 1;
		m[5][0] = 7;
		m[0][1] = -1;
		m[1][1] = 0;
		m[2][1] = 10;
		m[3][1] = -3;
		m[4][1] = -4;
		m[5][1] = -16;
		m[0][2] = 2;
		m[1][2] = 5;
		m[2][2] = -5;
		m[3][2] = -4;
		m[4][2] = -1;
		m[5][2] = 2;
		m[0][3] = 4;
		m[1][3] = 11;
		m[2][3] = -7;
		m[3][3] = -10;
		m[4][3] = -2;
		m[5][3] = 7;

		solve_and_print(m);
	}
	std::cout << "---------------" << std::endl;
	{
		Matrix<float, 4, 4> m {};
		m[0][0] = 1;
		m[1][0] = 2;
		m[2][0] = 6;
		m[3][0] = -1;
		m[0][1] = 2;
		m[1][1] = 1;
		m[2][1] = 1;
		m[3][1] = 8;
		m[0][2] = 3;
		m[1][2] = 1;
		m[2][2] = -1;
		m[3][2] = 15;
		m[0][3] = 1;
		m[1][3] = 3;
		m[2][3] = 10;
		m[3][3] = -5;

		solve_and_print(m);
	}
	std::cout << "---------------" << std::endl;
	return 0;
}