/*
 * Test filtering an array based on a predicate.
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

    /* Filter all elements that are not divisible by two */
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->length) {
            /* If it evaluates to 0, it does not match the predicate */
            if((((array)->contents[__M4_INDEX] % 2) == 0) == 1) {
                (array)->contents[__M4_CURSOR] = (array)->contents[__M4_INDEX];
                __M4_CURSOR++; 
            } else {
                ;
            }

            __M4_INDEX++;
		}

        (array)->length = __M4_CURSOR;
	} while(0)
;
    ASSERT_NUMEQ(array->length, 2);
    ASSERT_NUMEQ(array->contents[0], 2);
    ASSERT_NUMEQ(array->contents[1], 4);

    /* Add some more to filter further */
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

	(array)->contents[(array)->length] = (5);
	(array)->length++
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

	(array)->contents[(array)->length] = (6);
	(array)->length++
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

	(array)->contents[(array)->length] = (7);
	(array)->length++
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

	(array)->contents[(array)->length] = (8);
	(array)->length++
;

    /* Filter all elements that are not divisible by two */
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->length) {
            /* If it evaluates to 0, it does not match the predicate */
            if((((array)->contents[__M4_INDEX] % 2) == 0) == 1) {
                (array)->contents[__M4_CURSOR] = (array)->contents[__M4_INDEX];
                __M4_CURSOR++; 
            } else {
                ;
            }

            __M4_INDEX++;
		}

        (array)->length = __M4_CURSOR;
	} while(0)
;
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->contents[0], 2);
    ASSERT_NUMEQ(array->contents[1], 4);
    ASSERT_NUMEQ(array->contents[2], 6);
    ASSERT_NUMEQ(array->contents[3], 8);

	
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
