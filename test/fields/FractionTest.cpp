#include <gtest/gtest.h>
#include "Fraction.hpp"

TEST(Fraction, addition)
{
	Fraction a { 1, 2 };
	Fraction b { 1, 4 };
	Fraction result { 3, 4 };

	ASSERT_EQ(a + b, result);
}

TEST(Fraction, subtraction)
{
	Fraction a { 1, 2 };
	Fraction b { 1, 4 };
	Fraction result { 1, 4 };

	ASSERT_EQ(a - b, result);
}

TEST(Fraction, negation)
{
	Fraction a { 1, 2 };
	Fraction result { -1, 2 };

	ASSERT_EQ(-a, result);
}

TEST(Fraction, multiplication)
{
	Fraction a { 1, 2 };
	Fraction result { 1, 4 };

	ASSERT_EQ(a * a, result);
}

TEST(Fraction, division)
{
	Fraction a { 1, 2 };
	Fraction b { 1, 3 };
	Fraction result { 3, 2 };

	ASSERT_EQ(a / b, result);
}