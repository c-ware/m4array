/*
 * Testing of the insert operation.
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










void test_insert() {
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
	(struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3)
;

    /* Cannot insert into an empty array */
    
    
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

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[0] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[0] = b;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    ASSERT_NUMEQ(array->length, 2);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_NUMEQ(array->capacity, 3);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "bar");
    ASSERT_STREQ(array->contents[1], "foo");

    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[0] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[0] = c;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    ASSERT_NUMEQ(array->length, 3);
    ASSERT_NUMEQ(array->used, 3);
    ASSERT_NUMEQ(array->capacity, 3);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "baz");
    ASSERT_STREQ(array->contents[1], "bar");
    ASSERT_STREQ(array->contents[2], "foo");

    
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
	(struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3)
;

    /* Cannot insert into an empty array */
    
    
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

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[0] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[0] = b;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[0] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[0] = c;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;

    /* Should trigger a resize */
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (1 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (1) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[1] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[1] = d;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 4);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "baz");
    ASSERT_STREQ(array->contents[1], "tuna");
    ASSERT_STREQ(array->contents[2], "bar");
    ASSERT_STREQ(array->contents[3], "foo");

    /* Can we insert after a resize? */
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (2 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (2) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[2] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[2] = e;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    ASSERT_NUMEQ(array->length, 5);
    ASSERT_NUMEQ(array->used, 5);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "baz");
    ASSERT_STREQ(array->contents[1], "tuna");
    ASSERT_STREQ(array->contents[2], "spam");
    ASSERT_STREQ(array->contents[3], "bar");
    ASSERT_STREQ(array->contents[4], "foo");

    
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

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[0] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[0] = b;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (0 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (0) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[0] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[0] = c;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (1 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (1) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[1] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[1] = d;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (2 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (2) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[2] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[2] = e;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;

    /* Try "replacing" the last element of the array (in this case, foo,
     * which was held in pointer a, with f. */
    array->used = 4;

    
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

	do {
		int __M4_INDEX = (array)->used - 1;
        char * __M4_TEMP = (array)->contents[(array)->used];

		/* Shift each element before (2 - 1) over by 1. This WILL overwrite
           the first allocated, but unused slot in the array, but this is not
           an issue because in the case where we do care about memory reuse,
           we save the first reusable slot anyway. */
		while(__M4_INDEX != (2) - 1) {
			(array)->contents[__M4_INDEX + 1] = (array)->contents[__M4_INDEX];
			__M4_INDEX--;
		}

        if((array)->used < (array)->length) {
            (__M4_TEMP)[0] = 0x0; strcat(__M4_TEMP, f);

            /* We do not increase the length of the array because we do
               not actually increase the length of initialized data. */
		    (array)->contents[2] = __M4_TEMP;
		    (array)->used++;
        } else {
		    (array)->contents[2] = f;
		    (array)->length++;
		    (array)->used++;
        }
	} while(0)
;
    ASSERT_NUMEQ(array->length, 5);
    ASSERT_NUMEQ(array->used, 5);
    ASSERT_NUMEQ(array->capacity, 3 * 2);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_STREQ(array->contents[0], "baz");
    ASSERT_STREQ(array->contents[1], "tuna");
    ASSERT_STREQ(array->contents[2], "thud");
    ASSERT_STREQ(array->contents[3], "spam");
    ASSERT_STREQ(array->contents[4], "bar");

    /* Make sure we replaced the pointer 'a' */
    ASSERT_PTREQ(array->contents[2], a);

    
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
    test_insert();
    test_resize();
    test_reuse();

    return 0;
}
