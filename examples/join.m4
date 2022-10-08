dnl @docgen_start
dnl @type: project
dnl @name: m4array-examples-join
dnl @brief: an example for m4array, implementing a string join function
dnl
dnl @examples
dnl @#include <string.h>\N
dnl @#include <stdlib.h>
dnl @
dnl @include(src/m4array.m4)
dnl @
dnl @define(`STRING_ARRAY_TYPE', `char *')\N
dnl @define(`STRING_ARRAY_FREE', `') // String literals cannot be freed\N
dnl @define(`STRING_ARRAY_ARRAY_TYPE', `struct StringArray')\N
dnl @
dnl @M4ARRAY_DECLARE(StringArray, char *);
dnl @
dnl @char *join_string(const struct StringArray *array) {
dnl @   char *my_string = malloc(sizeof(char) * 128);
dnl @
dnl @   my_string[0] = '\0';
dnl @
dnl @   M4ARRAY_FOREACH(array, `
dnl @       // Prevent overflowing the array
dnl @       if((strlen(my_string) + strlen($1)) >= 127)
dnl @           break;
dnl @
dnl @       strcat(my_string, $1);
dnl @   ');
dnl @
dnl @   return my_string;\N
dnl @}
dnl @
dnl @int main() {
dnl @   char *joined_string = NULL;
dnl @   struct StringArray *my_array = M4ARRAY_INIT(my_array, STRING_ARRAY);
dnl @
dnl @   M4ARRAY_APPEND(my_array, "foo", STRING_ARRAY);
dnl @   M4ARRAY_APPEND(my_array, " ", STRING_ARRAY);
dnl @   M4ARRAY_APPEND(my_array, "bar", STRING_ARRAY);
dnl @   M4ARRAY_APPEND(my_array, " ", STRING_ARRAY);
dnl @   M4ARRAY_APPEND(my_array, "baz", STRING_ARRAY);
dnl @
dnl @   joined_string = join_string(my_array);
dnl @
dnl @   printf("Final string: '%s'\n", joined_string);
dnl @
dnl @   free(joined_string);
dnl @   M4ARRAY_FREE(my_array, STRING_ARRAY);
dnl @
dnl @   return 0;\N
dnl @}
dnl @examples
dnl
dnl @docgen_end

/*
 * An example of writing a function which joins strings in an array.
*/

#include <string.h>
#include <stdlib.h>

include(src/m4array.m4)

define(`STRING_ARRAY_TYPE', `char *')
define(`STRING_ARRAY_FREE', `') // String literals cannot be freed
define(`STRING_ARRAY_ARRAY_TYPE', `struct StringArray')

M4ARRAY_DECLARE(StringArray, char *);

char *join_string(const struct StringArray *array) {
   char *my_string = malloc(sizeof(char) * 128);

   my_string[0] = '\0';

   M4ARRAY_FOREACH(array, `
       // Prevent overflowing the array
       if((strlen(my_string) + strlen($1)) >= 127)
           break;

       strcat(my_string, $1);
   ');

   return my_string;
}

int main() {
   char *joined_string = NULL;
   struct StringArray *my_array = M4ARRAY_INIT(my_array, STRING_ARRAY);

   M4ARRAY_APPEND(my_array, "foo", STRING_ARRAY);
   M4ARRAY_APPEND(my_array, " ", STRING_ARRAY);
   M4ARRAY_APPEND(my_array, "bar", STRING_ARRAY);
   M4ARRAY_APPEND(my_array, " ", STRING_ARRAY);
   M4ARRAY_APPEND(my_array, "baz", STRING_ARRAY);

   joined_string = join_string(my_array);

   printf("Final string: '%s'\n", joined_string);

   free(joined_string);
   M4ARRAY_FREE(my_array, STRING_ARRAY);

   return 0;
}
