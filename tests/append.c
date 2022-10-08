/*
 * Testing of the append operation.
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










void test_append() {
    struct StringArray *array = (struct StringArray *) CWUTILS_NULL;
    char *a = (char *) malloc(16);
    char *b = (char *) malloc(16);
    char *c = (char *) malloc(16);
    char *d = (char *) malloc(16);
    char *e = (char *) malloc(16);
    char *f = (char *) malloc(16);

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
    ASSERT_NUMEQ(array->length, 1);
    ASSERT_NUMEQ(array->used, 1);
    ASSERT_NUMEQ(array->capacity, 3);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "foo");

    
    

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
    ASSERT_NUMEQ(array->length, 2);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_NUMEQ(array->capacity, 3);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "foo");
    ASSERT_STREQ(array->contents[1], "bar");

    
    

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
    ASSERT_NUMEQ(array->length, 3);
    ASSERT_NUMEQ(array->used, 3);
    ASSERT_NUMEQ(array->capacity, 3);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "foo");
    ASSERT_STREQ(array->contents[1], "bar");
    ASSERT_STREQ(array->contents[2], "baz");

    
    
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

void test_resize() {
    struct StringArray *array = (struct StringArray *) CWUTILS_NULL;
    char *a = (char *) malloc(16);
    char *b = (char *) malloc(16);
    char *c = (char *) malloc(16);
    char *d = (char *) malloc(16);
    char *e = (char *) malloc(16);
    char *f = (char *) malloc(16);

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

    /* Past this point, a resize should be triggered */
    
    

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
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 4);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "foo");
    ASSERT_STREQ(array->contents[1], "bar");
    ASSERT_STREQ(array->contents[2], "baz");
    ASSERT_STREQ(array->contents[3], "tuna");

    /* Can we continue to append to a resized array? */
    
    

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
    ASSERT_NUMEQ(array->length, 5);
    ASSERT_NUMEQ(array->used, 5);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "foo");
    ASSERT_STREQ(array->contents[1], "bar");
    ASSERT_STREQ(array->contents[2], "baz");
    ASSERT_STREQ(array->contents[3], "tuna");
    ASSERT_STREQ(array->contents[4], "spam");

    
    
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

void test_reuse() {
    struct StringArray *array = (struct StringArray *) CWUTILS_NULL;
    char *a = (char *) malloc(16);
    char *b = (char *) malloc(16);
    char *c = (char *) malloc(16);
    char *d = (char *) malloc(16);
    char *e = (char *) malloc(16);
    char *f = (char *) malloc(16);

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

    /* Can we reuse part of the array? */
    array->used = 4;

    
    

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
        ((array)->contents[(array)->used])[0] = 0x0; strcat((array)->contents[(array)->used], ("quz"));
    } else {
	    (array)->contents[(array)->length] = ("quz");
	    (array)->length++;
    }

    (array)->used++;
;
    ASSERT_NUMEQ(array->length, 5);
    ASSERT_NUMEQ(array->used, 5);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "foo");
    ASSERT_STREQ(array->contents[1], "bar");
    ASSERT_STREQ(array->contents[2], "baz");
    ASSERT_STREQ(array->contents[3], "tuna");
    ASSERT_STREQ(array->contents[4], "quz");
    ASSERT_PTREQ(array->contents[4], e);

    
    
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
    test_append();
    test_resize();
    test_reuse();

    return 0;
}
