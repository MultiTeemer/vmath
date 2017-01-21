#include "globals.h"
#include "mat4x4.h"

#include <algorithm>

namespace vmath {

	const int mat4x4::elements_count = 16;

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

	mat4x4::row_proxy mat4x4::operator[](int idx)
	{
		int idx_safe = std::max(std::min(idx, 3), 0);
		auto addr = data.data() + idx_safe * 4;

		return row_proxy(*addr, *(addr + 1), *(addr + 2), *(addr + 3));
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

}