#include "rmath/quat.h"
#include "rmath/helpers.h"

#include <math.h>

void rm_quat_slerp(rm_vec4f a, rm_vec4f b, float t, rm_vec4f out)
{
	float cos_angle = rm_vec4f_dot(a, b);

	t = rm_clampf_01(t);

	if(fabsf(cos_angle) >= 1.0f) {
		rm_vec4f_copy(a, out);
		return;
	}

	if(cos_angle < 0.0f) {
		rm_vec4f_negate(a);
		cos_angle *= -1;
	}

	float sin_angle = sqrtf(1.0f - cos_angle * cos_angle);
	float angle = acosf(cos_angle);

	if(fabsf(sin_angle) < RM_EPSILON) {
		rm_vec4f_lerp_01(a, b, t, out);
		return;
	}

	rm_vec4f_scale(a, sinf((1.0f - t) * angle));
	rm_vec4f_scale(b, sinf(t * angle));
	rm_vec4f_add(a, b, a);
	rm_vec4f_scale(a, 1.0f / sin_angle);
}
