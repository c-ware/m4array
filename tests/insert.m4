/*
 * Test inserting data into the array
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

    /* Cannot insert into an empty array */
    M4ARRAY_APPEND(my_array, string_1, STRING_ARRAY);

    M4ARRAY_INSERT(my_array, string_2, 0, STRING_ARRAY);
    ASSERT_STREQ(my_array->contents[0], string_2);
    ASSERT_STREQ(my_array->contents[1], string_1);
    ASSERT_NUMEQ(my_array->length, 2);
    ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);

    M4ARRAY_INSERT(my_array, string_3, 0, STRING_ARRAY);
    ASSERT_STREQ(my_array->contents[0], string_3);
    ASSERT_STREQ(my_array->contents[1], string_2);
    ASSERT_STREQ(my_array->contents[2], string_1);
    ASSERT_NUMEQ(my_array->length, 3);
    ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);

    M4ARRAY_INSERT(my_array, string_4, 1, STRING_ARRAY);
    ASSERT_STREQ(my_array->contents[0], string_3);
    ASSERT_STREQ(my_array->contents[1], string_4);
    ASSERT_STREQ(my_array->contents[2], string_2);
    ASSERT_STREQ(my_array->contents[3], string_1);
    ASSERT_NUMEQ(my_array->length, 4);
    ASSERT_NUMEQ(my_array->capacity, M4ARRAY_INITIAL_LENGTH * 2);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);

	return 0;
}
