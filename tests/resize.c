/*
 * Testing of the resizing functionality of the array.
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










/* Test to see if the resize happens when it should happen */
void test_when_resize_happens_for_length() {
    struct StringArray *array = (struct StringArray *) CWUTILS_NULL;

    array = 
	(struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3)
;

    /* Length of 0 should not cause a resize */
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 0);
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->capacity, 3);

    /* Length of 1 should not cause a resize */
    array->length = 1;
    array->used = 1;

    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 1);
    ASSERT_NUMEQ(array->length, 1);
    ASSERT_NUMEQ(array->capacity, 3);

    /* Length of 2 should not cause a resize */
    array->length = 2;
    array->used = 2;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_NUMEQ(array->length, 2);
    ASSERT_NUMEQ(array->capacity, 3);

    /* Length of 3 should cause a resize */
    array->length = 3;
    array->used = 3;

    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 3);
    ASSERT_NUMEQ(array->length, 3);
    ASSERT_NUMEQ(array->capacity, 3 * 2);

    /* Reset the length so we do not try to innapropriately free uninitialized
     * memory */
    array->length = 0;
    array->used = 0;

    
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

/* Test to make sure that the used field does not affect
   when resizes occur */
void test_used_doesnt_cause_resize() {
    struct StringArray *array = (struct StringArray *) CWUTILS_NULL;

    array = 
	(struct StringArray *) malloc(sizeof(*(array)));
	(array)->used = 0;
	(array)->length = 0;
	(array)->capacity = 3;
	(array)->contents = (char * *) malloc(sizeof(char *) * 3)
;

    /* 0 slots use should not cause a resize */
    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 0);
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->capacity, 3);

    /* 1 slot used should not cause a resize */
    array->used = 1;

    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 1);
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->capacity, 3);

    /* 2 used slots should not cause a resize */
    array->used = 2;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->capacity, 3);

    /* 3 used slots should not cause a resize */
    array->used = 3;

    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 3);
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->capacity, 3);

    /* 4 used slots should not cause a resize */
    array->used = 4;

    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 4);
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->capacity, 3);

    /* 5 used slots should not cause a resize */
    array->used = 5;

    
do {
	if(((array)->length == (array)->capacity) && ((array)->used == (array)->length)) {
		(array)->contents = (char * *) realloc((array)->contents, sizeof(char *) * ((array)->capacity * 2));
		(array)->capacity = ((array)->capacity * 2);
	}
} while(0)
;

    ASSERT_PTRNEQ(array, CWUTILS_NULL);
    ASSERT_PTRNEQ(array->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(array->used, 5);
    ASSERT_NUMEQ(array->length, 0);
    ASSERT_NUMEQ(array->capacity, 3);

    /* OK, I think that is enough. */

    
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
    test_when_resize_happens_for_length();
    test_used_doesnt_cause_resize();

    return 0;
}
