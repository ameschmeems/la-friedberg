#include <iostream>
#include "Matrix.hpp"

int main()
{
	Matrix<int, 2, 3> m {};
	m[0][0] = 1;
	m[1][0] = 2;
	m[2][0] = 3;
	m[0][1] = 4;
	m[1][1] = 5;
	m[2][1] = 6;

	std::cout << "Matrix:" << std::endl;
	m.print(std::cout);
	std::cout << "M_13: " << m[2][0] << std::endl;
	std::cout << "M_21: " << m[0][1] << std::endl;
	std::cout << "M_22: " << m[1][1] << std::endl;

	return 0;
}