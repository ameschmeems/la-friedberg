#include <iostream>
#include <Matrix.hpp>

int main()
{
	// (a)
	{
		Matrix<float, 2, 3> m {};
		m[0][0] = 2;
		m[1][0] = 5;
		m[2][0] = -3;
		m[0][1] = 1;
		m[1][1] = 0;
		m[2][1] = 7;
		Matrix<float, 2, 3> n {};
		n[0][0] = 4;
		n[1][0] = -2;
		n[2][0] = 5;
		n[0][1] = -5;
		n[1][1] = 3;
		n[2][1] = 2;
		m.print(std::cout);
		std::cout << "+" << std::endl;
		n.print(std::cout);
		std::cout << "=" << std::endl;
		(m + n).print(std::cout);
		std::cout << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << std::endl;
	}
	// (b)
	{
		Matrix<float, 3, 2> m {};
		m[0][0] = -6;
		m[1][0] = 4;
		m[0][1] = 3;
		m[1][1] = -2;
		m[0][2] = 1;
		m[1][2] = 8;
		Matrix<float, 3, 2> n {};
		n[0][0] = 7;
		n[1][0] = -5;
		n[0][1] = 0;
		n[1][1] = -3;
		n[0][2] = 2;
		n[1][2] = 0;
		m.print(std::cout);
		std::cout << "+" << std::endl;
		n.print(std::cout);
		std::cout << "=" << std::endl;
		(m + n).print(std::cout);
		std::cout << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << std::endl;
	}
	// (c)
	{
		Matrix<float, 2, 3> m {};
		m[0][0] = 2;
		m[1][0] = 5;
		m[2][0] = -3;
		m[0][1] = 1;
		m[1][1] = 0;
		m[2][1] = 7;
		std::cout << "4\n*" << std::endl;
		m.print(std::cout);
		std::cout << "=" << std::endl;
		(4.0f * m).print(std::cout);
		std::cout << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << std::endl;
	}
	// (d)
	{
		Matrix<float, 3, 2> m {};
		m[0][0] = -6;
		m[1][0] = 4;
		m[0][1] = 3;
		m[1][1] = -2;
		m[0][2] = 1;
		m[1][2] = 8;
		std::cout << "-5\n*" << std::endl;
		m.print(std::cout);
		std::cout << "=" << std::endl;
		(-5.0f * m).print(std::cout);
		std::cout << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << std::endl;
	}
}