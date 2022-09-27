include(src/m4array.m4)

M4ARRAY_DECLARE(IntArray, int);
M4ARRAY_DECLARE(StringArray, char *);

define(`STRING_ARRAY_TYPE', `char *')
define(`STRING_ARRAY_FREE', `free($1)')
define(`STRING_ARRAY_ARRAY_TYPE', `struct StringArray')

define(`INT_ARRAY_TYPE', `int')
define(`INT_ARRAY_FREE', `')
define(`INT_ARRAY_ARRAY_TYPE', `struct IntArray')
