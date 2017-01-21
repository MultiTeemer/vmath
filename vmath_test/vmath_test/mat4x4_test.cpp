#include "catch.h"
#include "vmath.h"

TEST_CASE("mat4x4 creation", "[mat4x4]") {

	SECTION("parameterless") {
		auto m = vmath::mat4x4();

		REQUIRE(m[0][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][2] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][3] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][2] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][3] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][1] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][2] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][3] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][0] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][1] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][2] == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][3] == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("one arg") {

		SECTION("scalar") {
			auto m = vmath::mat4x4(1);

			REQUIRE(m[0][0] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][1] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][2] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][3] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][0] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][1] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][2] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][3] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][0] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][1] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][2] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][3] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[3][0] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[3][1] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[3][2] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[3][3] == Approx(1).epsilon(vmath::zero_tolerance));
		}

		SECTION("raw data") {
			float data[16] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1  };

			auto m = vmath::mat4x4(data);
			REQUIRE(m[0][0] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][1] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][2] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[0][3] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][0] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][1] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][2] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[1][3] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][0] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][1] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][2] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[2][3] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[3][0] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[3][1] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[3][2] == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(m[3][3] == Approx(1).epsilon(vmath::zero_tolerance));
		}

	}

	SECTION("per-column initialization") {
		auto c1 = vmath::vec4(1, 2, 3, 4);
		auto c2 = vmath::vec4(5, 6, 7, 8);
		auto c3 = vmath::vec4(9, 10, 11, 12);
		auto c4 = vmath::vec4(13, 14, 15, 16);

		auto m = vmath::mat4x4(c1, c2, c3, c4);
		REQUIRE(m[0][0] == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][2] == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][3] == Approx(4).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(5).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(6).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][2] == Approx(7).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][3] == Approx(8).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][0] == Approx(9).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][1] == Approx(10).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][2] == Approx(11).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][3] == Approx(12).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][0] == Approx(13).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][1] == Approx(14).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][2] == Approx(15).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][3] == Approx(16).epsilon(vmath::zero_tolerance));
	}

	SECTION("full initialization") {
		auto m = vmath::mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

		REQUIRE(m[0][0] == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][2] == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][3] == Approx(4).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(5).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(6).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][2] == Approx(7).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][3] == Approx(8).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][0] == Approx(9).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][1] == Approx(10).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][2] == Approx(11).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][3] == Approx(12).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][0] == Approx(13).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][1] == Approx(14).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][2] == Approx(15).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][3] == Approx(16).epsilon(vmath::zero_tolerance));
	}

}

TEST_CASE("mat4x4 element access", "[mat4x4]") {
	
	SECTION("reading") {
		auto m = vmath::mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
	
		REQUIRE(m[0][0] == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][2] == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][3] == Approx(4).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(5).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(6).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][2] == Approx(7).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][3] == Approx(8).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][0] == Approx(9).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][1] == Approx(10).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][2] == Approx(11).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][3] == Approx(12).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][0] == Approx(13).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][1] == Approx(14).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][2] == Approx(15).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][3] == Approx(16).epsilon(vmath::zero_tolerance));
	}

	SECTION("writing") {
		auto m = vmath::mat4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

		m[0][0] = 16;
		m[0][1] = 15;
		m[0][2] = 14;
		m[0][3] = 13;
		m[1][0] = 12;
		m[1][1] = 11;
		m[1][2] = 10;
		m[1][3] = 9;
		m[2][0] = 8;
		m[2][1] = 7;
		m[2][2] = 6;
		m[2][3] = 5;
		m[3][0] = 4;
		m[3][1] = 3;
		m[3][2] = 2;
		m[3][3] = 1;

		REQUIRE(m[0][0] == Approx(16).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][1] == Approx(15).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][2] == Approx(14).epsilon(vmath::zero_tolerance));
		REQUIRE(m[0][3] == Approx(13).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][0] == Approx(12).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][1] == Approx(11).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][2] == Approx(10).epsilon(vmath::zero_tolerance));
		REQUIRE(m[1][3] == Approx(9).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][0] == Approx(8).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][1] == Approx(7).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][2] == Approx(6).epsilon(vmath::zero_tolerance));
		REQUIRE(m[2][3] == Approx(5).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][0] == Approx(4).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][1] == Approx(3).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][2] == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(m[3][3] == Approx(1).epsilon(vmath::zero_tolerance));
	}

}

TEST_CASE("mat4x4 constants", "[mat4x4]") {

	REQUIRE(vmath::mat4x4::elements_count == 16);

	auto m = vmath::mat4x4::identity;

	REQUIRE(m[0][0] == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(m[0][1] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[0][2] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[0][3] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[1][0] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[1][1] == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(m[1][2] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[1][3] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[2][0] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[2][1] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[2][2] == Approx(1).epsilon(vmath::zero_tolerance));
	REQUIRE(m[2][3] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[3][0] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[3][1] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[3][2] == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(m[3][3] == Approx(1).epsilon(vmath::zero_tolerance));
}

TEST_CASE("mat4x4 operators", "[mat4x4]") {

	SECTION("==/!=") {
		auto m1 = vmath::mat4x4(1);
		auto m2 = vmath::mat4x4(1);
		auto m3 = vmath::mat4x4(2);

		REQUIRE(m1 == m2);
		REQUIRE(m1 != m3);
		REQUIRE(m2 != m3);
	}

	SECTION("+") {
		auto m1 = vmath::mat4x4(1);
		auto m2 = vmath::mat4x4(1);
		auto m3 = vmath::mat4x4();
		auto m4 = vmath::mat4x4(-1);
		auto m5 = vmath::mat4x4(2);

		REQUIRE(m1 + m2 == m2 + m1);
		REQUIRE((m1 + m4) + m5 == m1 + (m4 + m5));
		REQUIRE(m1 + m2 == m5);
		REQUIRE(m1 + m1 == m5);
		REQUIRE(m1 + m4 == m3);
		REQUIRE(m1 + m2 + m4 == m1);
	}

	SECTION("+=") {
		auto m1 = vmath::mat4x4();
		auto m2 = vmath::mat4x4(1);

		REQUIRE((m1 += m2) == m2);
	}

	SECTION("-") {
		auto m1 = vmath::mat4x4(1);
		auto m2 = vmath::mat4x4(1);
		auto m3 = vmath::mat4x4();
		auto m4 = vmath::mat4x4(2);

		REQUIRE(m1 - m2 == m3);
		REQUIRE(m1 - m4 == -(m4 - m1));
		REQUIRE(m1 == -(-m1));
		REQUIRE(m4 - m1 - m2 == m3);
		REQUIRE(m3 - m3 == m3);
	}

	SECTION("-=") {
		auto m1 = vmath::mat4x4(1);
		auto m2 = vmath::mat4x4(1);
		auto m3 = vmath::mat4x4();

		REQUIRE((m1 -= m2) == m3);
	}

	SECTION("*") {

		SECTION("by scalar") {
			auto m = vmath::mat4x4(1);

			REQUIRE(m * 2 == 2 * m);
			REQUIRE(m * 2 == vmath::mat4x4(2));
			REQUIRE(m * 1 == m);
			REQUIRE(2 * m * 3 == 6 * m);
		}

		SECTION("by mat4x4") {
			auto m = vmath::mat4x4(1);
			auto i = vmath::mat4x4::identity;
			auto o33 = vmath::mat4x4(
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 1
			);

			REQUIRE(m * i == m);
			REQUIRE(m * i == i * m);
			REQUIRE(m * m == vmath::mat4x4(4));
			REQUIRE((m * o33)[3][3] == 1);
		}

	}

	SECTION("*=") {

		SECTION("by scalar") {
			auto m = vmath::mat4x4(1);

			REQUIRE((m *= 1) == m);
			REQUIRE((m *= 2) == vmath::mat4x4(2));
			REQUIRE((m *= 1 / 2.0) == vmath::mat4x4(1));
		}

		SECTION("by mat4x4") {
			auto m = vmath::mat4x4(1);
			auto o33 = vmath::mat4x4(
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 0,
				0, 0, 0, 1
			);

			REQUIRE((m *= m) == vmath::mat4x4(4));
			REQUIRE((m *= o33)[3][3] == 4);
		}

	}

}