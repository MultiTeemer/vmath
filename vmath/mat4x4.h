#pragma once

#include "globals.h"
#include "vec4.h"

#include <array>

namespace vmath {
	class mat4x4
	{
	private:
		class row_proxy;

	public:
		static const int elements_count;

		mat4x4();
		mat4x4(vec4 c1, vec4 c2, vec4 c3, vec4 c4);
		mat4x4(
			float_t m00, float_t m01, float_t m02, float_t m03,
			float_t m10, float_t m11, float_t m12, float_t m13,
			float_t m20, float_t m21, float_t m22, float_t m23,
			float_t m30, float_t m31, float_t m32, float_t m33
		);
		explicit mat4x4(float_t value);
		explicit mat4x4(float * const data);

		row_proxy operator[](int idx);

		friend bool operator==(const mat4x4& lhs, const mat4x4& rhs);
		friend bool operator!=(const mat4x4& lhs, const mat4x4& rhs);

		friend mat4x4 operator+(mat4x4 lhs, const mat4x4& rhs);
		friend mat4x4& operator+=(mat4x4& lhs, const mat4x4& rhs);

		friend mat4x4 operator-(const mat4x4& arg);
		friend mat4x4 operator-(mat4x4 lhs, const mat4x4& rhs);
		friend mat4x4& operator-=(mat4x4& lhs, const mat4x4& rhs);

	private:
		class element_proxy
		{
		public:
			element_proxy(float_t& element);

			operator float_t&();

			float_t& operator=(float_t value);

		private:
			float_t& element;
		};

		class row_proxy
		{
		public:
			row_proxy(float_t& x, float_t& y, float_t& z, float_t& w);

			element_proxy operator[](int idx);

			operator vec4() const;

		private:
			float_t& x;
			float_t& y;
			float_t& z;
			float_t& w;
		};

		std::array<float_t, 16> data;

		const float_t& element_at(int idx) const;
		float_t& element_at(int idx);
	};
}
