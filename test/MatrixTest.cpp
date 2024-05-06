#include <gtest/gtest.h>
#include "Matrix.hpp"
#include "Real.hpp"

TEST(Matrix, addition)
{
	Matrix<Real, 2, 2> m {};
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	m[1][1] = 4;
	Matrix<Real, 2, 2> result {};
	result[0][0] = 2;
	result[0][1] = 4;
	result[1][0] = 6;
	result[1][1] = 8;

	ASSERT_EQ(m + m, result);
}

TEST(Matrix, subtraction)
{
	Matrix<Real, 2, 2> m {};
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	m[1][1] = 4;
	Matrix<Real, 2, 2> n {};
	n[0][0] = 4;
	n[0][1] = 3;
	n[1][0] = 2;
	n[1][1] = 1;
	Matrix<Real, 2, 2> result {};
	result[0][0] = -3;
	result[0][1] = -1;
	result[1][0] = 1;
	result[1][1] = 3;

	ASSERT_EQ(m - n, result);
}

TEST(Matrix, negation)
{
	Matrix<Real, 2, 2> m {};
	m[0][0] = 1;
	m[0][1] = -1;
	m[1][0] = 1;
	m[1][1] = -1;
	Matrix<Real, 2, 2> result {};
	result[0][0] = -1;
	result[0][1] = 1;
	result[1][0] = -1;
	result[1][1] = 1;

	ASSERT_EQ(-m, result);
}

TEST(Matrix, scalarMultiplication)
{
	Matrix<Real, 2, 2> m {};
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	m[1][1] = 4;
	Matrix<Real, 2, 2> result {};
	result[0][0] = 2;
	result[0][1] = 4;
	result[1][0] = 6;
	result[1][1] = 8;

	ASSERT_EQ(Real { 2 } * m, result);
	ASSERT_EQ(m * Real { 2 }, result);
}

TEST(Matrix, scalarDivision)
{
	Matrix<Real, 2, 2> m {};
	m[0][0] = 2;
	m[0][1] = 4;
	m[1][0] = 6;
	m[1][1] = 8;
	Matrix<Real, 2, 2> result {};
	result[0][0] = 1;
	result[0][1] = 2;
	result[1][0] = 3;
	result[1][1] = 4;

	ASSERT_EQ(m / Real { 2 }, result);
}