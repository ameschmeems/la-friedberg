#include <gtest/gtest.h>
#include "Vector.hpp"
#include "Real.hpp"

TEST(Vector, addition)
{
	Vector<Real, 3> v {};
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	Vector<Real, 3> w {};
	w[0] = 3;
	w[1] = 3;
	w[2] = 3;
	Vector<Real, 3> result {};
	result[0] = 4;
	result[1] = 5;
	result[2] = 6;
	ASSERT_EQ(v + w, result);
	ASSERT_EQ(w + v, result);
}

TEST(Vector, subtraction)
{
	Vector<float, 2> v {};
	v[0] = 3;
	v[1] = 3;
	Vector<float, 2> w {};
	w[0] = 1;
	w[1] = 2;
	Vector<float, 2> result {};
	result[0] = 2;
	result[1] = 1;
	ASSERT_EQ(v - w, result);
}

TEST(Vector, negation)
{
	Vector<float, 2> v {};
	v[0] = 1;
	v[1] = 2;
	Vector<float, 2> result {};
	result[0] = -1;
	result[1] = -2;
	ASSERT_EQ(-v, result);
}

TEST(Vector, scalarMultiplication)
{
	Vector<float, 2> v {};
	v[0] = 1;
	v[1] = 2;
	Vector<float, 2> result {};
	result[0] = 2;
	result[1] = 4;
	ASSERT_EQ(v * 2, result);
	ASSERT_EQ(2.0f * v, result);
}

TEST(Vector, scalarDivision)
{
	Vector<float, 2> v {};
	v[0] = 2;
	v[1] = 4;
	Vector<float, 2> result {};
	result[0] = 1;
	result[1] = 2;
	ASSERT_EQ(v / 2, result);
}