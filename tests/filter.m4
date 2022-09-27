/*
 * Test filtering an array based on a predicate.
*/

#include "common.h"

include(template/common.m4)

int main() {
	struct IntArray *array = M4ARRAY_INIT(array, INT_ARRAY);

    M4ARRAY_APPEND(array, 1, INT_ARRAY);
    M4ARRAY_APPEND(array, 2, INT_ARRAY);
    M4ARRAY_APPEND(array, 3, INT_ARRAY);
    M4ARRAY_APPEND(array, 4, INT_ARRAY);

    /* Filter all elements that are not divisible by two */
    M4ARRAY_FILTER(array, `($1 % 2) == 0', INT_ARRAY);
    ASSERT_NUMEQ(array->length, 2);
    ASSERT_NUMEQ(array->contents[0], 2);
    ASSERT_NUMEQ(array->contents[1], 4);

    /* Add some more to filter further */
    M4ARRAY_APPEND(array, 5, INT_ARRAY);
    M4ARRAY_APPEND(array, 6, INT_ARRAY);
    M4ARRAY_APPEND(array, 7, INT_ARRAY);
    M4ARRAY_APPEND(array, 8, INT_ARRAY);

    /* Filter all elements that are not divisible by two */
    M4ARRAY_FILTER(array, `($1 % 2) == 0', INT_ARRAY);
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->contents[0], 2);
    ASSERT_NUMEQ(array->contents[1], 4);
    ASSERT_NUMEQ(array->contents[2], 6);
    ASSERT_NUMEQ(array->contents[3], 8);

	M4ARRAY_FREE(array, INT_ARRAY);

	return 0;
}
