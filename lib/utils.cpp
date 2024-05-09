#include "utils.hpp"
#include <iostream>

// au * bv = gcd(a,b) (a and b flipped if a < b)
int bezout_algorithm(int a, int b, int &u, int &v)
{
	if (a < b)
	{
		int temp { a };
		a = b;
		b = temp;
	}
	u = 1;
	int g { a };
	int x { 0 };
	int y { b };
	while (y != 0)
	{
		int t { g % y };
		int q { (g - t) / y };
		g /= y;
		int s { u - q * x };
		u = x;
		g = y;
		x = s;
		y = t;
	}
	v = (g - (a * u)) / b;
	return g;
}