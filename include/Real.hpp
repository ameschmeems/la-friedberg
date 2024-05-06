#ifndef REAL_HPP
# define REAL_HPP

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

private:

	float _num {};
};

#endif