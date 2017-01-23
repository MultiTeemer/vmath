#include "catch.h"
#include "vmath.h"

#include <string>

namespace Catch {
	std::string toString(vmath::vec4 const& value) {
		using std::to_string;
		return "("
				+ to_string(value.x)
				+ ", " + to_string(value.y)
				+ ", " + to_string(value.z)
				+ "," + to_string(value.w)
			+ ")";
	}
}

TEST_CASE("vec4 construction", "[vec4]") {

	SECTION("parameterless") {
		auto v = vmath::vec4();

		REQUIRE(v.x == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(v.z == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(v.w == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("one arg") {

		SECTION("scalar") {
			auto v = vmath::vec4(1);

			REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(v.y == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(v.z == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(v.w == Approx(1).epsilon(vmath::zero_tolerance));
		}

		SECTION("vec3") {
			auto v = vmath::vec4(vmath::vec3(1, 2, 3));

			REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(v.y == Approx(2).epsilon(vmath::zero_tolerance));
			REQUIRE(v.z == Approx(3).epsilon(vmath::zero_tolerance));
			REQUIRE(v.w == Approx(0).epsilon(vmath::zero_tolerance));
		}

	}

	SECTION("two args") {
		auto v = vmath::vec4(vmath::vec3(1, 2, 3), 1);

		REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(v.z == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(v.w == Approx(1).epsilon(vmath::zero_tolerance));
	}

	SECTION("three args") {
		auto v = vmath::vec4(1, 2, 3);

		REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(v.z == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(v.w == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("four args") {
		auto v = vmath::vec4(1, 2, 3, 4);

		REQUIRE(v.x == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(v.y == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(v.z == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(v.w == Approx(4).epsilon(vmath::zero_tolerance));
	}

}

TEST_CASE("vec4 constants", "[vec4]") {

	REQUIRE(vmath::vec4::zero.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::zero.y == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::zero.z == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::zero.w == Approx(0).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec4::one.x == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::one.y == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::one.z == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::one.w == Approx(1).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::vec4::unit_w.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::unit_w.y == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::unit_w.z == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::vec4::unit_w.w == Approx(1).epsilon(vmath::zero_tolerance));

}

TEST_CASE("vec4 operators", "[vec4]") {

	SECTION("equality/inequality") {
		auto v1 = vmath::vec4();
		auto v2 = vmath::vec4();
		auto v3 = vmath::vec4(1);

		REQUIRE(v1 == v2);
		REQUIRE(v1 != v3);
		REQUIRE(v2 != v3);
	}

	SECTION("addition") {
		auto v1 = vmath::vec4();
		auto v2 = vmath::vec4(1);

		REQUIRE(v1 + v2 == v2 + v1);
		REQUIRE(v1 + v1 == v1);
		REQUIRE(v1 + 1 == v2);
		REQUIRE(1 + v1 == v2);
	}

	SECTION("negation") {
		auto v1 = vmath::vec4();
		auto v2 = vmath::vec4(1);

		REQUIRE(v1 == -v1);
		REQUIRE(v2 == -(-v2));
		REQUIRE(v2 == v2 + (-v1));
		REQUIRE(-v2 == vmath::vec4(-1));
	}

	SECTION("substraction") {
		auto v1 = vmath::vec4();
		auto v2 = vmath::vec4(1);
		auto v3 = vmath::vec4(1, 2, 0, 0);

		REQUIRE(v1 - v1 == v1);
		REQUIRE(v1 - v2 == -v2);
		REQUIRE(v2 - v3 == vmath::vec4(0, -1, 1, 1));
	}

	SECTION("multiplication") {
		auto v1 = vmath::vec4();
		auto v2 = vmath::vec4(1);
		auto v3 = vmath::vec4(2);

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
		auto v1 = vmath::vec4();
		auto v2 = vmath::vec4(1);
		auto v3 = vmath::vec4(2);

		REQUIRE(v1 / 1 == v1);
		REQUIRE(v2 / 1 == v2);
		REQUIRE(v2 / v2 == vmath::vec4::one);
		REQUIRE(v2 * 2 == v3);
	}

	SECTION("element access") {
		auto v = vmath::vec4(1, 2, 3, 4);

		REQUIRE(v[0] == v.x);
		REQUIRE(v[1] == v.y);
		REQUIRE(v[2] == v.z);
		REQUIRE(v[3] == v.w);
	}

}

TEST_CASE("vec4 mathematics", "[vec4]") {

	SECTION("homogenization") {
		auto v = vmath::vec4(3, 3, 3, 3);
		auto vh = v.homogenized();

		REQUIRE(vh == vmath::vec4(1));
	}

}
