#include "globals.h"
#include "vec4.h"

#include <cmath>

namespace vmath {

	const vec4 vec4::zero = vec4();
	const vec4 vec4::one = vec4(1, 1, 1, 1);
	const vec4 vec4::unit_w = vec4(0, 0, 0, 1);

	vec4::vec4()
		:
		x(0),
		y(0),
		z(0),
		w(0)
	{}

	vec4::vec4(float_t value)
		:
		x(value),
		y(value),
		z(value),
		w(value)
	{}

	vec4::vec4(const vec3& xyz, float_t w)
		:
		x(xyz.x),
		y(xyz.y),
		z(xyz.z),
		w(w)
	{}

	vec4::vec4(float_t x, float_t y, float_t z, float_t w)
		:
		x(x),
		y(y),
		z(z),
		w(w)
	{}

	vec4 vec4::homogenized() const
	{
		return vec4(
			x / w,
			y / w,
			z / w,
			1
		);
	}

	float_t vec4::operator[](int idx) const
	{
		switch (idx)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			return w;
		}
	}

	float_t sum_of_elements(const vec4& v)
	{
		return v.x + v.y + v.z + v.w;
	}

	bool operator==(const vec4& lhs, const vec4& rhs)
	{
		return abs(lhs.x - rhs.x) < zero_tolerance
			&& abs(lhs.y - rhs.y) < zero_tolerance
			&& abs(lhs.z - rhs.z) < zero_tolerance
		;
	}

	bool operator!=(const vec4& lhs, const vec4& rhs)
	{
		return !(lhs == rhs);
	}

	vec4 operator+(const vec4& lhs, const vec4& rhs)
	{
		auto tmp = lhs;
		return tmp += rhs;
	}

	vec4 operator+(const vec4& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp += rhs;
	}

	vec4 operator+(float_t lhs, const vec4& rhs)
	{
		auto tmp = rhs;
		return tmp += lhs;
	}

	vec4& operator+=(vec4& lhs, const vec4& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		lhs.w += rhs.w;

		return lhs;
	}

	vec4& operator+=(vec4& lhs, float_t rhs)
	{
		lhs.x += rhs;
		lhs.y += rhs;
		lhs.z += rhs;
		lhs.w += rhs;

		return lhs;
	}

	vec4 operator-(const vec4& lhs, const vec4& rhs)
	{
		auto tmp = lhs;
		return tmp -= rhs;
	}

	vec4 operator-(const vec4& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp -= rhs;
	}

	vec4 operator-(float_t lhs, const vec4& rhs)
	{
		auto tmp = vec4(lhs);
		return tmp -= rhs;
	}

	vec4 operator-(const vec4& rhs)
	{
		auto tmp = vec4();
		return tmp -= rhs;
	}

	vec4& operator-=(vec4& lhs, const vec4& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		lhs.w -= rhs.w;

		return lhs;
	}

	vec4& operator-=(vec4& lhs, float_t rhs)
	{
		lhs.x -= rhs;
		lhs.y -= rhs;
		lhs.z -= rhs;
		lhs.w -= rhs;

		return lhs;
	}

	vec4 operator*(const vec4& lhs, const vec4& rhs)
	{
		auto tmp = lhs;
		return tmp *= rhs;
	}

	vec4 operator*(const vec4& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp *= rhs;
	}

	vec4 operator*(float_t lhs, const vec4& rhs)
	{
		auto tmp = rhs;
		return tmp *= lhs;
	}

	vec4& operator*=(vec4& lhs, const vec4& rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		lhs.z *= rhs.z;
		lhs.w *= rhs.w;

		return lhs;
	}

	vec4& operator*=(vec4& lhs, float_t rhs)
	{
		lhs.x *= rhs;
		lhs.y *= rhs;
		lhs.z *= rhs;
		lhs.w *= rhs;

		return lhs;
	}

	vec4 operator/(const vec4& lhs, const vec4& rhs)
	{
		auto tmp = lhs;
		return tmp /= lhs;
	}

	vec4 operator/(const vec4& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp /= rhs;
	}

	vec4 operator/(float_t lhs, const vec4& rhs)
	{
		auto tmp = vec4(lhs);
		return tmp /= rhs;
	}

	vec4& operator/=(vec4& lhs, const vec4& rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		lhs.z /= rhs.z;
		lhs.w /= rhs.w;

		return lhs;
	}

	vec4& operator/=(vec4& lhs, float_t rhs)
	{
		lhs.x /= rhs;
		lhs.y /= rhs;
		lhs.z /= rhs;
		lhs.w /= rhs;

		return lhs;
	}

}