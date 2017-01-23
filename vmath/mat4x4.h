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

		static const mat4x4 identity;

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

		mat4x4 transposed() const;
		mat4x4 homogenized() const;

		row_proxy operator[](int idx);
		vec4 operator[](int idx) const;

		friend bool operator==(const mat4x4& lhs, const mat4x4& rhs);
		friend bool operator!=(const mat4x4& lhs, const mat4x4& rhs);

		friend mat4x4 operator+(mat4x4 lhs, const mat4x4& rhs);
		friend mat4x4& operator+=(mat4x4& lhs, const mat4x4& rhs);

		friend mat4x4 operator-(const mat4x4& arg);
		friend mat4x4 operator-(mat4x4 lhs, const mat4x4& rhs);
		friend mat4x4& operator-=(mat4x4& lhs, const mat4x4& rhs);

		friend mat4x4 operator*(mat4x4 lhs, const mat4x4& rhs);
		friend mat4x4 operator*(mat4x4 lhs, float_t rhs);
		friend mat4x4 operator*(float_t lhs, mat4x4 rhs);
		friend mat4x4& operator*=(mat4x4& lhs, const mat4x4& rhs);
		friend mat4x4& operator*= (mat4x4& lhs, float_t rhs);

		static mat4x4 translation(const vec3& t);

		static mat4x4 rotation_x(float_t rad);
		static mat4x4 rotation_y(float_t rad);
		static mat4x4 rotation_z(float_t rad);

		static mat4x4 scale(float_t s);
		static mat4x4 scale(const vec3& scale);

		static mat4x4 ortho(float_t left, float_t right, float_t bottom, float_t top, float_t near, float_t far);

		static mat4x4 perspective(float_t fov, float_t ratio, float_t near, float_t far);

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
