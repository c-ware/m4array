/*
 * Testing of the filter operation.
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










void test_map() {
    char *a = (char *) malloc(16);
    char *b = (char *) malloc(16);
    char *c = (char *) malloc(16);
    char *d = (char *) malloc(16);
    char *e = (char *) malloc(16);
    char *f = (char *) malloc(16);
    struct StringArray *array = (struct StringArray *) CWUTILS_NULL;

    /* Initialize strings */
    strcpy(a, "foo"); 
    strcpy(b, "bar"); 
    strcpy(c, "baz"); 
    strcpy(d, "tuna"); 
    strcpy(e, "spam"); 
    strcpy(f, "thud"); 

    array = 
	(struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3)
;

    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (a);
	    (array)->length++;
    }

    (array)->used++;
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (b);
	    (array)->length++;
    }

    (array)->used++;
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (c);
	    (array)->length++;
    }

    (array)->used++;
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (d);
	    (array)->length++;
    }

    (array)->used++;
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (e);
	    (array)->length++;
    }

    (array)->used++;
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (f);
	    (array)->length++;
    }

    (array)->used++;
;

    /* Filter out strings that begin with b */
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->used) {
            /* A[I] matches the predicate-- swap A[I] and A[L]*/
            if((((array)->contents[__M4_INDEX])[0] != "b"[0]) == 1) {
                char * __M4_TEMP = (array)->contents[__M4_CURSOR];

                (array)->contents[__M4_CURSOR] = (array)->contents[__M4_INDEX];
                (array)->contents[__M4_INDEX] = __M4_TEMP;
                __M4_CURSOR++;
            }

            __M4_INDEX++;
		}

        /* If we are reusing memory, then we should leave the length alone.
           Otherwise, length should stay the same as the used count. Normally,
           at first thought, we should do x = (y + 1), but we do not have to,
           since y will be equal to the length of the array. */
        

        /* If we do not enforce memory reuse, everything after __M4_CURSOR
           must be freed, since it will not be reusable. Once this is done,
           we can set the length __M4_CURSOR */
        
            __M4_INDEX = __M4_CURSOR;

            while(__M4_INDEX < (array)->length) {
                free((array)->contents[__M4_INDEX]);
                __M4_INDEX++;
            }

            (array)->length = __M4_CURSOR;
            (array)->used = __M4_CURSOR;
         
	} while(0)
;
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 4);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "foo");
    ASSERT_STREQ(array->contents[1], "tuna");
    ASSERT_STREQ(array->contents[2], "spam");
    ASSERT_STREQ(array->contents[3], "thud");

    /* Filter out strings that do not begin with with a t */
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->used) {
            /* A[I] matches the predicate-- swap A[I] and A[L]*/
            if((((array)->contents[__M4_INDEX])[0] == "t"[0]) == 1) {
                char * __M4_TEMP = (array)->contents[__M4_CURSOR];

                (array)->contents[__M4_CURSOR] = (array)->contents[__M4_INDEX];
                (array)->contents[__M4_INDEX] = __M4_TEMP;
                __M4_CURSOR++;
            }

            __M4_INDEX++;
		}

        /* If we are reusing memory, then we should leave the length alone.
           Otherwise, length should stay the same as the used count. Normally,
           at first thought, we should do x = (y + 1), but we do not have to,
           since y will be equal to the length of the array. */
        

        /* If we do not enforce memory reuse, everything after __M4_CURSOR
           must be freed, since it will not be reusable. Once this is done,
           we can set the length __M4_CURSOR */
        
            __M4_INDEX = __M4_CURSOR;

            while(__M4_INDEX < (array)->length) {
                free((array)->contents[__M4_INDEX]);
                __M4_INDEX++;
            }

            (array)->length = __M4_CURSOR;
            (array)->used = __M4_CURSOR;
         
	} while(0)
;
    ASSERT_NUMEQ(array->length, 2);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "tuna");
    ASSERT_STREQ(array->contents[1], "thud");

    
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
			free((array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;
}

int main() {
    test_map();

    return 0;
}
