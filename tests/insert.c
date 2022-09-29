/*
 * Test inserting data into the array
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

    /* Cannot insert into an empty array */
    
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

    
	/* Resize the array if necessary */
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	do {
		int __M4_INDEX = (my_array)->used - 1;
        char * __M4_TEMP = (my_array)->contents[(my_array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(my_array)->contents[__M4_INDEX + 1] = (my_array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((my_array)->used < (my_array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (my_array)->contents[0] = __M4_TEMP;
		    (my_array)->used++;
        } else {
		    (my_array)->contents[0] = string_2;
		    (my_array)->length++;
		    (my_array)->used++;
        }
	} while(0)
;
    ASSERT_STREQ(my_array->contents[0], string_2);
    ASSERT_STREQ(my_array->contents[1], string_1);
    ASSERT_NUMEQ(my_array->length, 2);
    ASSERT_NUMEQ(my_array->used, 2);
    ASSERT_NUMEQ(my_array->capacity, 3);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);

    
	/* Resize the array if necessary */
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	do {
		int __M4_INDEX = (my_array)->used - 1;
        char * __M4_TEMP = (my_array)->contents[(my_array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(my_array)->contents[__M4_INDEX + 1] = (my_array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((my_array)->used < (my_array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (my_array)->contents[0] = __M4_TEMP;
		    (my_array)->used++;
        } else {
		    (my_array)->contents[0] = string_3;
		    (my_array)->length++;
		    (my_array)->used++;
        }
	} while(0)
;
    ASSERT_STREQ(my_array->contents[0], string_3);
    ASSERT_STREQ(my_array->contents[1], string_2);
    ASSERT_STREQ(my_array->contents[2], string_1);
    ASSERT_NUMEQ(my_array->length, 3);
    ASSERT_NUMEQ(my_array->used, 3);
    ASSERT_NUMEQ(my_array->capacity, 3);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);

    
	/* Resize the array if necessary */
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	do {
		int __M4_INDEX = (my_array)->used - 1;
        char * __M4_TEMP = (my_array)->contents[(my_array)->used];

		/* Shift each element before (1 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (1) - 1) {
			(my_array)->contents[__M4_INDEX + 1] = (my_array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((my_array)->used < (my_array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (my_array)->contents[1] = __M4_TEMP;
		    (my_array)->used++;
        } else {
		    (my_array)->contents[1] = string_4;
		    (my_array)->length++;
		    (my_array)->used++;
        }
	} while(0)
;
    ASSERT_STREQ(my_array->contents[0], string_3);
    ASSERT_STREQ(my_array->contents[1], string_4);
    ASSERT_STREQ(my_array->contents[2], string_2);
    ASSERT_STREQ(my_array->contents[3], string_1);
    ASSERT_NUMEQ(my_array->length, 4);
    ASSERT_NUMEQ(my_array->used, 4);
    ASSERT_NUMEQ(my_array->capacity, 3 * 2);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);

    /* OK, so we have verified that basic insertion behavior works. However,
       does insert respect memory reuse..? */

    my_array->used = 0;

    /* Cannot insert into an empty array */
    
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        ((my_array)->contents[(my_array)->used])[0] = 0x0; strcat((my_array)->contents[(my_array)->used], "aaa");
    } else {
	    (my_array)->contents[(my_array)->length] = ("aaa");
	    (my_array)->length++;
    }

    (my_array)->used++;
;
    ASSERT_STREQ(my_array->contents[0], "aaa");
    ASSERT_STREQ(my_array->contents[1], string_4);
    ASSERT_STREQ(my_array->contents[2], string_2);
    ASSERT_STREQ(my_array->contents[3], string_1);
    ASSERT_NUMEQ(my_array->used, 1);
    ASSERT_NUMEQ(my_array->length, 4);

    
	/* Resize the array if necessary */
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	do {
		int __M4_INDEX = (my_array)->used - 1;
        char * __M4_TEMP = (my_array)->contents[(my_array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(my_array)->contents[__M4_INDEX + 1] = (my_array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((my_array)->used < (my_array)->length) {
            (__M4_TEMP)[0] = 0x0; strcat(__M4_TEMP, "bbb");

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (my_array)->contents[0] = __M4_TEMP;
		    (my_array)->used++;
        } else {
		    (my_array)->contents[0] = "bbb";
		    (my_array)->length++;
		    (my_array)->used++;
        }
	} while(0)
;
    ASSERT_STREQ(my_array->contents[0], "bbb");
    ASSERT_STREQ(my_array->contents[1], "aaa");
    ASSERT_STREQ(my_array->contents[2], string_2);
    ASSERT_STREQ(my_array->contents[3], string_1);
    ASSERT_NUMEQ(my_array->used, 2);
    ASSERT_NUMEQ(my_array->length, 4);
    
    
	/* Resize the array if necessary */
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

	do {
		int __M4_INDEX = (my_array)->used - 1;
        char * __M4_TEMP = (my_array)->contents[(my_array)->used];

		/* Shift each element before (1 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (1) - 1) {
			(my_array)->contents[__M4_INDEX + 1] = (my_array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((my_array)->used < (my_array)->length) {
            (__M4_TEMP)[0] = 0x0; strcat(__M4_TEMP, "ccc");

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (my_array)->contents[1] = __M4_TEMP;
		    (my_array)->used++;
        } else {
		    (my_array)->contents[1] = "ccc";
		    (my_array)->length++;
		    (my_array)->used++;
        }
	} while(0)
;
    ASSERT_STREQ(my_array->contents[0], "bbb");
    ASSERT_STREQ(my_array->contents[1], "ccc");
    ASSERT_STREQ(my_array->contents[2], "aaa");
    ASSERT_STREQ(my_array->contents[3], string_1);
    ASSERT_NUMEQ(my_array->used, 3);
    ASSERT_NUMEQ(my_array->length, 4);

    
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
