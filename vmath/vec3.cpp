#include "globals.h"
#include "vec2.h"
#include "vec3.h"

#include <cmath>

namespace vmath {

	const vec3 vec3::zero = vec3();
	const vec3 vec3::half = vec3(0.5);
	const vec3 vec3::one = vec3(1);
	const vec3 vec3::unit_x = vec3(1, 0, 0);
	const vec3 vec3::unit_y = vec3(0, 1, 0);
	const vec3 vec3::unit_z = vec3(0, 0, 1);

	vec3::vec3()
		:
		x(0),
		y(0),
		z(0)
	{}

	vec3::vec3(float_t x, float_t y)
		:
		x(x),
		y(y),
		z(0)
	{}

	vec3::vec3(float_t x, float_t y, float_t z)
		:
		x(x),
		y(y),
		z(z)
	{}

	vec3::vec3(float_t value)
		:
		x(value),
		y(value),
		z(value)
	{}

	vec3::vec3(const vec2& xy)
		:
		x(xy.x),
		y(xy.y),
		z(0)
	{}

	float_t vec3::magnitude_squared() const
	{
		return x * x + y * y + z * z;
	}

	float_t vec3::magnitude() const
	{
		return sqrt(magnitude_squared());
	}

	float_t vec3::dot(const vec3& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	vec3 vec3::cross(const vec3& other) const
	{
		return vec3(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x
		);
	}

	vec3 vec3::normalized() const
	{
		auto m = magnitude();
		return vec3(x / m, y / m, z / m);
	}

	bool operator==(const vec3& lhs, const vec3& rhs)
	{
		return abs(lhs.x - rhs.x) < zero_tolerance
			&& abs(lhs.y - rhs.y) < zero_tolerance
			&& abs(lhs.z - rhs.z) < zero_tolerance
		;
	}

	bool operator!=(const vec3& lhs, const vec3& rhs)
	{
		return !(lhs == rhs);
	}

	vec3 operator+(const vec3& lhs, const vec3& rhs)
	{
		auto tmp = lhs;
		return tmp += rhs;
	}

	vec3 operator+(const vec3& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp += rhs;
	}

	vec3 operator+(float_t lhs, const vec3& rhs)
	{
		auto tmp = rhs;
		return tmp += lhs;
	}

	vec3& operator+=(vec3& lhs, const vec3& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;

		return lhs;
	}

	vec3& operator+=(vec3& lhs, float_t rhs)
	{
		lhs.x += rhs;
		lhs.y += rhs;
		lhs.z += rhs;

		return lhs;
	}

	vec3 operator-(const vec3& lhs, const vec3& rhs)
	{
		auto tmp = lhs;
		return tmp -= rhs;
	}

	vec3 operator-(const vec3& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp -= rhs;
	}

	vec3 operator-(float_t lhs, const vec3& rhs)
	{
		auto tmp = vec3(lhs);
		return tmp -= rhs;
	}

	vec3 operator-(const vec3& rhs)
	{
		auto tmp = vec3();
		return tmp -= rhs;
	}

	vec3& operator-=(vec3& lhs, const vec3& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;

		return lhs;
	}

	vec3& operator-=(vec3& lhs, float_t rhs)
	{
		lhs.x -= rhs;
		lhs.y -= rhs;
		lhs.z -= rhs;

		return lhs;
	}

	vec3 operator*(const vec3& lhs, const vec3& rhs)
	{
		auto tmp = lhs;
		return tmp *= rhs;
	}

	vec3 operator*(const vec3& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp *= rhs;
	}

	vec3 operator*(float_t lhs, const vec3& rhs)
	{
		auto tmp = rhs;
		return tmp *= lhs;
	}

	vec3& operator*=(vec3& lhs, const vec3& rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;
		lhs.z *= rhs.z;

		return lhs;
	}

	vec3& operator*=(vec3& lhs, float_t rhs)
	{
		lhs.x *= rhs;
		lhs.y *= rhs;
		lhs.z *= rhs;

		return lhs;
	}

	vec3 operator/(const vec3& lhs, const vec3& rhs)
	{
		auto tmp = lhs;
		return tmp /= lhs;
	}

	vec3 operator/(const vec3& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp /= rhs;
	}

	vec3 operator/(float_t lhs, const vec3& rhs)
	{
		auto tmp = vec3(lhs);
		return tmp /= rhs;
	}

	vec3& operator/=(vec3& lhs, const vec3& rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;
		lhs.z /= rhs.z;

		return lhs;
	}

	vec3& operator/=(vec3& lhs, float_t rhs)
	{
		lhs.x /= rhs;
		lhs.y /= rhs;
		lhs.z /= rhs;

		return lhs;
	}

}