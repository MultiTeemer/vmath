#pragma once

#include "globals.h"

namespace vmath
{
	struct vec2
	{
		float_t x;
		float_t y;

		vec2();
		vec2(float_t x, float_t y);
		explicit vec2(float_t value);

		float_t magnitude() const;
		float_t magnitude_squared() const;
		float_t dot(const vec2& other) const;
		float_t cross(const vec2& other) const;

		static const vec2 zero;
		static const vec2 half;
		static const vec2 one;
		static const vec2 left;
		static const vec2 right;
		static const vec2 up;
		static const vec2 down;
		static const vec2 unit_x;
		static const vec2 unit_y;
	};

	bool operator==(const vec2& lhs, const vec2& rhs);
	bool operator!=(const vec2& lhs, const vec2& rhs);

	vec2 operator+(const vec2& lhs, const vec2& rhs);
	vec2 operator+(const vec2& lhs, float_t rhs);
	vec2 operator+(float_t lhs, const vec2& rhs);

	vec2& operator+=(vec2& lhs, const vec2& rhs);
	vec2& operator+=(vec2& lhs, float_t rhs);

	vec2 operator-(const vec2& lhs, const vec2& rhs);
	vec2 operator-(const vec2& lhs, float_t rhs);
	vec2 operator-(float_t lhs, const vec2& rhs);
	vec2 operator-(const vec2& rhs);

	vec2& operator-=(vec2& lhs, const vec2& rhs);
	vec2& operator-=(vec2& lhs, float_t rhs);

	vec2 operator*(const vec2& lhs, const vec2& rhs);
	vec2 operator*(const vec2& lhs, float_t rhs);
	vec2 operator*(float_t, const vec2& rhs);

	vec2& operator*=(vec2& lhs, const vec2& rhs);
	vec2& operator*=(vec2& lhs, float_t rhs);

	vec2 operator/(const vec2& lhs, const vec2& rhs);
	vec2 operator/(const vec2& lhs, float_t rhs);
	vec2 operator/(float_t lhs, const vec2& rhs);

	vec2& operator/=(vec2& lhs, const vec2& rhs);
	vec2& operator/=(vec2& lhs, float_t rhs);
}
