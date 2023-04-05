#ifndef RUBY_MATH_QUATERNION_H
#define RUBY_MATH_QUATERNION_H

#include "rmath/vec4f.h"

void rm_quat_slerp(rm_vec4f a, rm_vec4f b, float t, rm_vec4f out);

#endif
