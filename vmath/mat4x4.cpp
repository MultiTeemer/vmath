#include "globals.h"
#include "utils.h"
#include "vec3.h"
#include "vec4.h"
#include "mat3x3.h"
#include "mat4x4.h"

#include <algorithm>
#include <cmath>

namespace vmath {

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
		_data()
	{}

	mat4x4::mat4x4(float_t value)
	{
		_data.fill(value);
	}

	mat4x4::mat4x4(float * const rawData)
	{
		std::copy(rawData, rawData + 16, _data.data());
	}

	mat4x4::mat4x4(vec4 c1, vec4 c2, vec4 c3, vec4 c4)
	{
		vec4 columns[4] = { c1, c2, c3, c4 };
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				_data[i * 4 + j] = columns[i][j];
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
		_data {
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
		auto last = _data.back();

		return (*this) * (1 / last);
	}

	mat4x4 mat4x4::inversed() const
	{
		float_t inv[16];

		inv[0] = _data[5] * _data[10] * _data[15] -
			_data[5] * _data[11] * _data[14] -
			_data[9] * _data[6] * _data[15] +
			_data[9] * _data[7] * _data[14] +
			_data[13] * _data[6] * _data[11] -
			_data[13] * _data[7] * _data[10];

		inv[4] = -_data[4] * _data[10] * _data[15] +
			_data[4] * _data[11] * _data[14] +
			_data[8] * _data[6] * _data[15] -
			_data[8] * _data[7] * _data[14] -
			_data[12] * _data[6] * _data[11] +
			_data[12] * _data[7] * _data[10];

		inv[8] = _data[4] * _data[9] * _data[15] -
			_data[4] * _data[11] * _data[13] -
			_data[8] * _data[5] * _data[15] +
			_data[8] * _data[7] * _data[13] +
			_data[12] * _data[5] * _data[11] -
			_data[12] * _data[7] * _data[9];

		inv[12] = -_data[4] * _data[9] * _data[14] +
			_data[4] * _data[10] * _data[13] +
			_data[8] * _data[5] * _data[14] -
			_data[8] * _data[6] * _data[13] -
			_data[12] * _data[5] * _data[10] +
			_data[12] * _data[6] * _data[9];

		inv[1] = -_data[1] * _data[10] * _data[15] +
			_data[1] * _data[11] * _data[14] +
			_data[9] * _data[2] * _data[15] -
			_data[9] * _data[3] * _data[14] -
			_data[13] * _data[2] * _data[11] +
			_data[13] * _data[3] * _data[10];

		inv[5] = _data[0] * _data[10] * _data[15] -
			_data[0] * _data[11] * _data[14] -
			_data[8] * _data[2] * _data[15] +
			_data[8] * _data[3] * _data[14] +
			_data[12] * _data[2] * _data[11] -
			_data[12] * _data[3] * _data[10];

		inv[9] = -_data[0] * _data[9] * _data[15] +
			_data[0] * _data[11] * _data[13] +
			_data[8] * _data[1] * _data[15] -
			_data[8] * _data[3] * _data[13] -
			_data[12] * _data[1] * _data[11] +
			_data[12] * _data[3] * _data[9];

		inv[13] = _data[0] * _data[9] * _data[14] -
			_data[0] * _data[10] * _data[13] -
			_data[8] * _data[1] * _data[14] +
			_data[8] * _data[2] * _data[13] +
			_data[12] * _data[1] * _data[10] -
			_data[12] * _data[2] * _data[9];

		inv[2] = _data[1] * _data[6] * _data[15] -
			_data[1] * _data[7] * _data[14] -
			_data[5] * _data[2] * _data[15] +
			_data[5] * _data[3] * _data[14] +
			_data[13] * _data[2] * _data[7] -
			_data[13] * _data[3] * _data[6];

		inv[6] = -_data[0] * _data[6] * _data[15] +
			_data[0] * _data[7] * _data[14] +
			_data[4] * _data[2] * _data[15] -
			_data[4] * _data[3] * _data[14] -
			_data[12] * _data[2] * _data[7] +
			_data[12] * _data[3] * _data[6];

		inv[10] = _data[0] * _data[5] * _data[15] -
			_data[0] * _data[7] * _data[13] -
			_data[4] * _data[1] * _data[15] +
			_data[4] * _data[3] * _data[13] +
			_data[12] * _data[1] * _data[7] -
			_data[12] * _data[3] * _data[5];

		inv[14] = -_data[0] * _data[5] * _data[14] +
			_data[0] * _data[6] * _data[13] +
			_data[4] * _data[1] * _data[14] -
			_data[4] * _data[2] * _data[13] -
			_data[12] * _data[1] * _data[6] +
			_data[12] * _data[2] * _data[5];

		inv[3] = -_data[1] * _data[6] * _data[11] +
			_data[1] * _data[7] * _data[10] +
			_data[5] * _data[2] * _data[11] -
			_data[5] * _data[3] * _data[10] -
			_data[9] * _data[2] * _data[7] +
			_data[9] * _data[3] * _data[6];

		inv[7] = _data[0] * _data[6] * _data[11] -
			_data[0] * _data[7] * _data[10] -
			_data[4] * _data[2] * _data[11] +
			_data[4] * _data[3] * _data[10] +
			_data[8] * _data[2] * _data[7] -
			_data[8] * _data[3] * _data[6];

		inv[11] = -_data[0] * _data[5] * _data[11] +
			_data[0] * _data[7] * _data[9] +
			_data[4] * _data[1] * _data[11] -
			_data[4] * _data[3] * _data[9] -
			_data[8] * _data[1] * _data[7] +
			_data[8] * _data[3] * _data[5];

		inv[15] = _data[0] * _data[5] * _data[10] -
			_data[0] * _data[6] * _data[9] -
			_data[4] * _data[1] * _data[10] +
			_data[4] * _data[2] * _data[9] +
			_data[8] * _data[1] * _data[6] -
			_data[8] * _data[2] * _data[5];

		float_t det = _data[0] * inv[0] + _data[1] * inv[4] + _data[2] * inv[8] + _data[3] * inv[12];

		for (int i = 0; i < 16; i++)
			inv[i] /= det;

		return mat4x4(
			inv[0], inv[1], inv[2], inv[3],
			inv[4], inv[5], inv[6], inv[7],
			inv[8], inv[9], inv[10], inv[11],
			inv[12], inv[13], inv[14], inv[15]
		);
	}

	bool mat4x4::invertable() const
	{
		return abs(det()) > zero_tolerance;
	}

	float_t* mat4x4::data()
	{
		return _data.data();
	}

	float_t mat4x4::det() const
	{
		auto& me = *this;
		return
			me[0][0] * mat3x3(me[1][1], me[1][2], me[1][3], me[2][1], me[2][2], me[2][3], me[3][1], me[3][2], me[3][3]).det()
			- me[1][0] * mat3x3(me[0][1], me[0][2], me[0][3], me[2][1], me[2][2], me[2][3], me[3][1], me[3][2], me[3][3]).det()
			+ me[2][0] * mat3x3(me[0][1], me[0][2], me[0][3], me[1][1], me[1][2], me[1][3], me[3][1], me[3][2], me[3][3]).det()
			- me[3][0] * mat3x3(me[0][1], me[0][2], me[0][3], me[1][1], me[1][2], me[1][3], me[2][1], me[2][2], me[2][3]).det()
		;
	}

	mat4x4::row_proxy mat4x4::operator[](int idx)
	{
		int idx_safe = std::max(std::min(idx, 3), 0);
		auto addr = _data.data() + idx_safe * 4;

		return row_proxy(*addr, *(addr + 1), *(addr + 2), *(addr + 3));
	}

	vec4 mat4x4::operator[] (int idx) const
	{
		int idx_safe = std::max(std::min(idx, 3), 0);
		auto addr = _data.data() + idx_safe * 4;

		return vec4(*addr, *(addr + 1), *(addr + 2), *(addr + 3));
	}

	vec4 mat4x4::row(int idx) const
	{
		int idx_safe = std::max(std::min(idx, 3), 0);
		auto addr = _data.data() + idx_safe;

		return vec4(*addr, *(addr + 4), *(addr + 8), *(addr + 12));
	}

	const float_t& mat4x4::element_at(int idx) const
	{
		return _data[idx];
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

	mat4x4 mat4x4::rotation(vec3 axis, float_t rad)
	{
		auto a = axis.normalized();
		float_t c = cos(rad);
		float_t s = sin(rad);

		return mat4x4(
			c + (1 - c) * a.x * a.x, (1 - c) * a.x * a.y + s * a.z, (1 - c) * a.x * a.z - s * a.y, 0,
			(1 - c) * a.x * a.y - s * a.z, c + (1 - c) * a.y * a.y, (1 - c) * a.y * a.z + s * a.x, 0,
			(1 - c) * a.x * a.z + s * a.y, (1 - c) * a.y * a.z - s * a.x, c + (1 - c) * a.z * a.z, 0,
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

	mat4x4 mat4x4::orthographic(float_t left, float_t right, float_t bottom, float_t top, float_t near, float_t far)
	{
		return mat4x4(
			2 / (right - left), 0, 0, 0,
			0, 2 / (top - bottom), 0, 0,
			0, 0, 2 / (near - far), 0,
			(right + left) / (left - right), (top + bottom) / (bottom - top), (far + near) / (near - far), 1
		);
	}

	mat4x4 mat4x4::perspective(float_t fov, float_t ratio, float_t near, float_t far)
	{
		auto t = tanf(deg_to_rad(fov / 2)) * near;
		auto r = t * ratio;
		auto l = -t * ratio;
		auto b = -t * ratio;

		return mat4x4(
			2 * near / (r - l), 0, 0, 0,
			0, 2 * near / (t - b), 0, 0,
			(r + l) / (r - l), (t + b) / (t - b), (far + near) / (near - far), -1,
			0, 0, 2 * far * near / (near - far), 0
		);
	}

	mat4x4 mat4x4::look_at(const vec3& from, const vec3& to, const vec3& up)
	{
		auto f = (to - from).normalized();
		auto s = f.cross(up);
		auto u = s.cross(f);

		return mat4x4(
			vec4(s),
			vec4(u),
			vec4(f),
			vec4(-from, 1)
		);
	}

	bool operator==(const mat4x4& lhs, const mat4x4& rhs)
	{
		bool equal = true;

		for (int i = 0; i < mat4x4::elements_count; ++i) {
			equal &= abs(lhs.element_at(i) - rhs.element_at(i)) < zero_tolerance;
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
		auto m00 = rhs[0][0] * lhs[0][0] + rhs[0][1] * lhs[1][0] + rhs[0][2] * lhs[2][0] + rhs[0][3] * lhs[3][0];
		auto m01 = rhs[0][0] * lhs[0][1] + rhs[0][1] * lhs[1][1] + rhs[0][2] * lhs[2][1] + rhs[0][3] * lhs[3][1];
		auto m02 = rhs[0][0] * lhs[0][2] + rhs[0][1] * lhs[1][2] + rhs[0][2] * lhs[2][2] + rhs[0][3] * lhs[3][2];
		auto m03 = rhs[0][0] * lhs[0][3] + rhs[0][1] * lhs[1][3] + rhs[0][2] * lhs[2][3] + rhs[0][3] * lhs[3][3];
		auto m10 = rhs[1][0] * lhs[0][0] + rhs[1][1] * lhs[1][0] + rhs[1][2] * lhs[2][0] + rhs[1][3] * lhs[3][0];
		auto m11 = rhs[1][0] * lhs[0][1] + rhs[1][1] * lhs[1][1] + rhs[1][2] * lhs[2][1] + rhs[1][3] * lhs[3][1];
		auto m12 = rhs[1][0] * lhs[0][2] + rhs[1][1] * lhs[1][2] + rhs[1][2] * lhs[2][2] + rhs[1][3] * lhs[3][2];
		auto m13 = rhs[1][0] * lhs[0][3] + rhs[1][1] * lhs[1][3] + rhs[1][2] * lhs[2][3] + rhs[1][3] * lhs[3][3];
		auto m20 = rhs[2][0] * lhs[0][0] + rhs[2][1] * lhs[1][0] + rhs[2][2] * lhs[2][0] + rhs[2][3] * lhs[3][0];
		auto m21 = rhs[2][0] * lhs[0][1] + rhs[2][1] * lhs[1][1] + rhs[2][2] * lhs[2][1] + rhs[2][3] * lhs[3][1];
		auto m22 = rhs[2][0] * lhs[0][2] + rhs[2][1] * lhs[1][2] + rhs[2][2] * lhs[2][2] + rhs[2][3] * lhs[3][2];
		auto m23 = rhs[2][0] * lhs[0][3] + rhs[2][1] * lhs[1][3] + rhs[2][2] * lhs[2][3] + rhs[2][3] * lhs[3][3];
		auto m30 = rhs[3][0] * lhs[0][0] + rhs[3][1] * lhs[1][0] + rhs[3][2] * lhs[2][0] + rhs[3][3] * lhs[3][0];
		auto m31 = rhs[3][0] * lhs[0][1] + rhs[3][1] * lhs[1][1] + rhs[3][2] * lhs[2][1] + rhs[3][3] * lhs[3][1];
		auto m32 = rhs[3][0] * lhs[0][2] + rhs[3][1] * lhs[1][2] + rhs[3][2] * lhs[2][2] + rhs[3][3] * lhs[3][2];
		auto m33 = rhs[3][0] * lhs[0][3] + rhs[3][1] * lhs[1][3] + rhs[3][2] * lhs[2][3] + rhs[3][3] * lhs[3][3];

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

	vec4 operator*(const mat4x4& lhs, const vec4& rhs)
	{
		return vec4(
			sum_of_elements(lhs.row(0) * rhs),
			sum_of_elements(lhs.row(1) * rhs),
			sum_of_elements(lhs.row(2) * rhs),
			sum_of_elements(lhs.row(3) * rhs)
		);
	}

}