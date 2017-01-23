#include "utils.h"

#define _USE_MATH_DEFINES
#include <cmath>


namespace vmath {

	float_t deg_to_rad(float_t deg)
	{
		return deg * M_PI / 180.0f;
	}

	float_t rad_to_deg(float_t rad)
	{
		return rad * 180.0f / M_PI;
	}

}