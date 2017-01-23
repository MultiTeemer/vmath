#include "globals.h"
#include "mat4x4.h"

#include <algorithm>
#include <cmath>

namespace vmath {

	const int mat4x4::elements_count = 16;

	const mat4x4 mat4x4::identity = mat4x4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	mat4x4::element_proxy::element_proxy(float_t& element)
		:
		element(element)
	{}

	mat4x4::element_proxy::operator float_t&()
	{
		return element;
	}

	float_t& mat4x4::element_proxy::operator=(float_t value)
	{
		element = value;

		return element;
	}

	mat4x4::row_proxy::row_proxy(float_t& x, float_t& y, float_t& z, float_t& w)
		:
		x(x),
		y(y),
		z(z),
		w(w)
	{}

	mat4x4::element_proxy mat4x4::row_proxy::operator[](int idx)
	{
		switch (idx)
		{
		case 0:
			return element_proxy(x);
		case 1:
			return element_proxy(y);
		case 2:
			return element_proxy(z);
		default:
			return element_proxy(w);
		}
	}

	mat4x4::row_proxy::operator vec4() const
	{
		return vec4(x, y, z, w);
	}

	mat4x4::mat4x4()
		:
		data()
	{}

	mat4x4::mat4x4(float_t value)
	{
		data.fill(value);
	}

	mat4x4::mat4x4(float * const rawData)
	{
		std::copy(rawData, rawData + 16, data.data());
	}

	mat4x4::mat4x4(vec4 c1, vec4 c2, vec4 c3, vec4 c4)
	{
		vec4 columns[4] = { c1, c2, c3, c4 };
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				data[i * 4 + j] = columns[i][j];
			}
		}
	}

	mat4x4::mat4x4(
		float_t m00, float_t m01, float_t m02, float_t m03,
		float_t m10, float_t m11, float_t m12, float_t m13,
		float_t m20, float_t m21, float_t m22, float_t m23,
		float_t m30, float_t m31, float_t m32, float_t m33
	)
		:
		data {
			m00,  m01,  m02,  m03,
			m10,  m11,  m12,  m13,
			m20,  m21,  m22,  m23,
			m30,  m31,  m32,  m33
		}
	{}

	mat4x4 mat4x4::transposed() const
	{
		auto& me = *this;
		auto c1 = me[0];
		auto c2 = me[1];
		auto c3 = me[2];
		auto c4 = me[3];

		return mat4x4(
			c1[0], c2[0], c3[0], c4[0],
			c1[1], c2[1], c3[1], c4[1],
			c1[2], c2[2], c3[2], c4[2],
			c1[3], c2[3], c3[3], c4[3]
		);
	}

	mat4x4 mat4x4::homogenized() const
	{
		auto last = data.back();

		return (*this) * (1 / last);
	}

	mat4x4::row_proxy mat4x4::operator[](int idx)
	{
		int idx_safe = std::max(std::min(idx, 3), 0);
		auto addr = data.data() + idx_safe * 4;

		return row_proxy(*addr, *(addr + 1), *(addr + 2), *(addr + 3));
	}

	vec4 mat4x4::operator[] (int idx) const
	{
		auto non_cost_me = const_cast<mat4x4&>(*this);
		auto proxy = non_cost_me[idx];

		return vec4(proxy[0], proxy[1], proxy[2], proxy[3]);
	}

	const float_t& mat4x4::element_at(int idx) const
	{
		return data[idx];
	}

	float_t& mat4x4::element_at(int idx)
	{
		auto& const_me = const_cast<const mat4x4&>(*this);
		return const_cast<float_t&>(const_me.element_at(idx));
	}

	mat4x4 mat4x4::translation(const vec3& t)
	{
		auto c1 = vec4(1, 0, 0, 0);
		auto c2 = vec4(0, 1, 0, 0);
		auto c3 = vec4(0, 0, 1, 0);
		auto c4 = vec4(t, 1);

		return mat4x4(c1, c2, c3, c4);
	}

	mat4x4 mat4x4::rotation_x(float_t rad)
	{
		auto sinx = sin(rad);
		auto cosx = cos(rad);

		return mat4x4(
			1, 0, 0, 0,
			0, cosx, sinx, 0,
			0, -sinx, cosx, 0,
			0, 0, 0, 1
		);
	}

	mat4x4 mat4x4::rotation_y(float_t rad)
	{
		auto sinx = sin(rad);
		auto cosx = cos(rad);

		return mat4x4(
			cosx, 0, -sinx, 0,
			0, 1, 0, 0,
			sinx, 0, cosx, 0,
			0, 0, 0, 1
		);
	}

	mat4x4 mat4x4::rotation_z(float_t rad)
	{
		auto sinx = sin(rad);
		auto cosx = cos(rad);

		return mat4x4(
			cosx, sinx, 0, 0,
			-sinx, cosx, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

	mat4x4 mat4x4::scale(float_t s)
	{
		return mat4x4(
			s, 0, 0, 0,
			0, s, 0, 0,
			0, 0, s, 0,
			0, 0, 0, 1
		);
	}

	mat4x4 mat4x4::scale(const vec3& s)
	{
		return mat4x4(
			s.x, 0, 0, 0,
			0, s.y, 0, 0,
			0, 0, s.z, 0,
			0, 0, 0, 1
		);
	}

	mat4x4 mat4x4::ortho(float_t left, float_t right, float_t bottom, float_t top, float_t near, float_t far)
	{
		return mat4x4(
			2 / (right - left), 0, 0, 0,
			0, 2 / (top - bottom), 0, 0,
			0, 0, 2 / (near - far), 0,
			(right + left) / (left - right), (top + bottom) / (bottom - top), (far + near) / (near - far), 1
		);
	}

	bool operator==(const mat4x4& lhs, const mat4x4& rhs)
	{
		bool equal = true;

		for (int i = 0; i < mat4x4::elements_count; ++i) {
			equal &= lhs.element_at(i) == rhs.element_at(i);
		}

		return equal;
	}

	bool operator!=(const mat4x4& lhs, const mat4x4& rhs)
	{
		return !(lhs == rhs);
	}

	mat4x4 operator+(mat4x4 lhs, const mat4x4& rhs)
	{
		return lhs += rhs;
	}

	mat4x4& operator+=(mat4x4& lhs, const mat4x4& rhs)
	{
		for (int i = 0; i < mat4x4::elements_count; ++i) {
			lhs.element_at(i) += rhs.element_at(i);
		}

		return lhs;
	}

	mat4x4 operator-(const mat4x4& arg)
	{
		return mat4x4() -= arg;
	}

	mat4x4 operator-(mat4x4 lhs, const mat4x4& rhs)
	{
		return lhs -= rhs;
	}

	mat4x4& operator-=(mat4x4& lhs, const mat4x4& rhs)
	{
		for (int i = 0; i < mat4x4::elements_count; ++i) {
			lhs.element_at(i) -= rhs.element_at(i);
		}

		return lhs;
	}

	mat4x4 operator*(mat4x4 lhs, const mat4x4& rhs)
	{
		auto m00 = (((lhs[0][0] * rhs[0][0]) + (lhs[0][1] * rhs[1][0])) + (lhs[0][2] * rhs[2][0])) + (lhs[0][3] * rhs[3][0]);
		auto m01 = (((lhs[0][0] * rhs[0][1]) + (lhs[0][1] * rhs[1][1])) + (lhs[0][2] * rhs[2][1])) + (lhs[0][3] * rhs[3][1]);
		auto m02 = (((lhs[0][0] * rhs[0][2]) + (lhs[0][1] * rhs[1][2])) + (lhs[0][2] * rhs[2][2])) + (lhs[0][3] * rhs[3][2]);
		auto m03 = (((lhs[0][0] * rhs[0][3]) + (lhs[0][1] * rhs[1][3])) + (lhs[0][2] * rhs[2][3])) + (lhs[0][3] * rhs[3][3]);
		auto m10 = (((lhs[1][0] * rhs[0][0]) + (lhs[1][1] * rhs[1][0])) + (lhs[1][2] * rhs[2][0])) + (lhs[1][3] * rhs[3][0]);
		auto m11 = (((lhs[1][0] * rhs[0][1]) + (lhs[1][1] * rhs[1][1])) + (lhs[1][2] * rhs[2][1])) + (lhs[1][3] * rhs[3][1]);
		auto m12 = (((lhs[1][0] * rhs[0][2]) + (lhs[1][1] * rhs[1][2])) + (lhs[1][2] * rhs[2][2])) + (lhs[1][3] * rhs[3][2]);
		auto m13 = (((lhs[1][0] * rhs[0][3]) + (lhs[1][1] * rhs[1][3])) + (lhs[1][2] * rhs[2][3])) + (lhs[1][3] * rhs[3][3]);
		auto m20 = (((lhs[2][0] * rhs[0][0]) + (lhs[2][1] * rhs[1][0])) + (lhs[2][2] * rhs[2][0])) + (lhs[2][3] * rhs[3][0]);
		auto m21 = (((lhs[2][0] * rhs[0][1]) + (lhs[2][1] * rhs[1][1])) + (lhs[2][2] * rhs[2][1])) + (lhs[2][3] * rhs[3][1]);
		auto m22 = (((lhs[2][0] * rhs[0][2]) + (lhs[2][1] * rhs[1][2])) + (lhs[2][2] * rhs[2][2])) + (lhs[2][3] * rhs[3][2]);
		auto m23 = (((lhs[2][0] * rhs[0][3]) + (lhs[2][1] * rhs[1][3])) + (lhs[2][2] * rhs[2][3])) + (lhs[2][3] * rhs[3][3]);
		auto m30 = (((lhs[3][0] * rhs[0][0]) + (lhs[3][1] * rhs[1][0])) + (lhs[3][2] * rhs[2][0])) + (lhs[3][3] * rhs[3][0]);
		auto m31 = (((lhs[3][0] * rhs[0][1]) + (lhs[3][1] * rhs[1][1])) + (lhs[3][2] * rhs[2][1])) + (lhs[3][3] * rhs[3][1]);
		auto m32 = (((lhs[3][0] * rhs[0][2]) + (lhs[3][1] * rhs[1][2])) + (lhs[3][2] * rhs[2][2])) + (lhs[3][3] * rhs[3][2]);
		auto m33 = (((lhs[3][0] * rhs[0][3]) + (lhs[3][1] * rhs[1][3])) + (lhs[3][2] * rhs[2][3])) + (lhs[3][3] * rhs[3][3]);

		return mat4x4(
			m00, m01, m02, m03,
			m10, m11, m12, m13,
			m20, m21, m22, m23,
			m30, m31, m32, m33
		);
	}

	mat4x4 operator*(mat4x4 lhs, float_t rhs)
	{
		return lhs *= rhs;;
	}

	mat4x4 operator*(float_t lhs, mat4x4 rhs)
	{
		return rhs *= lhs;
	}

	mat4x4& operator*=(mat4x4& lhs, const mat4x4& rhs)
	{
		return lhs = lhs * rhs;
	}

	mat4x4& operator*=(mat4x4& lhs, float_t rhs)
	{
		for (int i = 0; i < mat4x4::elements_count; ++i) {
			lhs.element_at(i) *= rhs;
		}

		return lhs;
	}

}