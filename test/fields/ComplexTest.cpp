#include <gtest/gtest.h>
#include "Complex.hpp"

TEST(Complex, addition)
{
	Complex a { 1.0, 2.0 };
	Complex b { 3.0, 4.0 };
	Complex result { 4.0, 6.0 };

	ASSERT_EQ(a + b, result);
}

TEST(Complex, subtraction)
{
	Complex a { 3.0, 4.0 };
	Complex b { 1.0, 2.0 };
	Complex result { 2.0, 2.0 };

	ASSERT_EQ(a - b, result);
}

TEST(Complex, negation)
{
	Complex a { 1.0, 2.0 };
	Complex result { -1.0, -2.0 };

	ASSERT_EQ(-a, result);
}

TEST(Complex, multiplication)
{
	Complex a { 1.0, 2.0 };
	Complex b { 3.0, 4.0 };
	Complex result { -5.0, 10.0 };

	ASSERT_EQ(a * b, result);
}

TEST(Complex, division)
{
	Complex a { 20.0, -4.0 };
	Complex b { 3.0, 2.0 };
	Complex result { 4.0, -4.0 };

	ASSERT_EQ(a / b, result);
}