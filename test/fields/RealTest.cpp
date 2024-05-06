#include <gtest/gtest.h>
#include "Real.hpp"

TEST(Real, addition)
{
	Real a { 1.0 };
	Real b { 2.0 };
	Real result { 3.0 };

	ASSERT_EQ(a + b, result);
}

TEST(Real, subtraction)
{
	Real a { 1.0 };
	Real b { 2.0 };
	Real result { -1.0 };
	
	ASSERT_EQ(a - b, result);
}

TEST(Real, negation)
{
	Real a { 1.0 };
	Real result { -1.0 };

	ASSERT_EQ(-a, result);
}

TEST(Real, multiplication)
{
	Real a { 2.0 };
	Real b { 4.0 };
	Real result { 8.0 };

	ASSERT_EQ(a * b, result);
}

TEST(Real, division)
{
	Real a { 4.0 };
	Real b { 2.0 };
	
	ASSERT_EQ(a / b, b);
}