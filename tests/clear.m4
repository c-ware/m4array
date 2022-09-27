/*
 * Test clearing the contents of an array.
*/

#include "common.h"

include(template/common.m4)

int main() {
    struct IntArray *array = M4ARRAY_INIT(array, INT_ARRAY);

    M4ARRAY_APPEND(array, 0, INT_ARRAY);    
    M4ARRAY_APPEND(array, 1, INT_ARRAY);    
    M4ARRAY_APPEND(array, 2, INT_ARRAY);    
    M4ARRAY_APPEND(array, 3, INT_ARRAY);    
    M4ARRAY_APPEND(array, 4, INT_ARRAY);    

    M4ARRAY_CLEAR(array, INT_ARRAY);
    ASSERT_NUMEQ(array->length, 0);

    M4ARRAY_APPEND(array, 0, INT_ARRAY);    
    M4ARRAY_APPEND(array, 1, INT_ARRAY);    
    M4ARRAY_APPEND(array, 2, INT_ARRAY);    

    ASSERT_NUMEQ(array->length, 3);

	M4ARRAY_FREE(array, INT_ARRAY);

	return 0;
}
