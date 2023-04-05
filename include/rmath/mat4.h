#ifndef RM_MAT4_H
#define RM_MAT4_H

#include "rmath/vec4f.h"
#include "rmath/vec3f.h"

typedef float rm_mat4[4][4];

#define RM_MAT4_ZERO_INIT {{0, 0, 0, 0}, \
	                   {0, 0, 0, 0}, \
	                   {0, 0, 0, 0}, \
	                   {0, 0, 0, 0}}

#define RM_MAT4_IDENTITY_INIT {{1, 0, 0, 0}, \
			       {0, 1, 0, 0}, \
			       {0, 0, 1, 0}, \
			       {0, 0, 0, 1}}

#define RM_MAT4_ZERO ((rm_mat4)RM_MAT4_ZERO_INIT)
#define RM_MAT4_IDENTITY ((rm_mat4)RM_MAT4_IDENTITY_INIT)

void rm_mat4_zero(rm_mat4 x);
void rm_mat4_identity(rm_mat4 x);
void rm_mat4_copy(rm_mat4 from, rm_mat4 to);
void rm_mat4_perspective(float fog_deg, float aspect, float near,
		float far, rm_mat4 out);
void rm_mat4_orthographic(float l, float r, float t, float b, rm_mat4 out);
void rm_mat4_translate(rm_mat4 mat, rm_vec3f vec);
void rm_mat4_scale(rm_mat4 mat, rm_vec3f vec);
void rm_mat4_scale_uni(rm_mat4 mat, float s);
void rm_mat4_rotate(rm_mat4 mat, rm_vec3f axis, float angle_rad);
void rm_mat4_rotate_x(rm_mat4 mat, float angle_rad);
void rm_mat4_rotate_y(rm_mat4 mat, float angle_rad);
void rm_mat4_rotate_z(rm_mat4 mat, float angle_rad);
void rm_mat4_multiply(rm_mat4 a, rm_mat4 b, rm_mat4 out);
void rm_mat4_from_quaternion(rm_vec4f quat, rm_mat4 out);
void rm_mat4_look_at(rm_vec3f eye, rm_vec3f focus, rm_mat4 out);
void rm_mat4_print(rm_mat4 m);

#endif
