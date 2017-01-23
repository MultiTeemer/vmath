#define _USE_MATH_DEFINES
#include <cmath>

#include "catch.h"
#include "vmath.h"

TEST_CASE("angle conversions", "[utils]") {

	auto deg = 180;
	auto rad = M_PI;

	REQUIRE(vmath::deg_to_rad(deg) == Approx(rad).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::rad_to_deg(rad) == Approx(deg).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::deg_to_rad(vmath::rad_to_deg(rad)) == Approx(rad).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::rad_to_deg(vmath::deg_to_rad(deg)) == Approx(deg).epsilon(vmath::zero_tolerance));

	REQUIRE(vmath::deg_to_rad(60) == Approx(rad / 3).epsilon(vmath::zero_tolerance));
	REQUIRE(vmath::rad_to_deg(rad * 2) == Approx(360).epsilon(vmath::zero_tolerance));

}