#ifndef RUBY_MATH_RAY_H
#define RUBY_MATH_RAY_H

#include <stdbool.h>
#include "rmath/vec3f.h"

bool ncx_ray_triangle(rm_vec3f eye, rm_vec3f dir,
		rm_vec3f *verts, float *distance);

#endif
