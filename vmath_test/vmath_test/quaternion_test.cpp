#include "catch.h"
#include "vmath.h"

#include <string>

namespace Catch {
	std::string toString(vmath::quaternion const& value) {
		using std::to_string;
		return "("
			+ to_string(value.x)
			+ ", " + to_string(value.y)
			+ ", " + to_string(value.z)
			+ "," + to_string(value.w)
		+ ")";
	}
}

TEST_CASE("quaternion construction", "[quaternion]") {

	SECTION("parameterless") {
		auto q = vmath::quaternion();

		REQUIRE(q.x == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(q.y == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(q.z == Approx(0).epsilon(vmath::zero_tolerance));
		REQUIRE(q.w == Approx(0).epsilon(vmath::zero_tolerance));
	}

	SECTION("one value") {
		auto q = vmath::quaternion(1);

		REQUIRE(q.x == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(q.y == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(q.z == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(q.w == Approx(1).epsilon(vmath::zero_tolerance));
	}

	SECTION("fully specified") {
		
		SECTION("by four values") {
			auto q = vmath::quaternion(4, 1, 2, 3);

			REQUIRE(q.x == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(q.y == Approx(2).epsilon(vmath::zero_tolerance));
			REQUIRE(q.z == Approx(3).epsilon(vmath::zero_tolerance));
			REQUIRE(q.w == Approx(4).epsilon(vmath::zero_tolerance));
		}
		
		SECTION("by parts") {
			auto real = 4;
			auto imaginary = vmath::vec3(1, 2, 3);
			auto q = vmath::quaternion(real, imaginary);

			REQUIRE(q.x == Approx(1).epsilon(vmath::zero_tolerance));
			REQUIRE(q.y == Approx(2).epsilon(vmath::zero_tolerance));
			REQUIRE(q.z == Approx(3).epsilon(vmath::zero_tolerance));
			REQUIRE(q.w == Approx(4).epsilon(vmath::zero_tolerance));
		}

	}

}

TEST_CASE("quaternion constants", "[quaternion]") {

	auto q = vmath::quaternion::identity;
	
	REQUIRE(q.x == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(q.y == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(q.z == Approx(0).epsilon(vmath::zero_tolerance));
	REQUIRE(q.w == Approx(1).epsilon(vmath::zero_tolerance));

}

TEST_CASE("quaternion parts accessors", "[quaternion]") {

	auto real = 4.0f;
	auto imaginary = vmath::vec3(1, 2, 3);
	auto q = vmath::quaternion(real, imaginary);

	REQUIRE(q.real() == real);
	REQUIRE(q.imaginary() == imaginary);

}

TEST_CASE("quaternion operators", "[quaternion]") {

	SECTION("==/!=") {
		auto q1 = vmath::quaternion(1);
		auto q2 = vmath::quaternion(1);
		auto q3 = vmath::quaternion(2);

		REQUIRE(q1 == q1);
		REQUIRE(q1 == q2);
		REQUIRE(q2 == q1);
		REQUIRE(q1 != q3);
		REQUIRE(q2 != q3);
	}

	SECTION("+") {
		auto q1 = vmath::quaternion(1);
		auto q2 = vmath::quaternion(3);
		auto q3 = vmath::quaternion(4);

		REQUIRE(q1 + q2 == q3);
	}

	SECTION("+=") {
		auto q1 = vmath::quaternion(1);
		auto q2 = vmath::quaternion(3);
		auto q3 = vmath::quaternion(4);

		REQUIRE((q1 += q2) == q3);
		REQUIRE(q1 == q3);
	}

	SECTION("-") {
		auto q1 = vmath::quaternion(1);
		auto q2 = vmath::quaternion(3);
		auto q3 = vmath::quaternion(4);

		REQUIRE(q3 - q1 == q2);
	}

	SECTION("-=") {
		auto q1 = vmath::quaternion(1);
		auto q2 = vmath::quaternion(3);
		auto q3 = vmath::quaternion(4);

		REQUIRE((q3 -= q1) == q2);
		REQUIRE(q3 == q2);
	}

	SECTION("*") {
		auto q1 = vmath::quaternion(1);
		auto q2 = vmath::quaternion(2);

		SECTION("q1 by q2") {
			auto res = q1 * q2;

			REQUIRE(res.w == -4);
			REQUIRE(res.imaginary() == vmath::vec3(4));
		}

		SECTION("q1 squared") {
			auto res = q1 * q1;

			REQUIRE(res.w == -2);
			REQUIRE(res.imaginary() == vmath::vec3(2));
		}
	}

	SECTION("*=") {
		SECTION("q1 *= q2") {
			auto q1 = vmath::quaternion(1);
			auto q2 = vmath::quaternion(2);

			q1 *= q2;

			REQUIRE(q1.real() == -4);
			REQUIRE(q1.imaginary() == vmath::vec3(4));
		}

		SECTION("q1 *= q1") {
			auto q1 = vmath::quaternion(1);

			q1 *= q1;

			REQUIRE(q1.real() == -2);
			REQUIRE(q1.imaginary() == vmath::vec3(2));
		}
	}

}

TEST_CASE("quaternion math", "[quaternion]") {

	SECTION("conjugate") {
		auto q = vmath::quaternion(4, vmath::vec3(1, 2, 3));
		auto r = vmath::quaternion(1, 2, 3, 4);
		auto qc = q.conjugated();

		REQUIRE(qc.real() == q.real());
		REQUIRE(qc.imaginary() == -q.imaginary());
		REQUIRE(qc.conjugated() == q);
		REQUIRE((q + r).conjugated() == q.conjugated() + r.conjugated());
		REQUIRE((q * r).conjugated() == r.conjugated() * q.conjugated());
	}

	SECTION("magnitude") {
		auto q = vmath::quaternion(1);
		auto r = vmath::quaternion(1, 2, 3, 4);
		auto i = vmath::quaternion::identity;

		REQUIRE(q.magnitude() == Approx(2).epsilon(vmath::zero_tolerance));
		REQUIRE(i.magnitude() == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(q.magnitude() == Approx(q.conjugated().magnitude()).epsilon(vmath::zero_tolerance));
		REQUIRE((q * r).magnitude() == Approx(q.magnitude() * r.magnitude()).epsilon(vmath::zero_tolerance));
	}

	SECTION("multiplication linearity") {
		auto p = vmath::quaternion(1);
		auto q = vmath::quaternion(2);
		auto r = vmath::quaternion(3);
		auto s = 3.0f;
		auto t = 15.0f;

		REQUIRE(p * (s * q + t * r) == (s * p * q + t * p * r));
	}

	SECTION("multiplication associativity") {
		auto p = vmath::quaternion(1);
		auto q = vmath::quaternion(2);
		auto r = vmath::quaternion(3);

		REQUIRE(p * (q * r) == (p * q) * r);
	}

	SECTION("normalization") {
		auto p = vmath::quaternion(1);
		auto pn = p.normalized();

		REQUIRE(pn.magnitude() == Approx(1).epsilon(vmath::zero_tolerance));
		REQUIRE(pn.real() == Approx(0.5f).epsilon(vmath::zero_tolerance));
		REQUIRE(pn.imaginary() == vmath::vec3(0.5f));
	}

	SECTION("rotation") {
		auto alpha = vmath::deg_to_rad(45);
		auto v = vmath::vec3(1);
		auto q = vmath::quaternion::rotation(v, alpha);
		auto e = vmath::quaternion(cos(alpha / 2), sin(alpha / 2) * v.normalized()).normalized();

		REQUIRE(q == e);
	}

}