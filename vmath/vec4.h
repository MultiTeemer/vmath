#pragma once

#include "globals.h"

namespace vmath {
	struct vec3;

	struct vec4
	{
		float_t x;
		float_t y;
		float_t z;
		float_t w;

		vec4();
		vec4(float_t x, float_t y, float_t z, float_t w = 0);
		explicit vec4(float_t value);
		explicit vec4(const vec3& xyz, float_t w = 0);

		vec4 homogenized() const;

		float_t operator[](int idx) const;

		static const vec4 zero;
		static const vec4 one;
		static const vec4 unit_w;
	};

	float_t sum_of_elements(const vec4& v);

	bool operator==(const vec4& lhs, const vec4& rhs);
	bool operator!=(const vec4& lhs, const vec4& rhs);

	vec4 operator+(const vec4& lhs, const vec4& rhs);
	vec4 operator+(const vec4& lhs, float_t rhs);
	vec4 operator+(float_t lhs, const vec4& rhs);

	vec4& operator+=(vec4& lhs, const vec4& rhs);
	vec4& operator+=(vec4& lhs, float_t rhs);

	vec4 operator-(const vec4& lhs, const vec4& rhs);
	vec4 operator-(const vec4& lhs, float_t rhs);
	vec4 operator-(float_t lhs, const vec4& rhs);
	vec4 operator-(const vec4& rhs);

	vec4& operator-=(vec4& lhs, const vec4& rhs);
	vec4& operator-=(vec4& lhs, float_t rhs);

	vec4 operator*(const vec4& lhs, const vec4& rhs);
	vec4 operator*(const vec4& lhs, float_t rhs);
	vec4 operator*(float_t, const vec4& rhs);

	vec4& operator*=(vec4& lhs, const vec4& rhs);
	vec4& operator*=(vec4& lhs, float_t rhs);

	vec4 operator/(const vec4& lhs, const vec4& rhs);
	vec4 operator/(const vec4& lhs, float_t rhs);
	vec4 operator/(float_t lhs, const vec4& rhs);

	vec4& operator/=(vec4& lhs, const vec4& rhs);
	vec4& operator/=(vec4& lhs, float_t rhs);
}
