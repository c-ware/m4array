include(src/m4array.m4)

M4ARRAY_DECLARE(IntArray, int);
M4ARRAY_DECLARE(StringArray, char *);

define(`STRING_ARRAY_TYPE', `char *')
define(`STRING_ARRAY_FREE', `free($1)')
define(`STRING_ARRAY_ARRAY_TYPE', `struct StringArray')

/* This array is used for testing memory reuse (hence
   the "RE" */
define(`STRING_ARRAY_RE_TYPE', `char *')
define(`STRING_ARRAY_RE_FREE', `free($1)')
define(`STRING_ARRAY_RE_ARRAY_TYPE', `struct StringArray')
define(`STRING_ARRAY_RE_REUSE', `($2)[0] = 0x0; strcat($2, $1)')

define(`INT_ARRAY_TYPE', `int')
define(`INT_ARRAY_FREE', `')
define(`INT_ARRAY_ARRAY_TYPE', `struct IntArray')
