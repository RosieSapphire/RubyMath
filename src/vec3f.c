#include "rmath/vec3f.h"

#include <math.h>

void rm_vec3f_scale(rm_vec3f x, float s)
{
	x[0] *= s;
	x[1] *= s;
	x[2] *= s;
}

void rm_vec3f_negate(rm_vec3f x)
{
	rm_vec3f_scale(x, -1.0f);
}

void rm_vec3f_add(rm_vec3f a, rm_vec3f b, rm_vec3f out)
{
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
	out[2] = a[2] + b[2];
}

void rm_vec3f_sub(rm_vec3f a, rm_vec3f b, rm_vec3f out)
{
	rm_vec3f_negate(b);
	rm_vec3f_add(a, b, out);
}

void rm_vec3f_lerp(rm_vec3f a, rm_vec3f b, float t, rm_vec3f out)
{
	rm_vec3f diff;

	rm_vec3f_sub(b, a, diff);
	rm_vec3f_scale(diff, t);
	rm_vec3f_add(a, diff, out);
}

void rm_vec3f_lerp_01(rm_vec3f a, rm_vec3f b, float t, rm_vec3f out)
{
	rm_vec3f_lerp(a, b, rm_clampf_01(t), out);
}

float rm_vec3f_dot(rm_vec3f a, rm_vec3f b)
{
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void rm_vec3f_cross(rm_vec3f a, rm_vec3f b, rm_vec3f out)
{
	out[0] = a[1] * b[2] - a[2] * b[1];
	out[1] = a[2] * b[0] - a[0] * b[2];
	out[2] = a[0] * b[1] - a[1] * b[0];
}

float rm_vec3f_magnitude(rm_vec3f x)
{
	return sqrtf(rm_vec3f_dot(x, x));
}

void rm_vec3f_normalize(rm_vec3f x)
{
	rm_vec3f_scale(x, 1.0f / rm_vec3f_magnitude(x));
}
