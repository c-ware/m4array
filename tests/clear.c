/*
 * Test clearing the contents of an array.
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
    struct IntArray *array = 
	(struct IntArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (int *) malloc(sizeof(int) * 3)
;

    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (0);
	    (array)->length++;
    }

    (array)->used++;
;    
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (1);
	    (array)->length++;
    }

    (array)->used++;
;    
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (2);
	    (array)->length++;
    }

    (array)->used++;
;    
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (3);
	    (array)->length++;
    }

    (array)->used++;
;    
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (4);
	    (array)->length++;
    }

    (array)->used++;
;    

    
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
			;
            __M4_INDEX++;
		}

        (array)->length = 0;
	} while(0)
;
    ASSERT_NUMEQ(array->length, 0);

    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (0);
	    (array)->length++;
    }

    (array)->used++;
;    
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (1);
	    (array)->length++;
    }

    (array)->used++;
;    
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (2);
	    (array)->length++;
    }

    (array)->used++;
;    

    ASSERT_NUMEQ(array->length, 3);

	
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
