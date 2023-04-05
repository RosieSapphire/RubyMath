#include <unistd.h>
#include "rmath/mat4.h"

int main()
{
	rm_mat4 a = RM_MAT4_IDENTITY_INIT;

	while(1) {
		usleep(500000);
		rm_mat4_print(a);
		rm_mat4_rotate_x(a, 0.001f);
		/*
		rm_mat4_translate(a,
				(rm_vec3f){0.0012486f, 0.0021259f, 0.0032189f});
				*/
	}

	return 0;
}
