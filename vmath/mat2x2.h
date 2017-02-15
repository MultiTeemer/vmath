#pragma once

#include <array>

#include "vec2.h"

namespace vmath {
	struct mat3x3;

	class mat2x2
	{
	public:
		static const int elements_count = 4;

		mat2x2();
		mat2x2(float_t m00, float_t m01, float_t m10, float_t m11);
		explicit mat2x2(float_t d);
		explicit mat2x2(const mat3x3& m);

		float_t* data();

		float_t det() const;

		vec2 operator[](int idx) const;

	private:
		std::array<float_t, elements_count> _data;
	};
}
