/*
 * Test finding data inthe array
*/

#include "common.h"

include(template/common.m4)

int main() {
    int index = 0;
	struct StringArray *my_array = 0;
	char *string_1 = (CWUTILS_GENERIC) malloc(4);
	char *string_2 = (CWUTILS_GENERIC) malloc(4);
	char *string_3 = (CWUTILS_GENERIC) malloc(4);
	char *string_4 = (CWUTILS_GENERIC) malloc(4);
	char *string_5 = (CWUTILS_GENERIC) malloc(4);

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

	string_5[0] = 'q';
	string_5[1] = 'a';
	string_5[2] = 'z';
	string_5[3] = '\0';


	my_array = M4ARRAY_INIT(my_array, STRING_ARRAY);	

	M4ARRAY_APPEND(my_array, string_1, STRING_ARRAY);
	M4ARRAY_APPEND(my_array, string_2, STRING_ARRAY);
	M4ARRAY_APPEND(my_array, string_3, STRING_ARRAY);
	M4ARRAY_APPEND(my_array, string_4, STRING_ARRAY);

    index = M4ARRAY_FIND(my_array, index, `strcmp($1, "qaz") == 0');
    ASSERT_NUMEQ(index, -1);

    index = M4ARRAY_FIND(my_array, index, `strcmp($1, "quz") == 0');
    ASSERT_NUMEQ(index, 3);

    index = M4ARRAY_FIND(my_array, index, `strcmp($1, "baz") == 0');
    ASSERT_NUMEQ(index, 2);

    index = M4ARRAY_FIND(my_array, index, `strcmp($1, "bar") == 0');
    ASSERT_NUMEQ(index, 1);

    index = M4ARRAY_FIND(my_array, index, `strcmp($1, "foo") == 0');
    ASSERT_NUMEQ(index, 0);

	M4ARRAY_FREE(my_array, STRING_ARRAY);

	return 0;
}
