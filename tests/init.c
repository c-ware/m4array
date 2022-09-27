/*
 * Test initializing the array
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
        int length;
        int capacity;
        int *contents;
    }
;

    struct StringArray {
        int length;
        int capacity;
        char * *contents;
    }
;










int main() {
	struct StringArray *my_array = 0;

	my_array = 
	(struct StringArray *) malloc(sizeof(*(my_array)));
	(my_array)->length = 0;
	(my_array)->capacity = 3;
	(my_array)->contents = (char * *) malloc(sizeof(char *) * 3)
;	

    ASSERT_NUMEQ(my_array->length, 0);
    ASSERT_NUMEQ(my_array->capacity, 3);
    ASSERT_PTRNEQ(my_array->contents, CWUTILS_NULL);

	return 0;
}
