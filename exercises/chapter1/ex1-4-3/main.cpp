#include <iostream>
#include "Matrix.hpp"

template<typename T, std::size_t m, std::size_t n>
void solve_and_print(std::array<Vector<T, m>, n> &cols)
{
	Matrix<T, m, n> mat { cols };
	Matrix<T, m, n> solved { mat.solve_system() };

	bool inconsistent { false };
	for (int i = 0; i < m; i++)
	{
		bool first_elem { false };
		for (int j = 0; j < n; j++)
		{
			if (!first_elem && solved[j][i] != 0 && j != n-1)
				first_elem = true;
			else if (!first_elem && std::abs(solved[j][i]) > 0.0001)
				inconsistent = true;
		}
		if (inconsistent)
		{
			std::cout << cols[n-1] << " is not a linear combination of ";
			for (int j = 0; j < n-2; j++)
				std::cout << cols[j] << ", ";
			std::cout << cols[n-2] << std::endl;
			return ;
		}
	}
	std::cout << cols[n - 1] << " = ";
	// I know im using square matrices here so this wont break, but using m for column index is not good
	for (int i = 0; i < m - 2; i++)
		std::cout << solved[n-1][i] << cols[i] << " + ";
	std::cout << solved[n-1][m-2] << cols[m-2] << std::endl;
}

int main()
{
	{
		Vector<float, 3> a { std::array<float, 3> { -2, 0, 3 } };
		Vector<float, 3> b { std::array<float, 3> { 1, 3, 0 } };
		Vector<float, 3> c { std::array<float, 3> { 2, 4, -1 } };
		std::array<Vector<float, 3>, 3> arr { b, c, a };
		solve_and_print(arr);
	}
	std::cout << "---------------" << std::endl;
	{
		Vector<float, 3> a { std::array<float, 3> { 1, 2, -3 } };
		Vector<float, 3> b { std::array<float, 3> { -3, 2, 1 } };
		Vector<float, 3> c { std::array<float, 3> { 2, -1, 1 } };
		std::array<Vector<float, 3>, 3> arr { b, c, a };
		solve_and_print(arr);
	}
	std::cout << "---------------" << std::endl;
	{
		Vector<float, 3> a { std::array<float, 3> { 3, 4, 1 } };
		Vector<float, 3> b { std::array<float, 3> { 1, -2, 1 } };
		Vector<float, 3> c { std::array<float, 3> { -2, -1, 1 } };
		std::array<Vector<float, 3>, 3> arr { b, c, a };
		solve_and_print(arr);
	}
	std::cout << "---------------" << std::endl;
	{
		Vector<float, 3> a { std::array<float, 3> { 2, -1, 0 } };
		Vector<float, 3> b { std::array<float, 3> { 1, 2, -3 } };
		Vector<float, 3> c { std::array<float, 3> { 1, -3, 2 } };
		std::array<Vector<float, 3>, 3> arr { b, c, a };
		solve_and_print(arr);
	}
	std::cout << "---------------" << std::endl;
	{
		Vector<float, 3> a { std::array<float, 3> { 5, 1, -5 } };
		Vector<float, 3> b { std::array<float, 3> { 1, -2, -3 } };
		Vector<float, 3> c { std::array<float, 3> { -2, 3, -4 } };
		std::array<Vector<float, 3>, 3> arr { b, c, a };
		solve_and_print(arr);
	}
	std::cout << "---------------" << std::endl;
	{
		Vector<float, 3> a { std::array<float, 3> { -2, 2, 2 } };
		Vector<float, 3> b { std::array<float, 3> { 1, 2, -1 } };
		Vector<float, 3> c { std::array<float, 3> { -3, -3, 3 } };
		std::array<Vector<float, 3>, 3> arr { b, c, a };
		solve_and_print(arr);
	}
	std::cout << "---------------" << std::endl;
	return 0;
}