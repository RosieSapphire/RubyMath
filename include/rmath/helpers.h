#ifndef RUBY_MATH_HELPERS_H
#define RUBY_MATH_HELPERS_H

#include <stdint.h>

#define RM_EPSILON 0.0001f
#define RM_PI      3.141592653589f
#define RM_PI_INV  0.3183098861838710434f

#define RM_TO_DEG  57.29577951309678781159f
#define RM_TO_RAD  0.01745329251993888889f

float rm_clampf(float val, float min, float max);
float rm_clampf_01(float val);
float rm_modf(float val, float mod);
float rm_lerp(float a, float b, float t);
float rm_lerp_01(float a, float b, float t);

#endif
