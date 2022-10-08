/*
 * Testing of the map operation.
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

    /* Append text to each string */
    
	
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			(array)->contents[__M4_INDEX] = (strcat((array)->contents[__M4_INDEX], "_spam"));
            __M4_INDEX++;
		}
	} while(0)
;

    ASSERT_STREQ(array->contents[0], "foo_spam");
    ASSERT_STREQ(array->contents[1], "bar_spam");
    ASSERT_STREQ(array->contents[2], "baz_spam");
    ASSERT_STREQ(array->contents[3], "tuna_spam");
    ASSERT_STREQ(array->contents[4], "spam_spam");
    ASSERT_STREQ(array->contents[5], "thud_spam");

    
    
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

void test_map_only_applies_to_used() {
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

    /* Only map to the first 4 strings */
    array->used = 4;

    /* Append text to each string */
    
	
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			(array)->contents[__M4_INDEX] = (strcat((array)->contents[__M4_INDEX], "_spam"));
            __M4_INDEX++;
		}
	} while(0)
;

    ASSERT_STREQ(array->contents[0], "foo_spam");
    ASSERT_STREQ(array->contents[1], "bar_spam");
    ASSERT_STREQ(array->contents[2], "baz_spam");
    ASSERT_STREQ(array->contents[3], "tuna_spam");
    ASSERT_STREQ(array->contents[4], "spam");
    ASSERT_STREQ(array->contents[5], "thud");

    /* Only map to the first 3 strings */
    array->used = 3;

    /* Append text to each string */
    
	
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			(array)->contents[__M4_INDEX] = (strcat((array)->contents[__M4_INDEX], "_"));
            __M4_INDEX++;
		}
	} while(0)
;

    ASSERT_STREQ(array->contents[0], "foo_spam_");
    ASSERT_STREQ(array->contents[1], "bar_spam_");
    ASSERT_STREQ(array->contents[2], "baz_spam_");
    ASSERT_STREQ(array->contents[3], "tuna_spam");
    ASSERT_STREQ(array->contents[4], "spam");
    ASSERT_STREQ(array->contents[5], "thud");

    /* Only map to the first 2 strings */
    array->used = 2;

    /* Append text to each string */
    
	
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			(array)->contents[__M4_INDEX] = (strcat((array)->contents[__M4_INDEX], "s"));
            __M4_INDEX++;
		}
	} while(0)
;

    ASSERT_STREQ(array->contents[0], "foo_spam_s");
    ASSERT_STREQ(array->contents[1], "bar_spam_s");
    ASSERT_STREQ(array->contents[2], "baz_spam_");
    ASSERT_STREQ(array->contents[3], "tuna_spam");
    ASSERT_STREQ(array->contents[4], "spam");
    ASSERT_STREQ(array->contents[5], "thud");

    /* Only map to the first string */
    array->used = 1;

    /* Append text to each string */
    
	
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			(array)->contents[__M4_INDEX] = (strcat((array)->contents[__M4_INDEX], "p"));
            __M4_INDEX++;
		}
	} while(0)
;

    ASSERT_STREQ(array->contents[0], "foo_spam_sp");
    ASSERT_STREQ(array->contents[1], "bar_spam_s");
    ASSERT_STREQ(array->contents[2], "baz_spam_");
    ASSERT_STREQ(array->contents[3], "tuna_spam");
    ASSERT_STREQ(array->contents[4], "spam");
    ASSERT_STREQ(array->contents[5], "thud");

    /* Don't map to any */
    array->used = 0;

    /* Append text to each string */
    
	
    
    LIBERROR_IS_NULL((array), "(array)");
    LIBERROR_IS_NULL((array)->contents, "(array)->contents");
    LIBERROR_IS_NEGATIVE((array)->used, "(array)->used");
    LIBERROR_IS_NEGATIVE((array)->length, "(array)->length");
    LIBERROR_IS_NEGATIVE((array)->capacity, "(array)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
            LIBERROR_IS_OOB(__M4_INDEX, (array)->length);
			(array)->contents[__M4_INDEX] = (strcat((array)->contents[__M4_INDEX], "a"));
            __M4_INDEX++;
		}
	} while(0)
;

    ASSERT_STREQ(array->contents[0], "foo_spam_sp");
    ASSERT_STREQ(array->contents[1], "bar_spam_s");
    ASSERT_STREQ(array->contents[2], "baz_spam_");
    ASSERT_STREQ(array->contents[3], "tuna_spam");
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

int main() {
    test_map();
    test_map_only_applies_to_used();

    return 0;
}
