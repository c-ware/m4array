/*
 * Test releasing the array
*/

#include "common.h"

include(template/common.m4)

int main() {
	struct StringArray *my_array = 0;

	my_array = M4ARRAY_INIT(my_array, STRING_ARRAY);	

    M4ARRAY_FREE(my_array, STRING_ARRAY);

	return 0;
}
