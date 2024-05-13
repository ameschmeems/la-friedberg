#include "utils.hpp"
#include <iostream>

// au * bv = gcd(a,b) (a and b flipped if a < b)
/**
 * Algorithm to find u and v, such that au + bv = gcd(a, b)
 * If a is smaller than b, a and b are flipped, so the result would be bu + av = gcd(a, b)
 * @param a, b	numbers for which to find a and b
 * @param u, v	references in which to store resulting u and v values respectively
 * @returns The greatest common divisor for a and b
*/
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