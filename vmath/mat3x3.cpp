#include "mat2x2.h"
#include "mat3x3.h"
#include "mat4x4.h"
#include "vec4.h"

namespace vmath {

	mat3x3::mat3x3()
		:
		_data()
	{}

	mat3x3::mat3x3(
		float_t m00, float_t m01, float_t m02,
		float_t m10, float_t m11, float_t m12,
		float_t m20, float_t m21, float_t m22
	)
		:
		_data{ m00, m01, m02, m10, m11, m12, m20, m21, m22 }
	{}

	mat3x3::mat3x3(const mat4x4& m)
		:
		_data{ m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2] }
	{}

	mat3x3::mat3x3(float_t d)
		:
		_data{ d, d, d, d, d, d, d, d, d }
	{}

	float_t* mat3x3::data()
	{
		return _data.data();
	}

	float_t mat3x3::det() const
	{
		auto& me = *this;

		return me[0][0] * mat2x2(me[1][1], me[1][2], me[2][1], me[2][2]).det()
			- me[1][0] * mat2x2(me[0][1], me[0][2], me[2][1], me[2][2]).det()
			+ me[2][0] * mat2x2(me[0][1], me[0][2], me[1][1], me[1][2]).det()
		;
	}

	vec3 mat3x3::operator[](int idx) const
	{
		return vec3(_data[idx * 3], _data[idx * 3 + 1], _data[idx * 3 + 2]);
	}

}