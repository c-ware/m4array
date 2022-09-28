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
    struct IntArray *array = CWUTILS_NULL;
	struct StringArray *str_array = CWUTILS_NULL;

	char *string_1 = (CWUTILS_GENERIC) malloc(4);
	char *string_2 = (CWUTILS_GENERIC) malloc(4);
	char *string_3 = (CWUTILS_GENERIC) malloc(4);
	char *string_4 = (CWUTILS_GENERIC) malloc(4);

    array = 
	(struct IntArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (int *) malloc(sizeof(int) * 3)
;
    str_array = 
	(struct StringArray *) malloc(sizeof(*(str_array)));
	(str_array)->used = 0;
	(str_array)->length = 0;
	(str_array)->capacity = 3;
	(str_array)->contents = (char * *) malloc(sizeof(char *) * 3)
;

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

    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
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

    
	do {
        /* We only need to release the contents of the array if
           we do not want to reuse memory. If we do want to reuse
           memory, all we need to do is set the used length to zero
           to signal to adding functions that there is allocated,
           but unused slots in the array. */
        
		    int __M4_INDEX = 0;

		    while(__M4_INDEX < (array)->length) {
		    	;
                __M4_INDEX++;
		    }
            
            (array)->length = 0;
        

        /* Regardless of whether or not we reuse memory, this
           can be reset to zero. */
        (array)->used = 0;

	} while(0)
;
    ASSERT_NUMEQ(array->length, 0);

    
	if((array)->length == (array)->capacity) {
		(array)->contents = (int *) realloc((array)->contents, sizeof(int) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
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

    ASSERT_NUMEQ(array->length, 3);

    /* Now that we've got basic clearing tests done, how about we
       test this with memory reuse? Let's start by loading the string
       array  */
    
	if((str_array)->length == (str_array)->capacity) {
		(str_array)->contents = (char * *) realloc((str_array)->contents, sizeof(char *) * ((str_array)->capacity * 2));
		(str_array)->capacity = ((str_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((str_array)->used < (str_array)->length) {
        ((str_array)->contents[(str_array)->used])[0] = 0x0; strcat((str_array)->contents[(str_array)->used], string_1);
    } else {
	    (str_array)->contents[(str_array)->length] = (string_1);
	    (str_array)->length++;
    }

    (str_array)->used++;
;
    
	if((str_array)->length == (str_array)->capacity) {
		(str_array)->contents = (char * *) realloc((str_array)->contents, sizeof(char *) * ((str_array)->capacity * 2));
		(str_array)->capacity = ((str_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((str_array)->used < (str_array)->length) {
        ((str_array)->contents[(str_array)->used])[0] = 0x0; strcat((str_array)->contents[(str_array)->used], string_2);
    } else {
	    (str_array)->contents[(str_array)->length] = (string_2);
	    (str_array)->length++;
    }

    (str_array)->used++;
;
    
	if((str_array)->length == (str_array)->capacity) {
		(str_array)->contents = (char * *) realloc((str_array)->contents, sizeof(char *) * ((str_array)->capacity * 2));
		(str_array)->capacity = ((str_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((str_array)->used < (str_array)->length) {
        ((str_array)->contents[(str_array)->used])[0] = 0x0; strcat((str_array)->contents[(str_array)->used], string_3);
    } else {
	    (str_array)->contents[(str_array)->length] = (string_3);
	    (str_array)->length++;
    }

    (str_array)->used++;
;
    
	if((str_array)->length == (str_array)->capacity) {
		(str_array)->contents = (char * *) realloc((str_array)->contents, sizeof(char *) * ((str_array)->capacity * 2));
		(str_array)->capacity = ((str_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((str_array)->used < (str_array)->length) {
        ((str_array)->contents[(str_array)->used])[0] = 0x0; strcat((str_array)->contents[(str_array)->used], string_4);
    } else {
	    (str_array)->contents[(str_array)->length] = (string_4);
	    (str_array)->length++;
    }

    (str_array)->used++;
;

    /* Now, let's clear the array and see if we can replace the
       contents of the array without using more memory. */
    ASSERT_NUMEQ(str_array->used, 4);

    
	do {
        /* We only need to release the contents of the array if
           we do not want to reuse memory. If we do want to reuse
           memory, all we need to do is set the used length to zero
           to signal to adding functions that there is allocated,
           but unused slots in the array. */
        

        /* Regardless of whether or not we reuse memory, this
           can be reset to zero. */
        (str_array)->used = 0;

	} while(0)
;
    ASSERT_NUMEQ(str_array->length, 4);
    ASSERT_NUMEQ(str_array->used, 0);

    /* Let's try refilling now, shall we? */
    
	if((str_array)->length == (str_array)->capacity) {
		(str_array)->contents = (char * *) realloc((str_array)->contents, sizeof(char *) * ((str_array)->capacity * 2));
		(str_array)->capacity = ((str_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((str_array)->used < (str_array)->length) {
        ((str_array)->contents[(str_array)->used])[0] = 0x0; strcat((str_array)->contents[(str_array)->used], "foo");
    } else {
	    (str_array)->contents[(str_array)->length] = ("foo");
	    (str_array)->length++;
    }

    (str_array)->used++;
;
    
	if((str_array)->length == (str_array)->capacity) {
		(str_array)->contents = (char * *) realloc((str_array)->contents, sizeof(char *) * ((str_array)->capacity * 2));
		(str_array)->capacity = ((str_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((str_array)->used < (str_array)->length) {
        ((str_array)->contents[(str_array)->used])[0] = 0x0; strcat((str_array)->contents[(str_array)->used], "bar");
    } else {
	    (str_array)->contents[(str_array)->length] = ("bar");
	    (str_array)->length++;
    }

    (str_array)->used++;
;
    ASSERT_NUMEQ(str_array->length, 4);
    ASSERT_NUMEQ(str_array->used, 2);
    ASSERT_STREQ(str_array->contents[0], "foo");
    ASSERT_STREQ(str_array->contents[1], "bar");

	
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
	
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (str_array)->length) {
			free((str_array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((str_array)->contents);
		free((str_array));
	} while(0)
;

	return 0;
}
