#pragma once

#include <iostream>

/**
 * Field of real numbers R
*/
class Real
{
public:

	Real() = default;
	Real(const Real &rhs);
	Real(const float num);

	Real &operator=(const Real &rhs);
	Real operator+(const Real &rhs) const;
	Real operator-(const Real &rhs) const;
	Real operator-() const;
	Real operator*(const Real &rhs) const;
	Real operator/(const Real &rhs) const;
	bool operator==(const Real &rhs) const;
	bool operator!=(const Real &rhs) const;

	bool is_zero() const;

	friend std::ostream &operator<<(std::ostream &os, const Real &rhs);

private:

	float _num {};
};
