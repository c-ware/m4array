/*
 * Test filtering an array based on a predicate.
*/

#include "common.h"

include(template/common.m4)

/* Test the basic behavior of the filter operation */
void filter_basic() {
	struct IntArray *array = M4ARRAY_INIT(array, INT_ARRAY);

    M4ARRAY_APPEND(array, 1, INT_ARRAY);
    M4ARRAY_APPEND(array, 2, INT_ARRAY);
    M4ARRAY_APPEND(array, 3, INT_ARRAY);
    M4ARRAY_APPEND(array, 4, INT_ARRAY);

    /* Filter all elements that are not divisible by two */
    M4ARRAY_FILTER(array, `($1 % 2) == 0', INT_ARRAY);
    ASSERT_NUMEQ(array->length, 2);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_NUMEQ(array->contents[0], 2);
    ASSERT_NUMEQ(array->contents[1], 4);

    /* Add some more to filter further */
    M4ARRAY_APPEND(array, 5, INT_ARRAY);
    M4ARRAY_APPEND(array, 6, INT_ARRAY);
    M4ARRAY_APPEND(array, 7, INT_ARRAY);
    M4ARRAY_APPEND(array, 8, INT_ARRAY);

    /* Filter all elements that are not divisible by two */
    M4ARRAY_FILTER(array, `($1 % 2) == 0', INT_ARRAY);
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 4);
    ASSERT_NUMEQ(array->contents[0], 2);
    ASSERT_NUMEQ(array->contents[1], 4);
    ASSERT_NUMEQ(array->contents[2], 6);
    ASSERT_NUMEQ(array->contents[3], 8);

    M4ARRAY_FREE(array, INT_ARRAY);
}

/* Test the behavior of the filter operation when we deal
   with memory reuse */
void filter_memory_reuse() {
    struct StringArray *array = M4ARRAY_INIT(array, STRING_ARRAY);
    char *string_a = malloc(16);
    char *string_b = malloc(16);
    char *string_c = malloc(16);
    char *string_d = malloc(16);
    char *string_e = malloc(16);
    char *string_f = malloc(16);

    strcpy(string_a, "foo");
    strcpy(string_b, "bar");
    strcpy(string_c, "baz");
    strcpy(string_d, "tuna");
    strcpy(string_e, "buzz");
    strcpy(string_f, "blue");

    M4ARRAY_APPEND(array, string_a, STRING_ARRAY_RE);
    M4ARRAY_APPEND(array, string_b, STRING_ARRAY_RE);
    M4ARRAY_APPEND(array, string_c, STRING_ARRAY_RE);
    M4ARRAY_APPEND(array, string_d, STRING_ARRAY_RE);

    /* Filter all strings not starting with 0x62 ('b') */
    M4ARRAY_FILTER(array, `($1)[0] == 0x62', STRING_ARRAY_RE);
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 2);
    ASSERT_STREQ(array->contents[0], "bar");
    ASSERT_STREQ(array->contents[1], "baz");

    /* Can we the filter operation handle 'refilled' data? */
    M4ARRAY_APPEND(array, string_e, STRING_ARRAY_RE);
    M4ARRAY_FILTER(array, `($1)[0] == 0x62', STRING_ARRAY_RE);
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 3);
    ASSERT_STREQ(array->contents[0], "bar");
    ASSERT_STREQ(array->contents[1], "baz");
    ASSERT_STREQ(array->contents[2], "buzz");

    /* Can we do it again?! */
    M4ARRAY_APPEND(array, string_f, STRING_ARRAY_RE);
    M4ARRAY_FILTER(array, `($1)[0] == 0x62', STRING_ARRAY_RE);
    ASSERT_NUMEQ(array->length, 4);
    ASSERT_NUMEQ(array->used, 4);
    ASSERT_STREQ(array->contents[0], "bar");
    ASSERT_STREQ(array->contents[1], "baz");
    ASSERT_STREQ(array->contents[2], "buzz");
    ASSERT_STREQ(array->contents[3], "blue");
    
    M4ARRAY_FREE(array, STRING_ARRAY);
}

int main() {
    filter_basic();
    filter_memory_reuse();

	return 0;
}
