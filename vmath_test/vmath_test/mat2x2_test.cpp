#include "catch.h"
#include "vmath.h"

namespace Catch {
	std::string toString(vmath::mat2x2 const& value) {
		using std::to_string;

		auto c1 = value[0];
		auto c2 = value[1];

		return std::string("(\n")
			+ " (" + to_string(c1.x) + ", " + to_string(c1.y) + "),\n"
			+ " (" + to_string(c2.x) + ", " + to_string(c2.y) + "),\n"
			+ ")\n";
	}
}

TEST_CASE("mat2x2 creation", "[mat2x2]") {

	SECTION("parameterless") {
		auto m = vmath::mat2x2();

		REQUIRE(m[0][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("one arg") {

		SECTION("scalar") {
			const float d = 1;
			auto m = vmath::mat2x2(d);

			REQUIRE(m[0][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][1] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][1] == Approx(d).epsilon(vmath::zero_tolerance));
		}

		SECTION("mat3x3") {
			const float d = 1;
			auto m3x3 = vmath::mat3x3(d);
			vmath::mat2x2 m(m3x3);

			REQUIRE(m[0][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][1] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][0] == Approx(d).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][1] == Approx(d).epsilon(vmath::zero_tolerance));
		}
	}

	SECTION("fully specified") {
		auto m = vmath::mat2x2(1, 2, 3, 4);

		REQUIRE(m[0][0] == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(4).epsilon(vmath::zero_tolerance));
	}

}

TEST_CASE("mat2x2 mathematics", "[mat2x2]") {

	SECTION("determinant") {
		auto m = vmath::mat2x2(2, 1, 2, 3);

		REQUIRE(m.det() == Approx(4).epsilon(vmath::zero_tolerance));
	}

}