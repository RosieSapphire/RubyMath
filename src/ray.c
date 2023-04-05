#include "rmath/ray.h"

bool ncx_ray_triangle(rm_vec3f eye, rm_vec3f dir,
		rm_vec3f *verts, float *distance)
{
	rm_vec3f edge1, edge2, p, t, q;

	rm_vec3f_sub(verts[1], verts[0], edge1);
	rm_vec3f_sub(verts[2], verts[0], edge2);
	rm_vec3f_cross(dir, edge2, p);

	float det = rm_vec3f_dot(edge1, p);
	
	if(det > -RM_EPSILON && det < RM_EPSILON) {
		return 0;
	}
	
	float inv_det = 1.0f / det;

	rm_vec3f_sub(eye, verts[0], t);

	float u = inv_det * rm_vec3f_dot(t, p);

	if(u < 0.0f || u > 1.0f) {
		return 0;
	}
	
	rm_vec3f_cross(t, edge1, q);

	float v = inv_det * rm_vec3f_dot(dir, q);

	if (v < 0.0f || u + v > 1.0f) {
		return 0;
	}
	
	float dist = inv_det * rm_vec3f_dot(edge2, q);

	if(!distance)
		return dist > RM_EPSILON;

	*distance = dist;

	return dist > RM_EPSILON;
}
