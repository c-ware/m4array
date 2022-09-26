/*
 * Test the foreach implementation of an array.
*/

#include "common.h"

include(template/common.m4)

int main() {
	struct StringArray *my_array = 0;
    char full_buffer[128 + 1];

    full_buffer[0] = '\0';

	my_array = M4ARRAY_INIT(my_array, STRING_ARRAY);	

    M4ARRAY_APPEND(my_array, "foo", STRING_ARRAY);
    M4ARRAY_APPEND(my_array, "bar", STRING_ARRAY);
    M4ARRAY_APPEND(my_array, "baz", STRING_ARRAY);

    M4ARRAY_FOREACH(my_array, `strcat(full_buffer, $1)');
    
    ASSERT_STREQ(full_buffer, "foobarbaz");

	return 0;
}
