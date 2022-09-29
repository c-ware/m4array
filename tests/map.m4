/*
 * Test mapping an operation to an array
*/

#include "common.h"

include(template/common.m4)

int main() {
	struct IntArray *array = M4ARRAY_INIT(array, INT_ARRAY);

    M4ARRAY_APPEND(array, 1, INT_ARRAY);
    M4ARRAY_APPEND(array, 2, INT_ARRAY);
    M4ARRAY_APPEND(array, 3, INT_ARRAY);
    M4ARRAY_APPEND(array, 4, INT_ARRAY);

    /* Square all numbers */
    M4ARRAY_MAP(array, `$1 * $1');

    ASSERT_NUMEQ(array->contents[0], 1);
    ASSERT_NUMEQ(array->contents[1], 4);
    ASSERT_NUMEQ(array->contents[2], 9);
    ASSERT_NUMEQ(array->contents[3], 16);

    /* Square an array with no numbers. Despite there technically
     * being no numbers, the map function should NOT change the
     * existing numbers, because that would imply it goes beyond
     * the length.
    */

    array->used = 0;
    M4ARRAY_MAP(array, `$1 * $1');
    ASSERT_NUMEQ(array->contents[0], 1);
    ASSERT_NUMEQ(array->contents[1], 4);
    ASSERT_NUMEQ(array->contents[2], 9);
    ASSERT_NUMEQ(array->contents[3], 16);

	M4ARRAY_FREE(array, INT_ARRAY);

	return 0;
}
