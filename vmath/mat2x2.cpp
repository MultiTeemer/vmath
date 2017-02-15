#include "mat2x2.h"
#include "mat3x3.h"

namespace vmath {

	mat2x2::mat2x2()
		:
		_data()
	{}

	mat2x2::mat2x2(float_t m00, float_t m01, float_t m10, float_t m11)
		:
		_data{m00, m01, m10, m11}
	{}

	mat2x2::mat2x2(const mat3x3& m)
		:
		_data{m[0][0], m[0][1], m[1][0], m[1][1]}
	{}

	mat2x2::mat2x2(float_t d)
		:
		_data{ d, d, d, d }
	{}

	float_t* mat2x2::data()
	{
		return _data.data();
	}

	float_t mat2x2::det() const
	{
		return _data[0] * _data[3] - _data[1] * _data[2];
	}

	vec2 mat2x2::operator[](int idx) const
	{
		return vec2(_data[idx * 2], _data[idx * 2 + 1]);
	}

}