#include "catch.h"
#include "vmath.h"

#include <string>

namespace Catch {
	std::string toString(vmath::vec2 const& value) {
		return "(" + std::to_string(value.x) + ", " + std::to_string(value.y) + ")";
	}
}

TEST_CASE("vec2 construction", "[vec2]") {
	
	SECTION("parameterless") {
		auto v = vmath::vec2();
		
		REQUIRE(v.x == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("one arg") {
		auto v = vmath::vec2(1);
		
		REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(1).epsilon(vmath::zero_tolerance));
	}

	SECTION("two args") {
		auto v = vmath::vec2(1, 2);
		
		REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(2).epsilon(vmath::zero_tolerance));
	}

}

TEST_CASE("vec2 constants", "[vec2]") {
	
	REQUIRE(vmath::vec2::zero.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::zero.y == Approx(0).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec2::one.x == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::one.y == Approx(1).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec2::left.x == Approx(-1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::left.y == Approx(0).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec2::right.x == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::right.y == Approx(0).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec2::up.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::up.y == Approx(1).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec2::down.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::down.y == Approx(-1).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec2::half.x == Approx(0.5).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::half.y == Approx(0.5).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec2::unit_x.x == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::unit_x.y == Approx(0).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec2::unit_y.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec2::unit_y.y == Approx(1).epsilon(vmath::zero_tolerance));

}

TEST_CASE("vec2 operators", "[vec2]") {
	
	SECTION("equality/inequality") {
		auto v1 = vmath::vec2();
		auto v2 = vmath::vec2();
		auto v3 = vmath::vec2(1);

		REQUIRE(v1 == v2);
		REQUIRE(v1 != v3);
		REQUIRE(v2 != v3);
	}

	SECTION("addition") {
		auto v1 = vmath::vec2();
		auto v2 = vmath::vec2(1);

		REQUIRE(v1 + v2 == v2 + v1);
		REQUIRE(v1 + v1 == v1);
		REQUIRE(v1 + 1 == v2);
		REQUIRE(1 + v1 == v2);
	}

	SECTION("negation") {
		auto v1 = vmath::vec2();
		auto v2 = vmath::vec2(1);

		REQUIRE(v1 == -v1);
		REQUIRE(v2 == -(-v2));
		REQUIRE(v2 == v2 + (-v1));
		REQUIRE(-v2 == vmath::vec2(-1));
	}

	SECTION("substraction") {
		auto v1 = vmath::vec2();
		auto v2 = vmath::vec2(1);
		auto v3 = vmath::vec2(1, 2);

		REQUIRE(v1 - v1 == v1);
		REQUIRE(v1 - v2 == -v2);
		REQUIRE(v2 - v3 == vmath::vec2(0, -1));
	}

	SECTION("multiplication") {
		auto v1 = vmath::vec2();
		auto v2 = vmath::vec2(1);
		auto v3 = vmath::vec2(2);

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
		auto v1 = vmath::vec2();
		auto v2 = vmath::vec2(1);
		auto v3 = vmath::vec2(2);

		REQUIRE(v1 / 1 == v1);
		REQUIRE(v2 / 1 == v2);
		REQUIRE(v2 / v2 == vmath::vec2::one);
		REQUIRE(v2 * 2 == v3);
	}

}

TEST_CASE("vec2 mathematics", "[vec2]") {
	
	auto zero = vmath::vec2::zero;
	auto one = vmath::vec2::one;
	auto two = vmath::vec2(2);
	auto one_x = vmath::vec2(1, 0);
	auto one_y = vmath::vec2(0, 1);

	SECTION("magnitude") {
		REQUIRE(zero.magnitude() == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(zero.magnitude_squared() == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(one.magnitude_squared() == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(one.magnitude() == Approx(sqrt(2)).epsilon(vmath::zero_tolerance));
		REQUIRE(one_x.magnitude() == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(one_y.magnitude() == Approx(1).epsilon(vmath::zero_tolerance));
	}

	SECTION("dot product") {
		REQUIRE(zero.dot(one) == one.dot(zero));
		REQUIRE(zero.dot(one) == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(two.dot(two) == Approx(two.magnitude_squared()).epsilon(vmath::zero_tolerance));
		REQUIRE(one_x.dot(one_y) == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("cross product") {
		REQUIRE(one_x.cross(one_y) == -one_y.cross(one_x));
		REQUIRE(one_x.cross(one_y) == 1);
	}

}
