/*
 * Test finding data inthe array
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
    int index = 0;
	struct StringArray *my_array = 0;
	char *string_1 = (CWUTILS_GENERIC) malloc(4);
	char *string_2 = (CWUTILS_GENERIC) malloc(4);
	char *string_3 = (CWUTILS_GENERIC) malloc(4);
	char *string_4 = (CWUTILS_GENERIC) malloc(4);
	char *string_5 = (CWUTILS_GENERIC) malloc(4);

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

	string_5[0] = 'q';
	string_5[1] = 'a';
	string_5[2] = 'z';
	string_5[3] = '\0';


	my_array = 
	(struct StringArray *) malloc(sizeof(*(my_array)));
	(my_array)->used = 0;
	(my_array)->length = 0;
	(my_array)->capacity = 3;
	(my_array)->contents = (char * *) malloc(sizeof(char *) * 3)
;	

	
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        
    } else {
	    (my_array)->contents[(my_array)->length] = (string_1);
	    (my_array)->length++;
    }

    (my_array)->used++;
;
	
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        
    } else {
	    (my_array)->contents[(my_array)->length] = (string_2);
	    (my_array)->length++;
    }

    (my_array)->used++;
;
	
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        
    } else {
	    (my_array)->contents[(my_array)->length] = (string_3);
	    (my_array)->length++;
    }

    (my_array)->used++;
;
	
	if((my_array)->length == (my_array)->capacity) {
		(my_array)->contents = (char * *) realloc((my_array)->contents, sizeof(char *) * ((my_array)->capacity * 2));
		(my_array)->capacity = ((my_array)->capacity * 2);
	}

    /* If used < length, that means we have data in the array that
       is currently unused, but initialized. We can reuse it. Otherwise,
       we can just append like normal. */
    if((my_array)->used < (my_array)->length) {
        
    } else {
	    (my_array)->contents[(my_array)->length] = (string_4);
	    (my_array)->length++;
    }

    (my_array)->used++;
;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "qaz") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "quz") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 3);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "baz") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 2);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "bar") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 1);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "foo") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 0);

    /* Make sure the find operation does not go past the length. */
    my_array->used = 0;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "qaz") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "quz") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "baz") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "bar") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->used) {
			if((strcmp((my_array)->contents[__M4_INDEX], "foo") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

	
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->length) {
			free((my_array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((my_array)->contents);
		free((my_array));
	} while(0)
;

	return 0;
}
