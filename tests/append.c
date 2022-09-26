/*
 * Test appending data to an array 
*/

#include "common.h"




#include <stdio.h>
#include <assert.h>
#include <string.h>


#if defined(__ULTRIX__) || defined(__QuasiBSD__)
#   if !defined(CWUTILS_GENERIC)
#       define CWUTILS_GENERIC char *
#   endif
#   if !defined(CWUTILS_NULL)
#       define CWUTILS_NULL    ((char *) 0)
#   endif
#else
#   if !defined(CWUTILS_GENERIC)
#      define CWUTILS_GENERIC void *
#   endif
#   if !defined(CWUTILS_NULL)
#      define CWUTILS_NULL    ((void *) 0)
#   endif
#endif




















struct StringArray {
	int length;
	int capacity;
	char **contents;
};






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


	my_array = 
	(struct StringArray *) malloc(sizeof(*(my_array)));
	(my_array)->length = 0;
	(my_array)->capacity = 3;
	(my_array)->contents = (char * *) malloc(sizeof(char *) * 3)
;	

	
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	(my_array)->contents[(my_array)->length] = (string_1);
	(my_array)->length++
;
	ASSERT_NUMEQ(my_array->length, 1);
	ASSERT_NUMEQ(my_array->capacity, 3);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[0], "foo");

	
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	(my_array)->contents[(my_array)->length] = (string_2);
	(my_array)->length++
;
	ASSERT_NUMEQ(my_array->length, 2);
	ASSERT_NUMEQ(my_array->capacity, 3);
	ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[1], "bar");

	
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	(my_array)->contents[(my_array)->length] = (string_3);
	(my_array)->length++
;
	ASSERT_NUMEQ(my_array->length, 3);
	ASSERT_NUMEQ(my_array->capacity, 3);
	ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[2], "baz");

	
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	(my_array)->contents[(my_array)->length] = (string_4);
	(my_array)->length++
;
	ASSERT_NUMEQ(my_array->length, 4);
	ASSERT_NUMEQ(my_array->capacity, 3 * 2);
	ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);
	ASSERT_STREQ(my_array->contents[3], "quz");

	
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->length) {
			free((my_array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((my_array)->contents);
		free((my_array));
	} while(0)
;

	return 0;
}
