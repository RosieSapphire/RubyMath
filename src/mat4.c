#include "rmath/mat4.h"
#include "rmath/quat.h"
#include "rmath/helpers.h"

#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

void rm_mat4_zero(rm_mat4 x)
{
	memset(x, 0, sizeof(rm_mat4));
}

void rm_mat4_identity(rm_mat4 x)
{
	rm_mat4 id = RM_MAT4_IDENTITY_INIT;

	memcpy(x, id, sizeof(rm_mat4));
}

void rm_mat4_copy(rm_mat4 from, rm_mat4 to)
{
	memcpy(to, from, sizeof(float) * 16);
}

void rm_mat4_perspective(float fog_deg, float aspect, float near,
		float far, rm_mat4 out)
{
	float fovItan = 1.0f / tanf(fog_deg * RM_TO_RAD * 0.5f);
	float zRange = 1.0f / (near - far);

	rm_mat4_zero(out);
	out[0][0] = fovItan / aspect;
	out[1][1] = fovItan;
	out[2][2] = (near + far) * zRange;
	out[2][3] = -1.0f;
	out[3][2] = 2.0f * near * far * zRange;
}

void rm_mat4_orthographic(float l, float r, float t, float b, rm_mat4 out)
{
	float rl = 1 / (r - l);
	float tb = 1 / (t - b);

	rm_mat4_zero(out);
	out[0][0] = 2 * rl;
	out[1][1] = 2 * tb;
	out[2][2] = -1;
	out[3][0] = -(r + l) * rl;
	out[3][1] = -(t + b) * tb;
	out[3][2] = 0;
	out[3][3] = 1;
}

void rm_mat4_translate(rm_mat4 mat, rm_vec3f vec)
{
	rm_vec3f_add(mat[3], vec, mat[3]);
}

void rm_mat4_translate_x(rm_mat4 mat, float move)
{
	rm_mat4_translate(mat, (rm_vec3f){move, 0, 0});
}

void rm_mat4_translate_y(rm_mat4 mat, float move)
{
	rm_mat4_translate(mat, (rm_vec3f){0, move, 0});
}

void rm_mat4_translate_z(rm_mat4 mat, float move)
{
	rm_mat4_translate(mat, (rm_vec3f){0, 0, move});
}

void rm_mat4_scale(rm_mat4 mat, rm_vec3f vec)
{
	mat[0][0] *= vec[0];
	mat[1][1] *= vec[1];
	mat[2][2] *= vec[2];
}

void rm_mat4_scale_uni(rm_mat4 mat, float s)
{
	rm_vec3f vec = {s, s, s};

	rm_mat4_scale(mat, vec);
}

void rm_mat4_rotate(rm_mat4 mat, rm_vec3f axis, float angle_rad)
{
	rm_mat4 rot = RM_MAT4_ZERO_INIT;
	const float angle_sin = sinf(angle_rad);
	const float angle_cos = cosf(angle_rad);

	rot[0][0] = angle_cos + (axis[0] * axis[0]) * (1 - angle_cos);
	rot[1][0] = axis[0] * axis[1] * (1 - angle_cos) - axis[2] * angle_sin;
	rot[2][0] = axis[0] * axis[2] * (1 - angle_cos) + axis[1] * angle_sin;

	rot[0][1] = axis[1] * axis[0] * (1 - angle_cos) + axis[2] * angle_sin;
	rot[1][1] = angle_cos + (axis[1] * axis[1]) * (1 - angle_cos);
	rot[2][1] = axis[1] * axis[2] * (1 - angle_cos) - axis[0] * angle_sin;

	rot[0][2] = axis[2] * axis[0] * (1 - angle_cos) - axis[1] * angle_sin;
	rot[1][2] = axis[2] * axis[1] * (1 - angle_cos) + axis[0] * angle_sin;
	rot[2][2] = angle_cos + (axis[2] * axis[2]) * (1 - angle_cos);

	rot[3][3] = 1.0f;

	rm_mat4_multiply(mat, rot, mat);
}

void rm_mat4_rotate_x(rm_mat4 mat, float angle_rad)
{
	rm_mat4_rotate(mat, RM_VEC3F_X, angle_rad);
}

void rm_mat4_rotate_y(rm_mat4 mat, float angle_rad)
{
	rm_mat4_rotate(mat, RM_VEC3F_Y, angle_rad);
}

void rm_mat4_rotate_z(rm_mat4 mat, float angle_rad)
{
	rm_mat4_rotate(mat, RM_VEC3F_Z, angle_rad);
}

void rm_mat4_multiply(rm_mat4 a, rm_mat4 b, rm_mat4 out)
{
	rm_mat4 a_tmp;

	rm_mat4_copy(a, a_tmp);
	rm_mat4_zero(out);

	for(int row = 0; row < 4; row++) {
		for(int col = 0; col < 4; col++) {
			for(int ind = 0; ind < 4; ind++) {
				out[col][row] += a_tmp[ind][row] * b[col][ind];
			}
		}
	}
}

void rm_mat4_from_quaternion(rm_vec4f quat, rm_mat4 out)
{
	float s = 0.0f;
	float norm = sqrtf(rm_vec4f_dot(quat, quat));

	if(norm > 0) {
 		s = (2.0f / norm);
	}

	out[0][0] = 1.0f - (s * quat[1] * quat[1]) - (s * quat[2] * quat[2]);
	out[0][1] = (s * quat[0] * quat[1]) + (s * quat[3] * quat[2]);
	out[0][2] = (s * quat[0] * quat[2]) - (s * quat[3] * quat[1]);
	out[0][3] = 0.0f;

	out[1][0] = (s * quat[0] * quat[1]) - (s * quat[3] * quat[2]);
	out[1][1] = 1.0f - (s * quat[0] * quat[0]) - (s * quat[2] * quat[2]);
	out[1][2] = (s * quat[1] * quat[2]) + (s * quat[3] * quat[0]);
	out[1][3] = 0.0f;

	out[1][0] = (s * quat[0] * quat[2]) + (s * quat[3] * quat[1]);
	out[1][1] = (s * quat[1] * quat[2]) - (s * quat[3] * quat[0]);
	out[1][2] = 1.0f - (s * quat[0] * quat[0]) - (s * quat[1] * quat[1]);
	out[1][3] = 0.0f;

	out[2][0] = 0.0f;
	out[2][1] = 0.0f;
	out[2][2] = 0.0f;
	out[2][3] = 1.0f;
}

void rm_mat4_look_at(rm_vec3f eye, rm_vec3f focus, rm_mat4 out)
{
	rm_vec3f f, s, u;

	rm_vec3f_sub(focus, eye, f);
	rm_vec3f_normalize(f);
	rm_vec3f_cross(RM_VEC3F_Y, f, s);
	rm_vec3f_normalize(s);
	rm_vec3f_cross(f, s, u);

	out[0][0] = s[0];
	out[0][1] = u[0];
	out[0][2] = f[0];
	out[0][3] = 0.0f;
                 
	out[1][0] = s[1];
	out[1][1] = u[1];
	out[1][2] = f[1];
	out[1][3] = 0.0f;
                 
	out[2][0] = s[2];
	out[2][1] = u[2];
	out[2][2] = f[2];
	out[2][3] = 0.0f;

	out[3][0] = -rm_vec3f_dot(s, eye);
	out[3][1] = -rm_vec3f_dot(u, eye);
	out[3][2] = -rm_vec3f_dot(f, eye);
	out[3][3] = 1.0f;
}

void rm_mat4_print(rm_mat4 m)
{
	for(uint8_t i = 0; i < 4; i++) {
		for(uint8_t j = 0; j < 4; j++) {
			printf("%.6f\t", m[j][i]);
		}

		printf("\n");
	}

	printf("\n");
}
