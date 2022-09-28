/*
 * Test appending data to an array 
*/

#include "common.h"

include(template/common.m4)

int main() {
	struct StringArray *my_array = 0;
	char *string_1 = (CWUTILS_GENERIC) malloc(4);
	char *string_2 = (CWUTILS_GENERIC) malloc(4);
	char *string_3 = (CWUTILS_GENERIC) malloc(4);
	char *string_4 = (CWUTILS_GENERIC) malloc(4);

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


	my_array = M4ARRAY_INIT(my_array, STRING_ARRAY);	

	M4ARRAY_APPEND(my_array, string_1, STRING_ARRAY);
	ASSERT_NUMEQ(my_array->used, 1);
	ASSERT_NUMEQ(my_array->length, 1);
	ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[0], "foo");

	M4ARRAY_APPEND(my_array, string_2, STRING_ARRAY);
	ASSERT_NUMEQ(my_array->used, 2);
	ASSERT_NUMEQ(my_array->length, 2);
	ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH);
	ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[1], "bar");

	M4ARRAY_APPEND(my_array, string_3, STRING_ARRAY);
	ASSERT_NUMEQ(my_array->used, 3);
	ASSERT_NUMEQ(my_array->length, 3);
	ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH);
	ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[2], "baz");

	M4ARRAY_APPEND(my_array, string_4, STRING_ARRAY);
	ASSERT_NUMEQ(my_array->used, 4);
	ASSERT_NUMEQ(my_array->length, 4);
	ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH * 2);
	ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[3], "quz");

    /* Now that we've tested the basic appending functionality, what if
       we simulate the need to perform memory reuse? We will tell m4array
       that we have 4 total strings allocated, but only 3 are in use. */

    my_array->used--;
	M4ARRAY_APPEND(my_array, "foo", STRING_ARRAY_RE);
	ASSERT_NUMEQ(my_array->used, 4);
	ASSERT_NUMEQ(my_array->length, 4);
	ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH * 2);
	ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[0], "foo");
	ASSERT_STREQ(my_array->contents[1], "bar");
	ASSERT_STREQ(my_array->contents[2], "baz");
	ASSERT_STREQ(my_array->contents[3], "foo");

    /* What about two strings to refill? */
    my_array->used--;
    my_array->used--;

	M4ARRAY_APPEND(my_array, "spam", STRING_ARRAY_RE);
	ASSERT_NUMEQ(my_array->used, 3);
	ASSERT_NUMEQ(my_array->length, 4);

	M4ARRAY_APPEND(my_array, "thud", STRING_ARRAY_RE);
	ASSERT_NUMEQ(my_array->used, 4);
	ASSERT_NUMEQ(my_array->length, 4);

	ASSERT_STREQ(my_array->contents[0], "foo");
	ASSERT_STREQ(my_array->contents[1], "bar");
	ASSERT_STREQ(my_array->contents[2], "spam");
	ASSERT_STREQ(my_array->contents[3], "thud");

	M4ARRAY_FREE(my_array, STRING_ARRAY);

	return 0;
}
