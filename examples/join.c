
/*
 * An example of writing a function which joins strings in an array.
*/

#include <string.h>
#include <stdlib.h>



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





























 // String literals cannot be freed



    struct StringArray {
        int used;
        int length;
        int capacity;

        char * *contents;
    }
;

char *join_string(const struct StringArray *array) {
   char *my_string = malloc(sizeof(char) * 128);

   my_string[0] = '\0';

   
	

    do {
        int __M4_INDEX = 0;

        while(__M4_INDEX < (array)->length) {
            
       // Prevent overflowing the array
       if((strlen(my_string) + strlen((array)->contents[__M4_INDEX])) >= 127)
           break;

       strcat(my_string, (array)->contents[__M4_INDEX]);
   ;

            __M4_INDEX++;
        }
    } while(0)
;

   return my_string;
}

int main() {
   char *joined_string = NULL;
   struct StringArray *my_array = 
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
	    (my_array)->contents[(my_array)->length] = ("foo");
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
	    (my_array)->contents[(my_array)->length] = (" ");
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
	    (my_array)->contents[(my_array)->length] = ("bar");
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
	    (my_array)->contents[(my_array)->length] = (" ");
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
	    (my_array)->contents[(my_array)->length] = ("baz");
	    (my_array)->length++;
    }

    (my_array)->used++;
;

   joined_string = join_string(my_array);

   printf("Final string: '%s'\n", joined_string);

   free(joined_string);
   
	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_array)->length) {
			;
			__M4_INDEX++;
		}

		free((my_array)->contents);
		free((my_array));
	} while(0)
;

   return 0;
}
