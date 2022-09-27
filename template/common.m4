include(src/m4array.m4)

struct StringArray {
	int length;
	int capacity;
	char **contents;
};

struct IntArray {
	int length;
	int capacity;
	int *contents;
};

define(`STRING_ARRAY_TYPE', `char *')
define(`STRING_ARRAY_FREE', `free($1)')
define(`STRING_ARRAY_ARRAY_TYPE', `struct StringArray')

define(`INT_ARRAY_TYPE', `int')
define(`INT_ARRAY_FREE', `')
define(`INT_ARRAY_ARRAY_TYPE', `struct IntArray')
