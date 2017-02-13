#pragma once

#include "globals.h"

namespace vmath {
	struct vec3;

	struct quaternion
	{
		static const quaternion identity;

		float_t x;
		float_t y;
		float_t z;
		float_t w;

		quaternion();
		quaternion(float_t w, float_t x, float_t y, float_t z);
		quaternion(float_t real, vec3 imaginary);
		explicit quaternion(float_t val);

		float_t real() const;
		vec3 imaginary() const;

		quaternion normalized() const;
		quaternion conjugated() const;
		float_t magnitude() const;

		quaternion& set_imaginary(const vec3& new_imaginary);

		static quaternion rotation(vec3 axis, float_t deg);
	};

	bool operator==(const quaternion& lhs, const quaternion& rhs);
	bool operator!=(const quaternion& lhs, const quaternion& rhs);

	quaternion operator+(quaternion lhs, const quaternion& rhs);
	quaternion& operator+=(quaternion& lhs, const quaternion& rhs);

	quaternion operator-(quaternion q);
	quaternion operator-(quaternion lhs, const quaternion& rhs);
	quaternion& operator-=(quaternion& lhs, const quaternion& rhs);

	quaternion operator*(quaternion lhs, float_t rhs);
	quaternion operator*(float_t lhs, quaternion rhs);
	quaternion operator*(quaternion lhs, const quaternion& rhs);
	quaternion& operator*=(quaternion& lhs, float_t rhs);
	quaternion& operator*=(quaternion& lhs, const quaternion& rhs);
}
