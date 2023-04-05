#include "rmath/vec4f.h"

#include <math.h>

void rm_vec4f_copy(rm_vec4f from, rm_vec4f to)
{
	to[0] = from[0];
	to[1] = from[1];
	to[2] = from[2];
	to[3] = from[3];
}

void rm_vec4f_add(rm_vec4f a, rm_vec4f b, rm_vec4f out)
{
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
	out[2] = a[2] + b[2];
	out[3] = a[3] + b[3];
}

void rm_vec4f_sub(rm_vec4f a, rm_vec4f b, rm_vec4f out)
{
	out[0] = a[0] - b[0];
	out[1] = a[1] - b[1];
	out[2] = a[2] - b[2];
	out[3] = a[3] - b[3];
}

void rm_vec4f_scale(rm_vec4f x, float s)
{
	x[0] *= s;
	x[1] *= s;
	x[2] *= s;
	x[3] *= s;
}

void rm_vec4f_negate(rm_vec4f x)
{
	rm_vec4f_scale(x, -1.0f);
}

void rm_vec4f_lerp(rm_vec4f a, rm_vec4f b, float t, rm_vec4f out)
{
	rm_vec4f diff;

	rm_vec4f_sub(b, a, diff);
	rm_vec4f_scale(diff, t);
	rm_vec4f_add(a, diff, out);
}

void rm_vec4f_lerp_01(rm_vec4f a, rm_vec4f b, float t, rm_vec4f out)
{
	rm_vec4f_lerp(a, b, rm_clampf_01(t), out);
}

float rm_vec4f_dot(rm_vec4f a, rm_vec4f b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2] + a[3] * b[3];
}

float rm_vec4f_magnitude(rm_vec4f x)
{
	return sqrtf(rm_vec4f_dot(x, x));
}

void rm_vec4f_normalize(rm_vec4f x)
{
	rm_vec4f_scale(x, 1.0f / rm_vec4f_magnitude(x));
}
