#pragma once

#include "vec3.h"

#include <array>

namespace vmath {
	struct mat4x4;

	class mat3x3
	{
	public:
		static const int elements_count = 9;

		mat3x3();
		mat3x3(
			float_t m00, float_t m01, float_t m02,
			float_t m10, float_t m11, float_t m12,
			float_t m20, float_t m21, float_t m22
		);
		explicit mat3x3(float_t d);
		explicit mat3x3(const mat4x4& m);

		float_t* data();

		float_t det() const;

		vec3 operator[](int idx) const;

	private:
		std::array<float_t, elements_count> _data;
	};
}
