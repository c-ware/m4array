/*
 * Test popping data from an array.
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





























    struct IntArray {
        int used;
        int length;
        int capacity;

        int *contents;
    }
;

    struct StringArray {
        int used;
        int length;
        int capacity;

        char * *contents;
    }
;





/* This array is used for testing memory reuse (hence
   the "RE" */










int main() {
	struct StringArray *my_array = 0;
    char *storage = (char *) CWUTILS_NULL;
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
	(my_array)->used = 0;
	(my_array)->length = 0;
	(my_array)->capacity = 3;
	(my_array)->contents = (char * *) malloc(sizeof(char *) * 3)
;	

    /* Fill the array up */
    
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        
    } else {
	    (my_array)->contents[(my_array)->length] = (string_1);
	    (my_array)->length++;
    }

    (my_array)->used++;
;
    
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        
    } else {
	    (my_array)->contents[(my_array)->length] = (string_2);
	    (my_array)->length++;
    }

    (my_array)->used++;
;
    
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        
    } else {
	    (my_array)->contents[(my_array)->length] = (string_3);
	    (my_array)->length++;
    }

    (my_array)->used++;
;
    
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        
    } else {
	    (my_array)->contents[(my_array)->length] = (string_4);
	    (my_array)->length++;
    }

    (my_array)->used++;
;

    ASSERT_STREQ(my_array->contents[0], "foo");
    ASSERT_STREQ(my_array->contents[1], "bar");
    ASSERT_STREQ(my_array->contents[2], "baz");
    ASSERT_STREQ(my_array->contents[3], "quz");
    ASSERT_NUMEQ(my_array->length, 4);
    ASSERT_NUMEQ(my_array->capacity, 3 * 2);



    storage = 
	(my_array)->contents[0];

	(storage) = (my_array)->contents[0];

	do {
		int __M4_INDEX = 0;

		/* Pull everything from index (0), onwards, back by 1. */
		while(__M4_INDEX < (my_array)->length) {
			(my_array)->contents[__M4_INDEX] = (my_array)->contents[__M4_INDEX + 1];
			__M4_INDEX++;
		}

		(my_array)->length--;
	} while(0)
;

    ASSERT_STREQ(storage, "foo");
    ASSERT_STREQ(my_array->contents[0], "bar");
    ASSERT_STREQ(my_array->contents[1], "baz");
    ASSERT_STREQ(my_array->contents[2], "quz");
    ASSERT_NUMEQ(my_array->length, 3);
    ASSERT_NUMEQ(my_array->capacity, 3 * 2);

    storage = 
	(my_array)->contents[0];

	(storage) = (my_array)->contents[1];

	do {
		int __M4_INDEX = 1;

		/* Pull everything from index (1), onwards, back by 1. */
		while(__M4_INDEX < (my_array)->length) {
			(my_array)->contents[__M4_INDEX] = (my_array)->contents[__M4_INDEX + 1];
			__M4_INDEX++;
		}

		(my_array)->length--;
	} while(0)
;

    ASSERT_STREQ(storage, "baz");
    ASSERT_STREQ(my_array->contents[0], "bar");
    ASSERT_STREQ(my_array->contents[1], "quz");
    ASSERT_NUMEQ(my_array->length, 2);
    ASSERT_NUMEQ(my_array->capacity, 3 * 2);

    storage = 
	(my_array)->contents[0];

	(storage) = (my_array)->contents[1];

	do {
		int __M4_INDEX = 1;

		/* Pull everything from index (1), onwards, back by 1. */
		while(__M4_INDEX < (my_array)->length) {
			(my_array)->contents[__M4_INDEX] = (my_array)->contents[__M4_INDEX + 1];
			__M4_INDEX++;
		}

		(my_array)->length--;
	} while(0)
;

    ASSERT_STREQ(storage, "quz");
    ASSERT_STREQ(my_array->contents[0], "bar");
    ASSERT_NUMEQ(my_array->length, 1);
    ASSERT_NUMEQ(my_array->capacity, 3 * 2);

    storage = 
	(my_array)->contents[0];

	(storage) = (my_array)->contents[0];

	do {
		int __M4_INDEX = 0;

		/* Pull everything from index (0), onwards, back by 1. */
		while(__M4_INDEX < (my_array)->length) {
			(my_array)->contents[__M4_INDEX] = (my_array)->contents[__M4_INDEX + 1];
			__M4_INDEX++;
		}

		(my_array)->length--;
	} while(0)
;

    ASSERT_STREQ(storage, "bar");
    ASSERT_NUMEQ(my_array->length, 0);
    ASSERT_NUMEQ(my_array->capacity, 3 * 2);

	return 0;
}
