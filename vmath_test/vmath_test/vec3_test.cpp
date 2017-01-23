#include "catch.h"
#include "vmath.h"

#include <string>

namespace Catch {
	std::string toString(vmath::vec3 const& value) {
		return "(" + std::to_string(value.x) + ", " + std::to_string(value.y) + ", " + std::to_string(value.z) + ")";
	}
}

TEST_CASE("vec3 construction", "[vec3]") {

	SECTION("parameterless") {
		auto v = vmath::vec3();

		REQUIRE(v.x == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(v.z == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("one arg") {

		SECTION("scalar") {
			auto v = vmath::vec3(1);

			REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(v.y == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(v.z == Approx(1).epsilon(vmath::zero_tolerance));
		}

		SECTION("vec2") {
			auto v = vmath::vec3(vmath::vec2::one);

			REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(v.y == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(v.z == Approx(0).epsilon(vmath::zero_tolerance));
		}

	}

	SECTION("two args") {
		auto v = vmath::vec3(1, 2);

		REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(v.z == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("three args") {
		auto v = vmath::vec3(1, 2, 3);

		REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(v.z == Approx(3).epsilon(vmath::zero_tolerance));
	}

}

TEST_CASE("vec3 constants", "[vec3]") {

	REQUIRE(vmath::vec3::zero.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::zero.y == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::zero.z == Approx(0).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec3::half.x == Approx(0.5).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::half.y == Approx(0.5).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::half.z == Approx(0.5).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec3::one.x == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::one.y == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::one.z == Approx(1).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec3::unit_x.x == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::unit_x.y == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::unit_x.z == Approx(0).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec3::unit_y.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::unit_y.y == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::unit_y.z == Approx(0).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec3::unit_z.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::unit_z.y == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec3::unit_z.z == Approx(1).epsilon(vmath::zero_tolerance));

}

TEST_CASE("vec3 operators", "[vec3]") {

	SECTION("equality/inequality") {
		auto v1 = vmath::vec3();
		auto v2 = vmath::vec3();
		auto v3 = vmath::vec3(1);

		REQUIRE(v1 == v2);
		REQUIRE(v1 != v3);
		REQUIRE(v2 != v3);
	}

	SECTION("addition") {
		auto v1 = vmath::vec3();
		auto v2 = vmath::vec3(1);

		REQUIRE(v1 + v2 == v2 + v1);
		REQUIRE(v1 + v1 == v1);
		REQUIRE(v1 + 1 == v2);
		REQUIRE(1 + v1 == v2);
	}

	SECTION("negation") {
		auto v1 = vmath::vec3();
		auto v2 = vmath::vec3(1);

		REQUIRE(v1 == -v1);
		REQUIRE(v2 == -(-v2));
		REQUIRE(v2 == v2 + (-v1));
		REQUIRE(-v2 == vmath::vec3(-1));
	}

	SECTION("substraction") {
		auto v1 = vmath::vec3();
		auto v2 = vmath::vec3(1);
		auto v3 = vmath::vec3(1, 2);

		REQUIRE(v1 - v1 == v1);
		REQUIRE(v1 - v2 == -v2);
		REQUIRE(v2 - v3 == vmath::vec3(0, -1, 1));
	}

	SECTION("multiplication") {
		auto v1 = vmath::vec3();
		auto v2 = vmath::vec3(1);
		auto v3 = vmath::vec3(2);

		REQUIRE(v1 * v2 == v2 * v1);
		REQUIRE(v2 * v3 == v3 * v2);
		REQUIRE((v1 * v2) * v3 == v1 * (v2 * v3));
		REQUIRE(v1 * v2 == v1);
		REQUIRE(v2 * v2 == v2);
		REQUIRE(v1 * 2 == v1);
		REQUIRE(v2 * 1 == v2);
		REQUIRE(v2 * 2 == v3);
		REQUIRE(2 * v2 == v2 * 2);
	}

	SECTION("division") {
		auto v1 = vmath::vec3();
		auto v2 = vmath::vec3(1);
		auto v3 = vmath::vec3(2);

		REQUIRE(v1 / 1 == v1);
		REQUIRE(v2 / 1 == v2);
		REQUIRE(v2 / v2 == vmath::vec3::one);
		REQUIRE(v2 * 2 == v3);
	}

}

TEST_CASE("vec3 mathematics", "[vec3]") {

	auto zero = vmath::vec3::zero;
	auto one = vmath::vec3::one;
	auto two = vmath::vec3(2);
	auto one_x = vmath::vec3(1, 0);
	auto one_y = vmath::vec3(0, 1);
	auto one_z = vmath::vec3(0, 0, 1);

	SECTION("magnitude") {
		REQUIRE(zero.magnitude() == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(zero.magnitude_squared() == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(one.magnitude_squared() == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(one.magnitude() == Approx(sqrt(3)).epsilon(vmath::zero_tolerance));
		REQUIRE(one_x.magnitude() == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(one_y.magnitude() == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(one_z.magnitude() == Approx(1).epsilon(vmath::zero_tolerance));
	}

	SECTION("dot product") {
		REQUIRE(zero.dot(one) == one.dot(zero));
		REQUIRE(zero.dot(one) == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(two.dot(two) == Approx(two.magnitude_squared()).epsilon(vmath::zero_tolerance));
		REQUIRE(one_x.dot(one_y) == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("cross product") {
		REQUIRE(one_x.cross(one_y) == -one_y.cross(one_x));
		REQUIRE(one_x.cross(one_y) == vmath::vec3(0, 0, 1));
	}

}