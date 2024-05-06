#include <gtest/gtest.h>
#include "Z_p.hpp"

TEST(Z_p, addition)
{
	Z_p a { 2, 1 };
	Z_p result { 2, 0 };

	ASSERT_EQ(a + a, result);
}

TEST(Z_p, subtraction)
{
	Z_p a { 3, 3 };
	Z_p b { 3, 2 };
	Z_p result { 3, 1 };
	
	ASSERT_EQ(a - b, result);
}

TEST(Z_p, negation)
{
	Z_p a { 2, 1 };
	Z_p result { 2, -1 };

	ASSERT_EQ(-a, result);
}

TEST(Z_p, multiplication)
{
	Z_p a { 2, 1 };
	Z_p b { 2, 2 };
	Z_p result { 2, 0 };

	ASSERT_EQ(a * b, result);
}

TEST(Z_p, division)
{
	Z_p a { 2, 4 };
	Z_p b { 2, 2 };
	Z_p result { 2, 0 };

	ASSERT_EQ(a / b, result);
}