#ifndef RUBY_MATH_VEC3F_H
#define RUBY_MATH_VEC3F_H

#include "rmath/helpers.h"

typedef float rm_vec3f[3];

#define RM_VEC3F_ZERO ((rm_vec3f){0, 0, 0})
#define RM_VEC3F_ONE  ((rm_vec3f){1, 1, 1})
#define RM_VEC3F_X    ((rm_vec3f){1, 0, 0})
#define RM_VEC3F_Y    ((rm_vec3f){0, 1, 0})
#define RM_VEC3F_Z    ((rm_vec3f){0, 0, 1})

void rm_vec3f_scale(rm_vec3f x, float s);
void rm_vec3f_negate(rm_vec3f x);
void rm_vec3f_add(rm_vec3f a, rm_vec3f b, rm_vec3f out);
void rm_vec3f_sub(rm_vec3f a, rm_vec3f b, rm_vec3f out);
void rm_vec3f_lerp(rm_vec3f a, rm_vec3f b, float t, rm_vec3f out);
void rm_vec3f_lerp_01(rm_vec3f a, rm_vec3f b, float t, rm_vec3f out);
float rm_vec3f_dot(rm_vec3f a, rm_vec3f b);
void rm_vec3f_cross(rm_vec3f a, rm_vec3f b, rm_vec3f out);
float rm_vec3f_magnitude(rm_vec3f x);
void rm_vec3f_normalize(rm_vec3f x);

#endif
