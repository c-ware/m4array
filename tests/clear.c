/*
 * Testing of the clear operation.
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










void test_clear() {
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
    CWUTILS_NULL;

	(array) = (struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");

	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3);

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")

;

    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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

    /* Clear the contents of the array, releasing each string in the process */
    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
        /* We only need to release the contents of the array if
           we do not want to reuse memory. If we do want to reuse
           memory, all we need to do is set the used length to zero
           to signal to adding functions that there is allocated,
           but unused slots in the array. */
        
		    int __M4_INDEX = 0;

		    while(__M4_INDEX < (array)->used) {
                LIBERROR_IS_OOB(__M4_INDEX, (array)->used);

		    	free((array)->contents[__M4_INDEX]);
                __M4_INDEX++;
		    }
            
            (array)->length = 0;
        

        /* Regardless of whether or not we reuse memory, this
           can be reset to zero. */
        (array)->used = 0;

	} while(0)
;
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->used, 0);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);

    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			free((array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;
}

void test_clear_reuse() {
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
    CWUTILS_NULL;

	(array) = (struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");

	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3);

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")

;

    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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

    /* Clear the contents of the array, without freeing the elements. */
    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
        /* We only need to release the contents of the array if
           we do not want to reuse memory. If we do want to reuse
           memory, all we need to do is set the used length to zero
           to signal to adding functions that there is allocated,
           but unused slots in the array. */
        

        /* Regardless of whether or not we reuse memory, this
           can be reset to zero. */
        (array)->used = 0;

	} while(0)
;
    ASSERT_NUMEQ(array->length, 6);
    ASSERT_NUMEQ(array->used, 0);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);

    ASSERT_STREQ(array->contents[0], "foo");
    ASSERT_STREQ(array->contents[1], "bar");
    ASSERT_STREQ(array->contents[2], "baz");
    ASSERT_STREQ(array->contents[3], "tuna");
    ASSERT_STREQ(array->contents[4], "spam");
    ASSERT_STREQ(array->contents[5], "thud");

    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			free((array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;
}

/* Attempt to clear an array with stuff in it, but that has a length of
 * of zero. Technically, this test only exists to verify that nothing
 * happens, as the clear function only goes up to the USED length. This
 * will not reuse memory, so it will free the contents of the array. */
void test_clear_length_zero_array_no_reuse() {
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
    CWUTILS_NULL;

	(array) = (struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");

	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3);

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")

;

    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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

    array->length = 0;

    /* Clear the contents of the array, freeing the elements in it.*/
    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
        /* We only need to release the contents of the array if
           we do not want to reuse memory. If we do want to reuse
           memory, all we need to do is set the used length to zero
           to signal to adding functions that there is allocated,
           but unused slots in the array. */
        
		    int __M4_INDEX = 0;

		    while(__M4_INDEX < (array)->used) {
                LIBERROR_IS_OOB(__M4_INDEX, (array)->used);

		    	free((array)->contents[__M4_INDEX]);
                __M4_INDEX++;
		    }
            
            (array)->length = 0;
        

        /* Regardless of whether or not we reuse memory, this
           can be reset to zero. */
        (array)->used = 0;

	} while(0)
;
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->used, 0);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);

    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			free((array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;
}

/* Attempt to clear an array with stuff in it, but that has a used of
 * of zero. Technically, this test only exists to verify that nothing
 * happens, as the clear function only goes up to the USED length. This
 * will reuse memory, so it will not free the contents of the array. */
void test_clear_length_zero_array_reuse() {
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
    CWUTILS_NULL;

	(array) = (struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");

	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3);

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")

;

    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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

    array->used = 0;

    /* Clear the contents of the array, freeing the elements in it.*/
    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
        /* We only need to release the contents of the array if
           we do not want to reuse memory. If we do want to reuse
           memory, all we need to do is set the used length to zero
           to signal to adding functions that there is allocated,
           but unused slots in the array. */
        

        /* Regardless of whether or not we reuse memory, this
           can be reset to zero. */
        (array)->used = 0;

	} while(0)
;
    ASSERT_NUMEQ(array->length, 6);
    ASSERT_NUMEQ(array->used, 0);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);

    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			free((array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;
}

/* Attempt to clear an array with stuff in it, but that has a length of
 * of zero. Technically, this test only exists to verify that nothing
 * happens, as the clear function only goes up to the USED length. This
 * will reuse memory, so it will not free the contents of the array. */
void test_clear_used_zero_array_reuse() {
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
    CWUTILS_NULL;

	(array) = (struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");

	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3);

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")

;

    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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

    array->used = 0;

    /* Clear the contents of the array, freeing the elements in it.*/
    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
        /* We only need to release the contents of the array if
           we do not want to reuse memory. If we do want to reuse
           memory, all we need to do is set the used length to zero
           to signal to adding functions that there is allocated,
           but unused slots in the array. */
        

        /* Regardless of whether or not we reuse memory, this
           can be reset to zero. */
        (array)->used = 0;

	} while(0)
;
    ASSERT_NUMEQ(array->length, 6);
    ASSERT_NUMEQ(array->used, 0);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);

    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			free((array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;
}

/* Attempt to clear an array with stuff in it, but that has a used of
 * of zero. Technically, this test only exists to verify that nothing
 * happens, as the clear function only goes up to the USED length. This
 * will not reuse memory, so it will free the contents of the array. */
void test_clear_used_zero_array_no_reuse() {
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
    CWUTILS_NULL;

	(array) = (struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");

	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3);

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")

;

    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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
    
    

    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);

        LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity");
        LIBERROR_MALLOC_FAILURE((array)->contents, "(array)->contents");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
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

    array->used = 0;

    /* Clear the contents of the array, freeing the elements in it.*/
    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
        /* We only need to release the contents of the array if
           we do not want to reuse memory. If we do want to reuse
           memory, all we need to do is set the used length to zero
           to signal to adding functions that there is allocated,
           but unused slots in the array. */
        
		    int __M4_INDEX = 0;

		    while(__M4_INDEX < (array)->used) {
                LIBERROR_IS_OOB(__M4_INDEX, (array)->used);

		    	free((array)->contents[__M4_INDEX]);
                __M4_INDEX++;
		    }
            
            (array)->length = 0;
        

        /* Regardless of whether or not we reuse memory, this
           can be reset to zero. */
        (array)->used = 0;

	} while(0)
;
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->used, 0);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);

    
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			free((array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;
}

int main() {
    test_clear();
    test_clear_reuse();
    test_clear_length_zero_array_no_reuse();
    test_clear_length_zero_array_reuse();
    test_clear_used_zero_array_reuse();
    test_clear_used_zero_array_reuse();

    return 0;
}
