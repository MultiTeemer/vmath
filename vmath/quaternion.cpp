#include "quaternion.h"
#include "vec3.h"
#include "mat4x4.h"

#include <cmath>

namespace vmath {

	const quaternion quaternion::identity = quaternion(1, vec3());

	quaternion::quaternion()
		:
		x(0),
		y(0),
		z(0),
		w(0)
	{}

	quaternion::quaternion(float_t w, float_t x, float_t y, float_t z)
		:
		x(x),
		y(y),
		z(z),
		w(w)
	{}

	quaternion::quaternion(float_t real, vec3 imaginary)
		:
		x(imaginary.x),
		y(imaginary.y),
		z(imaginary.z),
		w(real)
	{}

	quaternion::quaternion(float_t val)
		:
		x(val),
		y(val),
		z(val),
		w(val)
	{}

	float_t quaternion::real() const
	{
		return w;
	}

	vec3 quaternion::imaginary() const
	{
		return vec3(x, y, z);
	}

	quaternion quaternion::normalized() const
	{
		auto m = magnitude();

		return quaternion(w / m, x / m, y / m, z / m);
	}

	quaternion quaternion::conjugated() const
	{
		return quaternion(w, -imaginary());
	}

	float_t quaternion::magnitude() const
	{
		return std::sqrt(x * x + y * y + z * z + w * w);
	}

	quaternion& quaternion::set_imaginary(const vec3& new_imaginary)
	{
		x = new_imaginary.x;
		y = new_imaginary.y;
		z = new_imaginary.z;

		return *this;
	}

	mat4x4 quaternion::to_matrix() const
	{
		return mat4x4(
			1 - 2 * (y * y + z * z), 2 * (x * y + w * z), 2 * (x * z - w * y), 0,
			2 * (x * y - w * z), 1 - 2 * (x * x + z * z), 2 * (y * z + w * x), 0,
			2 * (x * z + w * y), 2 * (y * z - w * x), 1 - 2 * (x * x + y * y), 0,
			0, 0, 0, 1
		);
	}

	quaternion quaternion::rotation(vec3 axis, float_t deg)
	{
		return quaternion(cos(deg / 2), axis.normalized() * sin(deg / 2)).normalized();
	}

	bool operator==(const quaternion& lhs, const quaternion& rhs)
	{
		return std::abs(lhs.real() - rhs.real()) < zero_tolerance && lhs.imaginary() == rhs.imaginary();
	}

	bool operator!=(const quaternion& lhs, const quaternion& rhs)
	{
		return !(lhs == rhs);
	}

	quaternion& operator+=(quaternion& lhs, const quaternion& rhs)
	{
		lhs.w += rhs.w;
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;

		return lhs;
	}

	quaternion operator+(quaternion lhs, const quaternion& rhs)
	{
		return lhs += rhs;
	}

	quaternion& operator-=(quaternion& lhs, const quaternion& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
		lhs.w -= rhs.w;

		return lhs;
	}

	quaternion operator-(quaternion q)
	{
		return quaternion() -= q;
	}

	quaternion operator-(quaternion lhs, const quaternion& rhs)
	{
		return lhs -= rhs;
	}

	quaternion operator*(quaternion lhs, float_t rhs)
	{
		return lhs *= rhs;
	}
	
	quaternion operator*(float_t lhs, quaternion rhs)
	{
		return rhs *= lhs;
	}
	
	quaternion operator*(quaternion lhs, const quaternion& rhs)
	{
		return lhs *= rhs;
	}
	
	quaternion& operator*=(quaternion& lhs, float_t rhs)
	{
		lhs.x *= rhs;
		lhs.y *= rhs;
		lhs.z *= rhs;
		lhs.w *= rhs;

		return lhs;
	}
	
	quaternion& operator*=(quaternion& lhs, const quaternion& rhs)
	{
		auto r1 = lhs.real();
		auto r2 = rhs.real();
		auto im1 = lhs.imaginary();
		auto im2 = rhs.imaginary();
		auto new_im1 = im1.cross(im2) + r1 * im2 + r2 * im1;

		lhs.w = r1 * r2 - im1.dot(im2);
		lhs.set_imaginary(new_im1);

		return lhs;
	}

}