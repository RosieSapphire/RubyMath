#ifndef RUBY_MATH_VEC2F_H
#define RUBY_MATH_VEC2F_H

#include "rmath/helpers.h"

typedef float rm_vec2f[2];

#define RM_VEC2F_ZERO ((rm_vec2f){0, 0})
#define RM_VEC2F_ONE  ((rm_vec2f){1, 1})
#define RM_VEC2F_X    ((rm_vec2f){1, 0})
#define RM_VEC2F_Y    ((rm_vec2f){0, 1})

void rm_vec2f_scale(rm_vec2f x, float s);
void rm_vec2f_negate(rm_vec2f x);
void rm_vec2f_add(rm_vec2f a, rm_vec2f b, rm_vec2f out);
void rm_vec2f_sub(rm_vec2f a, rm_vec2f b, rm_vec2f out);
void rm_vec2f_lerp(rm_vec2f a, rm_vec2f b, float t, rm_vec2f out);
void rm_vec2f_lerp_01(rm_vec2f a, rm_vec2f b, float t, rm_vec2f out);
float rm_vec2f_dot(rm_vec2f a, rm_vec2f b);
float rm_vec2f_magnitude(rm_vec2f x);
void rm_vec2f_normalize(rm_vec2f x);

#endif
