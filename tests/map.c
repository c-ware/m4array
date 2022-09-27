/*
 * Test mapping an operation to an array
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
        int length;
        int capacity;
        int *contents;
    }
;

    struct StringArray {
        int length;
        int capacity;
        char * *contents;
    }
;










int main() {
	struct IntArray *array = 
	(struct IntArray *) malloc(sizeof(*(array)));
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (int *) malloc(sizeof(int) * 3)
;

    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

	(array)->contents[(array)->length] = (1);
	(array)->length++
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

	(array)->contents[(array)->length] = (2);
	(array)->length++
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

	(array)->contents[(array)->length] = (3);
	(array)->length++
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

	(array)->contents[(array)->length] = (4);
	(array)->length++
;

    /* Square all numbers */
    
	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
			(array)->contents[__M4_INDEX] = ((array)->contents[__M4_INDEX] * (array)->contents[__M4_INDEX]);
            __M4_INDEX++;
		}
	} while(0)
;

    ASSERT_NUMEQ(array->contents[0], 1);
    ASSERT_NUMEQ(array->contents[1], 4);
    ASSERT_NUMEQ(array->contents[2], 9);
    ASSERT_NUMEQ(array->contents[3], 16);

    /* Square an array with no numbers. Despite there technically
     * being no numbers, the map function should NOT change the
     * existing numbers, because that would imply it goes beyond
     * the length.
    */

    array->length = 0;
    
	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
			(array)->contents[__M4_INDEX] = ((array)->contents[__M4_INDEX] * (array)->contents[__M4_INDEX]);
            __M4_INDEX++;
		}
	} while(0)
;
    ASSERT_NUMEQ(array->contents[0], 1);
    ASSERT_NUMEQ(array->contents[1], 4);
    ASSERT_NUMEQ(array->contents[2], 9);
    ASSERT_NUMEQ(array->contents[3], 16);

	
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
			;
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;

	return 0;
}
