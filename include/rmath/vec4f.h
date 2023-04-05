#ifndef RMATH_VEC4F_H
#define RMATH_VEC4F_H

#include "rmath/helpers.h"

typedef float rm_vec4f[4];

#define RM_VEC4F_ZERO ((rm_vec4f){0, 0, 0, 0})
#define RM_VEC4F_1    ((rm_vec4f){1, 1, 1, 1})
#define RM_VEC4F_X    ((rm_vec4f){1, 0, 0, 0})
#define RM_VEC4F_Y    ((rm_vec4f){0, 1, 0, 0})
#define RM_VEC4F_Z    ((rm_vec4f){0, 0, 1, 0})
#define RM_VEC4F_W    ((rm_vec4f){0, 0, 0, 1})

void rm_vec4f_copy(rm_vec4f from, rm_vec4f to);
void rm_vec4f_add(rm_vec4f a, rm_vec4f b, rm_vec4f out);
void rm_vec4f_sub(rm_vec4f a, rm_vec4f b, rm_vec4f out);
void rm_vec4f_scale(rm_vec4f x, float s);
void rm_vec4f_negate(rm_vec4f x);
void rm_vec4f_lerp(rm_vec4f a, rm_vec4f b, float t, rm_vec4f out);
void rm_vec4f_lerp_01(rm_vec4f a, rm_vec4f b, float t, rm_vec4f out);
float rm_vec4f_dot(rm_vec4f a, rm_vec4f b);
float rm_vec4f_magnitude(rm_vec4f x);
void rm_vec4f_normalize(rm_vec4f x);

#endif
