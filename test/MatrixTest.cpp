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
	Matrix<float, 2, 2> m {};
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	m[1][1] = 4;
	Matrix<float, 2, 2> result {};
	result[0][0] = 2;
	result[0][1] = 4;
	result[1][0] = 6;
	result[1][1] = 8;

	ASSERT_EQ(2.0f * m, result);
	ASSERT_EQ(m * 2, result);
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

TEST(Matrix, isSquare)
{
	Matrix<float, 3, 3> square {};
	Matrix<float, 2, 3> not_square1 {};
	Matrix<float, 3, 2> not_square2 {};

	ASSERT_TRUE(square.is_square());
	ASSERT_FALSE(not_square1.is_square());
	ASSERT_FALSE(not_square2.is_square());
}

TEST(Matrix, transpose)
{
	Matrix<float, 1, 2> m {};
	m[0][0] = 1;
	m[1][0] = 2;
	Matrix<float, 2, 1> result {};
	result[0][0] = 1;
	result[0][1] = 2;
	
	ASSERT_EQ(m.transposed(), result);
}

TEST(Matrix, trace)
{
	Matrix<float, 4, 3> not_square {};
	Matrix<float, 2, 2> m {};
	m[0][0] = 1;
	m[1][0] = 2;
	m[0][1] = 3;
	m[1][1] = 5;

// without this define the ASSERT_THROW will cause issues, idk how to do it in a nicer way
#define MATRIX_NOT_SQ_EXCEPT Matrix<float,4,3>::MatrixNotSquareException
	ASSERT_THROW(not_square.trace(), MATRIX_NOT_SQ_EXCEPT);
	ASSERT_ANY_THROW(not_square.trace());
	ASSERT_EQ(m.trace(), 6);
}