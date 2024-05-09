#include <gtest/gtest.h>
#include "Polynomial.hpp"
#include "Real.hpp"

TEST(Polynomial, addition)
{
	std::vector<float> avec { 1, 2, 3, 4, 0 };
	Polynomial<float> a { avec };
	std::vector<float> bvec { 1, 0, 2 };
	Polynomial<float> b { bvec };
	std::vector<float> resvec { 2, 2, 5, 4 };
	Polynomial<float> result { resvec };

	ASSERT_EQ(a + b, result);
}

TEST(Polynomial, subtraction)
{
	std::vector<Real> avec { Real { 1 }, Real { 2 }, Real { 3 }, Real { 0 } };
	Polynomial<Real> a { avec };
	std::vector<Real> bvec { Real { 1 }, Real { 1 }, Real { 1 }, Real { 1 } };
	Polynomial<Real> b { bvec };
	std::vector<Real> resvec { Real { 0 }, Real { 1 }, Real { 2 }, Real { -1 } };
	Polynomial<Real> result { resvec };

	ASSERT_EQ(a - b, result);
}

TEST(Polynomial, negation)
{
	std::vector<Real> avec { Real { 1 }, Real { 2 }, Real { 3 }, Real { 0 } };
	Polynomial<Real> a { avec };
	std::vector<Real> resvec { Real { -1 }, Real { -2 }, Real { -3 } };
	Polynomial<Real> result { resvec };

	ASSERT_EQ(-a, result);
}

TEST(Polynomial, scalarMultiplication)
{
	std::vector<int> avec { 1, 2, 3, 4 };
	Polynomial<int> a { avec };
	std::vector<int> resvec { 2, 4, 6, 8 };
	Polynomial<int> result { resvec };

	ASSERT_EQ(a * 2, result);
	ASSERT_EQ(2 * a, result);
}

TEST(Polynomial, multiplication)
{
	std::vector<int> avec { 1, 2 };
	Polynomial<int> a { avec };
	std::vector<int> bvec { 3, 4 };
	Polynomial<int> b { bvec };
	std::vector<int> resvec { 3, 10, 8 };
	Polynomial<int> result { resvec };

	ASSERT_EQ(a * b, result);
}

TEST(Polynomial, scalarDivision)
{
	std::vector<int> avec { 2, 4, 6 };
	Polynomial<int> a { avec };
	std::vector<int> resvec { 1, 2, 3 };
	Polynomial<int> result { resvec };

	ASSERT_EQ(a / 2, result);
}