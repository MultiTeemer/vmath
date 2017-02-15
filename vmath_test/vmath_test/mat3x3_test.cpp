#include "catch.h"
#include "vmath.h"

namespace Catch {
	std::string toString(vmath::mat3x3 const& value) {
		using std::to_string;

		auto c1 = value[0];
		auto c2 = value[1];
		auto c3 = value[2];

		return std::string("(\n")
			+ " (" + to_string(c1.x) + ", " + to_string(c1.y) + ", " + to_string(c1.z) + "),\n"
			+ " (" + to_string(c2.x) + ", " + to_string(c2.y) + ", " + to_string(c2.z) + "),\n"
			+ " (" + to_string(c3.x) + ", " + to_string(c3.y) + ", " + to_string(c3.z) + "),\n"
			+ ")\n";
	}
}

TEST_CASE("mat3x3 creation", "[mat3x3]") {

	SECTION("parameterless") {
		auto m = vmath::mat3x3();

		REQUIRE(m[0][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][2] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][2] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][1] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][2] == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("one arg") {

		SECTION("scalar") {
			const float d = 1;
			auto m = vmath::mat3x3(d);

			REQUIRE(m[0][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][1] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][2] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][1] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][2] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][1] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][2] == Approx(d).epsilon(vmath::zero_tolerance));
		}

		SECTION("mat3x3") {
			const float d = 1;
			auto m4x4 = vmath::mat4x4(d);
			vmath::mat3x3 m(m4x4);

			REQUIRE(m[0][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][1] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][2] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][1] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][2] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][1] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][2] == Approx(d).epsilon(vmath::zero_tolerance));
		}
	}

	SECTION("fully specified") {
		auto m = vmath::mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);

		REQUIRE(m[0][0] == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][2] == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(4).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(5).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][2] == Approx(6).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][0] == Approx(7).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][1] == Approx(8).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][2] == Approx(9).epsilon(vmath::zero_tolerance));
	}

}

TEST_CASE("mat3x3 mathematics", "[mat3x3]") {

	SECTION("determinant") {
		auto m = vmath::mat3x3(1, 2, 3, 4, 5, 6, 7, 8, 9);

		REQUIRE(m.det() == Approx(0).epsilon(vmath::zero_tolerance));
	}

}