/*
 * Test initializing the array
*/

#include "common.h"

include(template/common.m4)

int main() {
	struct StringArray *my_array = 0;

	my_array = M4ARRAY_INIT(my_array, STRING_ARRAY);	

    ASSERT_NUMEQ(my_array->used, 0);
    ASSERT_NUMEQ(my_array->length, 0);
    ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);

	return 0;
}
