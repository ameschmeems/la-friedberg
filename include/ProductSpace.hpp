#pragma once

/**
 * Constructs a vector space out of two vector spaces V and W over field T
*/
template<typename V, typename W, typename T>
class ProductSpace
{
public:

	ProductSpace() = default;
	
	ProductSpace(const ProductSpace &rhs) : _v { rhs._v }, _w { rhs._w }
	{
	}

	ProductSpace(ProductSpace &&rhs) noexcept : _v { std::move(rhs._v) }, _w { std::move(rhs._w) }
	{
	}

	/**
	 * Initialize object with elements v and w
	*/
	ProductSpace(const V &v, const W &w) : _v { v }, _w { w }
	{
	}

	/**
	 * Initialize object with elements v and w
	*/
	ProductSpace(V &&v, W &&w) noexcept : _v { v }, _w { w }
	{
	}

	ProductSpace &operator=(const ProductSpace &rhs)
	{
		_v = rhs._v;
		_w = rhs._w;
		return *this;
	}

	ProductSpace &operator=(ProductSpace &&rhs) noexcept
	{
		_v = std::move(rhs._v);
		_w = std::move(rhs._w);
		return *this;
	}

	/**
	 * Componentwise addition
	*/
	ProductSpace operator+(const ProductSpace &rhs) const
	{
		V temp_v { _v + rhs._v };
		W temp_w { _w + rhs._w };
		return ProductSpace { std::move(temp_v), std::move(temp_w) };
	}

	/**
	 * Componentwise subtraction
	*/
	ProductSpace operator-(const ProductSpace &rhs) const
	{
		V temp_v { _v - rhs._v };
		W temp_w { _w - rhs._w };
		return ProductSpace { std::move(temp_v), std::move(temp_w) };
	}

	/**
	 * Componentwise negation
	*/
	ProductSpace operator-() const
	{
		return ProductSpace { -_v, -_w };
	}

	/**
	 * Componentwise scalar multiplication
	*/
	ProductSpace operator*(const T &rhs) const
	{
		return ProductSpace { _v * rhs, _w * rhs };
	}

	/**
	 * Componentwise scalar division
	*/
	ProductSpace operator/(const T &rhs) const
	{
		return ProductSpace { _v / rhs, _w / rhs };
	}

	/**
	 * True if both elements are equal, otherwise false
	*/
	bool operator==(const ProductSpace &rhs) const
	{
		return (_v == rhs._v) && (_w == rhs._w);
	}

	/**
	 * True if any elements are different, otherwise false
	*/
	bool operator!=(const ProductSpace &rhs) const
	{
		return !(*this == rhs);
	}

	friend std::ostream &operator<<(std::ostream &os, const ProductSpace &rhs)
	{
		os << "( " << rhs._v << ", " << rhs._w << " )";
		return os;
	}

private:

	V _v {};
	W _w {};
};

template<typename V, typename W, typename T>
ProductSpace<V, W, T> operator*(T i, const ProductSpace<V, W, T> &rhs)
{
	return rhs * i;
}