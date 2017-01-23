#pragma once

#include "globals.h"
#include "vec2.h"

namespace vmath {
	struct vec3
	{
		float_t x;
		float_t y;
		float_t z;

		vec3();
		vec3(float_t x, float_t y);
		vec3(float_t x, float_t y, float_t z);
		explicit vec3(float_t value);
		explicit vec3(const vec2& xy);

		float_t magnitude() const;
		float_t magnitude_squared() const;
		float_t dot(const vec3& other) const;

		vec3 cross(const vec3& other) const;
		vec3 normalized() const;

		static const vec3 zero;
		static const vec3 half;
		static const vec3 one;
		static const vec3 unit_x;
		static const vec3 unit_y;
		static const vec3 unit_z;
	};

	bool operator==(const vec3& lhs, const vec3& rhs);
	bool operator!=(const vec3& lhs, const vec3& rhs);

	vec3 operator+(const vec3& lhs, const vec3& rhs);
	vec3 operator+(const vec3& lhs, float_t rhs);
	vec3 operator+(float_t lhs, const vec3& rhs);

	vec3& operator+=(vec3& lhs, const vec3& rhs);
	vec3& operator+=(vec3& lhs, float_t rhs);

	vec3 operator-(const vec3& lhs, const vec3& rhs);
	vec3 operator-(const vec3& lhs, float_t rhs);
	vec3 operator-(float_t lhs, const vec3& rhs);
	vec3 operator-(const vec3& rhs);

	vec3& operator-=(vec3& lhs, const vec3& rhs);
	vec3& operator-=(vec3& lhs, float_t rhs);

	vec3 operator*(const vec3& lhs, const vec3& rhs);
	vec3 operator*(const vec3& lhs, float_t rhs);
	vec3 operator*(float_t, const vec3& rhs);

	vec3& operator*=(vec3& lhs, const vec3& rhs);
	vec3& operator*=(vec3& lhs, float_t rhs);

	vec3 operator/(const vec3& lhs, const vec3& rhs);
	vec3 operator/(const vec3& lhs, float_t rhs);
	vec3 operator/(float_t lhs, const vec3& rhs);

	vec3& operator/=(vec3& lhs, const vec3& rhs);
	vec3& operator/=(vec3& lhs, float_t rhs);
}
