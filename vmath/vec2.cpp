#include "globals.h"
#include "vec2.h"

#include <cmath>

namespace vmath {

	const vec2 vec2::zero = vec2();
	const vec2 vec2::half = vec2(0.5, 0.5);
	const vec2 vec2::one = vec2(1);
	const vec2 vec2::left = vec2(-1, 0);
	const vec2 vec2::right = vec2(1, 0);
	const vec2 vec2::up = vec2(0, 1);
	const vec2 vec2::down = vec2(0, -1);
	const vec2 vec2::unit_x = vec2(1, 0);
	const vec2 vec2::unit_y = vec2(0, 1);

	vec2::vec2()
		:
		x(0),
		y(0)
	{}

	vec2::vec2(float_t x, float_t y)
		:
		x(x),
		y(y)
	{}

	vec2::vec2(float_t value)
		:
		x(value),
		y(value)
	{}

	float_t vec2::magnitude_squared() const
	{
		return x * x + y * y;
	}

	float_t vec2::magnitude() const
	{
		return sqrt(magnitude_squared());
	}

	float_t vec2::dot(const vec2& other) const
	{
		return x * other.x + y * other.y;
	}

	float_t vec2::cross(const vec2& other) const
	{
		return x * other.y - y * other.x;
	}

	vec2 vec2::normalized() const
	{
		auto m = magnitude();
		return vec2(x / m, y / m);
	}

	float_t vec2::operator[](int idx) const
	{
		return idx == 0 ? x : y;
	}

	bool operator==(const vec2& lhs, const vec2& rhs)
	{
		return abs(lhs.x - rhs.x) < zero_tolerance && abs(lhs.y - rhs.y) < zero_tolerance;
	}

	bool operator!=(const vec2& lhs, const vec2& rhs)
	{
		return !(lhs == rhs);
	}

	vec2 operator+(const vec2& lhs, const vec2& rhs)
	{
		auto tmp = lhs;
		return tmp += rhs;
	}

	vec2 operator+(const vec2& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp += rhs;
	}

	vec2 operator+(float_t lhs, const vec2& rhs)
	{
		auto tmp = rhs;
		return tmp += lhs;
	}

	vec2& operator+=(vec2& lhs, const vec2& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;

		return lhs;
	}

	vec2& operator+=(vec2& lhs, float_t rhs)
	{
		lhs.x += rhs;
		lhs.y += rhs;

		return lhs;
	}

	vec2 operator-(const vec2& lhs, const vec2& rhs)
	{
		auto tmp = lhs;
		return tmp -= rhs;
	}

	vec2 operator-(const vec2& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp -= rhs;
	}

	vec2 operator-(float_t lhs, const vec2& rhs)
	{
		auto tmp = vec2(lhs);
		return tmp -= rhs;
	}

	vec2 operator-(const vec2& rhs)
	{
		auto tmp = vec2();
		return tmp -= rhs;
	}

	vec2& operator-=(vec2& lhs, const vec2& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;

		return lhs;
	}

	vec2& operator-=(vec2& lhs, float_t rhs)
	{
		lhs.x -= rhs;
		lhs.y -= rhs;

		return lhs;
	}

	vec2 operator*(const vec2& lhs, const vec2& rhs)
	{
		auto tmp = lhs;
		return tmp *= rhs;
	}

	vec2 operator*(const vec2& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp *= rhs;
	}

	vec2 operator*(float_t lhs, const vec2& rhs)
	{
		auto tmp = rhs;
		return tmp *= lhs;
	}

	vec2& operator*=(vec2& lhs, const vec2& rhs)
	{
		lhs.x *= rhs.x;
		lhs.y *= rhs.y;

		return lhs;
	}

	vec2& operator*=(vec2& lhs, float_t rhs)
	{
		lhs.x *= rhs;
		lhs.y *= rhs;

		return lhs;
	}

	vec2 operator/(const vec2& lhs, const vec2& rhs)
	{
		auto tmp = lhs;
		return tmp /= lhs;
	}

	vec2 operator/(const vec2& lhs, float_t rhs)
	{
		auto tmp = lhs;
		return tmp /= rhs;
	}

	vec2 operator/(float_t lhs, const vec2& rhs)
	{
		auto tmp = vec2(lhs);
		return tmp /= rhs;
	}

	vec2& operator/=(vec2& lhs, const vec2& rhs)
	{
		lhs.x /= rhs.x;
		lhs.y /= rhs.y;

		return lhs;
	}

	vec2& operator/=(vec2& lhs, float_t rhs)
	{
		lhs.x /= rhs;
		lhs.y /= rhs;

		return lhs;
	}

}