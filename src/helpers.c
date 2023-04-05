#include "rmath/helpers.h"

#include <stdio.h>
#include <string.h>

float rm_clampf(float val, float min, float max)
{
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wstrict-aliasing"
	#pragma GCC diagnostic ignored "-Wuninitialized"

	float diff[2] = {min - val, val - max};
	uint8_t flagA = (*(uint32_t *)&diff[0] >> 31);
	uint8_t flagB = (*(uint32_t *)&diff[1] >> 31);
	uint8_t flagAnd = (flagA & flagB);
	#pragma GCC diagnostic pop
	return (float)((flagAnd * val) + ((1 - flagA) * min)
			+ ((1 - flagB) * max));
}

float rm_clampf_01(float val)
{
	return rm_clampf(val, 0.0f, 1.0f);
}

float rm_modf(float val, float mod)
{
	float val_scaled = val * (1.0f / mod);
	return (val_scaled - (float)((int32_t)val_scaled)) * mod;
}

float rm_lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

float rm_lerp_01(float a, float b, float t)
{
	return rm_lerp(a, b, rm_clampf_01(t));
}
