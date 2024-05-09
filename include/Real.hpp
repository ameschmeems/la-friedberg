#ifndef REAL_HPP
# define REAL_HPP

#include <iostream>

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

#endif