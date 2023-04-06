#include <unistd.h>
#include "rmath/mat4.h"

int main()
{
	rm_mat4 a = RM_MAT4_IDENTITY_INIT;

	while(1) {
		usleep(500000);
		rm_mat4_print(a);
		rm_mat4_translate_x(a, 0.1f);
		rm_mat4_translate_y(a, 0.1f);
		rm_mat4_translate_z(a, 0.1f);
	}

	return 0;
}
