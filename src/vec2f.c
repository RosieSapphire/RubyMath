#include "rmath/vec2f.h"

#include <math.h>

void rm_vec2f_scale(rm_vec2f x, float s)
{
	x[0] *= s;
	x[1] *= s;
}

void rm_vec2f_negate(rm_vec2f x)
{
	rm_vec2f_scale(x, -1.0f);
}

void rm_vec2f_add(rm_vec2f a, rm_vec2f b, rm_vec2f out)
{
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
}

void rm_vec2f_sub(rm_vec2f a, rm_vec2f b, rm_vec2f out)
{
	rm_vec2f_negate(b);
	rm_vec2f_add(a, b, out);
}

void rm_vec2f_lerp(rm_vec2f a, rm_vec2f b, float t, rm_vec2f out)
{
	rm_vec2f diff;

	rm_vec2f_sub(b, a, diff);
	rm_vec2f_scale(diff, t);
	rm_vec2f_add(a, diff, out);
}

void rm_vec2f_lerp_01(rm_vec2f a, rm_vec2f b, float t, rm_vec2f out)
{
	rm_vec2f_lerp(a, b, rm_clampf_01(t), out);
}

float rm_vec2f_dot(rm_vec2f a, rm_vec2f b)
{
	return a[0] * b[0] + a[1] * b[1];
}

float rm_vec2f_magnitude(rm_vec2f x)
{
	return sqrtf(rm_vec2f_dot(x, x));
}

void rm_vec2f_normalize(rm_vec2f x)
{
	rm_vec2f_scale(x, 1.0f / rm_vec2f_magnitude(x));
}
