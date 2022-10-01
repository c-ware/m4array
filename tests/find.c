/*
 * Testing of the find operation.
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










void test_find() {
    int index = 0;
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

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "foo") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 0);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "bar") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "baz") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "tuna") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "spam") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 4);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "thud") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 5);

    
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

void test_find_doesnt_search_unused_sections() {
    int index = 0;
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

    /* Cut off the last two elements, then try to find them. */
    array->used = 4;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "spam") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "thud") == 0) == 0) {
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

		while(__M4_INDEX < (array)->length) {
			free((array)->contents[__M4_INDEX]);
			__M4_INDEX++;
		}

		free((array)->contents);
		free((array));
	} while(0)
;
}

/* Since we verified that the find operation doesn't check past the
 * used length, we need to make sure it still searches in a used length
 * that is not equal to the length of the array, like used = 0, used = 1,
 * used = 2, etc*/
void test_find_searches_before_used() {
    int index = 0;
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

    /* We only allow it to search 4 of the first strings */
    array->used = 4;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "foo") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 0);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "bar") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "baz") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "tuna") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "spam") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

    /* We only allow it to search 3 of the first strings */
    array->used = 3;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "foo") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 0);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "bar") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "baz") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "tuna") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

    /* We only allow it to search 2 of the first strings */
    array->used = 2;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "foo") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 0);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "bar") == 0) == 0) {
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

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "baz") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

    /* We only allow it to search 1 of the first strings */
    array->used = 1;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "foo") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, 0);

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "bar") == 0) == 0) {
				__M4_INDEX++;
				continue;
			}

			(index) = __M4_INDEX;
			break;
		}
	} while(0)
;
    ASSERT_NUMEQ(index, -1);

    /* We only allow it to search 0 of the first strings */
    array->used = 0;

    index = 
	-1;

	(index) = -1;

	

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (array)->used) {
			if((strcmp((array)->contents[__M4_INDEX], "foo") == 0) == 0) {
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
    test_find();
    test_find_doesnt_search_unused_sections();
    test_find_searches_before_used();

    return 0;
}
