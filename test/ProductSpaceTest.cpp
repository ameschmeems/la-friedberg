#include <gtest/gtest.h>
#include "ProductSpace.hpp"
#include "Real.hpp"
#include "Vector.hpp"
#include "Polynomial.hpp"

TEST(ProductSpace, addition)
{
	Vector<Real, 2> v {};
	v[0] = 1;
	v[1] = 2;
	std::vector<Real> temp {};
	temp.push_back(1);
	Polynomial<Real> p { temp };
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> ps { v, p };
	Vector<Real, 2> vres {};
	vres[0] = 2;
	vres[1] = 4;
	temp[0] = 2;
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> result { vres, temp };

	ASSERT_EQ(ps + ps, result);
}

TEST(ProductSpace, subtraction)
{
	Vector<Real, 2> v {};
	v[0] = 1;
	v[1] = 2;
	std::vector<Real> temp {};
	temp.push_back(1);
	Polynomial<Real> p { temp };
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> ps { v, p };
	Vector<Real, 2> vres {};
	vres[0] = 0;
	vres[1] = 0;
	temp[0] = 0;
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> result { vres, temp };

	ASSERT_EQ(ps - ps, result);
}

TEST(ProductSpace, negation)
{
	Vector<Real, 2> v {};
	v[0] = 1;
	v[1] = 2;
	std::vector<Real> temp {};
	temp.push_back(1);
	Polynomial<Real> p { temp };
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> ps { v, p };
	Vector<Real, 2> vres {};
	vres[0] = -1;
	vres[1] = -2;
	temp[0] = -1;
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> result { vres, temp };

	ASSERT_EQ(-ps, result);
}

TEST(ProductSpace, scalarMultiplication)
{
	Vector<Real, 2> v {};
	v[0] = 1;
	v[1] = 2;
	std::vector<Real> temp {};
	temp.push_back(1);
	Polynomial<Real> p { temp };
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> ps { v, p };
	Vector<Real, 2> vres {};
	vres[0] = 2;
	vres[1] = 4;
	temp[0] = 2;
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> result { vres, temp };

	ASSERT_EQ(ps * 2, result);
	ASSERT_EQ(Real { 2 } * ps, result);
}

TEST(ProductSpace, scalarDivision)
{
	Vector<Real, 2> v {};
	v[0] = 2;
	v[1] = 4;
	std::vector<Real> temp {};
	temp.push_back(2);
	Polynomial<Real> p { temp };
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> ps { v, p };
	Vector<Real, 2> vres {};
	vres[0] = 1;
	vres[1] = 2;
	temp[0] = 1;
	ProductSpace<Vector<Real, 2>, Polynomial<Real>, Real> result { vres, temp };

	ASSERT_EQ(ps / 2, result);
}