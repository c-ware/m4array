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










/* Test the basic behavior of the filter operation */
void filter_basic() {
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
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
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
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
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
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
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
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (4);
	    (array)->length++;
    }

    (array)->used++;
;

    /* Filter all elements that are not divisible by two */
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->used) {
            /* A[I] matches the predicate-- swap A[I] and A[L]*/
            if((((array)->contents[__M4_INDEX] % 2) == 0) == 1) {
                int __M4_TEMP = (array)->contents[__M4_CURSOR];

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
                ;
                __M4_INDEX++;
            }

            (array)->length = __M4_CURSOR;
            (array)->used = __M4_CURSOR;
         
	} while(0)
;
    ASSERT_NUMEQ(array->length, 2);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_NUMEQ(array->contents[0], 2);
    ASSERT_NUMEQ(array->contents[1], 4);

    /* Add some more to filter further */
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (5);
	    (array)->length++;
    }

    (array)->used++;
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (6);
	    (array)->length++;
    }

    (array)->used++;
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (7);
	    (array)->length++;
    }

    (array)->used++;
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        
    } else {
	    (array)->contents[(array)->length] = (8);
	    (array)->length++;
    }

    (array)->used++;
;

    /* Filter all elements that are not divisible by two */
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->used) {
            /* A[I] matches the predicate-- swap A[I] and A[L]*/
            if((((array)->contents[__M4_INDEX] % 2) == 0) == 1) {
                int __M4_TEMP = (array)->contents[__M4_CURSOR];

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
                ;
                __M4_INDEX++;
            }

            (array)->length = __M4_CURSOR;
            (array)->used = __M4_CURSOR;
         
	} while(0)
;
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 4);
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
}

/* Test the behavior of the filter operation when we deal
   with memory reuse */
void filter_memory_reuse() {
    struct StringArray *array = 
	(struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3)
;
    char *string_a = malloc(16);
    char *string_b = malloc(16);
    char *string_c = malloc(16);
    char *string_d = malloc(16);
    char *string_e = malloc(16);
    char *string_f = malloc(16);

    strcpy(string_a, "foo");
    strcpy(string_b, "bar");
    strcpy(string_c, "baz");
    strcpy(string_d, "tuna");
    strcpy(string_e, "buzz");
    strcpy(string_f, "blue");

    
	if((array)->length == (array)->capacity) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        ((array)->contents[(array)->used])[0] = 0x0; strcat((array)->contents[(array)->used], string_a);
    } else {
	    (array)->contents[(array)->length] = (string_a);
	    (array)->length++;
    }

    (array)->used++;
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        ((array)->contents[(array)->used])[0] = 0x0; strcat((array)->contents[(array)->used], string_b);
    } else {
	    (array)->contents[(array)->length] = (string_b);
	    (array)->length++;
    }

    (array)->used++;
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        ((array)->contents[(array)->used])[0] = 0x0; strcat((array)->contents[(array)->used], string_c);
    } else {
	    (array)->contents[(array)->length] = (string_c);
	    (array)->length++;
    }

    (array)->used++;
;
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        ((array)->contents[(array)->used])[0] = 0x0; strcat((array)->contents[(array)->used], string_d);
    } else {
	    (array)->contents[(array)->length] = (string_d);
	    (array)->length++;
    }

    (array)->used++;
;

    /* Filter all strings not starting with 0x62 ('b') */
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->used) {
            /* A[I] matches the predicate-- swap A[I] and A[L]*/
            if((((array)->contents[__M4_INDEX])[0] == 0x62) == 1) {
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
        (array)->used = __M4_CURSOR;

        /* If we do not enforce memory reuse, everything after __M4_CURSOR
           must be freed, since it will not be reusable. Once this is done,
           we can set the length __M4_CURSOR */
         
	} while(0)
;
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_STREQ(array->contents[0], "bar");
    ASSERT_STREQ(array->contents[1], "baz");

    /* Can we the filter operation handle 'refilled' data? */
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        ((array)->contents[(array)->used])[0] = 0x0; strcat((array)->contents[(array)->used], string_e);
    } else {
	    (array)->contents[(array)->length] = (string_e);
	    (array)->length++;
    }

    (array)->used++;
;
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->used) {
            /* A[I] matches the predicate-- swap A[I] and A[L]*/
            if((((array)->contents[__M4_INDEX])[0] == 0x62) == 1) {
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
        (array)->used = __M4_CURSOR;

        /* If we do not enforce memory reuse, everything after __M4_CURSOR
           must be freed, since it will not be reusable. Once this is done,
           we can set the length __M4_CURSOR */
         
	} while(0)
;
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 3);
    ASSERT_STREQ(array->contents[0], "bar");
    ASSERT_STREQ(array->contents[1], "baz");
    ASSERT_STREQ(array->contents[2], "buzz");

    /* Can we do it again?! */
    
	if((array)->length == (array)->capacity) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((array)->used < (array)->length) {
        ((array)->contents[(array)->used])[0] = 0x0; strcat((array)->contents[(array)->used], string_f);
    } else {
	    (array)->contents[(array)->length] = (string_f);
	    (array)->length++;
    }

    (array)->used++;
;
    
	

	do {
		int __M4_INDEX = 0;
        int __M4_CURSOR = 0;

		while(__M4_INDEX < (array)->used) {
            /* A[I] matches the predicate-- swap A[I] and A[L]*/
            if((((array)->contents[__M4_INDEX])[0] == 0x62) == 1) {
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
        (array)->used = __M4_CURSOR;

        /* If we do not enforce memory reuse, everything after __M4_CURSOR
           must be freed, since it will not be reusable. Once this is done,
           we can set the length __M4_CURSOR */
         
	} while(0)
;
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 4);
    ASSERT_STREQ(array->contents[0], "bar");
    ASSERT_STREQ(array->contents[1], "baz");
    ASSERT_STREQ(array->contents[2], "buzz");
    ASSERT_STREQ(array->contents[3], "blue");
    

    
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
    filter_basic();
    filter_memory_reuse();

	return 0;
}
