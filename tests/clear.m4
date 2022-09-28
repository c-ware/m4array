/*
 * Test clearing the contents of an array.
*/

#include "common.h"

include(template/common.m4)

int main() {
    struct IntArray *array = CWUTILS_NULL;
	struct StringArray *str_array = CWUTILS_NULL;

	char *string_1 = (CWUTILS_GENERIC) malloc(4);
	char *string_2 = (CWUTILS_GENERIC) malloc(4);
	char *string_3 = (CWUTILS_GENERIC) malloc(4);
	char *string_4 = (CWUTILS_GENERIC) malloc(4);

    array = M4ARRAY_INIT(array, INT_ARRAY);
    str_array = M4ARRAY_INIT(str_array, STRING_ARRAY);

	/* Fill up the input strings */
	string_1[0] = 'f';
	string_1[1] = 'o';
	string_1[2] = 'o';
	string_1[3] = '\0';

	string_2[0] = 'b';
	string_2[1] = 'a';
	string_2[2] = 'r';
	string_2[3] = '\0';

	string_3[0] = 'b';
	string_3[1] = 'a';
	string_3[2] = 'z';
	string_3[3] = '\0';

	string_4[0] = 'q';
	string_4[1] = 'u';
	string_4[2] = 'z';
	string_4[3] = '\0';

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

    /* Now that we've got basic clearing tests done, how about we
       test this with memory reuse? Let's start by loading the string
       array  */
    M4ARRAY_APPEND(str_array, string_1, STRING_ARRAY_RE);
    M4ARRAY_APPEND(str_array, string_2, STRING_ARRAY_RE);
    M4ARRAY_APPEND(str_array, string_3, STRING_ARRAY_RE);
    M4ARRAY_APPEND(str_array, string_4, STRING_ARRAY_RE);

    /* Now, let's clear the array and see if we can replace the
       contents of the array without using more memory. */
    ASSERT_NUMEQ(str_array->used, 4);

    M4ARRAY_CLEAR(str_array, STRING_ARRAY_RE);
    ASSERT_NUMEQ(str_array->length, 4);
    ASSERT_NUMEQ(str_array->used, 0);

    /* Let's try refilling now, shall we? */
    M4ARRAY_APPEND(str_array, "foo", STRING_ARRAY_RE);
    M4ARRAY_APPEND(str_array, "bar", STRING_ARRAY_RE);
    ASSERT_NUMEQ(str_array->length, 4);
    ASSERT_NUMEQ(str_array->used, 2);
    ASSERT_STREQ(str_array->contents[0], "foo");
    ASSERT_STREQ(str_array->contents[1], "bar");

	M4ARRAY_FREE(array, INT_ARRAY);
	M4ARRAY_FREE(str_array, STRING_ARRAY);

	return 0;
}
